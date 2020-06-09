#include "TeleporterActor.h"

#include "Engine/Public/TimerManager.h"
#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"
#include "Components/SceneComponent.h"

ATeleporterActor::ATeleporterActor()
{
	PrimaryActorTick.bCanEverTick = true;
}

void ATeleporterActor::BeginPlay()
{
	Super::BeginPlay();
	

	OnActorBeginOverlap.AddDynamic(this, &ATeleporterActor::OnOverlapBegin);

}

void ATeleporterActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void ATeleporterActor::TeleportToTarget(AActor * Actor)
{

	USceneComponent* TargetSpawn = Cast<USceneComponent>(Target->GetDefaultSubobjectByName("Spawn"));

	UGameplayStatics::PlaySound2D(this, TeleportSound);

	Actor->SetActorLocation(TargetSpawn->GetComponentLocation());

}

void ATeleporterActor::OnOverlapBegin(AActor * TeleporterActor, AActor * OtherActor)
{

	if (OtherActor->ActorHasTag("Pacman")) {
	
		GetWorldTimerManager().SetTimerForNextTick([OtherActor, this]() { TeleportToTarget(OtherActor); });

	}

}

