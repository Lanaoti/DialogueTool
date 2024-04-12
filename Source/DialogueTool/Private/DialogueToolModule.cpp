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

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FDialogueToolModule::RegisterMenus));
	
	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DialogueExcelToolTabName, FOnSpawnTab::CreateRaw(this, &FDialogueToolModule::OnSpawnDialogueExcelTool))
		.SetDisplayName(LOCTEXT("FDialogueToolTabTitle", "DialogueExcelTool"))
		.SetMenuType(ETabSpawnerMenuType::Enabled);

	FGlobalTabmanager::Get()->RegisterNomadTabSpawner(DialogueEditorTabName, FOnSpawnTab::CreateRaw(this, &FDialogueToolModule::OnSpawnDialogueEditor))
		.SetDisplayName(LOCTEXT("FDialogueToolTabTitle", "DialogueEditor"))
		.SetMenuType(ETabSpawnerMenuType::Hidden);
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

	FLevelEditorModule& LevelEditorModule = FModuleManager::LoadModuleChecked<FLevelEditorModule>("LevelEditor");
	{
		TSharedPtr<FExtender> MenuExtender = MakeShareable(new FExtender());
		MenuExtender->AddMenuExtension("WindowLayout", EExtensionHook::After, PluginCommands, FMenuExtensionDelegate::CreateRaw(this, &FDialogueToolModule::AddMenuExtension));

		LevelEditorModule.GetMenuExtensibilityManager()->AddExtender(MenuExtender);

		//UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		//{
		//	FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
		//	Section.AddEntryObject(MenuExtender);
		//	Section.AddMenuEntry(MenuExtender)
		//}

		//UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		//{
		//	FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
		//	{
		//		FToolMenuEntry& Entry = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FDialogueToolCommands::Get().OpenPluginWindow));
		//		Entry.SetCommandList(PluginCommands);
		//	}
		//}
	}
}

void FDialogueToolModule::AddMenuExtension(FMenuBuilder& Builder)
{
	Builder.BeginSection("DialogueTool", TAttribute<FText>(FText::FromString("DialogueTool")));
	{
		Builder.AddSubMenu(FText::FromString("DialogueTool"),
			FText::FromString("DONT WORRY BE HAPPY"),
			FNewMenuDelegate::CreateRaw(this, &FDialogueToolModule::AddProfilerMenu));
	}
	Builder.EndSection();
}

void FDialogueToolModule::AddProfilerMenu(FMenuBuilder& Builder)
{
	Builder.BeginSection("DialogueTool", TAttribute<FText>(FText::FromString("DialogueTool")));
	{
		Builder.AddMenuEntry(FDialogueToolCommands::Get().OpenDialogueExcelTool);
		Builder.AddMenuEntry(FDialogueToolCommands::Get().OpenDialogueEditor);
	}
	Builder.EndSection();
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FDialogueToolModule, DialogueTool)