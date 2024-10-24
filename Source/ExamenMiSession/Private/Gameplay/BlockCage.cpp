// Fill out your copyright notice in the Description page of Project Settings.


#include "BlockCage.h"

// Sets default values
ABlockCage::ABlockCage()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Block = CreateDefaultSubobject<UStaticMeshComponent>("Block");
	RootComponent = Block;
	isRaised = false;
	isRising = false;
	
}

// Called when the game starts or when spawned
void ABlockCage::BeginPlay()
{
	Super::BeginPlay();
	originalPosition = Block->GetRelativeLocation();
	finalPosition = originalPosition + (Block->GetUpVector()*500);
	
}

// Called every frame
void ABlockCage::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	if (isRising)
	{
		FVector actualLocation = Block->GetRelativeLocation();
		if (actualLocation != finalPosition)
		{
			Block->SetRelativeLocation(actualLocation + Block->GetUpVector()*10);
		}
		else
		{
			isRising = false;
			isRaised = true;
		}
		
	}

}

void ABlockCage::Raise()
{
	if(!isRaised)
	{
		isRising = true;
	}
}

