// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Docking/SDockTab.h"
#include "ExcelWarpper.h"


class SDialogueEditorDockTab : public SDockTab
{
public:
	SLATE_BEGIN_ARGS(SDialogueEditorDockTab) 
        :_WorkBook(FWorkBook())
        {}
        
    SLATE_ARGUMENT(FWorkBook, WorkBook)
    
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
};
