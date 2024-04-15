// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueExcelToolDockTab.h"
#include "DialogueToolCommands.h"
#include "DialogueToolStyle.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Styling/AppStyle.h"
#include "DesktopPlatformModule.h"

#include "ExcelWarpper.h"


#define LOCTEXT_NAMESPACE "SDialogueExcelToolDockTab"

void SDialogueExcelToolDockTab::Construct(const FArguments& InArgs)
{
	SDockTab::Construct(SDockTab::FArguments()
		.TabRole(ETabRole::NomadTab));

	DialogueList = InArgs._DialogueList;

	SetTabIcon(FDialogueToolStyle::Get().GetBrush(TEXT("DialogueTool.Icon128x128")));

	TapCommands = MakeShareable(new FUICommandList);

	TapCommands->MapAction(
		FDialogueToolCommands::Get().OpenExcel,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel),
		FCanExecuteAction());

	TapCommands->MapAction(
		FDialogueToolCommands::Get().SaveCurrentExcel,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel),
		FCanExecuteAction());

	TapCommands->MapAction(
		FDialogueToolCommands::Get().SaveCurrentExcelAs,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs),
		FCanExecuteAction());

	FilenameTextBlock = SNew(STextBlock);

	TSharedRef<SWidget> TitleBarRightContent = SNew(SOverlay)
		+ SOverlay::Slot()
		.HAlign(HAlign_Right)
		.VAlign(VAlign_Center)
		[
			FilenameTextBlock.ToSharedRef()
		];

	SetTitleBarRightContent(TitleBarRightContent);

	Content = SNew(SOverlay);

	TSharedRef<SWidget> MenuWidget = MakeMenuBar();
	TSharedRef<SWidget> NewContent = SNew(SBorder)
		.BorderImage(FCoreStyle::Get().GetBrush("ToolPanel.GroupBorder"))
		.BorderBackgroundColor(FLinearColor::Black)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(0.0f, 4.0f, 0.0f, 0.0f))
			[
				MenuWidget
			]
			
			+ SVerticalBox::Slot()
			.Padding(FMargin(0.0f, 4.0f, 0.0f, 0.0f))
			[
				SNew(SBorder)
				.BorderImage(FCoreStyle::Get().GetBrush("ToolPanel.GroupBorder"))
				.BorderBackgroundColor(FLinearColor::Gray)
				[
					Content.ToSharedRef()
				]
			]
		];

	SetContent(NewContent);
}

TSharedRef<SWidget> SDialogueExcelToolDockTab::MakeMenuBar()
{
	TSharedRef<SDialogueExcelToolDockTab> ThisRef = StaticCastSharedRef<SDialogueExcelToolDockTab>(AsShared());
	TabManager = FGlobalTabmanager::Get()->NewTabManager(ThisRef);

	FMenuBarBuilder MenuBarBuilder = FMenuBarBuilder(TSharedPtr<FUICommandList>());
	MenuBarBuilder.PushCommandList(TapCommands.ToSharedRef());
	MenuBarBuilder.AddPullDownMenu(
		LOCTEXT("FileLabel", "File"),
		FText::GetEmpty(),
		FNewMenuDelegate::CreateSP(this, &SDialogueExcelToolDockTab::HandlePullDownFileMenu),
		TEXT("File")
	);

	MenuBarBuilder.AddPullDownMenu(
		LOCTEXT("EditLabel", "Edit"),
		FText::GetEmpty(),
		FNewMenuDelegate::CreateSP(this, &SDialogueExcelToolDockTab::HandlePullDownEditMenu),
		TEXT("Edit")
	);

	const TSharedRef<SWidget> MenuWidget = MenuBarBuilder.MakeWidget();
	TabManager->SetMenuMultiBox(MenuBarBuilder.GetMultiBox(), MenuWidget);

	return MenuWidget;
}

TSharedRef<SWidget> SDialogueExcelToolDockTab::MakeWorkBookWidget(const FWorkBook& InWorkBook)
{
	return SNew(SVerticalBox);
}

