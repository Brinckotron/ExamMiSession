// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "FireTorch.generated.h"

UCLASS()
class AFireTorch : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AFireTorch();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Torch;
	UPROPERTY(EditAnywhere)
	USceneComponent* FireOrigin;
	UPROPERTY(EditAnywhere)
	class UNiagaraComponent* TorchFire;
	UPROPERTY(EditAnywhere)
	bool isLit;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;

};
