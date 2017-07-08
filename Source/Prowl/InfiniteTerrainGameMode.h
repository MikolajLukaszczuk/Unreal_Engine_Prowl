// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ProwlGameMode.h"
#include "InfiniteTerrainGameMode.generated.h"

/**
 * 
 */
UCLASS()
class PROWL_API AInfiniteTerrainGameMode : public AProwlGameMode
{
	GENERATED_BODY()
	
public:
	AInfiniteTerrainGameMode();

	UFUNCTION(BlueprintCallable, Category = "Bounds Pool")
	void PopulateBoundsVolumePool();

protected:
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "Pool")
	class UActorPool* NavMeshBoundsVolumePool;

private:
	void AddToPool(ANavMeshBoundsVolume *VolumeToAdd);
};
