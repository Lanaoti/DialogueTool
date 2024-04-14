// Copyright Epic Games, Inc. All Rights Reserved.

#include "Column.h"
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

int32 FColumn::Num() const
{
	if (!Column.IsValid())
	{
		return 0;
	}

	return Column->Num();
}

FCell FColumn::GetCell(int32 Index) const
{
	if (!Column.IsValid())
	{
		return FCell();
	}

	return Column->GetCell(Index);
}