#include "SDialogueToolGraphWindow.h"
#include "DialogueToolUEdGraph.h"
#include "DialogueToolUEdGraphSchema.h"

void SDialogueToolGraphWindow::Construct(const FArguments& InArgs, const FWorkBook& WorkBook)
{
	Graphobj = NewObject<UDialogueToolUEdGraph>();
	Graphobj->Schema = UDialogueToolUEdGraphSchema::StaticClass();
	Graphobj->ReBiuldGraph(WorkBook);
	Graphobj->AddToRoot();

	GraphEditorPtr = SNew(SGraphEditor)
		.GraphToEdit(Graphobj);

	ChildSlot
		[
			GraphEditorPtr.ToSharedRef()
		];
}