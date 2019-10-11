// © Ajit D'Monte

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "AI_Extended_BPL.generated.h"

/**
 * 
 */
UCLASS()
class UE4_AI_EXAMPLES_API UAI_Extended_BPL : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintCallable, Category = "Sorting Functions")            // Expose node to blueprints using 'BlueprintCallable', 'Category' gives your function a "searchable" header category in BPs
		static void  Integer_Sort(UPARAM(ref) TArray <int32> &Array_To_Sort, bool Descending, TArray <int32> &Sorted_Array);   // 'static' so node is accessible anywhere
																																// 'UPARAM' makes argument an exposed input pin
	UFUNCTION(BlueprintCallable, Category = "Sorting Functions")                                                                //  'UPARAM(ref)' passes argument by reference
		static void  Float_Sort(UPARAM(ref) TArray <float> &Array_To_Sort, bool Descending, TArray <float> &Sorted_Array);

	UFUNCTION(BlueprintCallable, Category = "Sorting Functions")
		static void  String_Sort(UPARAM(ref) TArray <FString> &Array_To_Sort, bool Descending, TArray <FString> &Sorted_Array);

};
