#include "Components/HealthComponent.h"

UHealthComponent UHealthComponent::HealthComponent()
{
	return UHealthComponent();
}

void UHealthComponent::BeginPlay()
{
	CurrentHealth = Health;
	GetOwner()->OnTakeAnyDamage.AddDynamic(this, &UHealthComponent::OwnerDamage);
}

// Blueprint Pure
float UHealthComponent::GetCurrentHealth()
{
	return CurrentHealth;
}

bool UHealthComponent::GetIsDead()
{
	return bIsDead;
}

float UHealthComponent::GetCurrentHealthPercentage()
{
	return CurrentHealth / Health;
}

void UHealthComponent::HealPlayer(float Heal)
{
	CurrentHealth = FMath::Clamp(CurrentHealth + Heal, 0.0f, Health);

	if (CurrentHealth > 0)
	{
		bIsDead = false;

		// Call Event Dispatchers
		OnUpdateHealth.Broadcast(CurrentHealth);
		OnUpdateHealthPercentage.Broadcast(CurrentHealth / Health);
	}
}

// Reset Healths
void UHealthComponent::ResetHealth()
{
	bIsDead = false;
	CurrentHealth = Health;

	// Call Event Dispatchers
	OnUpdateHealth.Broadcast(CurrentHealth);
	OnUpdateHealthPercentage.Broadcast(CurrentHealth / Health);
}

// Change Max Health
void UHealthComponent::ChangeMaxHealth(float NewMaxHealth)
{
	Health = NewMaxHealth;

	// Call Event Dispatcher
	OnUpdateHealthPercentage.Broadcast(CurrentHealth / Health);
}

// Damage Event
void UHealthComponent::OwnerDamage(AActor* DamageActor, float Damage, const UDamageType* DamageType, AController* EventInstigator, AActor* DamageCauser)
{
	if (!bIsDead)
	{
		CurrentHealth = FMath::Clamp(CurrentHealth - Damage, 0.0f, Health);

		// Call Event Dispatchers
		OnUpdateHealth.Broadcast(CurrentHealth);
		OnUpdateHealthPercentage.Broadcast(CurrentHealth / Health);

		if (CurrentHealth <= 0)
		{
			bIsDead = true;
			OnPlayerDeath.Broadcast();
		}
	}
}
