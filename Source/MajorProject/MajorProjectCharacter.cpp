// Copyright Epic Games, Inc. All Rights Reserved.

#include "MajorProjectCharacter.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "Camera/CameraComponent.h"
#include "Components/CapsuleComponent.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/Controller.h"
#include "GameFramework/SpringArmComponent.h"
#include "ShrineInteractable.h"
#include "MenuHUD.h"
#include "Blueprint/UserWidget.h"
#include <Kismet/GameplayStatics.h>
#include "BoatClass.h"
#include <string> 

//////////////////////////////////////////////////////////////////////////
// AMajorProjectCharacter

AMajorProjectCharacter::AMajorProjectCharacter()
{
	//shrineCount = 0;

	InteractionBox = CreateDefaultSubobject<UBoxComponent>(TEXT("Interaction Box"));
	InteractionBox->SetupAttachment(RootComponent);

	// Set size for collision capsule
	GetCapsuleComponent()->InitCapsuleSize(42.f, 96.0f);

	// set our turn rates for input
	BaseTurnRate = 45.f;
	BaseLookUpRate = 45.f;

	// Don't rotate when the controller rotates. Let that just affect the camera.
	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;

	// Configure character movement
	GetCharacterMovement()->bOrientRotationToMovement = true; // Character moves in the direction of input...	
	GetCharacterMovement()->RotationRate = FRotator(0.0f, 540.0f, 0.0f); // ...at this rotation rate
	GetCharacterMovement()->JumpZVelocity = 600.f;
	GetCharacterMovement()->AirControl = 0.2f;

	// Create a camera boom (pulls in towards the player if there is a collision)
	CameraBoom = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraBoom"));
	CameraBoom->SetupAttachment(RootComponent);
	CameraBoom->TargetArmLength = 300.0f; // The camera follows at this distance behind the character	
	CameraBoom->bUsePawnControlRotation = true; // Rotate the arm based on the controller

	// Create a follow camera
	FollowCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("FollowCamera"));
	FollowCamera->SetupAttachment(CameraBoom, USpringArmComponent::SocketName); // Attach the camera to the end of the boom and let the boom adjust to match the controller orientation
	FollowCamera->bUsePawnControlRotation = false; // Camera does not rotate relative to arm

	// Note: The skeletal mesh and anim blueprint references on the Mesh component (inherited from Character) 
	// are set in the derived blueprint asset named MyCharacter (to avoid direct content references in C++)
}

//////////////////////////////////////////////////////////////////////////
// Input

void AMajorProjectCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	InteractionBox->OnComponentBeginOverlap.AddDynamic(this, &AMajorProjectCharacter::OnBoxBeginOverlap);
	InteractionBox->OnComponentEndOverlap.AddDynamic(this, &AMajorProjectCharacter::OnBoxEndOverlap);

	// Set up gameplay key bindings
	check(PlayerInputComponent);
	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	//Interact with object
	PlayerInputComponent->BindAction("Interact", IE_Pressed, this, &AMajorProjectCharacter::OnInteract);

	PlayerInputComponent->BindAxis("MoveForward", this, &AMajorProjectCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AMajorProjectCharacter::MoveRight);

	// We have 2 versions of the rotation bindings to handle different kinds of devices differently
	// "turn" handles devices that provide an absolute delta, such as a mouse.
	// "turnrate" is for devices that we choose to treat as a rate of change, such as an analog joystick
	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("TurnRate", this, &AMajorProjectCharacter::TurnAtRate);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
	PlayerInputComponent->BindAxis("LookUpRate", this, &AMajorProjectCharacter::LookUpAtRate);

	// handle touch devices
	PlayerInputComponent->BindTouch(IE_Pressed, this, &AMajorProjectCharacter::TouchStarted);
	PlayerInputComponent->BindTouch(IE_Released, this, &AMajorProjectCharacter::TouchStopped);

	// VR headset functionality
	PlayerInputComponent->BindAction("ResetVR", IE_Pressed, this, &AMajorProjectCharacter::OnResetVR);
}


