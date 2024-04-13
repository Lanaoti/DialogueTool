#pragma once

#include "DialogueToolUEdGraphNode.h"
#include "Widgets/SDialogueToolGraphNode.h"

// 定义图表节点工厂
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
