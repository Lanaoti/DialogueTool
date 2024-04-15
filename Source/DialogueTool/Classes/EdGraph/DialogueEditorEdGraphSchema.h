// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/ObjectMacros.h"
#include "EdGraph/EdGraphschema.h"
#include "DialogueEditorEdGraphSchema.generated.h"


UCLASS(MinimalAPI)
class UDialogueEditorEdGraphSchema : public UEdGraphSchema
{
	GENERATED_UCLASS_BODY()

	virtual const FPinConnectionResponse CanCreateConnection(const UEdGraphPin* A, const UEdGraphPin* B) const override
	{
		return FPinConnectionResponse(CONNECT_RESPONSE_MAKE, TEXT("OK"));
	}

	virtual FLinearColor GetPinTypeColor(const FEdGraphPinType& PinType) const override 
	{
		return FLinearColor::White;
	}
};