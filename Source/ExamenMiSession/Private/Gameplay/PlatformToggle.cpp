// Fill out your copyright notice in the Description page of Project Settings.


#include "PlatformToggle.h"

// Sets default values
APlatformToggle::APlatformToggle()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	Cylinder = CreateDefaultSubobject<UStaticMeshComponent>("Cylinder");
	RootComponent = Cylinder;
	RedPlatform = CreateDefaultSubobject<UStaticMeshComponent>("RedPlatform");
	GreenPlatform = CreateDefaultSubobject<UStaticMeshComponent>("GreenPlatform");
	isRed = true;
}

// Called when the game starts or when spawned
void APlatformToggle::BeginPlay()
{
	Super::BeginPlay();
	GreenPlatform->SetVisibility(false);
	RedMat = Cylinder->GetMaterial(0);
	GreenMat = GreenPlatform->GetMaterial(0);
	
}

// Called every frame
void APlatformToggle::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void APlatformToggle::NotifyHit(UPrimitiveComponent* MyComp, AActor* Other, UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);

	if (MyComp == Cylinder)
	{
		if (isRed && RedPlatform)
		{
			isRed = false;
			RedPlatform->SetVisibility(false);
			GreenPlatform->SetVisibility(true);
			Cylinder->SetMaterial(0, GreenMat);
		}
		else if (!isRed && GreenPlatform)
		{
			isRed = true;
			RedPlatform->SetVisibility(true);
			GreenPlatform->SetVisibility(false);
			Cylinder->SetMaterial(0, RedMat);
		}
	}

	
}

