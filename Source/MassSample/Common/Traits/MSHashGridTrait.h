﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MassEntityTraitBase.h"
#include "MSHashGridTrait.generated.h"

/**
 *  This will subscribe the entity to our simple 3d point hash-grid so we can query for its position.
 */
UCLASS(meta=(DisplayName="3D Hash Grid Member"))
class MASSSAMPLE_API UMSHashGridTrait : public UMassEntityTraitBase
{
	GENERATED_BODY()

public:
	virtual void BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const override;
};
