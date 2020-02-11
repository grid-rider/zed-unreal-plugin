//======= Copyright (c) Stereolabs Corporation, All rights reserved. ===============

#pragma once

#include "Stereolabs/Public/Core/StereolabsTextureBatch.h"
#include "Stereolabs/Public/Core/StereolabsTexture.h"
#include "Engine/DirectionalLight.h"

#include "EnvironmentalLightingManager.generated.h"

/*
 * Manager for environmental lighting
 */
UCLASS(Category = "Stereolabs|EnvironmentalLighting")
class ENVIRONMENTALLIGHTING_API AEnvironmentalLightingManager : public AActor
{
	GENERATED_BODY()

public:
	AEnvironmentalLightingManager();

protected:
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaSeconds) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;


private:
	UFUNCTION()
	void ToggleTick();

	/*
	 * Callback updating texture
	 */
	void GrabCallback(ESlErrorCode ErrorCode, const FSlTimestamp& Timestamp);

public:
	/** Current directional light using environmental lighting */
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	ADirectionalLight* Light;

private:
	/** Batch for the CPU texture */
	UPROPERTY()
	USlTextureBatch* Batch;

	/** CPU left texture */
	UPROPERTY()
	USlTexture* LeftEyeTexture;

	/** The grab delegate handle */
	FDelegateHandle GrabDelegateHandle;

	/** Lighting data*/
	FEnvironmentalLightingSettings EnvironmentalLightingSettings;

	/** Update timestamp section */
	FCriticalSection TimestampSection;
};