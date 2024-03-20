// StellarInnovator


#include "Character/PlayerCharacterBase.h"
#include "EnhancedInputComponent.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/SkeletalMeshSocket.h"

// Sets default values
APlayerCharacterBase::APlayerCharacterBase()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;
#pragma region SkeletalMeshComponent사용시
	// 새로 만들어진 Subobject의 주소값을 반환 후 Pointer에 저장. 소켓 생성
	/*Sword = CreateDefaultSubobject<USkeletalMeshComponent>("Sword");
	Sword->SetupAttachment(GetMesh(), FName("SwordSocket"));
	Sword->SetCollisionEnabled(ECollisionEnabled::NoCollision);

	Bow = CreateDefaultSubobject<USkeletalMeshComponent>("Bow");
	Bow->SetupAttachment(GetMesh(), FName("BowSocket"));
	Bow->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	Shield = CreateDefaultSubobject<USkeletalMeshComponent>("Shield");
	Shield->SetupAttachment(GetMesh(), FName("ShieldSocket"));
	Shield->SetCollisionEnabled(ECollisionEnabled::NoCollision);*/
#pragma endregion
	SwordMesh = CreateDefaultSubobject<UStaticMeshComponent>("SwordMesh");
	SwordMesh->SetupAttachment(GetMesh(), FName("SwordSocket"));
	SwordMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	BowMesh = CreateDefaultSubobject<UStaticMeshComponent>("BowMesh");
	BowMesh->SetupAttachment(GetMesh(), FName("BowSocket"));
	BowMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
	ShieldMesh = CreateDefaultSubobject<UStaticMeshComponent>("ShieldMesh");
	ShieldMesh->SetupAttachment(GetMesh(), FName("ShieldSocket"));
	ShieldMesh->SetCollisionEnabled(ECollisionEnabled::NoCollision);
	
}

void APlayerCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}


