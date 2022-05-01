// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectPtr.h"
#include "MassObserverProcessor.h"
#include "MassProcessor.h"
#include "MSSubsystem.h"
#include "MSHashGridProcessor.generated.h"

/**
 * We reimplement a hash-grid because the one built in is too attached to crowd avoidance.
 * If we used the built in one, avoiding enabled crowd members avoid everything on the hash-grid!
 * Feels dirty to have two but oh well. Perhaps it should be 3d?
 */
UCLASS()
class MASSSAMPLE_API UMSHashGridProcessor : public UMassProcessor
{
	GENERATED_BODY()
public:
	UMSHashGridProcessor();

protected:
	FMassEntityQuery AddToHashGridQuery;
	FMassEntityQuery UpdateHashGridQuery;
	FMassEntityQuery RemoveFromGridEntityQuery;

	UPROPERTY(Transient)
	TObjectPtr<UMSSubsystem> MassSampleSystem;

	virtual void Initialize(UObject& Owner) override;
	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;
};

UCLASS()
class MASSSAMPLE_API UMSHashGridMemberInitializationProcessor : public UMassObserverProcessor
{
	GENERATED_BODY()
public:
	UMSHashGridMemberInitializationProcessor();

protected:
	FMassEntityQuery EntityQuery;

	UPROPERTY(Transient)
	TObjectPtr<UMSSubsystem> MassSampleSystem;

	virtual void Initialize(UObject& Owner) override;
	virtual void ConfigureQueries() override;
	virtual void Execute(UMassEntitySubsystem& EntitySubsystem, FMassExecutionContext& Context) override;
};
