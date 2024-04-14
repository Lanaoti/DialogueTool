// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

struct FColumn;
struct FCell;
struct FRow;

/// <summary>
/// 单元格迭代器
/// </summary>
class EXCELWARPPER_API FCellIterator
{
public:
	FCellIterator() = default;

	FCellIterator(const FCellIterator&) = default;

	FCellIterator& operator=(const FCellIterator&) = default;

	FCellIterator(FCellIterator&&) = default;

	FCellIterator& operator=(FCellIterator&&) = default;

	~FCellIterator() = default;

	FCellIterator(FColumn& InColumn, int32 InIndex);

	FCellIterator(FRow& InRow, int32 InIndex);

	FCell operator*();

	const FCell operator*() const;

	bool operator==(const FCellIterator& Comparand) const;

	bool operator!=(const FCellIterator& Comparand) const;

	FCellIterator operator++(int);

	FCellIterator& operator++();

	FCellIterator operator--(int);

	FCellIterator& operator--();

private:
	union
	{
		FColumn* Column;
		FRow* Row;
	};

	int32 Index = INDEX_NONE;
};

/// <summary>
/// 单元格常量迭代器
/// </summary>
class EXCELWARPPER_API FConstCellIterator
{
public:
	FConstCellIterator() = default;

	FConstCellIterator(const FConstCellIterator&) = default;

	FConstCellIterator& operator=(const FConstCellIterator&) = default;

	FConstCellIterator(FConstCellIterator&&) = default;

	FConstCellIterator& operator=(FConstCellIterator&&) = default;

	~FConstCellIterator() = default;

	FConstCellIterator(const FColumn& InColumn, int32 InIndex);

	FConstCellIterator(const FRow& InRow, int32 InIndex);

	FCell operator*();

	const FCell operator*() const;

	bool operator==(const FConstCellIterator& Comparand) const;

	bool operator!=(const FConstCellIterator& Comparand) const;

	FConstCellIterator operator++(int);

	FConstCellIterator& operator++();

	FConstCellIterator operator--(int);

	FConstCellIterator& operator--();

private:
	union
	{
		const FColumn* Column;
		const FRow* Row;
	};

	int32 Index = INDEX_NONE;
};