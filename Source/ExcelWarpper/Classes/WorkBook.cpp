// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkBook.h"
#include "WorkSheet.h"
#include "ExcelWarpperModule.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(WorkBook)


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


/// <summary>
/// FWorkBook
/// </summary>
FWorkBook::FWorkBook()
	: WorkBook(FExcelWarpperModule::MakeWorkBookWarpper())
{

}

bool FWorkBook::IsValid() const
{
	return WorkBook.IsValid();
}

bool FWorkBook::Load(const FString& Filename, const FString& Password)
{
	if (!FPaths::FileExists(Filename))
	{
		return false;
	}

	if (!WorkBook.IsValid())
	{
		return false;
	}

	return WorkBook->Load(Filename, Password);
}

FWorkSheet FWorkBook::GetWorkSheet(const FString& Title) const
{
	if (!WorkBook.IsValid())
	{
		return FWorkSheet(*this, nullptr);
	}

	return FWorkSheet(*this, WorkBook->GetWorkSheet(Title));
}

FWorkSheet FWorkBook::GetWorkSheet(int32 Index) const
{
	if (!WorkBook.IsValid())
	{
		return FWorkSheet(*this, nullptr);
	}

	return FWorkSheet(*this, WorkBook->GetWorkSheet(Index));
}

FWorkSheet FWorkBook::CreateWorkSheet(int32 Index)
{
	if (!WorkBook.IsValid())
	{
		return FWorkSheet(*this, nullptr);
	}

	return FWorkSheet(*this, WorkBook->CreateWorkSheet(Index));
}

TArray<FString> FWorkBook::GetTitles() const
{
	if (!WorkBook.IsValid())
	{
		return TArray<FString>();
	}

	return WorkBook->GetTitles();
}

int32 FWorkBook::Num() const
{
	if (!WorkBook.IsValid())
	{
		return 0;
	}

	return WorkBook->Num();
}

int32 FWorkBook::IndexOf(const FWorkSheet& WorkSheet)
{
	if (!WorkBook.IsValid())
	{
		return INDEX_NONE;
	}

	return WorkBook->IndexOf(WorkSheet.WorkSheet);
}

FWorkBook::Iterator FWorkBook::begin()
{
	return Iterator(*this, 0);
}

FWorkBook::Iterator FWorkBook::end()
{
	return FWorkBook::Iterator(*this, Num());
}

FWorkBook::ConstIterator FWorkBook::begin() const
{
	return cbegin();
}

FWorkBook::ConstIterator FWorkBook::end() const
{
	return cend();
}

FWorkBook::ConstIterator FWorkBook::cbegin() const
{
	return ConstIterator(*this, 0);
}

FWorkBook::ConstIterator FWorkBook::cend() const
{
	return ConstIterator(*this, Num());
}