// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolEditorMode.h"
#include "DialogueToolEditorModeToolkit.h"
#include "EdModeInteractiveToolsContext.h"
#include "InteractiveToolManager.h"
#include "DialogueToolEditorModeCommands.h"


//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
// AddYourTool Step 1 - include the header file for your Tools here
//////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////// 
#include "Tools/DialogueToolSimpleTool.h"
#include "Tools/DialogueToolInteractiveTool.h"

// step 2: register a ToolBuilder in FDialogueToolEditorMode::Enter() below


#define LOCTEXT_NAMESPACE "DialogueToolEditorMode"

const FEditorModeID UDialogueToolEditorMode::EM_DialogueToolEditorModeId = TEXT("EM_DialogueToolEditorMode");

FString UDialogueToolEditorMode::SimpleToolName = TEXT("DialogueTool_ActorInfoTool");
FString UDialogueToolEditorMode::InteractiveToolName = TEXT("DialogueTool_MeasureDistanceTool");


UDialogueToolEditorMode::UDialogueToolEditorMode()
{
	FModuleManager::Get().LoadModule("EditorStyle");

	// appearance and icon in the editing mode ribbon can be customized here
	Info = FEditorModeInfo(UDialogueToolEditorMode::EM_DialogueToolEditorModeId,
		LOCTEXT("ModeName", "DialogueTool"),
		FSlateIcon(),
		true);
}


UDialogueToolEditorMode::~UDialogueToolEditorMode()
{
}


void UDialogueToolEditorMode::ActorSelectionChangeNotify()
{
}

void UDialogueToolEditorMode::Enter()
{
	UEdMode::Enter();

	//////////////////////////////////////////////////////////////////////////
	//////////////////////////////////////////////////////////////////////////
	// AddYourTool Step 2 - register the ToolBuilders for your Tools here.
	// The string name you pass to the ToolManager is used to select/activate your ToolBuilder later.
	//////////////////////////////////////////////////////////////////////////
	////////////////////////////////////////////////////////////////////////// 
	const FDialogueToolEditorModeCommands& SampleToolCommands = FDialogueToolEditorModeCommands::Get();

	RegisterTool(SampleToolCommands.SimpleTool, SimpleToolName, NewObject<UDialogueToolSimpleToolBuilder>(this));
	RegisterTool(SampleToolCommands.InteractiveTool, InteractiveToolName, NewObject<UDialogueToolInteractiveToolBuilder>(this));

	// active tool type is not relevant here, we just set to default
	GetToolManager()->SelectActiveToolType(EToolSide::Left, SimpleToolName);
}

void UDialogueToolEditorMode::CreateToolkit()
{
	Toolkit = MakeShareable(new FDialogueToolEditorModeToolkit);
}

TMap<FName, TArray<TSharedPtr<FUICommandInfo>>> UDialogueToolEditorMode::GetModeCommands() const
{
	return FDialogueToolEditorModeCommands::Get().GetCommands();
}

#undef LOCTEXT_NAMESPACE
