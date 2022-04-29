﻿// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "MSDocumentationActor.generated.h"

UCLASS()
class MASSSAMPLE_API AMSDocumentationActor : public AActor
{
	GENERATED_BODY()

public:
	// Sets default values for this actor's properties
	AMSDocumentationActor();

	UFUNCTION(BlueprintCallable)
	static void NavigateToFunctionSource(const FString& SymbolName, const FString& ModuleName = "MassSample");
};
