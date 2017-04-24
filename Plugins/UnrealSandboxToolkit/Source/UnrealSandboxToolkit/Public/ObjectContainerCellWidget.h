// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Runtime/UMG/Public/UMG.h"
#include "Runtime/UMG/Public/UMGStyle.h"
#include "Runtime/UMG/Public/Slate/SObjectWidget.h"
#include "Runtime/UMG/Public/IUMGModule.h"
#include "Runtime/UMG/Public/Blueprint/UserWidget.h"

#include "Blueprint/UserWidget.h"
#include "ObjectContainerCellWidget.generated.h"


class UContainerComponent;

/**
 * 
 */
UCLASS()
class UNREALSANDBOXTOOLKIT_API USandboxObjectContainerCellWidget : public UUserWidget
{
	GENERATED_BODY()
	
public:	

	UPROPERTY(EditAnywhere, Category = "SandboxInventory")
	uint32 ContainerId; // 100 is current opened object, other ids is reserved for backpack, pockets, and etc

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	FLinearColor SlotBorderColor(int32 SlotId);

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	void SelectSlot(int32 SlotId);

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	UTexture2D* GetSlotTexture(int32 SlotId);

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	FString SlotGetAmountText(int32 SlotId);

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	bool SlotDrop(int32 SlotDropId, int32 SlotTargetId, AActor* SourceActor, UContainerComponent* SourceContainer);

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	bool SlotIsEmpty(int32 SlotId);

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	AActor* GetOpenedObject();

	UFUNCTION(BlueprintCallable, Category = "SandboxInventory")
	UContainerComponent* GetOpenedContainer();

protected:
	UContainerComponent* GetContainer();

};
