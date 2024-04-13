#include "DialogueToolUEdGraph.h"
#include "DialogueToolUEdGraphNode.h"

UDialogueToolUEdGraph::UDialogueToolUEdGraph(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}

void UDialogueToolUEdGraph::ReBiuldGraph()
{
	auto Node1 = CreateTestNode();
	auto Node2 = CreateTestNode();
	Node2->NodePosX = 10.0;
	Node2->NodePosY = 10.0;
}

UDialogueToolUEdGraphNode* UDialogueToolUEdGraph::CreateTestNode()
{
	FGraphNodeCreator<UDialogueToolUEdGraphNode> NodeCreator(*this);
	UDialogueToolUEdGraphNode* NewNode = NodeCreator.CreateNode();
	NodeCreator.Finalize();

	return NewNode;
}