// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExcelWarpper_xlntModule.h"
#include "WorkBook_xlnt.h"
#include "ExcelWarpperModule.h"


#define LOCTEXT_NAMESPACE "ExcelWarpper_xlntModule"

void FExcelWarpper_xlntModule::StartupModule()
{
	FExcelWarpperModule::GetExcelWarpper().BindLambda([](void) {
		return MakeShareable(new FWorkBookWarpper_xlnt());
	});
}

void FExcelWarpper_xlntModule::ShutdownModule()
{
	FExcelWarpperModule::GetExcelWarpper().Unbind();
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FExcelWarpper_xlntModule, ExcelWarpper_xlnt)