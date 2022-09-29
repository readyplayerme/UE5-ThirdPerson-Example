// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE5ThirdPersonEx : ModuleRules
{
	public UE5ThirdPersonEx(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });

		PrivateDependencyModuleNames.AddRange(new string[] { "ReadyPlayerMe" });
	}
}
