// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "DialogueToolStyle.h"

class FDialogueToolCommands : public TCommands<FDialogueToolCommands>
{
public:

	FDialogueToolCommands()
		: TCommands<FDialogueToolCommands>(TEXT("DialogueTool"), NSLOCTEXT("Contexts", "DialogueTool", "DialogueTool Plugin"), NAME_None, FDialogueToolStyle::GetStyleSetName())
	{

	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > OpenDialogueExcelTool;
	TSharedPtr< FUICommandInfo > OpenDialogueEditor;
	TSharedPtr< FUICommandInfo > OpenExcel;
	TSharedPtr< FUICommandInfo > ReloadExcel;
	TSharedPtr< FUICommandInfo > SaveCurrentExcel;
	TSharedPtr< FUICommandInfo > SaveCurrentExcelAs;
};