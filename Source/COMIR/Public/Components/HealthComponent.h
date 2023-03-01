// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnPlayerDeath);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateHealth, float, NewHealth);
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnUpdateHealthPercentage, float, HealthPercentage);

UCLASS(ClassGroup=(Custom), meta=(BlueprintSpawnableComponent))
class COMIR_API UHealthComponent : public UActorComponent
{
	GENERATED_BODY()
	UHealthComponent HealthComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	// Bindings
	UFUNCTION(BlueprintCallable)
	void OwnerDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* EventInstigator, AActor* DamageCauser);

private:
	// Variables
	bool bIsDead;
	float CurrentHealth;

public:
	// Event Dispatchers
	UPROPERTY(BlueprintAssignable, Category = "Health|Events")
	FOnPlayerDeath OnPlayerDeath;

	UPROPERTY(BlueprintAssignable, Category = "Health|Events")
	FOnUpdateHealth OnUpdateHealth;

	UPROPERTY(BlueprintAssignable, Category = "Health|Events")
	FOnUpdateHealthPercentage OnUpdateHealthPercentage;

	// Variables
	UPROPERTY(BlueprintAssignable, Category = "Health|Events")
	float Health = 100;

	// Functions
	UPROPERTY(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	float GetCurrentHealth();

	UPROPERTY(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	bool GetIsDead();

	UPROPERTY(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	float GetCurrentHealthPercentage();

	UPROPERTY(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	void HealPlayer(float Heal);

	UPROPERTY(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	void ResetHealth();

	UPROPERTY(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	void ChangeMaxHealth(float NewMaxHealth);
};