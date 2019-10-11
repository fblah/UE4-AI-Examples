// © Ajit D'Monte

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "BaseAIController.generated.h"

/**
 * 
 */
UCLASS()
class UE4_AI_EXAMPLES_API ABaseAIController : public AAIController
{
	GENERATED_BODY()
public:
	ABaseAIController(const FObjectInitializer& ObjectInitializer);
};
