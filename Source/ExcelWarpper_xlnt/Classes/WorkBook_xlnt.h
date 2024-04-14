// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "WorkBook.h"
#include <xlnt/xlnt.hpp>


class FWorkBookWarpper_xlnt : public FWorkBookWarpper
{
public:
	virtual bool Load(const FString& Filename, const FString& Password = TEXT("")) override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(const FString& Title) const override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(int32 Index) const override;
	virtual TSharedPtr<FWorkSheetWarpper> CreateWorkSheet(int32 Index = INDEX_NONE) override;
	virtual TArray<FString> GetTitles() const override;
	virtual int32 Num() const override;
	virtual int32 IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet) const override;
	virtual bool Save() override;
	virtual bool SaveAs(const FString& Filename) override;

private:
	mutable xlnt::workbook WorkBook;
};