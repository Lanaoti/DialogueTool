// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Cell.h"
#include <xlnt/xlnt.hpp>


class FCellWarpper_xlnt : public FCellWarpper
{
public:
	FCellWarpper_xlnt() = delete;
	FCellWarpper_xlnt(TSharedRef<FWorkSheetWarpper> InWorkSheet, const xlnt::cell& InCell);
	
	friend class FWorkSheetWarpper_xlnt;

	virtual TSharedRef<FWorkSheetWarpper> GetWorkSheet() const override;
	virtual TSharedRef<FColumnWarpper> GetColumn() const override;
	virtual TSharedRef<FRowWarpper> GetRow() const override;
	virtual FString GetString() const override;

private:
	
	TSharedRef<FWorkSheetWarpper> WorkSheet;

	xlnt::cell Cell;
};