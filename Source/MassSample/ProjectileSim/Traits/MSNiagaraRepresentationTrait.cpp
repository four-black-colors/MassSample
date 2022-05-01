﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MSNiagaraRepresentationTrait.h"

#include "MassCommonFragments.h"
#include "MassEntityTemplateRegistry.h"
#include "ProjectileSim/Fragments/MSProjectileFragments.h"
#include "ProjectileSim/MSProjectileSubsystem.h"
#include "NiagaraSystem.h"

void UMSNiagaraRepresentationTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	UMSProjectileSubsystem* ProjectileSubsystem = UWorld::GetSubsystem<UMSProjectileSubsystem>(&World);

	BuildContext.AddFragment<FTransformFragment>();

	const FSharedStruct SharedFragment = ProjectileSubsystem->GetOrCreateSharedNiagaraFragmentForSystemType(SharedNiagaraSystem);

	BuildContext.AddSharedFragment(SharedFragment);
}

void UMSNiagaraRepresentationTrait::ValidateTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	if (!SharedNiagaraSystem)
	{
		UE_VLOG(&World, LogMass, Error, TEXT("Failed to get SharedNiagaraSystem."));
	}
}
