// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolModule.h"
#include "DialogueToolStyle.h"
#include "DialogueToolCommands.h"
#include "LevelEditor.h"
#include "Widgets/Docking/SDockTab.h"
#include "Widgets/SDialogueEditorDockTab.h"
#include "Widgets/SDialogueExcelToolDockTab.h"
#include "ToolMenus.h"

static const FName DialogueExcelToolTabName("DialogueExcelTool");
static const FName DialogueEditorTabName("DialogueEditor");

#define LOCTEXT_NAMESPACE "FDialogueToolModule"

void FDialogueToolModule::StartupModule()
{
	FDialogueToolStyle::Initialize();
	FDialogueToolStyle::ReloadTextures();

	FDialogueToolCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FDialogueToolCommands::Get().OpenDialogueExcelTool,
		FExecuteAction::CreateRaw(this, &FDialogueToolModule::OnClicked_OpenDialogueExcelTool),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FDialogueToolCommands::Get().OpenDialogueEditor,
		FExecuteAction::CreateRaw(this, &FDialogueToolModule::OnClicked_OpenDialogueEditor),
		FCanExecuteAction());

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DialogueExcelToolTabName, FOnSpawnTab::CreateRaw(this, &FDialogueToolModule::OnSpawnDialogueExcelTool))
		.SetDisplayName(LOCTEXT("DialogueExcelTool", "DialogueExcelTool"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DialogueEditorTabName, FOnSpawnTab::CreateRaw(this, &FDialogueToolModule::OnSpawnDialogueEditor))
		.SetDisplayName(LOCTEXT("DialogueEditor", "DialogueEditor"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FDialogueToolModule::RegisterMenus));	
}

void FDialogueToolModule::ShutdownModule()
{
	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FDialogueToolStyle::Shutdown();

	FDialogueToolCommands::Unregister();

	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DialogueExcelToolTabName);
	FGlobalTabmanager::Get()->UnregisterNomadTabSpawner(DialogueEditorTabName);
}

TSharedRef<SDockTab> FDialogueToolModule::OnSpawnDialogueExcelTool(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDialogueExcelToolDockTab);
}

TSharedRef<SDockTab> FDialogueToolModule::OnSpawnDialogueEditor(const FSpawnTabArgs& SpawnTabArgs)
{
	return SNew(SDialogueEditorDockTab);
}

void FDialogueToolModule::OnClicked_OpenDialogueExcelTool()
{
	FGlobalTabmanager::Get()->TryInvokeTab(DialogueExcelToolTabName);
}

void FDialogueToolModule::OnClicked_OpenDialogueEditor()
{
	FGlobalTabmanager::Get()->TryInvokeTab(DialogueEditorTabName);
}

void FDialogueToolModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		FToolMenuEntry ToolMenuEntry = FToolMenuEntry::InitSubMenu(
			TEXT("DialogueTool"),
			LOCTEXT("DialogueTool", "DialogueTool"),
			FText::GetEmpty(),
			FNewToolMenuDelegate::CreateRaw(this, &FDialogueToolModule::MakeDialogueToolMenu),
			false,
			FSlateIcon(FDialogueToolStyle::GetStyleSetName(), TEXT("DialogueTool.Icon20x20"))
		);

		if (UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Tools"))
		{
			FToolMenuSection& Section = Menu->FindOrAddSection(TEXT("Developer"), LOCTEXT("Developer", "Developer"));
			Section.AddEntry(ToolMenuEntry);
		}
	}
}

void FDialogueToolModule::MakeDialogueToolMenu(UToolMenu* InToolMenu)
{
	if (InToolMenu)
	{
		{
			FToolMenuSection& Section = InToolMenu->FindOrAddSection(TEXT("Tool"), LOCTEXT("Tool", "Tool"));
			FToolMenuEntry& Entry = Section.AddMenuEntry(FDialogueToolCommands::Get().OpenDialogueExcelTool);
			Entry.SetCommandList(PluginCommands);
		}

		{
			FToolMenuSection& Section = InToolMenu->FindOrAddSection(TEXT("Editor"), LOCTEXT("Editor", "Editor"));
			FToolMenuEntry& Entry = Section.AddMenuEntry(FDialogueToolCommands::Get().OpenDialogueEditor);
			Entry.SetCommandList(PluginCommands);
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDialogueToolModule, DialogueTool)