void SDialogueExcelToolDockTab::HandlePullDownFileMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection(TEXT("File"));
	{
		MenuBuilder.AddMenuEntry(FDialogueToolCommands::Get().OpenExcel);
		MenuBuilder.AddMenuEntry(FDialogueToolCommands::Get().SaveCurrentExcel);
		MenuBuilder.AddMenuEntry(FDialogueToolCommands::Get().SaveCurrentExcelAs);
	}
	MenuBuilder.EndSection();
}

void SDialogueExcelToolDockTab::HandlePullDownEditMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection(TEXT("Edit"));
	{
	}
	MenuBuilder.EndSection();
}

void SDialogueExcelToolDockTab::OnClicked_OpenExcel()
{
	if (IDesktopPlatform* DesktopPlatform = FDesktopPlatformModule::Get())
	{
		TArray<FString> FileTypes;
		FileTypes.Add("Excel Files (*.xls;*.xlsx)|*.xls;*.xlsx");

		TArray<FString> OutFileNames;
		const bool bFileDialogOpened = DesktopPlatform->OpenFileDialog(
			FSlateApplication::Get().FindBestParentWindowHandleForDialogs(nullptr),
			LOCTEXT("ChooseAnExcelFile", "Choose an excel file").ToString(),
			TEXT(""),
			TEXT(""),
			FileTypes[0],
			EFileDialogFlags::None,
			OutFileNames
		);

		if (bFileDialogOpened && OutFileNames.Num() > 0)
		{
			FWorkBook WorkBook;
			WorkBook.Load(OutFileNames[0]);

			if (FilenameTextBlock.IsValid())
			{
				FilenameTextBlock->SetText(FText::FromString(OutFileNames[0]));
			}

			DialogueList.Prase(WorkBook);

			UpdateWorkBookWidget();
		}
	}
}

void SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel"));
}

void SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs"));
}

void SDialogueExcelToolDockTab::UpdateWorkBookWidget()
{
	FDialogueList DialogueListTests;
	
	FDialogueData DialogueData1;
	DialogueData1.ID = TEXT("1");
	DialogueData1.Fragments.Add(TEXT("DialogueData111"));
	DialogueData1.Fragments.Add(TEXT("DialogueData112"));
	DialogueData1.Fragments.Add(TEXT("DialogueData113"));
	DialogueListTests.List.Add(DialogueData1.ID, DialogueData1);

	FDialogueData DialogueData2;
	DialogueData2.ID = TEXT("2");
	DialogueData2.Fragments.Add(TEXT("DialogueData211"));
	DialogueData2.Fragments.Add(TEXT("DialogueData212"));
	DialogueData2.Fragments.Add(TEXT("DialogueData213"));
	DialogueListTests.List.Add(DialogueData2.ID, DialogueData2);

	FDialogueData DialogueData3;
	DialogueData3.ID = TEXT("3");
	DialogueData3.Fragments.Add(TEXT("DialogueData311"));
	DialogueData3.Fragments.Add(TEXT("DialogueData312"));
	DialogueData3.Fragments.Add(TEXT("DialogueData313"));
	DialogueListTests.List.Add(DialogueData3.ID, DialogueData3);

	if (Content.IsValid())
	{
		Content->ClearChildren();

		TSharedRef<SVerticalBox> VerticalBox = SNew(SVerticalBox);
		Content->AddSlot()
		[
			VerticalBox
		];

		for (TPair<FString, FDialogueData> Pair : DialogueListTests.List)
		{
			TSharedRef<SVerticalBox> DialogueBox = SNew(SVerticalBox);
			VerticalBox->AddSlot()
				[
					SNew(SHorizontalBox)
						+ SHorizontalBox::Slot()
						[
							SNew(STextBlock)
								.Text(FText::FromString(Pair.Key))
						]

						+ SHorizontalBox::Slot()
						[
							DialogueBox
						]
				];

			for (const FString& Fragment : Pair.Value.Fragments)
			{
				DialogueBox->AddSlot()
					[
						SNew(STextBlock)
							.Text(FText::FromString(Fragment))
					];
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
