#include "SDialogueToolGraphWindow.h"
#include "DialogueToolUEdGraph.h"
#include "DialogueToolUEdGraphSchema.h"

void SDialogueToolGraphWindow::Construct(const FArguments& InArgs)
{
	Graphobj = NewObject<UDialogueToolUEdGraph>();
	Graphobj->Schema = UDialogueToolUEdGraphSchema::StaticClass();
	Graphobj->ReBiuldGraph();
	Graphobj->AddToRoot();

	GraphEditorPtr = SNew(SGraphEditor)
		.GraphToEdit(Graphobj);

	ChildSlot
		[
			GraphEditorPtr.ToSharedRef()
		];
}