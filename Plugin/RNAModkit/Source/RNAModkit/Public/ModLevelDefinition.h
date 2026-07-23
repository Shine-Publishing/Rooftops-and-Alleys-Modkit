#pragma once

#include "ModItemDefinition.h"
#include "Engine/DataAsset.h"
#include "ModLevelDefinition.generated.h"

UCLASS(BlueprintType)
class RNAMODKIT_API UModLevelDefinition : public UModDefinitionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName LevelName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	TSoftObjectPtr<UWorld> Level;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	UTexture2D* PreviewImage;
};
