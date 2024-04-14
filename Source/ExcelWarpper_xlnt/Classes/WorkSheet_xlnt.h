// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "WorkSheet.h"
#include <xlnt/xlnt.hpp>


class FWorkBookWarpper_xlnt;

class FWorkSheetWarpper_xlnt : public FWorkSheetWarpper
{
public:
	FWorkSheetWarpper_xlnt() = delete;
	FWorkSheetWarpper_xlnt(TSharedRef<FWorkBookWarpper> InWorkBook, const xlnt::worksheet& InWorkSheet);
	
	friend class FWorkBookWarpper_xlnt;

	virtual TSharedPtr<FWorkBookWarpper> GetWorkBook() const override;
	virtual FString GetTitle() const override;
	virtual int32 Columns(bool bSkipNull = false) const override;
	virtual int32 Rows(bool bSkipNull = false) const override;
	virtual TSharedPtr<FColumnWarpper> GetColumn(int32 Index) const override;
	virtual TSharedPtr<FRowWarpper> GetRow(int32 Index) const override;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 ColumnIndex, int32 RowIndex) const override;

private:
	TSharedRef<FWorkBookWarpper> WorkBook;

	xlnt::worksheet WorkSheet;
};