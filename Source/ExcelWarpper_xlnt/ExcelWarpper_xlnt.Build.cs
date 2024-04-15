// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ExcelWarpper_xlnt : ModuleRules
{
    public ExcelWarpper_xlnt(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;

        CppStandard = CppStandardVersion.Cpp17;

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
                "ExcelWarpper",
                "xlnt"
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
    }
}
