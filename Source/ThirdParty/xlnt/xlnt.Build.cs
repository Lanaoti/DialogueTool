// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.IO;
using System.Linq;
using System.Reflection;
using UnrealBuildTool;

public class xlnt : ModuleRules
{
    private readonly string LibraryName = "xlnt";
    private readonly string Version = "1.5.0";
    private readonly string LibraryDir;
    private readonly string BuildSystem;
    private readonly string ConfigName;

    public xlnt(ReadOnlyTargetRules Target) : base(Target)
    {
        Type = ModuleType.External;

        bEnableUndefinedIdentifierWarnings = false;

        ShadowVariableWarningLevel = WarningLevel.Off;

        LibraryDir = Path.Combine(String.Format("xlnt-{0}", Version));
        BuildSystem = GetBuildSystem();
        ConfigName = GetConfigName();

        PublicIncludePaths.Add(Path.Combine(ModuleDirectory, LibraryDir, "include"));

        string BuildMethodName = "BuildFor" + Target.Platform;

        MethodInfo BuildMethod = GetType().GetMethod(BuildMethodName, BindingFlags.Instance | BindingFlags.NonPublic);
        if (BuildMethod == null)
            throw new NotSupportedException(BuildMethodName);

        BuildMethod.Invoke(this, Array.Empty<object>());
    }


    #region Build for Platforms
    private void BuildForWin64()
    {
        string DLLPath = Path.Combine(ModuleDirectory, "Win64", ConfigName, String.Format("{0}.dll", LibraryName));
        string LIBPath = Path.ChangeExtension(DLLPath, ".lib");
        string PDBPath = Path.ChangeExtension(DLLPath, ".pdb");
        string DirPath = Path.GetDirectoryName(DLLPath);

        Console.WriteLine(DLLPath);

        bool bIsDebug = (ConfigName == "Debug");
        List<string> DistFiles = new List<string> { DLLPath, LIBPath };
        if (bIsDebug)
        {
            DistFiles.Add(PDBPath);
        }

        if (!DistFiles.All(File.Exists))
        {
            var BuildDir = CMake();
            CopyDirectory(Path.Combine(BuildDir, "source", ConfigName), DirPath);
        }

        PublicDelayLoadDLLs.Add(LibraryName);
        PublicAdditionalLibraries.Add(LIBPath);
        RuntimeDependencies.Add(DLLPath);
        if (bIsDebug)
        {
            RuntimeDependencies.Add(PDBPath);
        }
    }

    private void BuildForLinux()
    {
        // Linux do something
    }

    private void BuildForLinuxAArch64()
    {
        // LinuxAArch64 do something
    }

    private void BuildForMac()
    {
        // Mac do something
    }
    #endregion

    private static void CopyDirectory(string SrcDir, string DistDir)
    {
        Console.WriteLine(String.Format("CopyDirectory SrcDir: {0} DistDir: {1}", SrcDir, DistDir));

        DirectoryInfo Dir = new DirectoryInfo(SrcDir);
        if (!Dir.Exists)
            throw new DirectoryNotFoundException(Dir.FullName);

        DirectoryInfo[] Dirs = Dir.GetDirectories();
        Directory.CreateDirectory(DistDir);

        foreach (FileInfo File in Dir.GetFiles())
        {
            var targetFilePath = Path.Combine(DistDir, File.Name);
            File.CopyTo(targetFilePath, true);
        }

        foreach (var SubDir in Dirs)
        {
            var NewDistDir = Path.Combine(DistDir, SubDir.Name);
            CopyDirectory(SubDir.FullName, NewDistDir);
        }
    }

