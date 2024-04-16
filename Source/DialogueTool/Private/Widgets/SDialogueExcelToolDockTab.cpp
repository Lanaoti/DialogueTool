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
		FDialogueToolCommands::Get().ReloadExcel,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_ReloadExcel),
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
		MenuBuilder.AddMenuEntry(FDialogueToolCommands::Get().ReloadExcel);
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
			ExcelFilename = OutFileNames[0];

			if (FilenameTextBlock.IsValid())
			{
				FilenameTextBlock->SetText(FText::FromString(ExcelFilename));
			}

			OpenExcel(ExcelFilename);
		}
	}
}

void SDialogueExcelToolDockTab::OnClicked_ReloadExcel()
{
	OpenExcel(ExcelFilename);
}

void SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel"));
}

void SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs"));
}

void SDialogueExcelToolDockTab::OpenExcel(const FString& Filename)
{
	FWorkBook WorkBook;
	WorkBook.Load(Filename);

	for (const FWorkSheet& WorkSheet : WorkBook)
	{
		UE_LOG(LogTemp, Log, TEXT("WorkSheet Title: %s Columns: %d Rows: %d"), *WorkSheet.GetTitle(), WorkSheet.Columns(), WorkSheet.Rows());

		int32 Rows = WorkSheet.Rows();
		for (int32 Index = 0; Index < Rows; Index++)
		{
			FRow Row = WorkSheet.GetRow(Index);
			for (FCell Cell : Row)
			{
				UE_LOG(LogTemp, Log, TEXT("Cell WorkSheet: %s Column: %d Row: %d Value: %s"), *WorkSheet.GetTitle(), Cell.GetColumn().GetIndex(), Cell.GetRow().GetIndex(), *Cell.GetString());
			}
		}
	}

	for (int32 i = 0; i < 10; i++)
	{
		TArray<FString> Titles = WorkBook.GetTitles();
		for (const FString& Title : Titles)
		{
			UE_LOG(LogTemp, Log, TEXT("WorkSheet Titles: %s"), *Title);
		}
	}

	DialogueList.Prase(WorkBook);

	UpdateDialogueListWidget();
}

void SDialogueExcelToolDockTab::UpdateDialogueListWidget()
{
	if (Content.IsValid())
	{
		Content->ClearChildren();

		TSharedRef<SVerticalBox> VerticalBox = SNew(SVerticalBox);
		Content->AddSlot()
		[
			VerticalBox
		];

		for (TPair<FString, FDialogueData> Pair : DialogueList.List)
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

			for (const FDialogueFragment& Fragment : Pair.Value.Fragments)
			{
				DialogueBox->AddSlot()
					[
						SNew(STextBlock)
							.Text(FText::FromString(Fragment.Speaker + TEXT(":") + Fragment.Content))
					];
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
