// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralFloor.h"
#include "DrawDebugHelpers.h"

// Sets default values
AProceduralFloor::AProceduralFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);

	GridSizeX = 2;
	GridSizeY = 2;
	SquareWidth = 10000.f;

	TopLeft = FVector(0.f);
	BottomRight = FVector(100000.f, 0.f, 100000.f);
	GridHeight = 1.f;
	RoomLength = 10000.f;
	RoomWidth = 10000.f;
	Radius = 25.f;

	TraceDistance = 10000.0f;
}

// Called when the game starts or when spawned
void AProceduralFloor::BeginPlay()
{
	Super::BeginPlay();

	CreateGrid();
	PlacePointsOnGrid();
	
	//SpawnItem(ShrineClass);
}

// Called every frame
void AProceduralFloor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//void AProceduralFloor::SpawnItem(UClass * ItemToSpawn)
//{
//	float XCoordinate = FMath::FRandRange(-500.f, 500.f);
//	float YCoordinate = FMath::FRandRange(-500.f, 500.f);

//	float Yaw = FMath::FRandRange(0.f, 360.f);

//	FRotator Rotation(0.f, Yaw, 0.f);
//
//	GetWorld()->SpawnActor<AActor>(ItemToSpawn, Location, Rotation);
//}

void AProceduralFloor::CreateGrid()
{
	for (int32 i = 0; i < GridSizeX + 1; i++)
	{
		FVector Start = TopLeft + FVector(i * SquareWidth, 0.f, GridHeight);
		FVector End = Start + FVector(0.f, RoomLength, GridHeight);
		//DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}

	for (int32 i = 0; i < GridSizeX + 1; i++)
	{
		FVector Start = TopLeft + FVector(0.f, i * SquareWidth, GridHeight);
		FVector End = Start + FVector(RoomWidth, 0.f, GridHeight);
		//DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}
}

FVector AProceduralFloor::GetRandomPointInSquare(const FVector& UpperLeft, const FVector& LowerRight)
{
	float RandomX = FMath::FRandRange(UpperLeft.X, LowerRight.X);
	float RandomY = FMath::FRandRange(UpperLeft.Y, LowerRight.Y);
	
	return FVector(RandomX, RandomY, 0.f);
}

void AProceduralFloor::PlacePointsOnGrid()
{
	for (int32 i = 0; i < GridSizeX; i++)
	{
		for (int32 j = 0; j < GridSizeY; j++)
		{
			FVector UpperLeft(i * SquareWidth + Radius, j * SquareWidth + Radius, GridHeight);
			FVector LowerRight(i * SquareWidth + SquareWidth - Radius, j * SquareWidth + SquareWidth - Radius, GridHeight);
			
			//Raycast down from random point in square to the ground
			//Raycast start and end points
			FVector Start = GetRandomPointInSquare(UpperLeft, LowerRight);
			FVector End = ((-GetActorUpVector() * TraceDistance) + Start);

			FHitResult Hit;
			FCollisionQueryParams TraceParams;
			bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);
			//DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 10.0f);

			if(bHit)
			{
				GEngine->AddOnScreenDebugMessage(-1, 1, FColor::Orange, FString::Printf(TEXT("Trace Hit: %s "), *Hit.GetActor()->GetName()));
				FVector impact = Hit.ImpactPoint;

				float RandomYaw = FMath::FRandRange(0.f, 360.f);
				GetWorld()->SpawnActor<AActor>(ShrineClass, impact, FRotator(0.f, RandomYaw, 0.f));
			}

			

			

			//DrawDebugPoint(GetWorld(), RandomPointInSquare, 5.f, FColor::Red, true);

		}
	}
}

//void AProceduralFloor::Trace()
//{
//	FVector Start = GetRandomPointInSquare(UpperLeft, LowerRight);
//	FVector End = ((GetForwardVector() * TraceDistance) + Start);
//}

