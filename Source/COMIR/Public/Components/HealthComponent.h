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
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Health")
	float Health = 100;

	// Functions
	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	float GetCurrentHealth();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	bool GetIsDead();

	UFUNCTION(BlueprintCallable, BlueprintPure, Category = "Health|Functions")
	float GetCurrentHealthPercentage();

	UFUNCTION(BlueprintCallable, Category = "Health|Functions")
	void HealPlayer(float Heal);

	UFUNCTION(BlueprintCallable, Category = "Health|Functions")
	void ResetHealth();

	UFUNCTION(BlueprintCallable, Category = "Health|Functions")
	void ChangeMaxHealth(float NewMaxHealth);
};