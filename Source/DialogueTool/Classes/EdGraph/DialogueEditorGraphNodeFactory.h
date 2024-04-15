#pragma once

#include "EdGraph/DialogueEditorEdGraphNode.h"
#include "Widgets/SDialogueEditorGraphNode.h"

// ����ͼ��ڵ㹤��
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
