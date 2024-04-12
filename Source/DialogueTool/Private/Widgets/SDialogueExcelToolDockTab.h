// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Docking/SDockTab.h"


class FTabManager;

class SDialogueExcelToolDockTab : public SDockTab
{
public:
    SLATE_BEGIN_ARGS(SDialogueExcelToolDockTab) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

    void HandlePullDownFileMenu(FMenuBuilder& MenuBuilder);
    void HandlePullDownEditMenu(FMenuBuilder& MenuBuilder);

protected:
    void OnClicked_OpenExcel();

private:
    TSharedPtr<FTabManager> TabManager;
};

