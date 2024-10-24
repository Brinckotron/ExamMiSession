// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelMachine.h"

// Sets default values
AWheelMachine::AWheelMachine()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Box = CreateDefaultSubobject<UStaticMeshComponent>("Box");
	RootComponent = Box;
	Wheel = CreateDefaultSubobject<UStaticMeshComponent>("Wheel");
	Wheel->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	Needle = CreateDefaultSubobject<UStaticMeshComponent>("Needle");
	Needle->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ButtonBlack = CreateDefaultSubobject<UStaticMeshComponent>("ButtonBlack");
	ButtonBlack->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);
	ButtonYellow = CreateDefaultSubobject<UStaticMeshComponent>("ButtonYellow");
	ButtonYellow->AttachToComponent(Box, FAttachmentTransformRules::KeepRelativeTransform);

}

// Called when the game starts or when spawned
void AWheelMachine::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AWheelMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

