// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

#include "WorkBook.generated.h"


struct FWorkBook;
struct FWorkSheet;
class FWorkSheetWarpper;

/// <summary>
/// ��������װ���ӿ�
/// </summary>
class EXCELWARPPER_API FWorkBookWarpper
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


/// <summary>
/// �����������
/// </summary>
class EXCELWARPPER_API FWorkSheetIterator
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
/// ��������������
/// </summary>
class EXCELWARPPER_API FConstWorkSheetIterator
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
/// ������
/// </summary>
USTRUCT(BlueprintType)
struct EXCELWARPPER_API FWorkBook
{
	GENERATED_BODY()

public:
	FWorkBook();

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