// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "SphereBase.generated.h"


UCLASS()
class MYPROJECT_API ASphereBase : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ASphereBase();

	UPROPERTY(EditAnywhere,BlueprintReadWrite,Category="SphereMeshComp")
		class UStaticMeshComponent * SphereMeshComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CameraArmComp")
		class USpringArmComponent * CameraArmComp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite,Category="CameraComp")
		class UCameraComponent * CameraComp;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool IsInput;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SphereSpeed;
	FVector AugularVector;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SphereSpeedMin;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SphereSpeed")
		float SphereSpeedMax;
protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UFUNCTION(BlueprintCallable)
	void Moveforward(float val);
	UFUNCTION(BlueprintCallable)
	void MoveRight(float val);
	UFUNCTION(BlueprintCallable)
	void SpeedUp();
	UFUNCTION(BlueprintCallable)
	void SpeedLow();
	
};
