// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WheelMachine.generated.h"

UCLASS()
class AWheelMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWheelMachine();
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Box;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ButtonYellow;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* ButtonBlack;
	UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* Needle;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Wheel;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
