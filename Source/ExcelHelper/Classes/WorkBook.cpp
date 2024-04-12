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
#endif


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

FWorkSheet FWorkBook::GetWorkSheet(const FString& Title)
{
	if (!WorkBook.IsValid())
	{
		return FWorkSheet(*this, nullptr);
	}

	return FWorkSheet(*this, WorkBook->GetWorkSheet(Title));
}

FWorkSheet FWorkBook::GetWorkSheet(int32 Index)
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