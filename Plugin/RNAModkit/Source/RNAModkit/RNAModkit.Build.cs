// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class RNAModkit : ModuleRules
{
	public RNAModkit(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = ModuleRules.PCHUsageMode.UseExplicitOrSharedPCHs;
		
		PublicIncludePaths.AddRange(new string[] {});
		
		PrivateIncludePaths.AddRange(new string[] {});
		
		PublicDependencyModuleNames.AddRange(new string[] { "Core", "Niagara", "DeveloperSettings" });
		
		PrivateDependencyModuleNames.AddRange(new string[] { "CoreUObject", "Engine", "Slate", "SlateCore", "AssetRegistry"});
		
		DynamicallyLoadedModuleNames.AddRange(new string[] { });
	}
}
