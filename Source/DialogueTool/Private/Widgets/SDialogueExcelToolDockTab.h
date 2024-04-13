// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Widgets/Docking/SDockTab.h"
#include "ExcelHelper.h"


class SWidget;
class SOverlay;
class FTabManager;

class SDialogueExcelToolDockTab : public SDockTab
{
public:
    SLATE_BEGIN_ARGS(SDialogueExcelToolDockTab) {}
    SLATE_END_ARGS()

    void Construct(const FArguments& InArgs);

protected:
    virtual TSharedRef<SWidget> MakeMenuBar();
    virtual TSharedRef<SWidget> MakeWorkBookWidget(const FWorkBook& InWorkBook);

    void HandlePullDownFileMenu(FMenuBuilder& MenuBuilder);
    void HandlePullDownEditMenu(FMenuBuilder& MenuBuilder);

protected:
    void OnClicked_OpenExcel();
    void OnClicked_SaveCurrentExcel();
    void OnClicked_SaveCurrentExcelAs();

    void UpdateWorkBookWidget();
    bool IsVaildWorkBook() const;

private:
    FWorkBook WorkBook;

    TSharedPtr<STextBlock> FilenameTextBlock;

    TSharedPtr<SOverlay> Content;

    TSharedPtr<FTabManager> TabManager;

    TSharedPtr<class FUICommandList> TapCommands;
};

