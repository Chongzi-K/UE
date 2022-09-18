// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class UE_NET : ModuleRules
{
	public UE_NET(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}
