// Fill out your copyright notice in the Description page of Project Settings.


#include "Procedural.h"
#include "DrawDebugHelpers.h"

// Sets default values
AProcedural::AProcedural()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//Create floor component and set it as root component
	Floor = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("FloorComponent"));
	SetRootComponent(Floor);

	//Assign default values to variables
	SquareWidth = 500.f;
	GridHeight = 1.f;
	RoomLength = 1000.f;
	RoomWidth = 1000.f;
	Radius = 25.f;
	GridSizeX = 2;
	GridSizeY = 2;
	TopLeft = FVector(0.f);
	BottomRight = FVector(1000.f, 1000.f, 0.f);
}

// Called when the game starts or when spawned
void AProcedural::BeginPlay()
{
	Super::BeginPlay();
	
	//Call function to spawn object and pass in cube blueprint
	SpawnObject(CubeClass);

	CreateGrid();

	PlacePointsOnGrid();
}

// Called every frame
void AProcedural::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

//Function to spawn blueprint actors into the world
void AProcedural::SpawnObject(UClass * ObjectToSpawn)
{
	//Generate random floats within specified range
	float XCoordinate = FMath::FRandRange(-500.f, 500.f);
	float YCoordinate = FMath::FRandRange(-500.f, 500.f);
	float Yaw = FMath::FRandRange(0.f, 360.f);

	//Create FVector using randomised X and Y coordinates
	FVector Location(XCoordinate, YCoordinate, 0.f);
	//Create Rotator using randomised yaw
	FRotator Rotation(0.f, Yaw, 0.f);

	GetWorld()->SpawnActor<AActor>(ObjectToSpawn, Location, Rotation);
}

void AProcedural::CreateGrid()
{
	//Horizontal lines
	for (int32 i = 0; i < GridSizeX +1; i++)
	{
		FVector Start = TopLeft + FVector(i * SquareWidth, 0.f, GridHeight);
		FVector End = Start + FVector(0.f, RoomLength, GridHeight);
		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}
	//Vertical lines
	for (int32 i = 0; i < GridSizeX + 1; i++)
	{
		FVector Start = TopLeft + FVector(0.f, i * SquareWidth, GridHeight);
		FVector End = Start + FVector(RoomWidth, 0.f, GridHeight);
		DrawDebugLine(GetWorld(), Start, End, FColor::Blue, true);
	}
}

FVector AProcedural::GetRandomPointInSquare(const FVector& UpperLeft, const FVector& LowerRight)
{
	float RandomX = FMath::FRandRange(UpperLeft.X, LowerRight.X);
	float RandomY = FMath::FRandRange(UpperLeft.Y, LowerRight.Y);

	return FVector(RandomX, RandomY, 0.f);
}

void AProcedural::PlacePointsOnGrid()
{
	//Nested loop to loop through each point on the grid, getting upper left corner and bottom right corner and then getting random point
	for (int32 i = 0; i < GridSizeX; i++)
	{
		for (int32 j = 0; j < GridSizeY; j++)
		{
			FVector UpperLeft(i * SquareWidth + Radius, j * SquareWidth + Radius, GridHeight);
			FVector LowerRight(i * SquareWidth + SquareWidth - Radius, j * SquareWidth + SquareWidth - Radius, GridHeight);

			FVector RandomPointInSquare = GetRandomPointInSquare(UpperLeft, LowerRight);

			//DrawDebugPoint(GetWorld(), RandomPointInSquare, 5.f, FColor::Red, true);
			DrawDebugCircle(GetWorld(), RandomPointInSquare, 25.f, 48, FColor::Red, -1.f, 0, 2.f, false, FVector(0.f, 1.f, 0.f), FVector(1.f, 0.f, 0.f), true);
		}
	}
}