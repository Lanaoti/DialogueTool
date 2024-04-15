// Copyright Epic Games, Inc. All Rights Reserved.

#include "CellIterator.h"
#include "Column.h"
#include "Row.h"
#include "Cell.h"


/// <summary>
/// FCellIterator
/// </summary>
FCellIterator::FCellIterator(FColumn& InColumn, int32 InIndex)
	: Type(IteratorType::IT_Column)
	, Column(&InColumn)
	, Index(InIndex)
{
	
}

FCellIterator::FCellIterator(FRow& InRow, int32 InIndex)
	: Type(IteratorType::IT_Row)
	, Row(&InRow)
	, Index(InIndex)
{
	
}

FCell FCellIterator::operator*()
{
	switch (Type)
	{
	case IteratorType::IT_Column:
		return Column->GetCell(Index);
	case IteratorType::IT_Row:
	default:
		return Row->GetCell(Index);
	}
}

const FCell FCellIterator::operator*() const
{
	switch (Type)
	{
	case IteratorType::IT_Column:
		return Column->GetCell(Index);
	case IteratorType::IT_Row:
	default:
		return Row->GetCell(Index);
	}
}

bool FCellIterator::operator==(const FCellIterator& Comparand) const
{
	switch (Type)
	{
	case IteratorType::IT_Column:
		return (Column == Comparand.Column) && (Index == Comparand.Index);
	case IteratorType::IT_Row:
	default:
		return (Row == Comparand.Row) && (Index == Comparand.Index);
	}	
}

bool FCellIterator::operator!=(const FCellIterator& Comparand) const
{
	return !(*this == Comparand);
}

FCellIterator FCellIterator::operator++(int)
{
	FCellIterator Temp;

	switch (Type)
	{
	case IteratorType::IT_Column:
		Temp = FCellIterator(*Column, Index);
	case IteratorType::IT_Row:
	default:
		Temp = FCellIterator(*Row, Index);
	}

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
	FCellIterator Temp;

	switch (Type)
	{
	case IteratorType::IT_Column:
		Temp = FCellIterator(*Column, Index);
	case IteratorType::IT_Row:
	default:
		Temp = FCellIterator(*Row, Index);
	}

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
	: Type(IteratorType::IT_Column)
	, Column(&InColumn)
	, Index(InIndex)
{

}

FConstCellIterator::FConstCellIterator(const FRow& InRow, int32 InIndex)
	: Type(IteratorType::IT_Row)
	, Row(&InRow)
	, Index(InIndex)
{

}

FCell FConstCellIterator::operator*()
{
	switch (Type)
	{
	case IteratorType::IT_Column:
		return Column->GetCell(Index);
	case IteratorType::IT_Row:
	default:
		return Row->GetCell(Index);
	}
}

const FCell FConstCellIterator::operator*() const
{
	switch (Type)
	{
	case IteratorType::IT_Column:
		return Column->GetCell(Index);
	case IteratorType::IT_Row:
	default:
		return Row->GetCell(Index);
	}
}

bool FConstCellIterator::operator==(const FConstCellIterator& Comparand) const
{
	switch (Type)
	{
	case IteratorType::IT_Column:
		return (Column == Comparand.Column) && (Index == Comparand.Index);
	case IteratorType::IT_Row:
	default:
		return (Row == Comparand.Row) && (Index == Comparand.Index);
	}
}

bool FConstCellIterator::operator!=(const FConstCellIterator& Comparand) const
{
	return !(*this == Comparand);
}

FConstCellIterator FConstCellIterator::operator++(int)
{
	FConstCellIterator Temp;

	switch (Type)
	{
	case IteratorType::IT_Column:
		Temp = FConstCellIterator(*Column, Index);
	case IteratorType::IT_Row:
	default:
		Temp = FConstCellIterator(*Row, Index);
	}

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
	FConstCellIterator Temp;

	switch (Type)
	{
	case IteratorType::IT_Column:
		Temp = FConstCellIterator(*Column, Index);
	case IteratorType::IT_Row:
	default:
		Temp = FConstCellIterator(*Row, Index);
	}

	--(*this);
	return Temp;
}

FConstCellIterator& FConstCellIterator::operator--()
{
	--Index;
	return *this;
}