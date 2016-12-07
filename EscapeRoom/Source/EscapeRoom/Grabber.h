// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/ActorComponent.h"
#include "Grabber.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class ESCAPEROOM_API UGrabber : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UGrabber();

	// Called when the game starts
	virtual void BeginPlay() override;
	
	// Called every frame
	virtual void TickComponent( float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction ) override;

private:
	float Reach = 100.0f;
		
	UPhysicsHandleComponent* PhysicsHandle = nullptr;

	UInputComponent* InputComponent = nullptr;

	//ray ast and grab what's in reach
	void Grab();

	//used when the grab button is released
	void Release();

	//find the (assumed) attached physics handle component
	void FindPhysicsHandleComponent();

	//find the (assumed) attached input component
	void SetupInputComponent();

	// return hit for first physics body in reach
	const FHitResult GetFirstPhysicsBodyInReach();
};
