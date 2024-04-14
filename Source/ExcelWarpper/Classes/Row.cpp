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

FRow::Iterator FRow::begin()
{
	return Iterator(*this, 0);
}

FRow::Iterator FRow::end()
{
	return FRow::Iterator(*this, Num());
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
	return ConstIterator(*this, Num());
}