// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "CubeInstanceActor.generated.h"

UCLASS()
class UE4BOILDS_API ACubeInstanceActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ACubeInstanceActor();

	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float Range;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float SeparationForceScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float CohesionForceScaler;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		float AlignForceScaler;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		TArray<AActor*> actorList;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	virtual void BeginDestroy() override;
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	//set velocity and position render target
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		class UTextureRenderTarget2D* VelocityRT;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = ComputeShaderFlocking)
		class UTextureRenderTarget2D* PositionRT;

private: 
	//vairiables that update velocity and positions
	TArray<FFloat16Color> posColorBuffer16;
	TArray<FFloat16Color> velColorBuffer16;
	class FTextureRenderTarget2DResource* posTextureResource;
	class FTextureRenderTarget2DResource* velTextureResource;




};
