// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"
#include "MSFragments.generated.h"

/**
 * FMassFragments are simple structs that can hold data.
 * If you want to, it is possible to add functions as well for getter/setters and the like.
 */

// Simple fragment that stores color value
USTRUCT(BlueprintType)
struct MASSSAMPLE_API FSampleColorFragment : public FMassFragment
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FColor Color = FColor::Red;
};


// This entity's starting location on our 3D hash-grid this frame.
USTRUCT(BlueprintType)
struct MASSSAMPLE_API FMSGridCellStartingLocationFragment : public FMassFragment
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere)
	FVector Location;
};