    private string GetBuildSystem()
    {
        var OSPlatform = Environment.OSVersion.Platform;
        if (OSPlatform == PlatformID.Win32NT)
        {
            if (Target.Platform.IsInGroup(UnrealPlatformGroup.Linux))
                return "Ninja";
            if (Target.Platform.IsInGroup(UnrealPlatformGroup.Android))
                return "Ninja";
            if (Target.Platform.IsInGroup(UnrealPlatformGroup.Windows))
            {
#if UE_5_3_OR_LAST
                if (Target.WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2019)
                    return "Visual Studio 16 2019";
#endif
#if UE_4_27_OR_LATER
                if (Target.WindowsPlatform.Compiler == WindowsCompiler.VisualStudio2022)
                    return "Visual Studio 17 2022";
#endif
            }
        }

        if (OSPlatform == PlatformID.Unix)
        {
            if (Target.Platform.IsInGroup(UnrealPlatformGroup.IOS))
                return "Xcode";
            return "Unix Makefiles";
        }

        return null;
    }

    private string GetConfigName()
    {
        if (Target.Configuration == UnrealTargetConfiguration.Debug
            || Target.Configuration == UnrealTargetConfiguration.DebugGame)
            return "Debug";
        return "Release";
    }

    private string CMake(Dictionary<string, string> ExtraArgs = null)
    {
        if (ExtraArgs == null)
            ExtraArgs = new Dictionary<string, string>();

        Console.WriteLine("generating {0} library with cmake...", LibraryName);

        var OSPlatform = Environment.OSVersion.Platform;
        if (OSPlatform == PlatformID.Win32NT)
        {
            var StartInfo = new ProcessStartInfo
            {
                FileName = "cmd.exe",
                WorkingDirectory = ModuleDirectory,
                RedirectStandardInput = true,
                UseShellExecute = false
            };

            Process BuildProcess = Process.Start(StartInfo);
            using (var Writer = BuildProcess.StandardInput)
            {
                var BuildDir = string.Format("\"{0}/build\"", LibraryDir);
                Writer.WriteLine("rmdir /s /q {0} &mkdir {0} &pushd {0}", BuildDir);
                if (string.IsNullOrEmpty(BuildSystem))
                    Writer.Write("cmake ../ ");
                else
                    Writer.Write("cmake -G \"{0}\" ../ ", BuildSystem);
                var Args = new Dictionary<string, string>
                {
                    { "XLNT_EXPORT", "1" },
                    { "XLNT_SHARED", "1" },
                };
                foreach (var Arg in Args)
                    Writer.Write(" -D{0}=\"{1}\"", Arg.Key, Arg.Value);
                foreach (var Arg in ExtraArgs)
                    Writer.Write(" -D{0}=\"{1}\"", Arg.Key, Arg.Value);
                Writer.WriteLine();
                Writer.WriteLine("popd");
                Writer.WriteLine("cmake --build {0}/build --config {1}", LibraryDir, ConfigName);
            }

            BuildProcess.WaitForExit();

            return Path.Combine(ModuleDirectory, LibraryDir, "build");
        }

        if (OSPlatform == PlatformID.Unix || OSPlatform == PlatformID.MacOSX)
        {
            var StartInfo = new ProcessStartInfo
            {
                FileName = "/bin/bash",
                WorkingDirectory = ModuleDirectory,
                RedirectStandardInput = true,
                UseShellExecute = false
            };

            Process BuildProcess = Process.Start(StartInfo);
            using (var Writer = BuildProcess.StandardInput)
            {
                var BuildDir = string.Format("\"{0}/build\"", LibraryDir);
                Writer.WriteLine("rm -rf {0} &&mkdir {0} &&cd {0}", BuildDir);
                Writer.Write("cmake -G \"{0}\" ../ ", BuildSystem);
                var Args = new Dictionary<string, string>
                {
                    { "XLNT_EXPORT", "1" },
                    { "XLNT_SHARED", "1" },
                };
                foreach (var Arg in Args)
                    Writer.Write(" -D{0}={1}", Arg.Key, Arg.Value);
                foreach (var Arg in ExtraArgs)
                    Writer.Write(" -D{0}={1}", Arg.Key, Arg.Value);
                Writer.WriteLine();
                Writer.WriteLine("cd ../..");
                Writer.WriteLine("cmake --build {0}/build --config {1}", LibraryDir, ConfigName);
            }

            BuildProcess.WaitForExit();

            return Path.Combine(ModuleDirectory, LibraryDir, "build");
        }

        throw new NotSupportedException();
    }
}