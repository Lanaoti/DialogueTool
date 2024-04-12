// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueExcelToolDockTab.h"
#include "DialogueToolStyle.h"
#include "Widgets/SBoxPanel.h"
#include "Widgets/Layout/SBox.h"
#include "Widgets/Text/STextBlock.h"
#include "Styling/AppStyle.h"


#define LOCTEXT_NAMESPACE "SDialogueExcelToolDockTab"

void SDialogueExcelToolDockTab::Construct(const FArguments& InArgs)
{
	SDockTab::Construct(SDockTab::FArguments()
		.TabRole(ETabRole::NomadTab));

	SetTabIcon(FDialogueToolStyle::Get().GetBrush(TEXT("DialogueTool.Icon128x128")));

	TSharedRef<SDialogueExcelToolDockTab> ThisRef = StaticCastSharedRef<SDialogueExcelToolDockTab>(AsShared());
	TabManager = FGlobalTabmanager::Get()->NewTabManager(ThisRef);

	FMenuBarBuilder MenuBarBuilder = FMenuBarBuilder(TSharedPtr<FUICommandList>());
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

	TSharedRef<SWidget> NewContent = SNew(SBorder)
		.BorderImage(FCoreStyle::Get().GetBrush("ToolPanel.GroupBorder"))
		.BorderBackgroundColor(FLinearColor::Gray)
		[
			SNew(SVerticalBox)

			+ SVerticalBox::Slot()
			.AutoHeight()
			.Padding(FMargin(0.0f, 4.0f, 0.0f, 0.0f))
			[
				MenuWidget
			]
			
			//+ SVerticalBox::Slot()
			//.Padding(FMargin(0.0f, 4.0f, 0.0f, 0.0f))
			//[
			//	TabManager->RestoreFrom(Layout, nullptr).ToSharedRef()
			//]
		];

	SetContent(NewContent);
}

void SDialogueExcelToolDockTab::HandlePullDownFileMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection(TEXT("File"));
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("OpenExcel", "Open Excel..."),
			LOCTEXT("OpenExcel_ToolTip", "Open an excel file"),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"),
			FUIAction(FExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel), FCanExecuteAction()));

		MenuBuilder.AddMenuEntry(
			LOCTEXT("SaveExcel", "Save Current Excel"),
			LOCTEXT("SaveExcel_ToolTip", "Save current excel"),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"),
			FUIAction(FExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel), FCanExecuteAction()));

		MenuBuilder.AddMenuEntry(
			LOCTEXT("SaveExcelAs", "Save Current Excel As..."),
			LOCTEXT("SaveExcelAs_ToolTip", "Save current excel as..."),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"),
			FUIAction(FExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel), FCanExecuteAction()));
	}
	MenuBuilder.EndSection();
}

void SDialogueExcelToolDockTab::HandlePullDownEditMenu(FMenuBuilder& MenuBuilder)
{
	MenuBuilder.BeginSection(TEXT("Edit"));
	{
		MenuBuilder.AddMenuEntry(
			LOCTEXT("OpenExcel", "Open Excel..."),
			LOCTEXT("OpenExcel_ToolTip", "Open an excel file"),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"),
			FUIAction(FExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel), FCanExecuteAction()));

		MenuBuilder.AddMenuEntry(
			LOCTEXT("SaveExcel", "Save Current Excel"),
			LOCTEXT("SaveExcel_ToolTip", "Save current excel"),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"),
			FUIAction(FExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel), FCanExecuteAction()));

		MenuBuilder.AddMenuEntry(
			LOCTEXT("SaveExcelAs", "Save Current Excel As..."),
			LOCTEXT("SaveExcelAs_ToolTip", "Save current excel as..."),
			FSlateIcon(FAppStyle::GetAppStyleSetName(), "LevelEditor.Tabs.Viewports"),
			FUIAction(FExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel), FCanExecuteAction()));
	}
	MenuBuilder.EndSection();
}

void SDialogueExcelToolDockTab::OnClicked_OpenExcel()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_OpenExcel"));
}

#undef LOCTEXT_NAMESPACE
