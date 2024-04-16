// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

struct FWorkBook;
struct FColumn;

struct FDialogueFragment
{
	FDialogueFragment();
	~FDialogueFragment();

	FString Speaker;

	FString Content;
};

struct FDialogueData
{
	FDialogueData();
	~FDialogueData();

	FString ID;

	TArray<FDialogueFragment> Fragments;
};

struct FDialogueList
{
	FDialogueList();
	~FDialogueList();

	void Prase(const FWorkBook& WorkBook);

	FColumn GetColumn(const FWorkSheet& WorkSheet, const FString& Value);

	TMap<FString, FDialogueData> List;
};