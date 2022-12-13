// Copyright Epic Games, Inc. All Rights Reserved.

using System.IO;
using UnrealBuildTool;

public class RmlUiDevelop : ModuleRules
{
	public RmlUiDevelop(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "RmlUi" });
		
		//PublicIncludePaths.AddRange(new string[] { Path.Combine(ModuleDirectory, "..", "RmlUi", "RmlUi-5.0", "Include") } );

	}
}
