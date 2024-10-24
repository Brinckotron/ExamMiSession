// Fill out your copyright notice in the Description page of Project Settings.


#include "FireTorch.h"

// Sets default values
AFireTorch::AFireTorch()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Torch = CreateDefaultSubobject<UStaticMeshComponent>("Torch");
	RootComponent = Torch;
	FireOrigin = CreateDefaultSubobject<USceneComponent>("FireOrigin");
	FireOrigin->AttachToComponent(Torch, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AFireTorch::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AFireTorch::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

