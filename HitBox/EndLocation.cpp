// Fill out your copyright notice in the Description page of Project Settings.

#include "EndLocation.h"
#include "GameMode/myprojectGameModeBase.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

AEndLocation::AEndLocation()
{
	EndMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("EndMeshComp"));
	HitBoxComp->SetupAttachment(EndMeshComp);
}
void AEndLocation::OnHitSphere(ASphereBase * sphere)
{
	AmyprojectGameModeBase * GameModeBase = Cast<AmyprojectGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetPlayerInput(false);
}
