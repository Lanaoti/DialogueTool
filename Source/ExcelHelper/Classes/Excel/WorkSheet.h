// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkBook.h"
#include "WorkSheet.generated.h"


/// <summary>
/// �������װ���ӿ�
/// </summary>
class EXCELHELPER_API FWorkSheetWarpper
{
public:
	FWorkSheetWarpper() {}
	virtual ~FWorkSheetWarpper() {}

	virtual FString GetTitle() const { return TEXT(""); }
	virtual int32 Columns(bool bSkipNull = false) const { return 0; }
	virtual int32 Rows(bool bSkipNull = false) const { return 0; }
};


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

	/// <summary>
	/// ��ȡ������
	/// </summary>
	/// <returns>����������</returns>
	FWorkBook GetWorkBook() const;

	/// <summary>
	/// ��ȡ���������
	/// </summary>
	/// <returns>����</returns>
	FString GetTitle() const;

	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="bSkipNull">�Ƿ�������</param>
	/// <returns>����</returns>
	int32 Columns(bool bSkipNull = false) const;

	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="bSkipNull">�Ƿ�������</param>
	/// <returns>����</returns>
	int32 Rows(bool bSkipNull = false) const;

	friend struct FWorkBook;

protected:
	UPROPERTY(BlueprintReadOnly, Category = Excel)
	FWorkBook WorkBook;

private:
	TSharedPtr<FWorkSheetWarpper> WorkSheet;
};
