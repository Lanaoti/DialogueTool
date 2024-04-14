// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkSheet.h"
#include "Column.h"
#include "Row.h"
#include "Cell.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(WorkSheet)


FWorkSheet::FWorkSheet()
	: WorkSheet(nullptr)
{

}

FWorkSheet::FWorkSheet(TSharedPtr<FWorkSheetWarpper> InWorkSheet)
	: WorkSheet(InWorkSheet)
{

}

FWorkSheet::FWorkSheet(TSharedRef<FWorkSheetWarpper> InWorkSheet)
	: WorkSheet(InWorkSheet)
{
	
}

bool FWorkSheet::IsValid() const
{
	return WorkSheet.IsValid();
}

FWorkBook FWorkSheet::GetWorkBook() const
{
	if (!WorkSheet.IsValid())
	{
		return FWorkBook();
	}

	return WorkSheet->GetWorkBook();
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

FColumn FWorkSheet::GetColumn(int32 Index) const
{
	if (!WorkSheet.IsValid())
	{
		return FColumn();
	}

	return FColumn(WorkSheet->GetColumn(Index));
}

FRow FWorkSheet::GetRow(int32 Index) const
{
	if (!WorkSheet.IsValid())
	{
		return FRow();
	}

	return WorkSheet->GetRow(Index);
}

FCell FWorkSheet::GetCell(int32 ColumnIndex, int32 RowIndex) const
{
	if (!WorkSheet.IsValid())
	{
		return FCell();
	}

	return WorkSheet->GetCell(ColumnIndex, RowIndex);
}