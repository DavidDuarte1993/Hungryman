#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "PacmanPawn.generated.h"

UCLASS()
class PACMAN_API APacmanPawn : public APawn
{
	GENERATED_BODY()

public:
	APacmanPawn();

protected:
	virtual void BeginPlay() override;

public:	
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:

	UPROPERTY(BlueprintReadOnly)
	bool Frozen = true;

public:

	void SetDirection(const FVector Direction);
	bool IsFrozen() { return Frozen; }

	UFUNCTION(BlueprintCallable)
		void SetFrozen(bool Value) { Frozen = Value; }

private:

	UFUNCTION()
		void OnOverlapBegin(AActor* PlayerActor, AActor* OtherActor);

};
