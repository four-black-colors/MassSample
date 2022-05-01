// Fill out your copyright notice in the Description page of Project Settings.


#include "MSDebugTagTrait.h"

#include "MassEntityTemplateRegistry.h"
#include "Common/Fragments/MSFragments.h"
#include "Common/MSTags.h"

void UMSDebugTagTrait::BuildTemplate(FMassEntityTemplateBuildContext& BuildContext, UWorld& World) const
{
	BuildContext.AddTag<FMassSampleDebuggableTag>();
	BuildContext.AddFragment<FSampleColorFragment>();

}
