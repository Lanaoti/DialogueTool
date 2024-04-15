// Copyright Epic Games, Inc. All Rights Reserved.

#include "Row.h"
#include "WorkSheet.h"
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

int32 FRow::GetIndex() const
{
	if (!Row.IsValid())
	{
		return INDEX_NONE;
	}

	return Row->GetIndex();
}

FWorkSheet FRow::GetWorkSheet() const
{
	if (!Row.IsValid())
	{
		return FWorkSheet();
	}

	return Row->GetWorkSheet();
}

FCell FRow::GetCell(int32 Index) const
{
	if (!Row.IsValid())
	{
		return FCell();
	}

	return Row->GetCell(Index);
}

FRow::Iterator FRow::begin()
{
	return Iterator(*this, 0);
}

FRow::Iterator FRow::end()
{
	return FRow::Iterator(*this, GetWorkSheet().Columns());
}

FRow::ConstIterator FRow::begin() const
{
	return cbegin();
}

FRow::ConstIterator FRow::end() const
{
	return cend();
}

FRow::ConstIterator FRow::cbegin() const
{
	return ConstIterator(*this, 0);
}

FRow::ConstIterator FRow::cend() const
{
	return ConstIterator(*this, GetWorkSheet().Columns());
}