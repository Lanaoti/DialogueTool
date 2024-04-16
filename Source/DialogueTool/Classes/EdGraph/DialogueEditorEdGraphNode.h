// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraph.h"
#include "DialogueEditorEdGraphNode.generated.h"

struct FDialogueFragment;

UCLASS()
class UDialogueEditorEdGraphNode : public UEdGraphNode
{
	GENERATED_UCLASS_BODY()

	TArray<FDialogueFragment> Fragments;

	virtual void AllocateDefaultPins() override;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual FLinearColor GetNodeTitleColor() const override;
};