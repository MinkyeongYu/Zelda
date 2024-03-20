// StellarInnovator

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "PlayerCharacterBase.generated.h"

UCLASS(Abstract)
class INVENTORYUI_API APlayerCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	APlayerCharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
	/*UPROPERTY(EditAnywhere, Category = "Socket")
	TObjectPtr<USkeletalMeshComponent> Sword;
	UPROPERTY(EditAnywhere, Category = "Socket")
	TObjectPtr<USkeletalMeshComponent> Bow;
	UPROPERTY(EditAnywhere, Category = "Socket")
	TObjectPtr<USkeletalMeshComponent> Shield;*/

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> SwordMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> BowMesh;
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Combat")
	TObjectPtr<UStaticMeshComponent> ShieldMesh;

};
