﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MSMoverMassTrait.generated.h"

/**
 * This trait uses 2 fragments. One to set the location of the entity, and another one to feed a constant force to add.
 */
UCLASS(meta = (DisplayName = "Sample Mover Trait"))
class MASSSAMPLE_API UMSMoverMassTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const override;

protected:
	UPROPERTY(EditAnywhere, Category = "Mass")
	FVector Force = {0,0,100.0f};
};
