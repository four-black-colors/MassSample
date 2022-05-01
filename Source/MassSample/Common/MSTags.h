// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTypes.h"
#include "MSTags.generated.h"

/**
* FMassTags are structs that exist only as tags on Mass entities. They cannot have data!
* Mostly used for filtering. They can be queried for to only include certain entities etc.
*/

// Tag that marks object as 'mover'
USTRUCT()
struct MASSSAMPLE_API FMoverTag : public FMassTag
{
	GENERATED_BODY()
};

// Tag used for debugging purposes
USTRUCT()
struct MASSSAMPLE_API FMassSampleDebuggableTag : public FMassTag
{
	GENERATED_BODY()
};

// Tag used to indicate the entity is currently added to the hash-grid.
USTRUCT()
struct MASSSAMPLE_API FMSInHashGridTag : public FMassTag
{
	GENERATED_BODY()
};


USTRUCT()
struct FBasicVisualizationTag : public FMassTag
{
	GENERATED_BODY()
};
