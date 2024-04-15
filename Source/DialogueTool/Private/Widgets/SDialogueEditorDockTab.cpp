// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueEditorDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SDialogueToolGraphWindow.h"


#define LOCTEXT_NAMESPACE "SDialogueEditorDockTab"

void SDialogueEditorDockTab::Construct(const FArguments& InArgs)
{
	SDockTab::Construct(SDockTab::FArguments()
		.TabRole(ETabRole::NomadTab));

	TSharedRef<SWidget> NewContent = 
		SNew(SDialogueToolGraphWindow)
		.WorkBook(FWorkBook());

	SetContent(NewContent);
}

#undef LOCTEXT_NAMESPACE
