#pragma once

#include "Classes/DialogueToolUEdGraphNode.h"
#include "Widgets/SDialogueToolGraphNode.h"

// ����ͼ��ڵ㹤��
class FDialogueToolNodeFactory :public FGraphPanelNodeFactory
{
	virtual TSharedPtr<class SGraphNode> CreateNode(UEdGraphNode* Node) const override
	{
		if (UDialogueToolUEdGraphNode* DialogueToolUEdGraphNode = Cast<UDialogueToolUEdGraphNode>(Node))
		{
			return SNew(SDialogueToolGraphNode, DialogueToolUEdGraphNode);
		}

		return nullptr;
	}
};
