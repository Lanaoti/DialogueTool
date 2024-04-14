// Copyright Epic Games, Inc. All Rights Reserved.

#include "CellIterator.h"
#include "Column.h"
#include "Row.h"
#include "Cell.h"


/// <summary>
/// FCellIterator
/// </summary>
FCellIterator::FCellIterator(FColumn& InColumn, int32 InIndex)
	: Column(&InColumn)
	, Index(InIndex)
{
	
}

FCellIterator::FCellIterator(FRow& InRow, int32 InIndex)
	: Row(&InRow)
	, Index(InIndex)
{
	
}

FCell FCellIterator::operator*()
{
	return Column->GetCell(Index);
}

const FCell FCellIterator::operator*() const
{
	return Column->GetCell(Index);
}

bool FCellIterator::operator==(const FCellIterator& Comparand) const
{
	return (Column == Comparand.Column) && (Index == Comparand.Index);
}

bool FCellIterator::operator!=(const FCellIterator& Comparand) const
{
	return !(*this == Comparand);
}

FCellIterator FCellIterator::operator++(int)
{
	FCellIterator Temp(*Column, Index);
	++(*this);
	return Temp;
}

FCellIterator& FCellIterator::operator++()
{
	++Index;
	return *this;
}

FCellIterator FCellIterator::operator--(int)
{
	FCellIterator Temp(*Column, Index);
	--(*this);
	return Temp;
}

FCellIterator& FCellIterator::operator--()
{
	--Index;
	return *this;
}


/// <summary>
/// FConstCellIterator
/// </summary>
FConstCellIterator::FConstCellIterator(const FColumn& InColumn, int32 InIndex)
	: Column(&InColumn)
	, Index(InIndex)
{

}

FConstCellIterator::FConstCellIterator(const FRow& InRow, int32 InIndex)
	: Row(&InRow)
	, Index(InIndex)
{

}

FCell FConstCellIterator::operator*()
{
	return Column->GetCell(Index);
}

const FCell FConstCellIterator::operator*() const
{
	return Column->GetCell(Index);
}

bool FConstCellIterator::operator==(const FConstCellIterator& Comparand) const
{
	return (Column == Comparand.Column) && (Index == Comparand.Index);
}

bool FConstCellIterator::operator!=(const FConstCellIterator& Comparand) const
{
	return !(*this == Comparand);
}

FConstCellIterator FConstCellIterator::operator++(int)
{
	FConstCellIterator Temp(*Column, Index);
	++(*this);
	return Temp;
}

FConstCellIterator& FConstCellIterator::operator++()
{
	++Index;
	return *this;
}

FConstCellIterator FConstCellIterator::operator--(int)
{
	FConstCellIterator Temp(*Column, Index);
	--(*this);
	return Temp;
}

FConstCellIterator& FConstCellIterator::operator--()
{
	--Index;
	return *this;
}