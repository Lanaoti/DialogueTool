#pragma once

#include "CoreMinimal.h"
#include "Uobject/objectMacros.h"
#include "EdGraph/EdGraphschema.h"
#include "DialogueToolUEdGraphSchema.generated.h"

UCLASS(MinimalAPI)
class UDialogueToolUEdGraphSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()

	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("OK"));
	}
};