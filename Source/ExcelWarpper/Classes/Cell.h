// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Cell.generated.h"


class FWorkSheetWarpper;
class FColumnWarpper;
class FRowWarpper;
struct FWorkSheet;
struct FColumn;
struct FRow;

/// <summary>
/// 单元格包装器接口
/// </summary>
class EXCELWARPPER_API FCellWarpper : public TSharedFromThis<FCellWarpper>
{
public:
	FCellWarpper() {}
	virtual ~FCellWarpper() {}

	virtual TSharedRef<FWorkSheetWarpper> GetWorkSheet() const = 0;
	virtual TSharedRef<FColumnWarpper> GetColumn() const = 0;
	virtual TSharedRef<FRowWarpper> GetRow() const = 0;
	virtual FString GetString() const = 0;
	virtual int32 GetInt() const;
	virtual int64 GetInt64() const;
	virtual float GetFloat() const;
	virtual double GetDouble() const;
};

/// <summary>
/// 单元格
/// </summary>
USTRUCT(BlueprintType)
struct FCell
{
	GENERATED_BODY()

public:

	FCell();
	FCell(TSharedPtr<FCellWarpper> InCell);

	/// <summary>
	/// 验证单元格是否有效
	/// </summary>
	/// <returns>是否有效</returns>
	bool IsValid() const;

	/// <summary>
	/// 获取单元格所在工作表
	/// </summary>
	/// <returns>工作表对象</returns>
	FWorkSheet GetWorkSheet() const;

	/// <summary>
	/// 获取单元格所在列
	/// </summary>
	/// <returns>列对象</returns>
	FColumn GetColumn() const;

	/// <summary>
	/// 获取单元格所在行
	/// </summary>
	/// <returns>行对象</returns>
	FRow GetRow() const;

private:
	TSharedPtr<FCellWarpper> Cell;
};