#pragma once

// UE4
#include "Runtime/Engine/Classes/Components/StaticMeshComponent.h"

// Ascentroid
#include "AscMapKit/Public/Fan/AscMapKitFanPropertiesStruct.h"
#include "Components/ArrowComponent.h"

// Generated
#include "AscMapKitFanActor.generated.h"

UCLASS(HideCategories=("Activation", "Actor", "Asset User Data", "Collision", "Cooking", "HLOD", "Input", "LOD", "Lighting", "Mobile", "Physics", "Rendering", "Replication", "Sprite", "Tags", "Virtual Texture"))
class ASCMAPKIT_API AAscMapKitFanActor : public AActor
{
    GENERATED_BODY()

public:
    AAscMapKitFanActor();

    // Edit the majority of the map kit actor properties here.
    UPROPERTY(EditAnywhere, BlueprintReadWrite, SaveGame, Category="Ascentroid")
    FAscMapKitFanPropertiesStruct MapKit;

    UPROPERTY()
    USceneComponent *EmptyRootComponent;

    UPROPERTY()
    UArrowComponent *ArrowComponent; // todo: need for facing direction

    UPROPERTY()
    UStaticMeshComponent *StaticMeshComponent;

    UFUNCTION()
    void OnConstruction(const FTransform &Transform) override;

    UFUNCTION()
    void BeginPlay() override;

#if WITH_EDITOR
    virtual void PostEditChangeProperty(struct FPropertyChangedEvent &PropertyChangedEvent) override;

    void EditorUpdateFanType(EAscMapKitFanTypeEnum FanType);
#endif

private:
    UPROPERTY()
    UStaticMesh *Animated20x20mBasic001StaticMesh;
};