#include "ModDefinitionBase.h"

UModDefinitionBase::UModDefinitionBase()
	: ModkitVersion(0)
{
}

void UModDefinitionBase::PostInitProperties()
{
	Super::PostInitProperties();
	
#if WITH_EDITOR
	if (!HasAnyFlags(RF_ClassDefaultObject))
	{
		if (const URNAModkitSettings* Settings = GetDefault<URNAModkitSettings>())
		{
			ModkitVersion = Settings->CurrentVersion;
		}
	}
#endif
}