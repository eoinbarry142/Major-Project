// Fill out your copyright notice in the Description page of Project Settings.

#include "ProceduralFloor.h"
#include "DrawDebugHelpers.h"
#include "Components/StaticMeshComponent.h"
#include "Kismet/KismetSystemLibrary.h"
#include "PhysicalMaterials/PhysicalMaterial.h"

// Sets default values
AProceduralFloor::AProceduralFloor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);

	GridSizeX = 2;
	GridSizeY = 2;
	SquareWidth = 15000.f;

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
			while (temp < 1)
			{
				FVector UpperLeft(i * SquareWidth + Radius, j * SquareWidth + Radius, GridHeight);
				FVector LowerRight(i * SquareWidth + SquareWidth - Radius, j * SquareWidth + SquareWidth - Radius, GridHeight);

				//Raycast down from random point in square to the ground
				//Raycast start and end points
				FVector Start = GetRandomPointInSquare(UpperLeft, LowerRight);
				FVector End = ((-GetActorUpVector() * TraceDistance) + Start);

				FHitResult Hit;
				FCollisionQueryParams TraceParams;
				TraceParams.bReturnPhysicalMaterial = true;
				bool bHit = GetWorld()->LineTraceSingleByChannel(Hit, Start, End, ECC_Visibility, TraceParams);
				//DrawDebugLine(GetWorld(), Start, End, FColor::Orange, false, 10.0f);

				if (bHit && Hit.GetActor()->GetName() == "Landscape_0")
				{
					const EPhysicalSurface SurfaceType = UPhysicalMaterial::DetermineSurfaceType(Hit.PhysMaterial.Get());
					const FName SurfaceName = *StaticEnum<EPhysicalSurface>()->GetAuthoredNameStringByValue(SurfaceType);

					FVector impact = Hit.ImpactPoint;

					//Randomise yaw rotation
					float RandomYaw = FMath::FRandRange(0.f, 360.f);

					if (SurfaceName.ToString() == "SurfaceType_Default")
					{
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, FString::Printf(TEXT("SurfaceType_Default")));
					}
					//Grass
					else if (SurfaceName.ToString() == "SurfaceType1")
					{
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, FString::Printf(TEXT("Grass")));
						GetWorld()->SpawnActor<AActor>(ShrineClass, impact, FRotator(0.f, RandomYaw, 0.f));
						temp += 1;
					}
					//Sand
					else if (SurfaceName.ToString() == "SurfaceType2")
					{
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, FString::Printf(TEXT("Sand")));
						GetWorld()->SpawnActor<AActor>(ShrineClass, impact, FRotator(0.f, RandomYaw, 0.f));
						temp += 1;
					}
					//Water
					else if (SurfaceName.ToString() == "SurfaceType3")
					{
						GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, FString::Printf(TEXT("Water")));
					}
					//GEngine->AddOnScreenDebugMessage(-1, 5, FColor::Orange, FString::Printf(TEXT("Trace Hit: %s "), *Hit.GetActor()->GetName()));
				}
				//DrawDebugPoint(GetWorld(), RandomPointInSquare, 5.f, FColor::Red, true);
			}

			temp = 0;

		}
	}
}

//void AProceduralFloor::Trace()
//{
//	FVector Start = GetRandomPointInSquare(UpperLeft, LowerRight);
//	FVector End = ((GetForwardVector() * TraceDistance) + Start);
//}

