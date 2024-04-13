// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExcelHelper.h"
#if EXCELANALYSIS_WITH_XLINT
#include "xlnt/WorkBook_xlnt.h"
#endif

TSharedPtr<FWorkBookWarpper> FExcelHelper::MakeWorkBookWarpper()
{
#if EXCELANALYSIS_WITH_XLINT
	return MakeShareable(new FWorkBookWarpper_xlnt());
#else
	return nullptr;
#endif
}