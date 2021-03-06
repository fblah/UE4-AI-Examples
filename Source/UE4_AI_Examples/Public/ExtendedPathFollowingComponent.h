// © Ajit D'Monte

#pragma once

#include "CoreMinimal.h"
#include "Navigation/PathFollowingComponent.h"

#include "NavigationSystem.h"
#include "AI/NavigationSystemBase.h"
#include "Engine/Engine.h"
#include "Runtime/Engine/Classes/Engine/World.h"
#include "NavMesh/RecastNavMesh.h"

#include "ExtendedPathFollowingComponent.generated.h"

class UNavMovementComponent;
class UCharacterMovementComponent;

DECLARE_LOG_CATEGORY_EXTERN(ExtendedPathFollowing, Log, All);

/**
 * 
 */
UCLASS()
class UE4_AI_EXAMPLES_API UExtendedPathFollowingComponent : public UPathFollowingComponent
{
	GENERATED_BODY()
protected:
	
public:	

	/** follow current path segment */
	virtual void FollowPathSegment(float DeltaTime) override;

	//Choose Which Nav Data To Use
	FORCEINLINE const ANavigationData* GetNavData() const
	{
		const FNavAgentProperties& AgentProperties = MovementComp->GetNavAgentPropertiesRef();
		UNavigationSystemV1* NavSys = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld());
		const ANavigationData* NavData = NavSys->GetNavDataForProps(AgentProperties);
		
		if (NavData == NULL)
		{			
			NavData = FNavigationSystem::GetCurrent<UNavigationSystemV1>(GetWorld())->GetDefaultNavDataInstance();
		}

		return NavData;
	}

	//VERY IMPORTANT FOR CRASH PROTECTION !!!!!
	FORCEINLINE bool TileIsValid(const ARecastNavMesh* NavMesh, int32 TileIndex) const
	{
		if (!NavMesh) return false;
		//~~~~~~~~~~~~~~
		const FBox TileBounds = NavMesh->GetNavMeshTileBounds(TileIndex);

		return TileBounds.IsValid != 0;
	}

	//add this to your custom path follow component!
	bool NavPoly_GetAllPolys(TArray<NavNodeRef>& Polys);

};
