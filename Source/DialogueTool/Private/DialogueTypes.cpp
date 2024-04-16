// Copyright Epic Games, Inc. All Rights Reserved.

#include "DialogueTypes.h"
#include "ExcelWarpper.h"


FDialogueFragment::FDialogueFragment()
{

}

FDialogueFragment::~FDialogueFragment()
{

}

FDialogueData::FDialogueData()
{

}

FDialogueData::~FDialogueData()
{

}

FDialogueList::FDialogueList()
{

}

FDialogueList::~FDialogueList()
{

}

void FDialogueList::Prase(const FWorkBook& WorkBook)
{
	for (const FWorkSheet& WorkSheet : WorkBook)
	{
		FColumn Column = GetColumn(WorkSheet, TEXT("ID"));
		if (Column.IsValid())
		{
			FDialogueData DialogueData = FDialogueData();

			int32 FragmentID = -1;
			int32 LastFragmentID = -1;
			int32 RowNum = 0;
			bool bEndRow = false;
			for (FCell Cell : Column)
			{
				int32 TempID = Cell.GetInt();

				//处理读到最后一行的逻辑
				FCell NextCell = Column.GetCell(RowNum);
				if (!NextCell.IsValid())
				{
					bEndRow = true;
				}

				if (TempID > 0 && TempID != FragmentID)
				{
					if (FragmentID > -1)
					{
						List.Add(DialogueData.ID, DialogueData);
						DialogueData = FDialogueData();
					}

					LastFragmentID = FragmentID;
					FragmentID = TempID;
					DialogueData.ID = FString::FromInt(FragmentID);
				}

				if (FragmentID > 0)
				{
					FDialogueFragment NewFragment = FDialogueFragment();

					FColumn SpeakerColumn = WorkSheet.GetColumn(1);
					FColumn ContentColumn = WorkSheet.GetColumn(2);

					if (SpeakerColumn.IsValid())
					{
						NewFragment.Speaker = SpeakerColumn.GetCell(RowNum).GetString();
					}

					if (ContentColumn.IsValid())
					{
						NewFragment.Content = ContentColumn.GetCell(RowNum).GetString();
					}

					DialogueData.Fragments.Add(NewFragment);
				}
				++RowNum;

				if (bEndRow)
				{
					List.Add(DialogueData.ID, DialogueData);
				}

				UE_LOG(LogTemp, Log, TEXT("Cell WorkSheet: %s Column: %d Row: %d Value: %d"), *WorkSheet.GetTitle(), Cell.GetColumn().GetIndex(), Cell.GetRow().GetIndex(), Cell.GetInt());
			}
		}
	}
}

FColumn FDialogueList::GetColumn(const FWorkSheet& WorkSheet, const FString& Value)
{
	int32 Rows = WorkSheet.Rows();
	for (int32 Index = 0; Index < Rows; Index++)
	{
		FRow Row = WorkSheet.GetRow(Index);
		for (FCell Cell : Row)
		{
			if (Cell.GetString().Equals(Value, ESearchCase::IgnoreCase))
			{
				return Cell.GetColumn();
			}
		}
	}

	return FColumn();
}