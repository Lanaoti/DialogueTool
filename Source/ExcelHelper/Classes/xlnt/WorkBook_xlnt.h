// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Excel/WorkBook.h"
#include "Excel/WorkSheet.h"


#if EXCELANALYSIS_WITH_XLINT
#include <xlnt/xlnt.hpp>
/// <summary>
/// 基于xlnt库实现
/// </summary>
class EXCELHELPER_API FWorkBookWarpper_xlnt : public FWorkBookWarpper
{
public:
	/// FWorkBookWarpper
	virtual bool Load(const FString& Filename, const FString& Password = TEXT("")) override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(const FString& Title) override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(int32 Index) override;
	virtual TSharedPtr<FWorkSheetWarpper> CreateWorkSheet(int32 Index = INDEX_NONE) override;
	virtual TArray<FString> GetTitles() const override;
	virtual int32 Num() const override;
	virtual int32 IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet) override;
	/// FWorkBookWarpper

private:
	xlnt::workbook WorkBook;
};
#endif