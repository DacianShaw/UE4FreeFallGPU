// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "InstanceRootActor.generated.h"

UCLASS()
class UE4BOILDS_API AInstanceRootActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AInstanceRootActor();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	class UMaterialInstanceDynamic* DrawMatInstance;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flocking")
		class UInstancedStaticMeshComponent* InstancedComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Flocking")
		class UStaticMeshComponent* rootStaticMesh;


	UFUNCTION(BlueprintCallable)
		void InitInstances(int instatnceNum);


	UFUNCTION(BlueprintCallable)
		int GetInstanceCount();

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Flocking")
		class UMaterial* DrawMat;



};
