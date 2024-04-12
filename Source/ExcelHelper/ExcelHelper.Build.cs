// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExcelHelper : ModuleRules
{
	private enum EExcelAnalysis
	{
		XLINT,
		//...
	}

	private readonly EExcelAnalysis ExcelAnalysis = EExcelAnalysis.XLINT;


    public ExcelHelper(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(
			new string[] {

			});
				
		
		PrivateIncludePaths.AddRange(
			new string[] {

			});
			
		
		PublicDependencyModuleNames.AddRange(
			new string[]
			{
				"Core"
            });

		
		PrivateDependencyModuleNames.AddRange(
			new string[]
			{
                "CoreUObject",
                "Engine"
            });
		
		
		DynamicallyLoadedModuleNames.AddRange(
			new string[]
			{

			});


		if (ExcelAnalysis == EExcelAnalysis.XLINT)
		{
            PublicDependencyModuleNames.AddRange(
                new string[]
                {
                    "xlnt"
                });

            PublicDefinitions.Add("EXCELANALYSIS_WITH_XLINT");
        }

    }
}
