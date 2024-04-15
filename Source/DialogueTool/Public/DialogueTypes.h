// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

struct FWorkBook;

struct FDialogueData
{
	FDialogueData();
	~FDialogueData();

	FString ID;

	TArray<FString> Fragments;
};

struct FDialogueList
{
	FDialogueList();
	~FDialogueList();

	void Prase(const FWorkBook& WorkBook);

	TMap<FString, FDialogueData> List;
};