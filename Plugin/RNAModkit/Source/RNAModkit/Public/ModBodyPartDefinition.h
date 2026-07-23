#pragma once

#include "ModDefinitionBase.h"
#include "Engine/DataAsset.h"
#include "NiagaraSystem.h"
#include "ModBodyPartDefinition.generated.h"

UENUM(BlueprintType)
enum class EModBodyParts : uint8
{
	Head UMETA(DisplayName = "Head"),
	UpperBody UMETA(DisplayName = "UpperBody"),
	LowerBody UMETA(DisplayName = "LowerBody"),
	Shoes UMETA(DisplayName = "Shoes"),
	Headphones UMETA(DisplayName = "Headphones"),
	Backpack UMETA(DisplayName = "Backpack"),
	BackpackSecondary UMETA(DisplayName = "BackpackSecondary"),
	ShoesSecondary UMETA(DisplayName = "ShoesSecondary"),
	Trails UMETA(DisplayName = "Trails"),
	PigeonSkin UMETA(DisplayName = "Pigeon Skin"),
	PigeonAccessory UMETA(DisplayName = "Pigeon Accessory"),
};

UCLASS(BlueprintType)
class RNAMODKIT_API UModBodyPartDefinition : public UModDefinitionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D *Thumbnail;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	EModBodyParts BodyPart;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMesh *SkeletalMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UStaticMesh *StaticMesh; //Can be used for either Backpack, Headphones or Pigeon accessory
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	int Feathers;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UNiagaraSystem *Niagara;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UMaterialInstance *PigeonSkin;
};
