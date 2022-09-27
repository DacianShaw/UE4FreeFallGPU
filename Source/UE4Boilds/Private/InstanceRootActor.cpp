// Fill out your copyright notice in the Description page of Project Settings.


#include "InstanceRootActor.h"
#include "Components/InstancedStaticMeshComponent.h"
#include "Components/StaticMeshComponent.h"

// Sets default values
AInstanceRootActor::AInstanceRootActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//this staticmeshComponent act as the bound of the UInstancedStaticMeshComponent ot avoid blink
	rootStaticMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("rootStaticMesh"));
	RootComponent = rootStaticMesh;

	InstancedComponent = CreateDefaultSubobject<UInstancedStaticMeshComponent>(TEXT("UInstancedStaticMeshComponent"));
	InstancedComponent->SetupAttachment(rootStaticMesh);

	//set the number of custom data needed
	InstancedComponent->NumCustomDataFloats = 1;
	InstancedComponent->SetCollisionEnabled(ECollisionEnabled::NoCollision);

}

// Called when the game starts or when spawned
void AInstanceRootActor::BeginPlay()
{
	Super::BeginPlay();
	UE_LOG(LogTemp, Warning, TEXT("InitInstances!"));
	//create the material used to draw instance
	if (DrawMat != nullptr)
	{
		DrawMatInstance = InstancedComponent->CreateDynamicMaterialInstance(0, DrawMat);
		InitInstances(1000);
		UE_LOG(LogTemp, Warning, TEXT("InitInstances!"));
	}
}

// Called every frame
void AInstanceRootActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AInstanceRootActor::InitInstances(int instatnceNum) {

	if (instatnceNum <= 1)
	{
		instatnceNum = 1;
	}
	else if (instatnceNum > 2000)
	{
		instatnceNum = 2000;
	}


	for (int i = 0; i < instatnceNum; i++) {
		//initialize a transform;
		FTransform t = FTransform();
		InstancedComponent->AddInstance(t);
		InstancedComponent->SetCustomDataValue(i, 0, i);
		UE_LOG(LogTemp, Warning, TEXT("AddInstance %d"), i);

	}
}


int AInstanceRootActor::GetInstanceCount()
{
	if (InstancedComponent != nullptr)
	{
		return InstancedComponent->GetInstanceCount();
	}
	return 0;
}