// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkSheet_xlnt.h"


/// <summary>
/// FWorkSheetWarpper_xlnt
/// </summary>
FString FWorkSheetWarpper_xlnt::GetTitle() const
{
	FString Temp = UTF8_TO_TCHAR(WorkSheet.title().c_str());
	return Temp;
}

int32 FWorkSheetWarpper_xlnt::Columns(bool bSkipNull) const
{
	return WorkSheet.columns(bSkipNull).length();
}

int32 FWorkSheetWarpper_xlnt::Rows(bool bSkipNull) const
{
	return WorkSheet.rows(bSkipNull).length();
}