#pragma once

#include "CoreMinimal.h"
#include "Uobject/objectMacros.h"
#include "EdGraph/EdGraph.h"
#include "DialogueToolUEdGraph.generated.h"

UCLASS()
class UDialogueToolUEdGraph : public UEdGraph
{
	GENERATED_UCLASS_BODY()

public:

	void ReBiuldGraph();

	class UDialogueToolUEdGraphNode* CreateTestNode();
};