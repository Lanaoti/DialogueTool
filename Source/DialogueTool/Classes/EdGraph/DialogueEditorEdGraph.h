// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraph.h"
#include "DialogueEditorEdGraph.generated.h"


struct FDialogueList;
struct FDialogueData;

UCLASS()
class UDialogueEditorEdGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:

	void ReBiuldGraph(const FDialogueList& DialogueList);

	class UDialogueEditorEdGraphNode* CreateTestNode(const FDialogueData& DialogueData);

private:

	float NodeX = 0.0f;

	float NodeY = 0.0f;
};