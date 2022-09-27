// Fill out your copyright notice in the Description page of Project Settings.


#include "CubeInstanceActor.h"
#include "FlockingComputeShader.h"

// Sets default values
ACubeInstanceActor::ACubeInstanceActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	SeparationForceScaler = 1.0;
	CohesionForceScaler = 1.0;
	AlignForceScaler = 1.0;

}

// Called when the game starts or when spawned
void ACubeInstanceActor::BeginPlay()
{
	Super::BeginPlay();

	//bind render target resources;
	if (PositionRT != NULL) posTextureResource = (FTextureRenderTarget2DResource*)PositionRT->Resource;
	if (VelocityRT != NULL) velTextureResource = (FTextureRenderTarget2DResource*)VelocityRT->Resource;

	//invoke compute shader;
	FFlockingComputeShader::Get().BeginRendering();
	
}

void ACubeInstanceActor::BeginDestroy()
{
	FFlockingComputeShader::Get().EndRendering();
	Super::BeginDestroy();
}



// Called every frame
void ACubeInstanceActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
	FShaderUsageExampleParameters DrawParameters(VelocityRT, PositionRT);
	{
		DrawParameters.Range = Range;
		DrawParameters.AlignScaler = AlignForceScaler;
		DrawParameters.CohesionScaler = CohesionForceScaler;
		DrawParameters.SeparationScaler = SeparationForceScaler;
	}
	FFlockingComputeShader::Get().UpdateParameters(DrawParameters);
	

	if (posTextureResource != NULL) {
		if (posTextureResource->ReadFloat16Pixels(posColorBuffer16) && velTextureResource->ReadFloat16Pixels(velColorBuffer16)) {
			for (int i = 0; i < actorList.Num() && i < posColorBuffer16.Num(); i++)
			{
				float x = posColorBuffer16[i].R.GetFloat();
				float y = posColorBuffer16[i].G.GetFloat();
				float z = posColorBuffer16[i].B.GetFloat();
				//UE_LOG(LogTemp, Warning, TEXT("f is  %f"), f);
				//SetActorLocation(FVector(x, y, z));//??? 


				AActor* p = actorList[i];

				//bottle neck, it is slow!
				p->SetActorLocation(FVector(x, y, z));
			}


		}

	}
}

