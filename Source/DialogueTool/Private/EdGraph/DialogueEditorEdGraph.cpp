// Copyright Epic Games, Inc. All Rights Reserved.

#include "EdGraph/DialogueEditorEdGraph.h"
#include "EdGraph/DialogueEditorEdGraphNode.h"


UDialogueEditorEdGraph::UDialogueEditorEdGraph(const FObjectInitializer& objectInitializer)
	:Super(objectInitializer)
{

}

void UDialogueEditorEdGraph::ReBiuldGraph(const FWorkBook& WorkBook)
{
	auto Node1 = CreateTestNode();
	auto Node2 = CreateTestNode();

	NodeX += 100;
	NodeY += 100;

	Node2->NodePosX = NodeX;
	Node2->NodePosY = NodeY;
}

UDialogueEditorEdGraphNode* UDialogueEditorEdGraph::CreateTestNode()
{
	FGraphNodeCreator<UDialogueEditorEdGraphNode> NodeCreator(*this);
	UDialogueEditorEdGraphNode* NewNode = NodeCreator.CreateNode();
	NewNode->DialogueTexts = {FText::FromString(TEXT("111")), FText::FromString(TEXT("222")), FText::FromString(TEXT("333")) };
	NodeCreator.Finalize();

	return NewNode;
}