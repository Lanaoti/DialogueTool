// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueExcelToolDockTab.h"
#include "DialogueToolCommands.h"
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

	TapCommands = MakeShareable(new FUICommandList);

	TapCommands->MapAction(
		FDialogueToolCommands::Get().OpenExcel,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_OpenExcel),
		FCanExecuteAction());

	TapCommands->MapAction(
		FDialogueToolCommands::Get().SaveCurrentExcel,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel),
		FCanExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::IsVaildWorkBook));

	TapCommands->MapAction(
		FDialogueToolCommands::Get().SaveCurrentExcelAs,
		FExecuteAction::CreateRaw(this, &SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs),
		FCanExecuteAction::CreateSP(this, &SDialogueExcelToolDockTab::IsVaildWorkBook));

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
	//TSharedPtr<SWindow> ParentWindow;
	//if (FModuleManager::Get().IsModuleLoaded("MainFrame"))
	//{
	//	IMainFrameModule& MainFrame = FModuleManager::LoadModuleChecked<IMainFrameModule>("MainFrame");
	//	ParentWindow = MainFrame.GetParentWindow();
	//}

	//TSharedRef<SWindow> Window =
	//	SNew(SWindow).Title(LOCTEXT("MDLImportOptionsTitle", "MDL Import Options")).SizingRule(ESizingRule::Autosized);

	//TSharedPtr<SMDLOptionsWindow> OptionsWindow;
	//Window->SetContent(
	//	SAssignNew(OptionsWindow, SMDLOptionsWindow)
	//	.ImportOptions(&ImporterOptions)
	//	.WidgetWindow(Window)
	//	.FileNameText(FText::Format(LOCTEXT("MDLImportOptionsFileName", "  Import File  :    {0}"),
	//		FText::FromString(FPaths::GetCleanFilename(Filepath))))
	//	.FilePathText(FText::FromString(Filepath))
	//	.PackagePathText(FText::Format(LOCTEXT("MDLImportOptionsPackagePath", "  Import To   :    {0}"), FText::FromString(PackagePath)))
	//	.MaterialCount(GetMaterialCount(Filepath)));
	//FSlateApplication::Get().AddModalWindow(Window, ParentWindow, false);
	//return OptionsWindow->ShouldImport();

	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_OpenExcel"));
}

void SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcel"));
}

void SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs()
{
	UE_LOG(LogTemp, Log, TEXT("SDialogueExcelToolDockTab::OnClicked_SaveCurrentExcelAs"));
}

bool SDialogueExcelToolDockTab::IsVaildWorkBook() const
{
	return WorkBook.IsValid();
}

#undef LOCTEXT_NAMESPACE
