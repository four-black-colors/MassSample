// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"
#include "Spatial/PointHashGrid3.h"
#include "MSHashGridFragments.generated.h"


// This entity's starting location on our 3D hash-grid this frame.
USTRUCT()
struct MASSSAMPLE_API FMSGridCellStartingLocationFragment : public FMassFragment
{
	GENERATED_BODY()
	FVector Location;
};


// Tag used to indicate the entity is currently added to the hash-grid.
USTRUCT()
struct MASSSAMPLE_API FMSInHashGridTag : public FMassTag
{
	GENERATED_BODY()
};
