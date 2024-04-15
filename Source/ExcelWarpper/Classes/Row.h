// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CellIterator.h"
#include "Row.generated.h"


struct FWorkSheet;
struct FCell;
class FWorkSheetWarpper;
class FCellWarpper;

/// <summary>
/// 行包装器接口
/// </summary>
class EXCELWARPPER_API FRowWarpper : public TSharedFromThis<FRowWarpper>
{
public:
	FRowWarpper() {}
	virtual ~FRowWarpper() {}

	virtual int32 Num() const = 0;
	virtual int32 GetIndex() const = 0;
	virtual TSharedPtr<FWorkSheetWarpper> GetWorkSheet() const = 0;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 Index) const = 0;
};

/// <summary>
/// 行
/// </summary>
USTRUCT(BlueprintType)
struct EXCELWARPPER_API FRow
{
	GENERATED_BODY()

public:
	FRow();
	FRow(TSharedPtr<FRowWarpper> InRow);
	FRow(TSharedRef<FRowWarpper> InRow);

	bool IsValid() const;
	int32 Num() const;
	int32 GetIndex() const;
	FWorkSheet GetWorkSheet() const;
	FCell GetCell(int32 Index) const;

public:
	using Iterator = FCellIterator;
	using ConstIterator = FConstCellIterator;

	Iterator begin();
	Iterator end();
	ConstIterator begin() const;
	ConstIterator end() const;
	ConstIterator cbegin() const;
	ConstIterator cend() const;

private:
	
	TSharedPtr<FRowWarpper> Row;
};