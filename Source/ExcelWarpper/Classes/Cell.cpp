// Copyright Epic Games, Inc. All Rights Reserved.

#include "Cell.h"
#include "WorkSheet.h"
#include "Column.h"
#include "Row.h"


int32 FCellWarpper::GetInt() const
{
	return FCString::Atoi(*GetString());
}

int64 FCellWarpper::GetInt64() const
{
	return FCString::Atoi64(*GetString());
}

float FCellWarpper::GetFloat() const
{
	return FCString::Atof(*GetString());
}

double FCellWarpper::GetDouble() const
{
	return FCString::Atod(*GetString());
}

FCell::FCell()
	: Cell(nullptr)
{

}

FCell::FCell(TSharedPtr<FCellWarpper> InCell)
	: Cell(InCell)
{

}

bool FCell::IsValid() const
{
	return Cell.IsValid();
}

FWorkSheet FCell::GetWorkSheet() const
{
	if (!Cell.IsValid())
	{
		return FWorkSheet();
	}

	return Cell->GetWorkSheet();
}

FColumn FCell::GetColumn() const
{
	if (!Cell.IsValid())
	{
		return FColumn();
	}

	return Cell->GetColumn();
}

FRow FCell::GetRow() const
{
	if (!Cell.IsValid())
	{
		return FRow();
	}

	return Cell->GetRow();
}