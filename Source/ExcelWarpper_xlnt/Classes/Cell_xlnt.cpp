// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cell_xlnt.h"
#include "WorkSheet_xlnt.h"
#include "Column_xlnt.h"
#include "Row_xlnt.h"


FCellWarpper_xlnt::FCellWarpper_xlnt(TSharedRef<FWorkSheetWarpper> InWorkSheet, const xlnt::cell& InCell)
	: WorkSheet(InWorkSheet)
	, Cell(InCell)
{
	
}

TSharedRef<FWorkSheetWarpper> FCellWarpper_xlnt::GetWorkSheet() const
{
	return WorkSheet;	
}

TSharedRef<FColumnWarpper> FCellWarpper_xlnt::GetColumn() const
{
	return MakeShared<FColumnWarpper_xlnt>(WorkSheet, Cell.column());
}

TSharedRef<FRowWarpper> FCellWarpper_xlnt::GetRow() const
{
	return MakeShared<FRowWarpper_xlnt>(WorkSheet, Cell.row());
}

FString FCellWarpper_xlnt::GetString() const
{
	return UTF8_TO_TCHAR(Cell.to_string().c_str());
}