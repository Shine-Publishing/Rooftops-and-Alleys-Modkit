#pragma once

#include "CoreMinimal.h"
#include "Engine/DeveloperSettings.h"
#include "RNAModkitSettings.generated.h"

UCLASS(Config=Game, defaultconfig, meta=(DisplayName="Modkit Settings"))
class RNAMODKIT_API URNAModkitSettings : public UDeveloperSettings
{
	GENERATED_BODY()
public:
	URNAModkitSettings();
	
	UPROPERTY(Config, EditAnywhere, Category = "Version Control", meta = (ClampMin = "1"))
	int32 CurrentVersion;

	UPROPERTY(Config, EditAnywhere, Category = "Version Control", meta = (ClampMin = "1"))
	int32 MinSupportedVersion;
	
	UPROPERTY(Config, EditAnywhere, Category = "Version Control", meta = (ClampMin = "1"))
	int32 MaxSupportedVersion;
};
