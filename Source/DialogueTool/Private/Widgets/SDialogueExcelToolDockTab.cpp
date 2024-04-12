// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueExcelToolDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"


#define LOCTEXT_NAMESPACE "SDialogueExcelToolDockTab"

void SDialogueExcelToolDockTab::Construct(const FArguments& InArgs)
{
	SDockTab::Construct(SDockTab::FArguments()
		.TabRole(ETabRole::NomadTab));

	FText WidgetText = FText::Format(
		LOCTEXT("WindowWidgetText", "Add code in {0} to override this window's contents"),
		FText::FromString(TEXT("SDialogueExcelToolDockTab.cpp")));

	TSharedRef<SWidget> NewContent = SNew(SBox)
		.HAlign(HAlign_Center)
		.VAlign(VAlign_Center)
		[
			SNew(STextBlock)
				.Text(WidgetText)
		];

	SetContent(NewContent);
}

#undef LOCTEXT_NAMESPACE