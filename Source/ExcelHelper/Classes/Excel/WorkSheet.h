// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkBook.h"
#include "WorkSheet.generated.h"


/// <summary>
/// 工作表包装器接口
/// </summary>
class EXCELHELPER_API FWorkSheetWarpper
{
public:
	FWorkSheetWarpper() {}
	virtual ~FWorkSheetWarpper() {}

	virtual FString GetTitle() const { return TEXT(""); }
	virtual int32 Columns(bool bSkipNull = false) const { return 0; }
	virtual int32 Rows(bool bSkipNull = false) const { return 0; }
};


USTRUCT(BlueprintType)
struct EXCELHELPER_API FWorkSheet
{
	GENERATED_BODY()

public:
	FWorkSheet()
		: WorkSheet(nullptr)
	{

	}

	FWorkSheet(const FWorkBook& InWorkBook, TSharedPtr<FWorkSheetWarpper> InWorkSheet)
		: WorkBook(InWorkBook)
		, WorkSheet(InWorkSheet)
	{

	}

	/// <summary>
	/// 获取工作簿
	/// </summary>
	/// <returns>工作簿对象</returns>
	FWorkBook GetWorkBook() const;

	/// <summary>
	/// 获取工作表标题
	/// </summary>
	/// <returns>标题</returns>
	FString GetTitle() const;

	/// <summary>
	/// 工作表列数
	/// </summary>
	/// <param name="bSkipNull">是否跳过空</param>
	/// <returns>数量</returns>
	int32 Columns(bool bSkipNull = false) const;

	/// <summary>
	/// 工作表行数
	/// </summary>
	/// <param name="bSkipNull">是否跳过空</param>
	/// <returns>数量</returns>
	int32 Rows(bool bSkipNull = false) const;

	friend struct FWorkBook;

protected:
	UPROPERTY(BlueprintReadOnly, Category = Excel)
	FWorkBook WorkBook;

private:
	TSharedPtr<FWorkSheetWarpper> WorkSheet;
};
