// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "WorkSheetIterator.h"
#include "WorkBook.generated.h"


struct FWorkBook;
struct FWorkSheet;
class FWorkSheetWarpper;

/// <summary>
/// ��������װ���ӿ�
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
/// ������
/// </summary>
USTRUCT(BlueprintType)
struct EXCELWARPPER_API FWorkBook
{
	GENERATED_BODY()

public:
	FWorkBook();
	FWorkBook(TSharedPtr<FWorkBookWarpper> InWorkBook);

	/// <summary>
	/// ��֤�������Ƿ���Ч
	/// </summary>
	/// <returns>�Ƿ���Ч</returns>
	bool IsValid() const;

	/// <summary>
	/// ����excel�ļ�
	/// </summary>
	/// <param name="Filename">�ļ�·��</param>
	/// <returns>�Ƿ�ɹ�</returns>
	bool Load(const FString& Filename, const FString& Password = TEXT(""));

	/// <summary>
	/// ��ȡ������
	/// </summary>
	/// <param name="Title">���������</param>
	/// <returns>���������</returns>
	FWorkSheet GetWorkSheet(const FString& Title) const;

	/// <summary>
	/// ��ȡ������
	/// </summary>
	/// <param name="Index">�������±�</param>
	/// <returns>���������</returns>
	FWorkSheet GetWorkSheet(int32 Index) const;

	/// <summary>
	/// ����������
	/// </summary>
	/// <param name="Index">�������±�</param>
	/// <returns>����������</returns>
	FWorkSheet CreateWorkSheet(int32 Index = INDEX_NONE);

	/// <summary>
	/// ��ȡ���й�����ı���
	/// </summary>
	/// <returns></returns>
	TArray<FString> GetTitles() const;

	/// <summary>
	/// ��ȡ����������
	/// </summary>
	/// <returns>����</returns>
	int32 Num() const;

	/// <summary>
	/// ��ȡ�������±�
	/// </summary>
	/// <param name="WorkSheet">���������</param>
	/// <returns>�±�</returns>
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