// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueEditorGraphWindow.h"
#include "EdGraph/DialogueEditorEdGraph.h"
#include "EdGraph/DialogueEditorEdGraphSchema.h"


void SDialogueEditorGraphWindow::Construct(const FArguments& InArgs)
{
	Graphobj = NewObject<UDialogueEditorEdGraph>();
	Graphobj->Schema = UDialogueEditorEdGraphSchema::StaticClass();
	Graphobj->ReBiuldGraph(InArgs._DialogueList);
	Graphobj->AddToRoot();

	GraphEditorPtr = SNew(SGraphEditor)
		.GraphToEdit(Graphobj);

	ChildSlot
		[
			GraphEditorPtr.ToSharedRef()
		];
}