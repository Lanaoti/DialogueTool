// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkSheet.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(WorkSheet)

/// <summary>
/// FWorkSheet
/// </summary>

FWorkBook FWorkSheet::GetWorkBook() const
{
	return WorkBook;
}

FString FWorkSheet::GetTitle() const
{
	if (!WorkSheet.IsValid())
	{
		return TEXT("");
	}

	return WorkSheet->GetTitle();
}

int32 FWorkSheet::Columns(bool bSkipNull) const
{
	if (!WorkSheet.IsValid())
	{
		return 0;
	}

	return WorkSheet->Columns(bSkipNull);
}

int32 FWorkSheet::Rows(bool bSkipNull) const
{
	if (!WorkSheet.IsValid())
	{
		return 0;
	}

	return WorkSheet->Rows(bSkipNull);
}