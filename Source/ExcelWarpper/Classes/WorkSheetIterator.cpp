// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkSheetIterator.h"
#include "WorkBook.h"
#include "WorkSheet.h"


/// <summary>
/// FWorkSheetIterator
/// </summary>
FWorkSheetIterator::FWorkSheetIterator(FWorkBook& InWorkBook, int32 InIndex)
	: WorkBook(&InWorkBook)
	, Index(InIndex)
{

}

FWorkSheet FWorkSheetIterator::operator*()
{
	return WorkBook->GetWorkSheet(Index);
}

const FWorkSheet FWorkSheetIterator::operator*() const
{
	return WorkBook->GetWorkSheet(Index);
}

bool FWorkSheetIterator::operator==(const FWorkSheetIterator& Comparand) const
{
	return (WorkBook == Comparand.WorkBook) && (Index == Comparand.Index);
}

bool FWorkSheetIterator::operator!=(const FWorkSheetIterator& Comparand) const
{
	return !(*this == Comparand);
}

FWorkSheetIterator FWorkSheetIterator::operator++(int)
{
	FWorkSheetIterator Temp(*WorkBook, Index);
	++(*this);
	return Temp;
}

FWorkSheetIterator& FWorkSheetIterator::operator++()
{
	++Index;
	return *this;
}

FWorkSheetIterator FWorkSheetIterator::operator--(int)
{
	FWorkSheetIterator Temp(*WorkBook, Index);
	--(*this);
	return Temp;
}

FWorkSheetIterator& FWorkSheetIterator::operator--()
{
	--Index;
	return *this;
}


/// <summary>
/// FConstWorkSheetIterator
/// </summary>
FConstWorkSheetIterator::FConstWorkSheetIterator(const FWorkBook& InWorkBook, int32 InIndex)
	: WorkBook(&InWorkBook)
	, Index(InIndex)
{

}

FWorkSheet FConstWorkSheetIterator::operator*()
{
	return WorkBook->GetWorkSheet(Index);
}

const FWorkSheet FConstWorkSheetIterator::operator*() const
{
	return WorkBook->GetWorkSheet(Index);
}

bool FConstWorkSheetIterator::operator==(const FConstWorkSheetIterator& Comparand) const
{
	return (WorkBook == Comparand.WorkBook) && (Index == Comparand.Index);
}

bool FConstWorkSheetIterator::operator!=(const FConstWorkSheetIterator& Comparand) const
{
	return !(*this == Comparand);
}

FConstWorkSheetIterator FConstWorkSheetIterator::operator++(int)
{
	FConstWorkSheetIterator Temp(*WorkBook, Index);
	++(*this);
	return Temp;
}

FConstWorkSheetIterator& FConstWorkSheetIterator::operator++()
{
	++Index;
	return *this;
}

FConstWorkSheetIterator FConstWorkSheetIterator::operator--(int)
{
	FConstWorkSheetIterator Temp(*WorkBook, Index);
	--(*this);
	return Temp;
}

FConstWorkSheetIterator& FConstWorkSheetIterator::operator--()
{
	--Index;
	return *this;
}