// Copyright Epic Games, Inc. All Rights Reserved.

#include "Row_xlnt.h"
#include "WorkSheet_xlnt.h"
#include "Cell_xlnt.h"


FRowWarpper_xlnt::FRowWarpper_xlnt(TSharedRef<FWorkSheetWarpper> InWorkSheet, const xlnt::row_t& InRow)
	: WorkSheet(InWorkSheet)
	, Row(InRow)
{

}

int32 FRowWarpper_xlnt::Num() const
{
	return WorkSheet->Rows();
}

TSharedPtr<FCellWarpper> FRowWarpper_xlnt::GetCell(int32 Index) const
{
	return WorkSheet->GetCell(Index, Row);
}