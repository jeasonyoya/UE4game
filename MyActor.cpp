// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMyActor::InputText(int32 num) {
	GEngine->AddOnScreenDebugMessage(-1, 5.0f, FColor::Blue, FString::FromInt(num));
}