void AMajorProjectCharacter::OnResetVR()
{
	// If MajorProject is added to a project via 'Add Feature' in the Unreal Editor the dependency on HeadMountedDisplay in MajorProject.Build.cs is not automatically propagated
	// and a linker error will result.
	// You will need to either:
	//		Add "HeadMountedDisplay" to [YourProject].Build.cs PublicDependencyModuleNames in order to build successfully (appropriate if supporting VR).
	// or:
	//		Comment or delete the call to ResetOrientationAndPosition below (appropriate if not supporting VR)
	UHeadMountedDisplayFunctionLibrary::ResetOrientationAndPosition();
}

//void AMajorProjectCharacter::BeginPlay()
//{
//	if (GEngine)
//		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Yellow, TEXT("BeginPlay"));
//}

void AMajorProjectCharacter::TouchStarted(ETouchIndex::Type FingerIndex, FVector Location)
{
		Jump();
}

void AMajorProjectCharacter::TouchStopped(ETouchIndex::Type FingerIndex, FVector Location)
{
		StopJumping();
}

void AMajorProjectCharacter::TurnAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerYawInput(Rate * BaseTurnRate * GetWorld()->GetDeltaSeconds());
}

void AMajorProjectCharacter::LookUpAtRate(float Rate)
{
	// calculate delta for this frame from the rate information
	AddControllerPitchInput(Rate * BaseLookUpRate * GetWorld()->GetDeltaSeconds());
}

void AMajorProjectCharacter::MoveForward(float Value)
{
	if ((Controller != nullptr) && (Value != 0.0f))
	{
		// find out which way is forward
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);

		// get forward vector
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
		AddMovementInput(Direction, Value);
	}
}

void AMajorProjectCharacter::MoveRight(float Value)
{
	if ( (Controller != nullptr) && (Value != 0.0f) )
	{
		// find out which way is right
		const FRotator Rotation = Controller->GetControlRotation();
		const FRotator YawRotation(0, Rotation.Yaw, 0);
	
		// get right vector 
		const FVector Direction = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
		// add movement in that direction
		AddMovementInput(Direction, Value);
	}
}

void AMajorProjectCharacter::OnInteract()
{
	if (Interface)
	{
		Interface->InteractWithMe();
		//shrineCountIncrement();
	}
}

void AMajorProjectCharacter::OnBoxBeginOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult & SweepResult)
{
	Interface = Cast<IInteractionInterface>(OtherActor);

	if (Interface)
	{
		Interface->ShowInteractionWidget();
	}
	//Oui();
}

void AMajorProjectCharacter::OnBoxEndOverlap(UPrimitiveComponent * OverlappedComp, AActor * OtherActor, UPrimitiveComponent * OtherComp, int32 OtherBodyIndex)
{
	if (Interface) {
		Interface->HideInteractionWidget();
		Interface = nullptr;
	}
}

void AMajorProjectCharacter::ShrineCountIncrement()
{
	//if (GEngine)
	//	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Yellow, TEXT("called"));
	shrineCount = shrineCount + 1;
	//UE_LOG(LogTemp, Warning, TEXT("Text, %d"), shrineCount);

	if (shrineCount == 4)
	{
		//GetWorld()->GetTimerManager().SetTimer(_loopTimerHandle, this, &AMajorProjectCharacter::WinScreen, 3.5f, false);

		//if (GEngine)
		//	GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Yellow, TEXT("4"));

		for (TObjectIterator<ABoatClass> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(ABoatClass::StaticClass()))
			{
				ABoatClass* actorClass = *Itr;
				actorClass->Ready();
			}
		}
	}
}

void AMajorProjectCharacter::WinScreen()
{
	
}

void AMajorProjectCharacter::Settings()
{
	if (GEngine)
		GEngine->AddOnScreenDebugMessage(1, 2.0f, FColor::Yellow, TEXT("called"));
}


