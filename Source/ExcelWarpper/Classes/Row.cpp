// Copyright Epic Games, Inc. All Rights Reserved.

#include "Row.h"
#include "Cell.h"


FRow::FRow()
	: Row(nullptr)
{

}

FRow::FRow(TSharedPtr<FRowWarpper> InRow)
	: Row(InRow)
{

}

FRow::FRow(TSharedRef<FRowWarpper> InRow)
	: Row(InRow)
{

}

int32 FRow::Num() const
{
	if (!Row.IsValid())
	{
		return 0;
	}

	return Row->Num();
}

FCell FRow::GetCell(int32 Index) const
{
	if (!Row.IsValid())
	{
		return FCell();
	}

	return Row->GetCell(Index);
}