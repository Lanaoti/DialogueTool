// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkSheet.h"
#include <xlnt/xlnt.hpp>

#include UE_INLINE_GENERATED_CPP_BY_NAME(WorkSheet)

#if EXCELANALYSIS_WITH_XLINT
/// <summary>
/// FWorkSheetWarpper_xlnt
/// </summary>
FString FWorkSheetWarpper_xlnt::GetTitle() const
{
	return UTF8_TO_TCHAR(WorkSheet.title().c_str());
}
#endif


/// <summary>
/// FWorkSheet
/// </summary>
FString FWorkSheet::GetTitle() const
{
	if (!WorkSheet.IsValid())
	{
		return TEXT("");
	}

	return WorkSheet->GetTitle();
}