// StellarInnovator


#include "Player/AdventurerController.h"
#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "Character/Adventurer.h"
#include "DSP/Delay.h"
#include "GameFramework/CharacterMovementComponent.h"

AAdventurerController::AAdventurerController()
{
	// 멀티
	//bReplicates = true;
	
}

void AAdventurerController::BeginPlay()
{
	Super::BeginPlay();

	check(ZeldaContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(ZeldaContext, 0);
	
	ULocalPlayer* LocalPlayer = Cast<ULocalPlayer>(Player);
	LocalPlayer->ViewportClient->ShouldAlwaysLockMouse();
	
	//true
	bShowMouseCursor = false;
	DefaultMouseCursor = EMouseCursor::Default;
	
	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::LockAlways);
	// false
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);
	this->SetInputMode(FInputModeGameOnly());
}

void AAdventurerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(IA_Move, ETriggerEvent::Triggered, this, &AAdventurerController::Move);
	EnhancedInputComponent->BindAction(IA_Look, ETriggerEvent::Triggered, this, &AAdventurerController::Look);
	
	EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Started, this, &AAdventurerController::Jump);
	EnhancedInputComponent->BindAction(IA_Jump, ETriggerEvent::Completed, this, &AAdventurerController::StopJumping);
}

void AAdventurerController::SetupInactiveStateInputComponent(UInputComponent* InComponent)
{
	Super::SetupInactiveStateInputComponent(InComponent);
}

void AAdventurerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	// 단위벡터
	// X, Y축 회전으로 앞/오른쪽 방향 값 가져옴
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);
	
	// get pawn controlled by player controller
	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}

void AAdventurerController::Look(const FInputActionValue& InputActionValue)
{
	const FVector2D LookVector = InputActionValue.Get<FVector2D>();

	if(APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddControllerYawInput(LookVector.X);
		ControlledPawn->AddControllerPitchInput(LookVector.Y);
	}
}

void AAdventurerController::Jump()
{
	if(ACharacter* ControlledPawn = GetPawn<ACharacter>())
	{
		ControlledPawn->Jump();
		isJumping = true;
	}
}

void AAdventurerController::StopJumping()
{
	if(ACharacter* ControlledPawn = GetPawn<ACharacter>())
	{
		ControlledPawn->StopJumping();
		isJumping = false;
	}
}
