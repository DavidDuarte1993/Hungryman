#include "Foodie.h"

#include "Kismet/GameplayStatics.h"
#include "Sound/SoundCue.h"

AFoodie::AFoodie()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AFoodie::BeginPlay()
{
	Super::BeginPlay();	
}

void AFoodie::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AFoodie::Consume()
{
	UGameplayStatics::PlaySound2D(this, ConsumptionSound);
	FoodieEatenEvent.Broadcast(FoodieType);
	Destroy();
}

