// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkBook_xlnt.h"
#include "WorkSheet_xlnt.h"


#if EXCELANALYSIS_WITH_XLINT
/// <summary>
/// FWorkBookWarpper_xlnt
/// </summary>
bool FWorkBookWarpper_xlnt::Load(const FString& Filename, const FString& Password)
{
	if (Password.IsEmpty())
	{
		WorkBook.load(*Filename);
	}
	else
	{
		WorkBook.load(*Filename, TCHAR_TO_UTF8(*Password));
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

	std::vector<std::string> SheetTitles = WorkBook.sheet_titles();
	for (const std::string& Title : SheetTitles)
	{
		FString Temp = UTF8_TO_TCHAR(Title.c_str());
		Results.Add(Temp);
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