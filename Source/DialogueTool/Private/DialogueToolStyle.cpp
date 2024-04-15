// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueToolStyle.h"
#include "Styling/SlateStyleRegistry.h"
#include "Framework/Application/SlateApplication.h"
#include "Slate/SlateGameResources.h"
#include "Interfaces/IPluginManager.h"
#include "Styling/SlateStyleMacros.h"

#define RootToContentDir Style->RootToContentDir

TSharedPtr<FSlateStyleSet> FDialogueToolStyle::StyleInstance = nullptr;

void FDialogueToolStyle::Initialize()
{
	if (!StyleInstance.IsValid())
	{
		StyleInstance = Create();
		FSlateStyleRegistry::RegisterSlateStyle(*StyleInstance);
	}
}

void FDialogueToolStyle::Shutdown()
{
	FSlateStyleRegistry::UnRegisterSlateStyle(*StyleInstance);
	ensure(StyleInstance.IsUnique());
	StyleInstance.Reset();
}

FName FDialogueToolStyle::GetStyleSetName()
{
	static FName StyleSetName(TEXT("DialogueToolStyle"));
	return StyleSetName;
}

const FVector2D Icon16x16(16.0f, 16.0f);
const FVector2D Icon20x20(20.0f, 20.0f);
const FVector2D Icon128x128(128.0f, 128.0f);

TSharedRef< FSlateStyleSet > FDialogueToolStyle::Create()
{
	TSharedRef< FSlateStyleSet > Style = MakeShareable(new FSlateStyleSet("DialogueToolStyle"));
	Style->SetContentRoot(IPluginManager::Get().FindPlugin("DialogueTool")->GetBaseDir() / TEXT("Resources"));

	Style->Set("DialogueTool.Icon16x16", new IMAGE_BRUSH(TEXT("Icon16"), Icon16x16));
	Style->Set("DialogueTool.Icon20x20", new IMAGE_BRUSH(TEXT("Icon20"), Icon20x20));
	Style->Set("DialogueTool.Icon128x128", new IMAGE_BRUSH(TEXT("Icon128"), Icon128x128));
	Style->Set("DialogueTool.OpenExcel", new IMAGE_BRUSH(TEXT("OpenExcel"), Icon20x20));
	Style->Set("DialogueTool.ReloadExcel", new IMAGE_BRUSH(TEXT("ReloadExcel"), Icon20x20));
	Style->Set("DialogueTool.SaveCurrentExcel", new IMAGE_BRUSH(TEXT("SaveCurrentExcel"), Icon20x20));
	Style->Set("DialogueTool.SaveCurrentExcelAs", new IMAGE_BRUSH(TEXT("SaveCurrentExcelAs"), Icon20x20));

	return Style;
}

void FDialogueToolStyle::ReloadTextures()
{
	if (FSlateApplication::IsInitialized())
	{
		FSlateApplication::Get().GetRenderer()->ReloadTextureResources();
	}
}

const ISlateStyle& FDialogueToolStyle::Get()
{
	return *StyleInstance;
}
