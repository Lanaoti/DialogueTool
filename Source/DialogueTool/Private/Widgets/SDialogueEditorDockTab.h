// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Docking/SDockTab.h"
#include "DialogueTypes.h"

class SDialogueEditorDockTab : public SDockTab
{
public:
	SLATE_BEGIN_ARGS(SDialogueEditorDockTab) 
		: _DialogueList()
		{

		}

	SLATE_ARGUMENT(FDialogueList, DialogueList)
    
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
};
