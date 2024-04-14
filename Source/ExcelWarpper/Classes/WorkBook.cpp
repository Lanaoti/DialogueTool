// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkBook.h"
#include "WorkSheet.h"
#include "ExcelWarpperModule.h"

#include UE_INLINE_GENERATED_CPP_BY_NAME(WorkBook)


/// <summary>
/// FWorkBook
/// </summary>
FWorkBook::FWorkBook()
	: WorkBook(FExcelWarpperModule::MakeWorkBookWarpper())
{

}

FWorkBook::FWorkBook(TSharedPtr<FWorkBookWarpper> InWorkBook)
	: WorkBook(InWorkBook)
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
		return FWorkSheet();
	}

	return WorkBook->GetWorkSheet(Title);
}

FWorkSheet FWorkBook::GetWorkSheet(int32 Index) const
{
	if (!WorkBook.IsValid())
	{
		return FWorkSheet();
	}

	return WorkBook->GetWorkSheet(Index);
}

FWorkSheet FWorkBook::CreateWorkSheet(int32 Index)
{
	if (!WorkBook.IsValid())
	{
		return FWorkSheet();
	}

	return WorkBook->CreateWorkSheet(Index);
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