// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Docking/SDockTab.h"

class SDialogueEditorDockTab : public SDockTab
{
public:
	SLATE_BEGIN_ARGS(SDialogueEditorDockTab) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);
};
