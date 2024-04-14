// Copyright Epic Games, Inc. All Rights Reserved.

#include "WorkBook_xlnt.h"
#include "WorkSheet_xlnt.h"


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

TSharedPtr<FWorkSheetWarpper> FWorkBookWarpper_xlnt::GetWorkSheet(const FString& Title) const
{
	xlnt::worksheet WorkSheet = WorkBook.sheet_by_title(TCHAR_TO_UTF8(*Title));
	return MakeShareable(new FWorkSheetWarpper_xlnt(ConstCastSharedRef<FWorkBookWarpper>(AsShared()), WorkSheet));
}

TSharedPtr<FWorkSheetWarpper> FWorkBookWarpper_xlnt::GetWorkSheet(int32 Index) const
{
	return MakeShareable(new FWorkSheetWarpper_xlnt(ConstCastSharedRef<FWorkBookWarpper>(AsShared()), WorkBook.sheet_by_index(Index)));
}

TSharedPtr<FWorkSheetWarpper> FWorkBookWarpper_xlnt::CreateWorkSheet(int32 Index)
{
	if (Index == INDEX_NONE)
	{
		return MakeShareable(new FWorkSheetWarpper_xlnt(AsShared(), WorkBook.create_sheet()));
	}
	else
	{
		return MakeShareable(new FWorkSheetWarpper_xlnt(AsShared(), WorkBook.create_sheet(Index)));
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

int32 FWorkBookWarpper_xlnt::IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet) const
{
	const TSharedPtr<FWorkSheetWarpper_xlnt> WorkSheetWarpper = StaticCastSharedPtr<FWorkSheetWarpper_xlnt>(WorkSheet);
	if (WorkSheetWarpper.IsValid())
	{
		return (int32)WorkBook.index(WorkSheetWarpper->WorkSheet);
	}

	return INDEX_NONE;
}

bool FWorkBookWarpper_xlnt::Save()
{
	check(false);
	return false;
}

bool FWorkBookWarpper_xlnt::SaveAs(const FString& Filename)
{
	check(false);
	return false;
}