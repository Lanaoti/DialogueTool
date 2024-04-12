// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolEditorModeToolkit.h"
#include "DialogueToolEditorMode.h"
#include "Engine/Selection.h"

#include "Modules/ModuleManager.h"
#include "PropertyEditorModule.h"
#include "IDetailsView.h"
#include "EditorModeManager.h"

#define LOCTEXT_NAMESPACE "DialogueToolEditorModeToolkit"

FDialogueToolEditorModeToolkit::FDialogueToolEditorModeToolkit()
{
}

void FDialogueToolEditorModeToolkit::Init(const TSharedPtr<IToolkitHost>& InitToolkitHost, TWeakObjectPtr<UEdMode> InOwningMode)
{
	FModeToolkit::Init(InitToolkitHost, InOwningMode);
}

void FDialogueToolEditorModeToolkit::GetToolPaletteNames(TArray<FName>& PaletteNames) const
{
	PaletteNames.Add(NAME_Default);
}


FName FDialogueToolEditorModeToolkit::GetToolkitFName() const
{
	return FName("DialogueToolEditorMode");
}

FText FDialogueToolEditorModeToolkit::GetBaseToolkitName() const
{
	return LOCTEXT("DisplayName", "DialogueToolEditorMode Toolkit");
}

#undef LOCTEXT_NAMESPACE
