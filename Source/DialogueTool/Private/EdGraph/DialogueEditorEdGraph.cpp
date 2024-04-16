// Copyright Epic Games, Inc. All Rights Reserved.

#include "EdGraph/DialogueEditorEdGraph.h"
#include "EdGraph/DialogueEditorEdGraphNode.h"
#include "DialogueTypes.h"


UDialogueEditorEdGraph::UDialogueEditorEdGraph(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}

void UDialogueEditorEdGraph::ReBiuldGraph(const FDialogueList& DialogueList)
{
	for (TPair<FString, FDialogueData> Pair : DialogueList.List)
	{
		auto NewNode = CreateTestNode(Pair.Value);
		if (NewNode != nullptr)
		{
			NewNode->NodePosX = NodeX;
			NewNode->NodePosY = NodeY;

			NodeX += 100;
			NodeY += 100;
		}
	}
}

UDialogueEditorEdGraphNode* UDialogueEditorEdGraph::CreateTestNode(const FDialogueData& DialogueData)
{
	FGraphNodeCreator<UDialogueEditorEdGraphNode> NodeCreator(*this);
	UDialogueEditorEdGraphNode* NewNode = NodeCreator.CreateNode();

	NewNode->Fragments = TArray<FDialogueFragment>(DialogueData.Fragments);
	NodeCreator.Finalize();

	return NewNode;
}