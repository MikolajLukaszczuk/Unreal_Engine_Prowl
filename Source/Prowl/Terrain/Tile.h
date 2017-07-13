// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "GameFramework/Actor.h"
#include "Tile.generated.h"

class UActorPool;

UCLASS()
class PROWL_API ATile : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	ATile();

	UFUNCTION(BlueprintCallable, Category = "Weapon")
		void PlaceActors(TSubclassOf<AActor> ToSpawn, int MinSpawn, int MaxSpawn, float Radius, float MinScale = 1, float MaxScale = 1);

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void EndPlay(const::EEndPlayReason::Type EndPlayReason) override;

	UPROPERTY(EditDefaultsOnly, category = "Navigation")
	FVector NavigationBoundsOffset;

	UPROPERTY(EditDefaultsOnly, category = "Spawning")
	FVector MinExtent;
	UPROPERTY(EditDefaultsOnly, category = "Spawning")
	FVector MaxExtent;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UFUNCTION(BlueprintCallable, Category = "Pool")
	void SetPool(UActorPool* Pool);

private: 
	bool CanSpawnAtLocation(FVector Location, float Radius);
	
	bool FindEmptyLocation(FVector& OutLocation, float Radius);

	void PlaceActor(TSubclassOf<AActor> ToSpawn, FVector SpawnPoint, float Scale);

	void PositionNavMeshBoundsVolume();

	UActorPool* Pool;

	AActor* NavMeshBoundsVolume;

};
