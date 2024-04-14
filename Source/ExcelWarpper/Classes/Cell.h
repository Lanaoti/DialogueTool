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
/// ��Ԫ���װ���ӿ�
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
/// ��Ԫ��
/// </summary>
USTRUCT(BlueprintType)
struct FCell
{
	GENERATED_BODY()

public:

	FCell();
	FCell(TSharedPtr<FCellWarpper> InCell);

	/// <summary>
	/// ��֤��Ԫ���Ƿ���Ч
	/// </summary>
	/// <returns>�Ƿ���Ч</returns>
	bool IsValid() const;

	/// <summary>
	/// ��ȡ��Ԫ�����ڹ�����
	/// </summary>
	/// <returns>���������</returns>
	FWorkSheet GetWorkSheet() const;

	/// <summary>
	/// ��ȡ��Ԫ��������
	/// </summary>
	/// <returns>�ж���</returns>
	FColumn GetColumn() const;

	/// <summary>
	/// ��ȡ��Ԫ��������
	/// </summary>
	/// <returns>�ж���</returns>
	FRow GetRow() const;

private:
	TSharedPtr<FCellWarpper> Cell;
};