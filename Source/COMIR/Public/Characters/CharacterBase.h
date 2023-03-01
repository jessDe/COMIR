// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/HealthComponent.h"
#include "GameFramework/Character.h"
#include "CharacterBase.generated.h"

UCLASS()
class COMIR_API ACharacterBase : public ACharacter
{
	GENERATED_BODY()

	// Health Component
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = Health, meta = (AllowPrivateAccess = "true"))
	UHealthComponent* HealthComponent;

public:
	// Sets default values for this character's properties
	ACharacterBase();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};
