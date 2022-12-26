#include "HealthComponent.h"

UHealthComponent::UHealthComponent()
{
    PrimaryComponentTick.bCanEverTick = false;
    MaxHealth = 10;
    CurrentHealth = 10;
}

// Called when the game starts
void UHealthComponent::BeginPlay()
{
    Super::BeginPlay();

#if WITH_EDITOR
    if (CurrentHealth > MaxHealth)
    {
        UE_LOG(LogTemp, Error, TEXT("CurrentHealth is greater than MaxHealth!"));
    }
#endif
}

float UHealthComponent::GetMaxHealth() const
{
    return MaxHealth;
}

float UHealthComponent::GetCurrentHealth() const
{
    return CurrentHealth;
}

void UHealthComponent::SetMaxHealth(float NewMaxHealth = 0.0f)
{
    MaxHealth = NewMaxHealth;
}

void UHealthComponent::SetCurrentHealth(float NewCurrentHealth = 0.0f)
{
    if (NewCurrentHealth > GetMaxHealth())
    {
        // Our current health can not be greater than the max health!
        CurrentHealth = GetMaxHealth();
        return;
    }

    CurrentHealth = NewCurrentHealth;
}


void UHealthComponent::ChangeHealth(const float AppliedChange)
{
    if (CurrentHealth <= 0)
        return;

    CurrentHealth -= AppliedChange;

    if (CurrentHealth > MaxHealth)
    {
        CurrentHealth = MaxHealth;
        return;
    }
    
    if (CurrentHealth <= 0)
    {
        ActorDied.Broadcast();
        return;
    }
}