// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkBook.h"
#include "WorkSheet.h"
#include <xlnt/xlnt.hpp>

#include UE_INLINE_GENERATED_CPP_BY_NAME(WorkBook)

#if EXCELANALYSIS_WITH_XLINT
/// <summary>
/// FWorkBookWarpper_xlnt
/// </summary>
bool FWorkBookWarpper_xlnt::Load(const FString& Filename, const FString& Password)
{
	if (Password.IsEmpty())
	{
		WorkBook.load(TCHAR_TO_UTF8(*Filename));
	}
	else
	{
		WorkBook.load(TCHAR_TO_UTF8(*Filename), TCHAR_TO_UTF8(*Password));
	}

	return true;
}

TSharedPtr<FWorkSheetWarpper> FWorkBookWarpper_xlnt::GetWorkSheet(const FString& Title)
{
	xlnt::worksheet WorkSheet = WorkBook.sheet_by_title(TCHAR_TO_UTF8(*Title));
	return MakeShareable(new FWorkSheetWarpper_xlnt(&WorkSheet));
}

TSharedPtr<FWorkSheetWarpper> FWorkBookWarpper_xlnt::GetWorkSheet(int32 Index)
{
	xlnt::worksheet WorkSheet = WorkBook.sheet_by_index(Index);
	return MakeShareable(new FWorkSheetWarpper_xlnt(&WorkSheet));
}

TSharedPtr<FWorkSheetWarpper> FWorkBookWarpper_xlnt::CreateWorkSheet(int32 Index)
{
	if (Index == INDEX_NONE)
	{
		xlnt::worksheet WorkSheet = WorkBook.create_sheet();
		return MakeShareable(new FWorkSheetWarpper_xlnt(&WorkSheet));
	}
	else
	{
		xlnt::worksheet WorkSheet = WorkBook.create_sheet(Index);
		return MakeShareable(new FWorkSheetWarpper_xlnt(&WorkSheet));
	}
}

TArray<FString> FWorkBookWarpper_xlnt::GetTitles() const
{
	TArray<FString> Results;

	std::vector<std::string> Titles = WorkBook.sheet_titles();
	for (std::string Title : Titles)
	{
		Results.Add(UTF8_TO_TCHAR(Title.c_str()));
	}

	return Results;
}

int32 FWorkBookWarpper_xlnt::Num() const
{
	return WorkBook.sheet_count();
}

int32 FWorkBookWarpper_xlnt::IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet)
{
	const TSharedPtr<FWorkSheetWarpper_xlnt> WorkSheetWarpper = StaticCastSharedPtr<FWorkSheetWarpper_xlnt>(WorkSheet);
	if (WorkSheetWarpper.IsValid())
	{
		return (int32)WorkBook.index(WorkSheetWarpper->WorkSheet);
	}

	return INDEX_NONE;
}
#endif


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
bool FWorkBook::IsValid() const
{
	return WorkBook.IsValid();
}

bool FWorkBook::Load(const FString& Filename, const FString& Password)
{
	if (FPaths::FileExists(Filename))
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