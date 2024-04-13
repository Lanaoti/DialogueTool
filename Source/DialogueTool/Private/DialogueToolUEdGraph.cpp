#include "DialogueToolUEdGraph.h"
#include "DialogueToolUEdGraphNode.h"

UDialogueToolUEdGraph::UDialogueToolUEdGraph(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}

void UDialogueToolUEdGraph::ReBiuldGraph(const FWorkBook& WorkBook)
{
	auto Node1 = CreateTestNode();
	auto Node2 = CreateTestNode();

	NodeX += 100;
	NodeY += 100;

	Node2->NodePosX = NodeX;
	Node2->NodePosY = NodeY;
}

UDialogueToolUEdGraphNode* UDialogueToolUEdGraph::CreateTestNode()
{
	FGraphNodeCreator<UDialogueToolUEdGraphNode> NodeCreator(*this);
	UDialogueToolUEdGraphNode* NewNode = NodeCreator.CreateNode();
	NewNode->DialogueTexts = {FText::FromString(TEXT("111")), FText::FromString(TEXT("222")), FText::FromString(TEXT("333")) };
	NodeCreator.Finalize();

	return NewNode;
}