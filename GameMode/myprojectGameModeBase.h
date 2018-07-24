// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "myprojectGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class MYPROJECT_API AmyprojectGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	AmyprojectGameModeBase();

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayPawn")
		class ASphereBase * PlayPawn;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayPawn")
		FVector CurrentStart;//´æµµµã£»

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerDieNum")
		int32 PlayerDieNum;//ËÀÍö´ÎÊý£»

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsEnd;

public:
	virtual void BeginPlay();

	virtual void Tick(float DeltaTime);

public:
	UFUNCTION(BlueprintCallable)
	void SetPlayerLocation();
	UFUNCTION(BlueprintCallable)
	void SetPlayerLocation(FVector Start);
	UFUNCTION(BlueprintCallable)
	void SetCurrentStart(FVector Location);
	UFUNCTION(BlueprintCallable)
	void SetPlayerInput(bool isInput);
};
