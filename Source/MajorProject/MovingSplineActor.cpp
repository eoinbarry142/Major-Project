// Fill out your copyright notice in the Description page of Project Settings.


#include "MovingSplineActor.h"

// Sets default values
AMovingSplineActor::AMovingSplineActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SplineComponent = CreateDefaultSubobject<USplineComponent>(TEXT("Spline Component"));
	SplineComponent->SetupAttachment(GetRootComponent());

	MeshComponent = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("Mesh Component"));
	MeshComponent->SetupAttachment(SplineComponent);

	TriggerComponent = CreateDefaultSubobject<UBoxComponent>(TEXT("Trigger Component"));
	TriggerComponent->SetupAttachment(MeshComponent);

}

// Called when the game starts or when spawned
void AMovingSplineActor::BeginPlay()
{
	Super::BeginPlay();

	TriggerComponent->OnComponentBeginOverlap.AddDynamic(this, &AMovingSplineActor::TriggerBeginOverlap);
	TriggerComponent->OnComponentEndOverlap.AddDynamic(this, &AMovingSplineActor::TriggerEndOverlap);

}

// Called every frame
void AMovingSplineActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (MovementTimeline.IsPlaying())
	{
		MovementTimeline.TickTimeline(DeltaTime);
	}
}

//Move mesh along spline
void AMovingSplineActor::ProcessMovementTimeline(float Value)
{
	const float SplineLength = SplineComponent->GetSplineLength();

	FVector CurrentSplineLocation = SplineComponent->GetLocationAtDistanceAlongSpline(Value * SplineLength, ESplineCoordinateSpace::World);
	FRotator CurrentSplineRotation = SplineComponent->GetRotationAtDistanceAlongSpline(Value * SplineLength, ESplineCoordinateSpace::World);

	MeshComponent->SetWorldLocationAndRotation(CurrentSplineLocation, CurrentSplineRotation);
}

void AMovingSplineActor::OnEndMovementTimeline()
{
}

//Called when player enters trigger box
void AMovingSplineActor::TriggerBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	FOnTimelineFloat ProgressFunction;
	ProgressFunction.BindUFunction(this, TEXT("ProcessMovementTimeline"));
	MovementTimeline.AddInterpFloat(MovementCurve, ProgressFunction);

	FOnTimelineEvent OnTimelineFinishedFunction;
	OnTimelineFinishedFunction.BindUFunction(this, TEXT("OnEndMovementTimeline"));
	MovementTimeline.SetTimelineFinishedFunc(OnTimelineFinishedFunction);

	MovementTimeline.SetTimelineLengthMode(TL_LastKeyFrame);
	MovementTimeline.Play();
}

//Called when player leaves trigger box
void AMovingSplineActor::TriggerEndOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex)
{
}

