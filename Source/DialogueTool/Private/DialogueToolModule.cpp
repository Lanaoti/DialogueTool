// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolModule.h"
#include "DialogueToolEditorModeCommands.h"

#include <xlnt/xlnt.hpp>

#define LOCTEXT_NAMESPACE "DialogueToolModule"

void FDialogueToolModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	xlnt::workbook wb;
	wb.load(TCHAR_TO_UTF8(TEXT(""))); // ×¢ÒâÂ·¾¶×ª»»

	FDialogueToolEditorModeCommands::Register();
}

void FDialogueToolModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	FDialogueToolEditorModeCommands::Unregister();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FDialogueToolModule, DialogueToolEditorMode)