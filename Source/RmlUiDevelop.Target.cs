// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RmlUiDevelopTarget : TargetRules
{
	public RmlUiDevelopTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Game;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string []{ "RmlUiDevelop" });
		DefaultWarningLevel = WarningLevel.Off;
		
	}
}
