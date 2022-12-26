// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "HealthComponent.generated.h"

UDELEGATE(BlueprintCallable)
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FOnActorDied);


UCLASS( ClassGroup=Health, meta=(BlueprintSpawnableComponent) )
class POSTJAM_API UHealthComponent : public UActorComponent
{
    GENERATED_BODY()

public:    
    // Sets default values for this component's properties
    UHealthComponent();

private:
    UPROPERTY(EditAnywhere, BlueprintReadOnly, BlueprintGetter=GetMaxHealth, BlueprintSetter=SetMaxHealth, Category="Health", meta=(AllowPrivateAccess=true))
    float MaxHealth;

    UPROPERTY(EditAnywhere, BlueprintReadOnly, BlueprintGetter=GetCurrentHealth, BlueprintSetter=SetCurrentHealth, Category="Health", meta=(AllowPrivateAccess=true))
    float CurrentHealth;

protected:
    // Called when the game starts
    virtual void BeginPlay() override;

public:    
    UFUNCTION(BlueprintGetter, Category="Health")
    float GetMaxHealth() const;

    UFUNCTION(BlueprintGetter, Category="Health")
    float GetCurrentHealth() const;

    UFUNCTION(BlueprintSetter, Category="Health")
    void SetMaxHealth(float NewMaxHealth);

    UFUNCTION(BlueprintSetter, Category="Health")
    void SetCurrentHealth(float NewCurrentHealth);

    UFUNCTION(BlueprintCallable, Category="Health")
    void ChangeHealth(const float AppliedChange);

    UPROPERTY(BlueprintAssignable, Category = "Health")
    FOnActorDied OnActorDied;
};