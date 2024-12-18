// Fill out your copyright notice in the Description page of Project Settings.


#include "WheelMachine.h"

#include "PlayerWidget.h"
#include "Kismet/GameplayStatics.h"

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
	button = "";

}

// Called when the game starts or when spawned
void AWheelMachine::BeginPlay()
{
	Super::BeginPlay();
	Player = Cast<AExamenMiSessionCharacter>(UGameplayStatics::GetPlayerCharacter(GetWorld(), 0));
}

void AWheelMachine::NotifyHit(class UPrimitiveComponent* MyComp, AActor* Other, class UPrimitiveComponent* OtherComp,
	bool bSelfMoved, FVector HitLocation, FVector HitNormal, FVector NormalImpulse, const FHitResult& Hit)
{
	if (MyComp == ButtonBlack)
	{
		button = "black";
		SpinWheel();
	}
	else if (MyComp == ButtonYellow)
	{
		button = "yellow";
		SpinWheel();
	}
	
	
	Super::NotifyHit(MyComp, Other, OtherComp, bSelfMoved, HitLocation, HitNormal, NormalImpulse, Hit);
}

void AWheelMachine::SpinWheel()
{
	float SpinDuration = FMath::FRandRange(1.f, 2.f);
	
	float TargetRotation = FMath::RandRange(0.f, 360.f);
	
	FTimerHandle TimerHandle;
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AWheelMachine::UpdateScore, SpinDuration, false);
	
	FRotator CurrentRotation = Wheel->GetRelativeRotation();
	FVector CurrentPosition = Wheel->GetRelativeLocation();
	FRotator FinalRotation(TargetRotation, CurrentRotation.Yaw, CurrentRotation.Roll);
	FLatentActionInfo LatentInfo;
	LatentInfo.CallbackTarget = this;

	Wheel->SetRelativeRotation(FRotator(0.f, CurrentRotation.Yaw, CurrentRotation.Roll));
	UKismetSystemLibrary::MoveComponentTo(Wheel, CurrentPosition, FinalRotation, true, false, SpinDuration, true, EMoveComponentAction::Move, LatentInfo);
	
	LastRotation = FinalRotation;
}

void AWheelMachine::UpdateScore()
{
	float RotationAngle = Wheel->GetRelativeRotation().Pitch;

	int rot = (int)RotationAngle;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Red, FString::FromInt(rot), true);
	
	
	if (RotationAngle < 0.f)
	{
		RotationAngle += 360.f;
		RotationAngle = FMath::Modulo(RotationAngle, 360.f);
	}

	rot = (int)RotationAngle;
	GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Black, FString::FromInt(rot), true);
	
	FString SegmentNeedle;
	if (RotationAngle >= 0.f && RotationAngle < 90.f)
	{
		SegmentNeedle = "black";
	}
	else if (RotationAngle >= 90.f && RotationAngle < 180.f)
	{
		SegmentNeedle = "yellow";
	}
	else if (RotationAngle >= 180.f && RotationAngle < 270.f)
	{
		SegmentNeedle = "black";
	}
	else if (RotationAngle >= 270.f && RotationAngle < 360.f)
	{
		SegmentNeedle = "yellow";
	}
	

	if (button == SegmentNeedle)
	{
		if (Player)
		{
			Player->playerScore++;
			Player->PlayerWidget->UpdateScore(Player->playerScore);
		}
	}
	
	button = "";
}

// Called every frame
void AWheelMachine::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



