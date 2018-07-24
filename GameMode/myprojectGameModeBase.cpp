// Fill out your copyright notice in the Description page of Project Settings.

#include "myprojectGameModeBase.h"
#include "Engine.h"
#include "Player/SphereBase.h"

AmyprojectGameModeBase::AmyprojectGameModeBase() 
{
	PrimaryActorTick.bCanEverTick = true;
	PlayerDieNum = 0;
	IsEnd = false;
}
void AmyprojectGameModeBase::BeginPlay()
{
	Super::BeginPlay();
	ASphereBase * Pawn=Cast<ASphereBase>(GetWorld()->GetFirstPlayerController()->GetPawn());

	if (Pawn) 
	{
		PlayPawn = Pawn;
		CurrentStart = PlayPawn->GetActorLocation();
	}
	
}

void AmyprojectGameModeBase::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AmyprojectGameModeBase::SetPlayerLocation()//重载
{
	PlayPawn->SetActorLocation(CurrentStart);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));
	PlayerDieNum++;
}

void AmyprojectGameModeBase::SetPlayerLocation(FVector Start)//特殊操作。传送到指定位置
{
	PlayPawn->SetActorLocation(Start);
	PlayPawn->SphereMeshComp->SetPhysicsLinearVelocity(FVector(0, 0, 0));
	PlayPawn->SphereMeshComp->SetPhysicsAngularVelocity(FVector(0, 0, 0));

}

void AmyprojectGameModeBase::SetCurrentStart(FVector Location)
{
	if (Location != FVector(0, 0, 0))
	{
		CurrentStart = Location;
	}
}
void AmyprojectGameModeBase::SetPlayerInput(bool isInput)
{
	PlayPawn->IsInput = isInput;
	if (!isInput)
	{
		IsEnd = true;
	}
}