// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/SCompoundWidget.h"
#include "GraphEditor.h"


class SDialogueEditorGraphWindow :public SCompoundWidget
{

public:
	SLATE_BEGIN_ARGS(SDialogueEditorGraphWindow)
		: _DialogueList()
		{

		}

	SLATE_ARGUMENT(FDialogueList, DialogueList)

	SLATE_END_ARGS()

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);
	
	// ͼ��༭���ؼ�
	TSharedPtr<SGraphEditor>GraphEditorPtr;
	
	// ͼ�����
	class UDialogueEditorEdGraph * Graphobj;

};