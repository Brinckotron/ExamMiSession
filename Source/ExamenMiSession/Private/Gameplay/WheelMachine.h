// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ExamenMiSession/ExamenMiSessionCharacter.h"
#include "GameFramework/Actor.h"
#include "WheelMachine.generated.h"

UCLASS()
class AWheelMachine : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AWheelMachine();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Box;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ButtonYellow;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* ButtonBlack;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Needle;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Wheel;
	FRotator LastRotation;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	virtual void NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

	void SpinWheel();
	void UpdateScore();
	FString button;

	AExamenMiSessionCharacter* Player;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};
