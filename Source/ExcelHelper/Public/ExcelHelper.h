// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Excel/WorkBook.h"
#include "Excel/WorkSheet.h"
#include "Excel/Row.h"
#include "Excel/Column.h"
#include "Excel/Cell.h"

class FExcelHelper
{
public:
	static TSharedPtr<FWorkBookWarpper> MakeWorkBookWarpper();
};
