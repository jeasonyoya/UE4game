// Fill out your copyright notice in the Description page of Project Settings.

#include "DieSphere.h"
#include "Player/SphereBase.h"
#include "Engine.h"
#include "GameMode/myprojectGameModeBase.h"

void ADieSphere::OnHitSphere(ASphereBase * sphere)
{
	AmyprojectGameModeBase * GameModeBase = Cast<AmyprojectGameModeBase>(GetWorld()->GetAuthGameMode());
	GameModeBase->SetPlayerLocation();
}
