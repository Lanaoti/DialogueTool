#pragma once

#include "CoreMinimal.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "SGraphNode.h"

class UDialogueToolUEdGraphNode;

class SDialogueToolGraphNode :public SGraphNode
{
public:
	SLATE_BEGIN_ARGS(SDialogueToolGraphNode) {}
		
	SLATE_END_ARGS()
	
	/** Constructs this widget with InArgs */
	void Construct( const FArguments& InArgs, UDialogueToolUEdGraphNode* InNode );
		
protected:
	virtual TSharedRef<SWidget> CreateNodeContentArea() override;


private:
	TSharedPtr<SVerticalBox> DialogueTextBox;

	TSharedRef<SWidget> CreateDialogueText();
};
