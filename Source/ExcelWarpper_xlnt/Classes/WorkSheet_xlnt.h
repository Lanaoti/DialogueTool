// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "WorkSheet.h"
#include <xlnt/xlnt.hpp>


/// <summary>
/// 基于xlnt库实现
/// </summary>
class FWorkSheetWarpper_xlnt : public FWorkSheetWarpper
{
public:
	FWorkSheetWarpper_xlnt()
	{

	}

	FWorkSheetWarpper_xlnt(const xlnt::worksheet* InWorkSheet)
		: WorkSheet(*InWorkSheet)
	{

	}
	
	friend class FWorkBookWarpper_xlnt;

	virtual FString GetTitle() const override;
	virtual int32 Columns(bool bSkipNull = false) const override;
	virtual int32 Rows(bool bSkipNull = false) const override;

private:
	xlnt::worksheet WorkSheet;
};