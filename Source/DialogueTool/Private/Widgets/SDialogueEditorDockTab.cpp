// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueEditorDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SDialogueEditorGraphWindow.h"


#define LOCTEXT_NAMESPACE "SDialogueEditorDockTab"

void SDialogueEditorDockTab::Construct(const FArguments& InArgs)
{
	SDockTab::Construct(SDockTab::FArguments()
		.TabRole(ETabRole::NomadTab));

	TSharedRef<SWidget> NewContent = 
		SNew(SDialogueEditorGraphWindow)
		.WorkBook(InArgs._WorkBook);

	SetContent(NewContent);
}

#undef LOCTEXT_NAMESPACE
