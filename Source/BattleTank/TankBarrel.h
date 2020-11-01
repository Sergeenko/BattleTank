// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/StaticMeshComponent.h"
#include "TankBarrel.generated.h"

/**
 * 
 */
UCLASS(meta = (BlueprintSpawnableComponent))
class BATTLETANK_API UTankBarrel : public UStaticMeshComponent
{
	GENERATED_BODY()
	
public:
	void Elevate(float RelativeSpeed);

private:
	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxDegreesPerSecond = 5; // Default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MaxElevationDegrees = 10; // Default

	UPROPERTY(EditDefaultsOnly, Category = Setup)
	float MinElevationDegrees = 0; // Default
};