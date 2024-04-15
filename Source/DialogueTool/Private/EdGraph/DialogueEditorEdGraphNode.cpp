// Copyright Epic Games, Inc. All Rights Reserved.

#include "EdGraph/DialogueEditorEdGraphNode.h"


UDialogueEditorEdGraphNode::UDialogueEditorEdGraphNode(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}

void UDialogueEditorEdGraphNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Input, NAME_None, NAME_None);
	CreatePin(EEdGraphPinDirection::EGPD_Output, NAME_None, NAME_None);
}


FText UDialogueEditorEdGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("Dialogue"));
}

FLinearColor UDialogueEditorEdGraphNode::GetNodeTitleColor() const
{
	return FLinearColor(128, 0, 128);
}
