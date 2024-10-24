// Fill out your copyright notice in the Description page of Project Settings.


#include "FireTorch.h"

#include "ExamenMiSession/ExamenMiSessionCharacter.h"
#include "NiagaraComponent.h"

// Sets default values
AFireTorch::AFireTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Torch = CreateDefaultSubobject<UStaticMeshComponent>("Torch");
	RootComponent = Torch;
	FireOrigin = CreateDefaultSubobject<USceneComponent>("FireOrigin");
	FireOrigin->AttachToComponent(Torch, FAttachmentTransformRules::KeepRelativeTransform);
	TorchFire = CreateDefaultSubobject<UNiagaraComponent>("TorchFire");
	TorchFire->AttachToComponent(FireOrigin, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AFireTorch::BeginPlay()
{
	Super::BeginPlay();
	TorchFire->SetVisibility(false);
	
}

// Called every frame
void AFireTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AFireTorch::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp, bool bSelfMoved,
	FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
	if (Cast<AExamenMiSessionCharacter>(Other) && !isLit)
	{
		isLit = true;
		Cast<AExamenMiSessionCharacter>(Other)->torchesLit++;
		TorchFire->SetVisibility(true);
		if (Cast<AExamenMiSessionCharacter>(Other)->torchesLit == 2)
		{
			if (!Cage->isRaised)
			{
				Cage->Raise();
			}
			
		}
	}
}

