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
struct EXCELWARPPER_API FCell
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

	/// <summary>
	/// 获取字符串值
	/// </summary>
	/// <returns>FString</returns>
	FString GetString() const;

	/// <summary>
	/// 获取int32值
	/// </summary>
	/// <returns>int32</returns>
	int32 GetInt() const;

	/// <summary>
	/// 获取int64值
	/// </summary>
	/// <returns>int64</returns>
	int64 GetInt64() const;

	/// <summary>
	/// 获取float值
	/// </summary>
	/// <returns>float</returns>
	float GetFloat() const;

	/// <summary>
	/// 获取double值
	/// </summary>
	/// <returns>double</returns>
	double GetDouble() const;

private:
	TSharedPtr<FCellWarpper> Cell;
};