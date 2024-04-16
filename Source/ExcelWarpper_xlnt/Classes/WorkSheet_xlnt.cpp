// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkSheet_xlnt.h"
#include "WorkBook_xlnt.h"
#include "Column_xlnt.h"
#include "Row_xlnt.h"
#include "Cell_xlnt.h"


FWorkSheetWarpper_xlnt::FWorkSheetWarpper_xlnt(TSharedRef<FWorkBookWarpper> InWorkBook, const xlnt::worksheet& InWorkSheet)
	: WorkBook(InWorkBook)
	, WorkSheet(InWorkSheet)
{

}

TSharedPtr<FWorkBookWarpper> FWorkSheetWarpper_xlnt::GetWorkBook() const
{
	return WorkBook;
}

FString FWorkSheetWarpper_xlnt::GetTitle() const
{
	return UTF8_TO_TCHAR(WorkSheet.title().c_str());
}

int32 FWorkSheetWarpper_xlnt::Columns(bool bSkipNull) const
{
	return WorkSheet.columns(bSkipNull).length();
}

int32 FWorkSheetWarpper_xlnt::Rows(bool bSkipNull) const
{
	return WorkSheet.rows(bSkipNull).length();
}

TSharedPtr<FColumnWarpper> FWorkSheetWarpper_xlnt::GetColumn(int32 Index) const
{
	check(Index >= 0);

	return MakeShareable(new FColumnWarpper_xlnt(ConstCastSharedRef<FWorkSheetWarpper>(AsShared()), xlnt::column_t(Index + 1)));
}

TSharedPtr<FRowWarpper> FWorkSheetWarpper_xlnt::GetRow(int32 Index) const
{
	check(Index >= 0);

	return MakeShareable(new FRowWarpper_xlnt(ConstCastSharedRef<FWorkSheetWarpper>(AsShared()), xlnt::row_t(Index + 1)));
}

TSharedPtr<FCellWarpper> FWorkSheetWarpper_xlnt::GetCell(int32 ColumnIndex, int32 RowIndex) const
{
	check(ColumnIndex >= 0 && RowIndex >= 0);

	xlnt::cell_reference CellReference = xlnt::cell_reference(ColumnIndex + 1, RowIndex + 1);
	if (WorkSheet.has_cell(CellReference))
	{
		return MakeShareable(new FCellWarpper_xlnt(ConstCastSharedRef<FWorkSheetWarpper>(AsShared()), WorkSheet.cell(CellReference)));
	}
	
	return nullptr;
}