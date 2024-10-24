// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlatformToggle.generated.h"

UCLASS()
class APlatformToggle : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	APlatformToggle();
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* Cylinder;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* RedPlatform;
	UPROPERTY(EditAnywhere)
	UStaticMeshComponent* GreenPlatform;
	bool isRed;
	UMaterialInterface* GreenMat;
	UMaterialInterface* RedMat;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;
	virtual void NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit) override;
};
