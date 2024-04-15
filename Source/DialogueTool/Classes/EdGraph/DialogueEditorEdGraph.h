// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraph.h"
#include "ExcelWarpper.h"
#include "DialogueEditorEdGraph.generated.h"


UCLASS()
class UDialogueEditorEdGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:

	void ReBiuldGraph(const FWorkBook& WorkBook);

	class UDialogueEditorEdGraphNode* CreateTestNode();

private:

	float NodeX = 0.0f;

	float NodeY = 0.0f;
};