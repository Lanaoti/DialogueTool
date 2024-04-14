// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkBook.h"
#include "WorkSheet.generated.h"

struct FColumn;
struct FRow;
struct FCell;
class FColumnWarpper;
class FRowWarpper;
class FCellWarpper;

/// <summary>
/// �������װ���ӿ�
/// </summary>
class EXCELWARPPER_API FWorkSheetWarpper : public TSharedFromThis<FWorkSheetWarpper>
{
public:
	FWorkSheetWarpper() {}
	virtual ~FWorkSheetWarpper() {}

	virtual TSharedPtr<FWorkBookWarpper> GetWorkBook() const = 0;
	virtual FString GetTitle() const = 0;
	virtual int32 Columns(bool bSkipNull = false) const = 0;
	virtual int32 Rows(bool bSkipNull = false) const = 0;
	virtual TSharedPtr<FColumnWarpper> GetColumn(int32 Index) const = 0;
	virtual TSharedPtr<FRowWarpper> GetRow(int32 Index) const = 0;
	virtual TSharedPtr<FCellWarpper> GetCell(int32 ColumnIndex, int32 RowIndex) const = 0;
};


USTRUCT(BlueprintType)
struct EXCELWARPPER_API FWorkSheet
{
	GENERATED_BODY()

public:
	FWorkSheet();
	FWorkSheet(TSharedPtr<FWorkSheetWarpper> InWorkSheet);
	FWorkSheet(TSharedRef<FWorkSheetWarpper> InWorkSheet);

	friend struct FWorkBook;

	/// <summary>
	/// ��֤�������Ƿ���Ч
	/// </summary>
	/// <returns>�Ƿ���Ч</returns>
	bool IsValid() const;

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

	/// <summary>
	/// ��ȡ��
	/// </summary>
	/// <param name="Index">���±�</param>
	/// <returns>�ж���</returns>
	FColumn GetColumn(int32 Index) const;

	/// <summary>
	/// ��ȡ��
	/// </summary>
	/// <param name="Index">���±�</param>
	/// <returns>�ж���</returns>
	FRow GetRow(int32 Index) const;

	/// <summary>
	/// ��ȡ��Ԫ��
	/// </summary>
	/// <param name="ColumnIndex">���±�</param>
	/// <param name="RowIndex">���±�</param>
	/// <returns>��Ԫ�����</returns>
	FCell GetCell(int32 ColumnIndex, int32 RowIndex) const;

private:	
	TSharedPtr<FWorkSheetWarpper> WorkSheet;
};
