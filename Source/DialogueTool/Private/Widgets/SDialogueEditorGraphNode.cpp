// Copyright Epic Games, Inc. All Rights Reserved.

#include "SDialogueEditorGraphNode.h"
#include "EditorStyleSet.h"
#include "Widgets/SBoxPanel.h"
#include "EdGraph/DialogueEditorEdGraphNode.h"

void SDialogueEditorGraphNode::Construct(const FArguments& InArgs, UDialogueEditorEdGraphNode* InNode)
{
	GraphNode = InNode;
	UpdateGraphNode();
	CreateDialogueText();
}

TSharedRef<SWidget> SDialogueEditorGraphNode::CreateNodeContentArea()
{
	// NODE CONTENT AREA
	return SNew(SBorder)
		.BorderImage(FAppStyle::GetBrush("NoBorder"))
		.HAlign(HAlign_Fill)
		.VAlign(VAlign_Fill)
		.Padding(FMargin(0, 3))
		[
			SNew(SHorizontalBox)
				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Left)
				.AutoWidth()
				[
					// LEFT
					SAssignNew(LeftNodeBox, SVerticalBox)
				]

				+ SHorizontalBox::Slot()
				.HAlign(HAlign_Center)
				.FillWidth(1.0f)
				[
					SAssignNew(DialogueTextBox, SVerticalBox)
				]

				+ SHorizontalBox::Slot()
				.AutoWidth()
				.HAlign(HAlign_Right)
				[
					// RIGHT
					SAssignNew(RightNodeBox, SVerticalBox)
				]
		];
}

TSharedRef<SWidget> SDialogueEditorGraphNode::CreateDialogueText()
{
	UDialogueEditorEdGraphNode* Node = Cast<UDialogueEditorEdGraphNode>(GraphNode);
	auto Num = Node->Fragments.Num();
	UE_LOG(LogTemp, Log, TEXT("Node Node Node:%d"), Num);

	for (int i = 0; i< Num; ++i)
	{
		FText TempText = FText::FromString(Node->Fragments[i].Speaker + TEXT("") + Node->Fragments[i].Content);

		auto NewSlot = DialogueTextBox->AddSlot();
		NewSlot.AutoHeight();
		NewSlot.AttachWidget(SNew(STextBlock).Text(TempText));
	}

	return DialogueTextBox.ToSharedRef();
}