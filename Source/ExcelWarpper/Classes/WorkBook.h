// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkSheetIterator.h"
#include "WorkBook.generated.h"


struct FWorkBook;
struct FWorkSheet;
class FWorkSheetWarpper;

/// <summary>
/// 工作簿包装器接口
/// </summary>
class EXCELWARPPER_API FWorkBookWarpper : public TSharedFromThis<FWorkBookWarpper>
{
public:
	FWorkBookWarpper() {}
	virtual ~FWorkBookWarpper() {}

	virtual bool Load(const FString& Filename, const FString& Password = TEXT("")) = 0;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(const FString& Title) const = 0;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(int32 Index) const = 0;
	virtual TSharedPtr<FWorkSheetWarpper> CreateWorkSheet(int32 Index = INDEX_NONE) = 0;
	virtual TArray<FString> GetTitles() const = 0;
	virtual int32 Num() const = 0;
	virtual int32 IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet) const = 0;
	virtual bool Save() = 0;
	virtual bool SaveAs(const FString& Filename) = 0;
};


/// <summary>
/// 工作簿
/// </summary>
USTRUCT(BlueprintType)
struct EXCELWARPPER_API FWorkBook
{
	GENERATED_BODY()

public:
	FWorkBook();
	FWorkBook(TSharedPtr<FWorkBookWarpper> InWorkBook);

	/// <summary>
	/// 验证工作簿是否有效
	/// </summary>
	/// <returns>是否有效</returns>
	bool IsValid() const;

	/// <summary>
	/// 加载excel文件
	/// </summary>
	/// <param name="Filename">文件路径</param>
	/// <returns>是否成功</returns>
	bool Load(const FString& Filename, const FString& Password = TEXT(""));

	/// <summary>
	/// 获取工作表
	/// </summary>
	/// <param name="Title">工作表标题</param>
	/// <returns>工作表对象</returns>
	FWorkSheet GetWorkSheet(const FString& Title) const;

	/// <summary>
	/// 获取工作表
	/// </summary>
	/// <param name="Index">工作表下标</param>
	/// <returns>工作表对象</returns>
	FWorkSheet GetWorkSheet(int32 Index) const;

	/// <summary>
	/// 创建工作表
	/// </summary>
	/// <param name="Index">工作表下标</param>
	/// <returns>创建工作表</returns>
	FWorkSheet CreateWorkSheet(int32 Index = INDEX_NONE);

	/// <summary>
	/// 获取所有工作表的标题
	/// </summary>
	/// <returns></returns>
	TArray<FString> GetTitles() const;

	/// <summary>
	/// 获取工作表数量
	/// </summary>
	/// <returns>数量</returns>
	int32 Num() const;

	/// <summary>
	/// 获取工作表下标
	/// </summary>
	/// <param name="WorkSheet">工作表对象</param>
	/// <returns>下标</returns>
	int32 IndexOf(const FWorkSheet& WorkSheet);

public:
	using Iterator = FWorkSheetIterator;
	using ConstIterator = FConstWorkSheetIterator;

	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;
	ConstIterator cbegin() const;
	ConstIterator cend() const;

private:
	TSharedPtr<FWorkBookWarpper> WorkBook;
};