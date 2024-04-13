#include "DialogueToolUEdGraphNode.h"

UDialogueToolUEdGraphNode::UDialogueToolUEdGraphNode(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}

void UDialogueToolUEdGraphNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Input, NAME_None, NAME_None);
	CreatePin(EEdGraphPinDirection::EGPD_Output, NAME_None, NAME_None);
}


FText UDialogueToolUEdGraphNode::GetNodeTitle(ENodeTitleType::Type TitleType) const
{
	return FText::FromString(TEXT("Dialogue"));
}
