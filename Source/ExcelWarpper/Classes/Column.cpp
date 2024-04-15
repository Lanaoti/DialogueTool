// Copyright Epic Games, Inc. All Rights Reserved.

#include "Column.h"
#include "WorkSheet.h"
#include "Cell.h"


FColumn::FColumn()
	: Column(nullptr)
{

}

FColumn::FColumn(TSharedPtr<FColumnWarpper> InColumn)
	: Column(InColumn)
{

}

FColumn::FColumn(TSharedRef<FColumnWarpper> InColumn)
	: Column(InColumn)
{

}

bool FColumn::IsValid() const
{
	return Column.IsValid();
}

int32 FColumn::Num() const
{
	if (!Column.IsValid())
	{
		return 0;
	}

	return Column->Num();
}

int32 FColumn::GetIndex() const
{
	if (!Column.IsValid())
	{
		return INDEX_NONE;
	}

	return Column->GetIndex();
}

FWorkSheet FColumn::GetWorkSheet() const
{
	if (!Column.IsValid())
	{
		return FWorkSheet();
	}

	return Column->GetWorkSheet();
}

FCell FColumn::GetCell(int32 Index) const
{
	if (!Column.IsValid())
	{
		return FCell();
	}

	return Column->GetCell(Index);
}

FColumn::Iterator FColumn::begin()
{
	return Iterator(*this, 0);
}

FColumn::Iterator FColumn::end()
{
	return FColumn::Iterator(*this, GetWorkSheet().Rows());
}

FColumn::ConstIterator FColumn::begin() const
{
	return cbegin();
}

FColumn::ConstIterator FColumn::end() const
{
	return cend();
}

FColumn::ConstIterator FColumn::cbegin() const
{
	return ConstIterator(*this, 0);
}

FColumn::ConstIterator FColumn::cend() const
{
	return ConstIterator(*this, GetWorkSheet().Rows());
}