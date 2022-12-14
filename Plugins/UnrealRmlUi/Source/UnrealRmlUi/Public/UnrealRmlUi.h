// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "RmlUiFwd.h"

extern TMap<FKey, Rml::Input::KeyIdentifier> KeyConvertMap;
extern TMap<FKey, int> MouseConvertMap;


class FUnrealRmlUiModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;




	static Rml::Input::KeyIdentifier ConvertKey(FKey InKey);
	static int GetKeyModifierState(FModifierKeysState& InState);
	static int GetMouseKey(const FKey& InMouseEvent);
	static UTexture2D* LoadTextureFromRaw(const uint8* InSource, FIntPoint InSize);
	static UTexture2D* LoadTextureFromFile(const FString& InFilePath);
	static UTexture2D* LoadTextureFromAsset(const FString& InAssetPath, UObject* InOuter = GetTransientPackage());

};

DECLARE_LOG_CATEGORY_EXTERN(LogRml, Log, All);