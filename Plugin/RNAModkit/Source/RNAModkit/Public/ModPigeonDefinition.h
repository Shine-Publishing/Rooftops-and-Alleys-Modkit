#pragma once

#include "ModDefinitionBase.h"
#include "Engine/DataAsset.h"
#include "ModPigeonDefinition.generated.h"

UCLASS(BlueprintType)
class RNAMODKIT_API UModPigeonDefinition : public UModDefinitionBase
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	FName Name;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UTexture2D *Thumbnail;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	USkeletalMesh* SkeletalMesh;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> ABP_Default;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> ABP_Pickup;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	TSubclassOf<UAnimInstance> ABP_NPC;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* AM_BarrelRoll_R;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly)
	UAnimMontage* AM_BarrelRoll_L;
};
