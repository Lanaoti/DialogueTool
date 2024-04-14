// Copyright Epic Games, Inc. All Rights Reserved.

#include "Column_xlnt.h"
#include "WorkSheet_xlnt.h"
#include "Cell_xlnt.h"


FColumnWarpper_xlnt::FColumnWarpper_xlnt(TSharedRef<FWorkSheetWarpper> InWorkSheet, const xlnt::column_t& InColumn)
	: WorkSheet(InWorkSheet)
	, Column(InColumn)
{

}

int32 FColumnWarpper_xlnt::Num() const
{
	return WorkSheet->Columns();
}

TSharedPtr<FCellWarpper> FColumnWarpper_xlnt::GetCell(int32 Index) const
{
	return WorkSheet->GetCell(Column.index, Index);
}