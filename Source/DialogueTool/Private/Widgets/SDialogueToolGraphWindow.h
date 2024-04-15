#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "GraphEditor.h"
#include "ExcelWarpper.h"


class SDialogueToolGraphWindow :public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SDialogueToolGraphWindow) 
		:_WorkBook(FWorkBook())
		{}

	SLATE_ARGUMENT(FWorkBook, WorkBook)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	// 图表编辑器控件
	TSharedPtr<SGraphEditor>GraphEditorPtr;
	
	// 图表对象
	class UDialogueToolUEdGraph * Graphobj;

};