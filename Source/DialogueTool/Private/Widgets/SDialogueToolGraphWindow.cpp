#include "SDialogueToolGraphWindow.h"
#include "EdGraph/DialogueToolUEdGraph.h"
#include "EdGraph/DialogueToolUEdGraphSchema.h"

void SDialogueToolGraphWindow::Construct(const FArguments& InArgs)
{
	Graphobj = NewObject<UDialogueToolUEdGraph>();
	Graphobj->Schema = UDialogueToolUEdGraphSchema::StaticClass();
	Graphobj->ReBiuldGraph(InArgs._WorkBook);
	Graphobj->AddToRoot();

	GraphEditorPtr = SNew(SGraphEditor)
		.GraphToEdit(Graphobj);

	ChildSlot
		[
			GraphEditorPtr.ToSharedRef()
		];
}