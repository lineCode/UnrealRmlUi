// Copyright Epic Games, Inc. All Rights Reserved.

using System;
using System.IO;
using UnrealBuildTool;

public class RmlUi : ModuleRules
{
	public string GetUProjectPath()
	{
		return Directory.GetParent(ModuleDirectory).Parent.ToString();
	}
	
	private void CopyToBinaries(string Filepath, ReadOnlyTargetRules Target)
	{
		string BinariesDirectory = Path.Combine(GetUProjectPath(), "Binaries", /*"ThirdParty", Path.GetFileName(ModuleDirectory),*/ Target.Platform.ToString());
		Console.WriteLine("GetUProjectPath: " + GetUProjectPath());

		string Filename = Path.GetFileName(Filepath);
		if (!Directory.Exists(BinariesDirectory))
			Directory.CreateDirectory(BinariesDirectory);
		if (!File.Exists(Path.Combine(BinariesDirectory, Filename)))
		{
			File.Copy(Filepath, Path.Combine(BinariesDirectory, Filename), true);
		}
	} 
	
	public RmlUi(ReadOnlyTargetRules Target) : base(Target)
	{
        Type = ModuleType.External;
        // Add any macros that need to be set
        PublicDefinitions.Add("WITH_RMLUI=1");
        
        PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "RmlUi-5.0", "Include") } );

        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "RmlUi-5.0", "build", "Release", "RmlCore.lib"));
        PublicAdditionalLibraries.Add(Path.Combine(ModuleDirectory, "RmlUi-5.0", "build", "Release", "RmlDebugger.lib"));

        RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "RmlUi-5.0", "build", "Release", "RmlCore.dll"));
        RuntimeDependencies.Add(Path.Combine(ModuleDirectory, "RmlUi-5.0", "build", "Release", "RmlDebugger.dll"));
        
        CopyToBinaries(Path.Combine(ModuleDirectory, "RmlUi-5.0", "build", "Release", "RmlCore.dll"), Target);
        CopyToBinaries(Path.Combine(ModuleDirectory, "RmlUi-5.0", "build", "Release", "RmlDebugger.dll"), Target);
	}
}
