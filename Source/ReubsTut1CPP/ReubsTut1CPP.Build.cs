// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class ReubsTut1CPP : ModuleRules
{
    public ReubsTut1CPP(ReadOnlyTargetRules Target) : base(Target)
    {
        PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });

        PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags" });
    }
}
