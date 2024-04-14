// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Column.h"
#include <xlnt/xlnt.hpp>


class FCellWarpper;
class FWorkSheetWarpper;

class FColumnWarpper_xlnt : public FColumnWarpper
{
public:
	FColumnWarpper_xlnt() = delete;
	FColumnWarpper_xlnt(TSharedRef<FWorkSheetWarpper> InWorkSheet, const xlnt::column_t& Column);

	virtual int32 Num() const override;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 Index) const override;

private:

	TSharedRef<FWorkSheetWarpper> WorkSheet;

	xlnt::column_t Column;
};