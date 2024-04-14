// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkBook.h"
#include "WorkSheet.generated.h"

struct FColumn;
struct FRow;
struct FCell;
class FColumnWarpper;
class FRowWarpper;
class FCellWarpper;

/// <summary>
/// 工作表包装器接口
/// </summary>
class EXCELWARPPER_API FWorkSheetWarpper : public TSharedFromThis<FWorkSheetWarpper>
{
public:
	FWorkSheetWarpper() {}
	virtual ~FWorkSheetWarpper() {}

	virtual TSharedPtr<FWorkBookWarpper> GetWorkBook() const = 0;
	virtual FString GetTitle() const = 0;
	virtual int32 Columns(bool bSkipNull = false) const = 0;
	virtual int32 Rows(bool bSkipNull = false) const = 0;
	virtual TSharedPtr<FColumnWarpper> GetColumn(int32 Index) const = 0;
	virtual TSharedPtr<FRowWarpper> GetRow(int32 Index) const = 0;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 ColumnIndex, int32 RowIndex) const = 0;
};


USTRUCT(BlueprintType)
struct EXCELWARPPER_API FWorkSheet
{
	GENERATED_BODY()

public:
	FWorkSheet();
	FWorkSheet(TSharedPtr<FWorkSheetWarpper> InWorkSheet);
	FWorkSheet(TSharedRef<FWorkSheetWarpper> InWorkSheet);

	friend struct FWorkBook;

	/// <summary>
	/// 验证工作表是否有效
	/// </summary>
	/// <returns>是否有效</returns>
	bool IsValid() const;

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

	/// <summary>
	/// 获取行
	/// </summary>
	/// <param name="Index">行下标</param>
	/// <returns>行对象</returns>
	FColumn GetColumn(int32 Index) const;

	/// <summary>
	/// 获取列
	/// </summary>
	/// <param name="Index">列下标</param>
	/// <returns>列对象</returns>
	FRow GetRow(int32 Index) const;

	/// <summary>
	/// 获取单元格
	/// </summary>
	/// <param name="ColumnIndex">列下标</param>
	/// <param name="RowIndex">行下标</param>
	/// <returns>单元格对象</returns>
	FCell GetCell(int32 ColumnIndex, int32 RowIndex) const;

private:	
	TSharedPtr<FWorkSheetWarpper> WorkSheet;
};
