// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class SDockTab;
class FToolBarBuilder;
class FMenuBuilder;

class FDialogueToolModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** On clicked open dialogue excel tool */
	void OnClicked_OpenDialogueExcelTool();

	/** On clicked open dialogue editor */
	void OnClicked_OpenDialogueEditor();

private:

	void RegisterMenus();

	void AddMenuExtension(FMenuBuilder& Builder);

	void AddProfilerMenu(FMenuBuilder& Builder);

	TSharedRef<SDockTab> OnSpawnDialogueExcelTool(const FSpawnTabArgs& SpawnTabArgs);
	TSharedRef<SDockTab> OnSpawnDialogueEditor(const FSpawnTabArgs& SpawnTabArgs);

private:
	TSharedPtr<class FUICommandList> PluginCommands;
};
