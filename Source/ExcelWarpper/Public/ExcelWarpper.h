// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkBook.h"
#include "WorkSheet.h"
#include "Row.h"
#include "Column.h"
#include "Cell.h"

class FExcelWarpper
{
public:
	static TSharedPtr<FWorkBookWarpper> MakeWorkBookWarpper();
};
