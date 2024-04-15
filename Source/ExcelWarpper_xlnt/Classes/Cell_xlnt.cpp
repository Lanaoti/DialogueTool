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
	return UTF8_TO_TCHAR(Cell.value<std::string>().c_str());
}

int32 FCellWarpper_xlnt::GetInt() const
{
	return Cell.value<int32>();
}

int64 FCellWarpper_xlnt::GetInt64() const
{
	return Cell.value<int64>();
}

float FCellWarpper_xlnt::GetFloat() const
{
	return Cell.value<float>();
}

double FCellWarpper_xlnt::GetDouble() const
{
	return Cell.value<double>();
}