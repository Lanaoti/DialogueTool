// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class DialogueTool : ModuleRules
{
	public DialogueTool(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        OptimizeCode = CodeOptimization.InShippingBuildsOnly;

        PublicIncludePaths.AddRange(
			new string[] {

			});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {

			});


        PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core",
                "ExcelHelper"
            });
			
		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
				"CoreUObject",
				"Engine",
				"Slate",
				"SlateCore",
				"InputCore",
                "ToolMenus",
                "Projects",
                "MainFrame",
                "EditorFramework",
				"EditorStyle",
				"UnrealEd",
				"LevelEditor",
				"InteractiveToolsFramework",
				"EditorInteractiveToolsFramework"
			});
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{

			});
	}
}
