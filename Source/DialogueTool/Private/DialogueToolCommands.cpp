// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolCommands.h"

#define LOCTEXT_NAMESPACE "FDialogueToolModule"

void FDialogueToolCommands::RegisterCommands()
{
	UI_COMMAND(OpenDialogueExcelTool, "DialogueExcelTool", "Open dialogue excel tool window", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(OpenDialogueEditor, "DialogueEditor", "Open dialogue editor window", EUserInterfaceActionType::Button, FInputChord());
}

#undef LOCTEXT_NAMESPACE
