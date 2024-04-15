// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolCommands.h"

#define LOCTEXT_NAMESPACE "FDialogueToolModule"

void FDialogueToolCommands::RegisterCommands()
{
	UI_COMMAND(OpenDialogueExcelTool, "DialogueExcelTool", "Open dialogue excel tool window", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(OpenDialogueEditor, "DialogueEditor", "Open dialogue editor window", EUserInterfaceActionType::Button, FInputChord());
	UI_COMMAND(OpenExcel, "OpenExcel", "Open an excel file", EUserInterfaceActionType::Button, FInputChord(EKeys::O, EModifierKey::Control));
	UI_COMMAND(ReloadExcel, "ReloadExcel", "Reload an excel file", EUserInterfaceActionType::Button, FInputChord(EKeys::R, EModifierKey::Control));
	UI_COMMAND(SaveCurrentExcel, "SaveCurrentExcel", "Save Current Excel", EUserInterfaceActionType::Button, FInputChord(EKeys::S, EModifierKey::Control));
	UI_COMMAND(SaveCurrentExcelAs, "SaveCurrentExcelAs", "Save Current Excel As...", EUserInterfaceActionType::Button, FInputChord(EKeys::S, EModifierKey::Control | EModifierKey::Shift));

}

#undef LOCTEXT_NAMESPACE
