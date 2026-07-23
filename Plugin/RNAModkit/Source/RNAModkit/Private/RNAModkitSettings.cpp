#include "RNAModkitSettings.h"

URNAModkitSettings::URNAModkitSettings()
	: CurrentVersion(1)
	, MinSupportedVersion(1)
	, MaxSupportedVersion(1) 
{
	CategoryName = TEXT("Plugins");
	SectionName = TEXT("RNAModkit Settings");
}