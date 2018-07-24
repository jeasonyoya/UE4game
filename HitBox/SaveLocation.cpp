// Fill out your copyright notice in the Description page of Project Settings.

#include "SaveLocation.h"
#include "GameMode/myprojectGameModeBase.h"
#include "Components/BoxComponent.h"
#include "Components/StaticMeshComponent.h"
#include "Engine.h"

ASaveLocation::ASaveLocation() {
	SaveMeshComp = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("SaveMesh"));
	HitBoxComp->SetupAttachment(SaveMeshComp);
}// ÊµÀý»¯£» 
void ASaveLocation::OnHitSphere(ASphereBase * sphere) 
{
	AmyprojectGameModeBase * GameModeBase = Cast<AmyprojectGameModeBase>(GetWorld()->GetAuthGameMode());

	GameModeBase->SetCurrentStart(HitBoxComp->GetComponentLocation());
}


