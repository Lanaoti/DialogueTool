// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

/**
 * This is the module definition for the editor mode. You can implement custom functionality
 * as your plugin module starts up and shuts down. See IModuleInterface for more extensibility options.
 */
class FExcelWarpperModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

private:
	DECLARE_DELEGATE_RetVal(TSharedPtr<class FWorkBookWarpper>, FExcelWarpper)
	static FExcelWarpper ExcelWarpper;

	static TSharedPtr<class FWorkBookWarpper> MakeWorkBookWarpper();

public:
	friend struct FWorkBook;

	EXCELWARPPER_API static FExcelWarpper& GetExcelWarpper()
	{
		return ExcelWarpper;
	}
};
