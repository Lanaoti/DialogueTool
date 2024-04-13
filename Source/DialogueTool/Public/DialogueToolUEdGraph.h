#pragma once

#include "CoreMinimal.h"
#include "Uobject/objectMacros.h"
#include "EdGraph/EdGraph.h"
#include "ExcelHelper.h"
#include "DialogueToolUEdGraph.generated.h"

UCLASS()
class UDialogueToolUEdGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:

	void ReBiuldGraph(const FWorkBook& WorkBook);

	class UDialogueToolUEdGraphNode* CreateTestNode();

private:

	float NodeX = 0.0f;

	float NodeY = 0.0f;
};