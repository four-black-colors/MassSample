
#pragma once

#include "MassEntityTypes.h"
#include "Chaos/Real.h"
#include "Spatial/PointHashGrid3.h"
#include "MSTypes.generated.h"

typedef UE::Geometry::TPointHashGrid3<FMassEntityHandle, Chaos::FReal> FMSHashGrid3D;

UENUM(BlueprintType)
enum EReturnSuccess
{
	Success,
	Failure
};

// Entity handle wrapper that enables passing handles around in blueprint.
USTRUCT(BlueprintType)
struct MASSSAMPLE_API FEntityHandleWrapper
{
	GENERATED_BODY()
	FMassEntityHandle Entity;
};

// Simple MassFragment struct wrapper for easy blueprint access
USTRUCT(BlueprintType)
struct MASSSAMPLE_API FFragmentWrapper
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, meta = (BaseStruct = "MassFragment", ExcludeBaseStruct))
	FInstancedStruct Fragment;
};
