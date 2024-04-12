// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#if EXCELANALYSIS_WITH_XLINT
#include <xlnt/xlnt.hpp>
#endif

#include "WorkBook.generated.h"


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

	/// <summary>
	/// 加载excel文件
	/// </summary>
	/// <param name="Filename">文件路径</param>
	/// <returns>是否成功</returns>
	virtual bool Load(const FString& Filename, const FString& Password = TEXT("")) { return false; }
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(const FString& Title) { return nullptr; }
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet(int32 Index) { return nullptr; }
	virtual TSharedPtr<FWorkSheetWarpper> CreateWorkSheet(int32 Index = INDEX_NONE) { return nullptr; }
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
	/// FWorkBookWarpper

private:
	xlnt::workbook WorkBook;
};
#endif

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

	bool IsValid() const;
	bool Load(const FString& Filename, const FString& Password = TEXT(""));
	FWorkSheet GetWorkSheet(const FString& Title);
	FWorkSheet GetWorkSheet(int32 Index);
	FWorkSheet CreateWorkSheet(int32 Index = INDEX_NONE);

private:
	TSharedPtr<FWorkBookWarpper> WorkBook;
};