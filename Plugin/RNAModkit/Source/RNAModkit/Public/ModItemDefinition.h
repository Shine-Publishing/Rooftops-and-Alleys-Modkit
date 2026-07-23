#pragma once

#include "ModDefinitionBase.h"
#include "Engine/DataAsset.h"
#include "ModItemDefinition.generated.h"

UCLASS(BlueprintType)
class RNAMODKIT_API UModItemDefinition : public UModDefinitionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName ItemName;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh *Mesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D *Thumbnail;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TArray<UMaterial*> Materials;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Category;
};
