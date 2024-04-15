#pragma once

#include "CoreMinimal.h"
#include "Uobject/objectMacros.h"
#include "EdGraph/EdGraph.h"
#include "DialogueToolUEdGraphNode.generated.h"

UCLASS()
class UDialogueToolUEdGraphNode : public UEdGraphNode
{
	GENERATED_UCLASS_BODY()

	TArray<FText> DialogueTexts;

	virtual void AllocateDefaultPins() override;

	virtual FText GetNodeTitle(ENodeTitleType::Type TitleType) const override;

	virtual FLinearColor GetNodeTitleColor() const override;
};