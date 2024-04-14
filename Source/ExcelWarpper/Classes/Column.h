// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "CellIterator.h"
#include "Column.generated.h"


struct FCell;
class FCellWarpper;

/// <summary>
/// 行包装器接口
/// </summary>
class EXCELWARPPER_API FColumnWarpper : public TSharedFromThis<FColumnWarpper>
{
public:
	FColumnWarpper() {}
	virtual ~FColumnWarpper() {}

	virtual int32 Num() const = 0;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 Index) const = 0;
};

/// <summary>
/// 行
/// </summary>
USTRUCT(BlueprintType)
struct FColumn
{
	GENERATED_BODY()

public:
	FColumn();
	FColumn(TSharedPtr<FColumnWarpper> InColumn);
	FColumn(TSharedRef<FColumnWarpper> InColumn);

	int32 Num() const;
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
	
	TSharedPtr<FColumnWarpper> Column;
};