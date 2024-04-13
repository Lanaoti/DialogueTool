// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#if EXCELANALYSIS_WITH_XLINT
#include <xlnt/xlnt.hpp>
#endif

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

	template<typename WS> FWorkSheetWarpper(const WS* InWS)
	{

	}

	virtual FString GetTitle() const { return TEXT(""); }
};

#if EXCELANALYSIS_WITH_XLINT
/// <summary>
/// 基于xlnt库实现
/// </summary>
class EXCELHELPER_API FWorkSheetWarpper_xlnt : public FWorkSheetWarpper
{
public:
	FWorkSheetWarpper_xlnt()
	{

	}

	FWorkSheetWarpper_xlnt(const xlnt::worksheet* InWorkSheet)
		: WorkSheet(*InWorkSheet)
	{

	}
	
	friend class FWorkBookWarpper_xlnt;

	virtual FString GetTitle() const;

private:
	xlnt::worksheet WorkSheet;
};
#endif

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

	UPROPERTY(BlueprintReadOnly, Category = Excel)
	FWorkBook WorkBook;

	/// <summary>
	/// 获取工作表标题
	/// </summary>
	/// <returns>标题</returns>
	FString GetTitle() const;

	friend struct FWorkBook;

private:
	TSharedPtr<FWorkSheetWarpper> WorkSheet;
};
