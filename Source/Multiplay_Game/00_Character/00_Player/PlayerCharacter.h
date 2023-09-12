// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Multiplay_Game/00_Character/BaseCharacter.h"

#include "InputActionValue.h"

#include "PlayerCharacter.generated.h"

/**
 * �÷��̾� ĳ���Ͱ� ����� Ŭ���� �Դϴ�
 */

class UInputComponent;
class USkeletalMeshComponent;
class USceneComponent;
class UCameraComponent;
class UAnimMontage;
class USoundBase;

UCLASS(config = Game)
class MULTIPLAY_GAME_API APlayerCharacter : public ABaseCharacter
{
	GENERATED_BODY()
	
	/** �÷��̾� ���Ը� ���̴� 1��Ī �Ž� */
	UPROPERTY(VisibleDefaultsOnly, Category = Mesh)
	USkeletalMeshComponent* Mesh1P;

	/** 1��Ī ī�޶� ������Ʈ */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* FirstPersonCameraComponent;

	/** 3��Ī ī�޶� ������Ʈ */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Camera, meta = (AllowPrivateAccess = "true"))
	UCameraComponent* ThirdPersonCameraComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = MovementComponent, meta = (AllowPrivateAccess = "true"))
	UPawnMovementComponent* MovementComponent;

	/** MappingContext */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputMappingContext* DefaultMappingContext;

	/** Jump ��ǲ �׼� */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* JumpAction;

	/** Move ��ǲ �׼� */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* MoveAction;

	/** Crouch ��ǲ �׼� */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* CrouchAction;

	/** Look ��ǲ �׼� */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Input, meta = (AllowPrivateAccess = "true"))
	class UInputAction* LookAction;

public:
	APlayerCharacter();

protected:
	virtual void BeginPlay();

protected:
	/** Called for movement input */
	void Move(const FInputActionValue& Value);
	/** Called for looking input */
	void Look(const FInputActionValue& Value);

protected:
	virtual void SetupPlayerInputComponent(UInputComponent* PlayerInputComponent) override;

public:
	/** Mesh1P ���� */
	USkeletalMeshComponent* GetMesh1P() const { return Mesh1P; }

	/** FirstPersonCameraComponent ���� */
	UCameraComponent* GetFirstPersonCameraComponent() const { return FirstPersonCameraComponent; }

	/** ThirdPersonCameraComponent ���� */
	UCameraComponent* GetThirdPersonCameraComponent() const { return ThirdPersonCameraComponent; }
};
