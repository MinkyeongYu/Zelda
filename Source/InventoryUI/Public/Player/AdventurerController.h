// StellarInnovator

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/PlayerController.h"
#include "Character/PlayerCharacterBase.h"
#include "AdventurerController.generated.h"

class UInputMappingContext;
class UInputAction;
class Adventurer;
struct FInputActionValue;

/**
 * 
 */
UCLASS()
class INVENTORYUI_API AAdventurerController : public APlayerController
{
	GENERATED_BODY()
public:
	AAdventurerController();
protected:
	virtual void BeginPlay() override;
	virtual void SetupInputComponent() override;
	virtual void SetupInactiveStateInputComponent(UInputComponent* InComponent) override;
private:
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputMappingContext> ZeldaContext;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> IA_Move;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> IA_Look;
	UPROPERTY(EditAnywhere, Category="Input")
	TObjectPtr<UInputAction> IA_Jump;
public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Transient, Category="InputCheck")
	bool isJumping;
private:
	void Move(const FInputActionValue& InputActionValue);
	void Look(const FInputActionValue& InputActionValue);

	void Jump();
	void StopJumping();
};
