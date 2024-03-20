// StellarInnovator


#include "Character/Adventurer.h"

#include "EnhancedInputSubsystems.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "EnhancedInputComponent.h"


AAdventurer::AAdventurer()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}


	/*check(ZeldaContext);
	if(TObjectPtr<APlayerController> pc = Cast<APlayerController>(Controller))
	{
		UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(pc->GetLocalPlayer());
		check(Subsystem);
		Subsystem->AddMappingContext(ZeldaContext, 0);
	}*/

