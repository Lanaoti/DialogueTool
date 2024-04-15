// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Row.h"
#include <xlnt/xlnt.hpp>


class FWorkSheetWarpper;

class FRowWarpper_xlnt : public FRowWarpper
{
public:
	FRowWarpper_xlnt() = delete;
	FRowWarpper_xlnt(TSharedRef<FWorkSheetWarpper> InWorkSheet, const xlnt::row_t& InRow);
		
	virtual int32 Num() const override;
	virtual int32 GetIndex() const override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet() const override;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 Index) const override;

private:

	TSharedRef<FWorkSheetWarpper> WorkSheet;

	xlnt::row_t Row;
};