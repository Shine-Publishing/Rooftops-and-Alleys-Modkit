#pragma once

#include "RNAModkit.h"
#include "RNAModkitSettings.h"
#include "CoreMinimal.h"
#include "Engine/DataAsset.h"
#include "ModDefinitionBase.generated.h"

UCLASS(Abstract, BlueprintType)
class RNAMODKIT_API UModDefinitionBase : public UPrimaryDataAsset
{
	GENERATED_BODY()
public:
	UModDefinitionBase();
	
	virtual void PostInitProperties() override;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	int32 ModkitVersion;
};
