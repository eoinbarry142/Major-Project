// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Procedural.generated.h"

UCLASS()
class MAJORPROJECT_API AProcedural : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProcedural();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

private:
	//Create floor component
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Floor, meta = (AllowPrivateAccess = "true"))
	UStaticMeshComponent* Floor;

	//Create variable to reference cube/shrine blueprint
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Floor, meta = (AllowPrivateAccess = "true"))
	TSubclassOf<AActor> RockClass1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Floor, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> RockClass2;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Floor, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> RockClass3;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Floor, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> TreeClass1;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Floor, meta = (AllowPrivateAccess = "true"))
		TSubclassOf<AActor> TreeClass2;

	//Function to spawn blueprint actors into the world
	//void SpawnObject(UClass* ObjectToSpawn);

	//Grid variables
	float SquareWidth;
	float GridHeight;
	float RoomLength;
	float RoomWidth;
	float Radius;
	float TraceDistance;
	int32 GridSizeX;
	int32 GridSizeY;
	FVector TopLeft;
	FVector BottomRight;

	//Create grid function
	void CreateGrid();

	//Takes parameters
	FVector GetRandomPointInSquare(const FVector& UpperLeft, const FVector& LowerRight);

	void PlacePointsOnGrid();
};
