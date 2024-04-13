// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#if EXCELANALYSIS_WITH_XLINT
#include <xlnt/xlnt.hpp>
#endif

#include "WorkBook.generated.h"


struct FWorkBook;
struct FWorkSheet;
class FWorkSheetWarpper;

/// <summary>
/// 工作簿包装器接口
/// </summary>
class EXCELHELPER_API FWorkBookWarpper
{
public:
	FWorkBookWarpper() {}
	virtual ~FWorkBookWarpper() {}

	virtual bool Load(const FString& Filename, const FString& Password = TEXT("")) { return false; }
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(const FString& Title) { return nullptr; }
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(int32 Index) { return nullptr; }
	virtual TSharedPtr<FWorkSheetWarpper> CreateWorkSheet(int32 Index = INDEX_NONE) { return nullptr; }
	virtual TArray<FString> GetTitles() const { return TArray<FString>(); }
	virtual int32 Num() const { return 0; }
	virtual int32 IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet) { return INDEX_NONE; }
	virtual bool Save() { return false; }
	virtual bool SaveAs(const FString& Filename) { return false; }
};

#if EXCELANALYSIS_WITH_XLINT
/// <summary>
/// 基于xlnt库实现
/// </summary>
class EXCELHELPER_API FWorkBookWarpper_xlnt : public FWorkBookWarpper
{
public:
	/// FWorkBookWarpper
	virtual bool Load(const FString& Filename, const FString& Password = TEXT("")) override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(const FString& Title) override;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(int32 Index) override;
	virtual TSharedPtr<FWorkSheetWarpper> CreateWorkSheet(int32 Index = INDEX_NONE) override;
	virtual TArray<FString> GetTitles() const override;
	virtual int32 Num() const override;
	virtual int32 IndexOf(TSharedPtr<FWorkSheetWarpper> WorkSheet) override;
	/// FWorkBookWarpper

private:
	xlnt::workbook WorkBook;
};
#endif

/// <summary>
/// 工作表迭代器
/// </summary>
class EXCELHELPER_API FWorkSheetIterator
{
public:
	FWorkSheetIterator() = default;

	FWorkSheetIterator(const FWorkSheetIterator&) = default;

	FWorkSheetIterator& operator=(const FWorkSheetIterator&) = default;

	FWorkSheetIterator(FWorkSheetIterator&&) = default;

	FWorkSheetIterator& operator=(FWorkSheetIterator&&) = default;

	~FWorkSheetIterator() = default;

	FWorkSheetIterator(FWorkBook& InWorkBook, int32 InIndex);

	FWorkSheet operator*();

	const FWorkSheet operator*() const;

	bool operator==(const FWorkSheetIterator& Comparand) const;

	bool operator!=(const FWorkSheetIterator& Comparand) const;

	FWorkSheetIterator operator++(int);

	FWorkSheetIterator& operator++();

	FWorkSheetIterator operator--(int);

	FWorkSheetIterator& operator--();

private:
	FWorkBook* WorkBook = nullptr;

	int32 Index = INDEX_NONE;
};

/// <summary>
/// 工作表常量迭代器
/// </summary>
class EXCELHELPER_API FConstWorkSheetIterator
{
public:
	FConstWorkSheetIterator() = default;

	FConstWorkSheetIterator(const FConstWorkSheetIterator&) = default;

	FConstWorkSheetIterator& operator=(const FConstWorkSheetIterator&) = default;

	FConstWorkSheetIterator(FConstWorkSheetIterator&&) = default;

	FConstWorkSheetIterator& operator=(FConstWorkSheetIterator&&) = default;

	~FConstWorkSheetIterator() = default;

	FConstWorkSheetIterator(const FWorkBook& InWorkBook, int32 InIndex);

	FWorkSheet operator*();

	const FWorkSheet operator*() const;

	bool operator==(const FConstWorkSheetIterator& Comparand) const;

	bool operator!=(const FConstWorkSheetIterator& Comparand) const;

	FConstWorkSheetIterator operator++(int);

	FConstWorkSheetIterator& operator++();

	FConstWorkSheetIterator operator--(int);

	FConstWorkSheetIterator& operator--();

private:
	const FWorkBook* WorkBook = nullptr;

	int32 Index = INDEX_NONE;
};

/// <summary>
/// 工作簿
/// </summary>
USTRUCT(BlueprintType)
struct EXCELHELPER_API FWorkBook
{
	GENERATED_BODY()

public:
#if EXCELANALYSIS_WITH_XLINT
	template<typename T = FWorkBookWarpper_xlnt>
#else
	template<typename T = FWorkBookWarpper>
#endif
	FWorkBook()
		: WorkBook(MakeShareable(new T()))
	{

	}
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