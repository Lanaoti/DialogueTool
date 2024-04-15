// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "SGraphNode.h"

class UDialogueEditorEdGraphNode;

class SDialogueEditorGraphNode :public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SDialogueEditorGraphNode) {}
		
	SLATE_END_ARGS()
	
	/** Constructs this widget with InArgs */
	void Construct( const FArguments& InArgs, UDialogueEditorEdGraphNode* InNode );
		
protected:
	virtual TSharedRef<SWidget> CreateNodeContentArea() override;


private:
	TSharedPtr<SVerticalBox> DialogueTextBox;

	TSharedRef<SWidget> CreateDialogueText();
};
