// Copyright Epic Games, Inc. All Rights Reserved.

#include "ExcelWarpperModule.h"
#include "WorkBook.h"


#define LOCTEXT_NAMESPACE "ExcelWarpperModule"

FExcelWarpperModule::FExcelWarpper FExcelWarpperModule::ExcelWarpper;

TSharedPtr<FWorkBookWarpper> FExcelWarpperModule::MakeWorkBookWarpper()
{
	if (ExcelWarpper.IsBound())
	{
		return ExcelWarpper.Execute();
	}

	return nullptr;
}

void FExcelWarpperModule::StartupModule()
{

}

void FExcelWarpperModule::ShutdownModule()
{

}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FExcelWarpperModule, ExcelWarpper)