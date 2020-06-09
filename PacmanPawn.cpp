#include "PacmanPawn.h"

#include "Foodie.h"

APacmanPawn::APacmanPawn()
{
	PrimaryActorTick.bCanEverTick = true;
}

void APacmanPawn::BeginPlay()
{
	Super::BeginPlay();

	OnActorBeginOverlap.AddDynamic(this, &APacmanPawn::OnOverlapBegin);
}

void APacmanPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (!Frozen) {
		
		AddMovementInput(GetActorForwardVector());
	}

}

void APacmanPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
}

void APacmanPawn::SetDirection(const FVector Direction)
{
	if (Direction == FVector::UpVector) {

		SetActorRotation(FRotator(0, 270, 0));

	} else if (Direction == FVector::DownVector) {

		SetActorRotation(FRotator(0, 90, 0));

	}
	else if (Direction == FVector::RightVector) {

		SetActorRotation(FRotator(0, 0, 0));

	}
	else if (Direction == FVector::LeftVector) {

		SetActorRotation(FRotator(0, 180, 180));
	}
}

void APacmanPawn::OnOverlapBegin(AActor * PlayerActor, AActor * OtherActor)
{

	if (OtherActor->ActorHasTag("Foodie.Regular")) {
	
		Cast<AFoodie>(OtherActor)->Consume();
	}

	if (OtherActor->ActorHasTag("Foodie.PowerUp")) {

		Cast<AFoodie>(OtherActor)->Consume();
	}
}

