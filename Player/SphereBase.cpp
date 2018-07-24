// Fill out your copyright notice in the Description page of Project Settings.

#include "SphereBase.h"
#include "Components/StaticMeshComponent.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Components/InputComponent.h"
#include "Engine.h"

// Sets default values
ASphereBase::ASphereBase()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	IsInput = true;
	SphereSpeed = 300.0f;
	SphereSpeedMin = SphereSpeed;
	SphereSpeedMax = 500.0f;

	SphereMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SphereBaseComp"));
	SphereMeshComp->SetSimulatePhysics(true);
	CameraArmComp = CreateDefaultSubobject<USpringArmComponent>(TEXT("CameraArm"));
	CameraArmComp->SetupAttachment(SphereMeshComp);
	CameraComp = CreateDefaultSubobject<UCameraComponent>(TEXT("CameraComp"));
	CameraComp->SetupAttachment(CameraArmComp);
}	

// Called when the game starts or when spawned
void ASphereBase::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ASphereBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if(IsInput&&AugularVector != FVector(0,0,0))
	SphereMeshComp->SetPhysicsAngularVelocity(AugularVector);
}

// Called to bind functionality to input
void ASphereBase::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	PlayerInputComponent->BindAxis("MoveForward", this, &ASphereBase::Moveforward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASphereBase::MoveRight);
	PlayerInputComponent->BindAction("SpeedUp", IE_Pressed, this, &ASphereBase::SpeedUp);
	PlayerInputComponent->BindAction("SpeedUp", IE_Released, this, &ASphereBase::SpeedLow);
}

void ASphereBase::Moveforward(float val)
{
	if (IsInput) {
		AugularVector.Y = SphereSpeed * val;
	}
}

void ASphereBase::MoveRight(float val)
{
	if (IsInput) {
		AugularVector.X = -SphereSpeed * val;
	}
}

void ASphereBase::SpeedUp()
{
	SphereSpeed = SphereSpeedMax;
}
void ASphereBase::SpeedLow()
{
	SphereSpeed = SphereSpeedMin;
}

