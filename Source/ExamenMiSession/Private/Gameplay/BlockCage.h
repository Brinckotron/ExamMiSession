// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "BlockCage.generated.h"

UCLASS()
class ABlockCage : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ABlockCage();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Block;
	bool isRaised;
	bool isRising;
	FVector originalPosition;
	FVector finalPosition;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void Raise();

};
