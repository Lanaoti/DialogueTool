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

	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code in {0} to override this window's contents"),
		FText::FromString(TEXT("SDialogueEditorDockTab.cpp")));

	TSharedRef<SWidget> NewContent = SNew(SDialogueToolGraphWindow, FWorkBook());

	SetContent(NewContent);
}

#undef LOCTEXT_NAMESPACE
