// StellarInnovator

#pragma once

#include "CoreMinimal.h"
#include "Character/PlayerCharacterBase.h"
#include "Adventurer.generated.h"

/**
 * 
 */
UCLASS()
class INVENTORYUI_API AAdventurer : public APlayerCharacterBase
{
	GENERATED_BODY()
public:
	AAdventurer();
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> ZeldaContext;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> IA_Jump;
};
