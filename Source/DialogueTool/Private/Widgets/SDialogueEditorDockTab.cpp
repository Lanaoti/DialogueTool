// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueEditorDockTab.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Widgets/SDialogueEditorGraphWindow.h"


#define LOCTEXT_NAMESPACE "SDialogueEditorDockTab"

void SDialogueEditorDockTab::Construct(const FArguments& InArgs)
{
	FDialogueList DialogueList = FDialogueList();

	FDialogueFragment DialogueFragment1 = FDialogueFragment();
	DialogueFragment1.Speaker = FString(TEXT("a"));
	DialogueFragment1.Content = FString(TEXT("1111"));

	FDialogueFragment DialogueFragment2 = FDialogueFragment();
	DialogueFragment2.Speaker = FString(TEXT("b"));
	DialogueFragment2.Content = FString(TEXT("22222"));

	FDialogueFragment DialogueFragment3 = FDialogueFragment();
	DialogueFragment3.Speaker = FString(TEXT("c"));
	DialogueFragment3.Content = FString(TEXT("33333"));

	FDialogueFragment DialogueFragment4 = FDialogueFragment();
	DialogueFragment4.Speaker = FString(TEXT("a"));
	DialogueFragment4.Content = FString(TEXT("44444"));

	FDialogueData DialogueData = FDialogueData();
	DialogueData.ID = TEXT("1");
	DialogueData.Fragments.Add(DialogueFragment1);
	DialogueData.Fragments.Add(DialogueFragment2);
	DialogueData.Fragments.Add(DialogueFragment3);
	DialogueData.Fragments.Add(DialogueFragment4);

	FDialogueFragment DialogueFragment5 = FDialogueFragment();
	DialogueFragment5.Speaker = FString(TEXT("a"));
	DialogueFragment5.Content = FString(TEXT("55555555"));

	FDialogueFragment DialogueFragment6 = FDialogueFragment();
	DialogueFragment6.Speaker = FString(TEXT("b"));
	DialogueFragment6.Content = FString(TEXT("66666666"));

	FDialogueData DialogueData2 = FDialogueData();
	DialogueData2.ID = FString(TEXT("2"));
	DialogueData2.Fragments.Add(DialogueFragment5);
	DialogueData2.Fragments.Add(DialogueFragment6);

	DialogueList.List.Add(FString(TEXT("1")), DialogueData);
	DialogueList.List.Add(FString(TEXT("2")), DialogueData2);

	SDockTab::Construct(SDockTab::FArguments()
		.TabRole(ETabRole::NomadTab));

	TSharedRef<SWidget> NewContent = 
		SNew(SDialogueEditorGraphWindow)
		.DialogueList(DialogueList);

	SetContent(NewContent);
}

#undef LOCTEXT_NAMESPACE
