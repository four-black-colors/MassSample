﻿// Fill out your copyright notice in the Description page of Project Settings.


#include "MSSubsystem.h"

#include "MassCommonFragments.h"
#include "MassEntitySubsystem.h"
#include "MassMovementFragments.h"
#include "Common/Fragments/MSFragments.h"
#include "Common/MSTags.h"


void UMSSubsystem::Initialize(FSubsystemCollectionBase& Collection)
{
	const UWorld* World = GetWorld();

	// Cache our Mass Entity Subsystem
	EntitySystem = World->GetSubsystem<UMassEntitySubsystem>();

	// To spawn entities from C++ we can make a new archetype like so:
	MoverArchetype = EntitySystem->CreateArchetype(
	{
		FTransformFragment::StaticStruct(),
		FMassVelocityFragment::StaticStruct()
	});

	Context = EntitySystem->CreateExecutionContext(0);
}

int32 UMSSubsystem::SpawnEntity()
{
	// Create and store a handle to our new entity
	const FMassEntityHandle NewEntity = EntitySystem->CreateEntity(MoverArchetype);

	// Afterwards you can add, remove or change fragments of the entity. Let's add a tag fragment!
	EntitySystem->AddTagToEntity(NewEntity, FMoverTag::StaticStruct());
	// Make sure you use AddTag for tags and AddFragment for fragments!
	EntitySystem->AddFragmentToEntity(NewEntity, FSampleColorFragment::StaticStruct());

	// How about changing data on a fragment?
	EntitySystem->GetFragmentDataChecked<FMassVelocityFragment>(NewEntity).Value = FMath::VRand() * 100.0;
	EntitySystem->GetFragmentDataChecked<FSampleColorFragment>(NewEntity).Color = FColor::Blue;

	// Calling mass.PrintEntityFragments 1 in editor should reveal this entity's fragments! For example:

	// Listing fragments values for Entity[i: 1 sn: 1] in /Game/ThirdPerson/Maps/ThirdPersonMap.ThirdPersonMap:MassEntitySubsystem_0
	// TransformFragment: (Transform=(Rotation=(X=0.000000,Y=0.000000,Z=0.000000,W=1.000000),Translation=(X=0.000000,Y=0.000000,Z=0.000000),Scale3D=(X=1.000000,Y=1.000000,Z=1.000000)))
	// MassVelocityFragment: ()
	// SampleColorFragment: ()
	UE_LOG(LogTemp, Warning, TEXT("%i entity created on frame %i"),	NewEntity.Index, GFrameCounter);

	return NewEntity.Index;
}
