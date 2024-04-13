#include "SDialogueToolGraphNode.h"
#include "SDialogueToolGraphNode.h"
#include "EditorStyleSet.h"

void SDialogueToolGraphNode::Construct(const FArguments& InArgs, UDialogueToolUEdGraphNode* InNode)
{
	GraphNode = InNode;
	UpdateGraphNode();
}

//void SDialogueToolGraphNode::UpdateGraphNode()
//{
//	RightNodeBox.Reset();
//	LeftNodeBox.Reset();
//
//	GetOrAddSlot(ENodeZone::Center)
//	.HAlign(HAlign_Center)
//	.VAlign(VAlign_Center)
//	[
//		SNew(SVerticalBox)
//		+ SVerticalBox::Slot()
//		.AutoHeight()
//		[
//			SNew(SBorder)
//			.BorderImage(FEditorStyle::GetBrush("Graph.Node.Body"))
//			.Padding(0)
//			[
//				SNew(SVerticalBox)
//				+ SVerticalBox::Slot()
//				.AutoHeight()
//				.HAlign(HAlign_Fill)
//				.VAlign(VAlign_Top)
//				[
//					// NODE CONTENT AREA
//					SNew(SBorder)
//					.BorderImage(FEditorStyle::GetBrush("NoBorder"))
//					.HAlign(HAlign_Fill)
//					.VAlign(VAlign_Fill)
//					.Padding(FMargin(0, 3))
//					[
//						SNew(SHorizontalBox)
//						+ SHorizontalBox::Slot()
//						.AutoWidth()
//						.VAlign(VAlign_Center)
//						[
//							// LEFT
//							SNew(SBox)
//							.WidthOverride(40)
//							[
//								SAssignNew(LeftNodeBox, SVerticalBox)
//							]
//						]
//						
//						+ SHorizontalBox::Slot()
//						.VAlign(VAlign_Center)
//						.HAlign(HAlign_Center)
//						.FillWidth(1.0f)
//						[
//							SNew(STextBlock).Text(FText::FromString("hello World"))
//						]
//												
//						+ SHorizontalBox::Slot()
//						.AutoWidth()
//						.VAlign(VAlign_Center)
//						[
//							// RIGHT
//							SNew(SBox)
//							.WidthOverride(40)
//							[
//								SAssignNew(RightNodeBox, SVerticalBox)
//							]
//						]
//
//					]
//
//				]
//	
//			]
//
//		]
//
//	];
//
//	CreatePinWidgets();
//}