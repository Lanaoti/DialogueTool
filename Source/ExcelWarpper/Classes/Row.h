// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Row.generated.h"


struct FCell;
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
	virtual TSharedPtr<FCellWarpper> GetCell(int32 Index) const = 0;
};

/// <summary>
/// 行
/// </summary>
USTRUCT(BlueprintType)
struct FRow 
{
	GENERATED_BODY()

public:
	FRow();
	FRow(TSharedPtr<FRowWarpper> InRow);
	FRow(TSharedRef<FRowWarpper> InRow);

	int32 Num() const;
	FCell GetCell(int32 Index) const;

private:
	
	TSharedPtr<FRowWarpper> Row;
};