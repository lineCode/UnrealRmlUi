// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;
using System.Collections.Generic;

public class RmlUiDevelopEditorTarget : TargetRules
{
	public RmlUiDevelopEditorTarget(TargetInfo Target) : base(Target)
	{
		Type = TargetType.Editor;
		DefaultBuildSettings = BuildSettingsVersion.V2;
		ExtraModuleNames.AddRange( new string []{ "RmlUiDevelop" });
		DefaultWarningLevel = WarningLevel.Off;
	}
}
