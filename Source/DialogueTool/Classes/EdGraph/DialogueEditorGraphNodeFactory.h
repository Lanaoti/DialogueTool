#pragma once

#include "EdGraph/DialogueEditorEdGraphNode.h"
#include "Widgets/SDialogueEditorGraphNode.h"

// 定义图表节点工厂
class FDialogueEditorNodeFactory :public FGraphPanelNodeFactory
{
	virtual TSharedPtr<class SGraphNode> CreateNode(UEdGraphNode* Node) const override
	{
		if (UDialogueEditorEdGraphNode* DialogueEditorUEdGraphNode = Cast<UDialogueEditorEdGraphNode>(Node))
		{
			return SNew(SDialogueEditorGraphNode, DialogueEditorUEdGraphNode);
		}

		return nullptr;
	}
};
