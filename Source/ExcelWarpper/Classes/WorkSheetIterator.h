// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

struct FWorkBook;
struct FWorkSheet;

/// <summary>
/// 工作表迭代器
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
/// 工作表常量迭代器
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