// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "InstancedStruct.h"
#include "MassEntityTraitBase.h"
#include "MSAssortedTags.generated.h"

/**
 * The build in assorted fragments will probably do this too at some point
 */
UCLASS(meta=(DisplayName="Assorted Tags"))
class MASSSAMPLE_API UMSAssortedTags : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere, meta = (BaseStruct = "MassTag", ExcludeBaseStruct))
	TArray<FInstancedStruct> Tags;

	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const override;
};
