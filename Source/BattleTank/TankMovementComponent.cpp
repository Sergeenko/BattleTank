// Fill out your copyright notice in the Description page of Project Settings.


#include "TankMovementComponent.h"
#include "TankTrack.h"

void UTankMovementComponent::Initialise(UTankTrack* LeftTrackToSet, UTankTrack* RightTrackToSet)
{
	LeftTrack = LeftTrackToSet;
	RightTrack = RightTrackToSet;
	if (LeftTrack && RightTrack)
	{
		LeftTrack->SetNotifyRigidBodyCollision(true);
		RightTrack->SetNotifyRigidBodyCollision(true);
	}
}

void UTankMovementComponent::IntendMoveAlong(float Throw)
{
	if (!LeftTrack && !RightTrack) { return; }
	LeftTrack->SetThrottle(Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::IntendTurnSide(float Throw)
{

	if (!LeftTrack && !RightTrack) { return; }
	LeftTrack->SetThrottle(-Throw);
	RightTrack->SetThrottle(Throw);
}

void UTankMovementComponent::RequestDirectMove(const FVector& MoveVelocity, bool bForceMaxSpeed)
{
	auto TankForwardVector = GetOwner()->GetActorForwardVector().GetSafeNormal();
	auto MoveVector = MoveVelocity.GetSafeNormal();

	auto DirectThrow = FVector::DotProduct(TankForwardVector, MoveVector);
	IntendMoveAlong(DirectThrow);

	auto SideThrow = FVector::CrossProduct(TankForwardVector, MoveVector).Z;
	IntendTurnSide(SideThrow);
}
