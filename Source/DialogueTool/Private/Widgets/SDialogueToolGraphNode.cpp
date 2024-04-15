#include "SDialogueToolGraphNode.h"
#include "EditorStyleSet.h"
#include "Widgets/SBoxPanel.h"
#include "EdGraph/DialogueToolUEdGraphNode.h"

void SDialogueToolGraphNode::Construct(const FArguments& InArgs, UDialogueToolUEdGraphNode* InNode)
{
	GraphNode = InNode;
	UpdateGraphNode();
	CreateDialogueText();
}

TSharedRef<SWidget> SDialogueToolGraphNode::CreateNodeContentArea()
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

TSharedRef<SWidget> SDialogueToolGraphNode::CreateDialogueText()
{
	UDialogueToolUEdGraphNode* TestNode = Cast<UDialogueToolUEdGraphNode>(GraphNode);
	auto Num = TestNode->DialogueTexts.Num();
	UE_LOG(LogTemp, Log, TEXT("TestNode TestNode TestNode:%d"), Num);

	for (int i = 0; i< Num; ++i)
	{
		FText TempText = TestNode->DialogueTexts[i];

		auto NewSlot = DialogueTextBox->AddSlot();
		NewSlot.AutoHeight();
		NewSlot.AttachWidget(SNew(STextBlock).Text(TempText));
	}

	return DialogueTextBox.ToSharedRef();
}