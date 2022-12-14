// Copyright Epic Games, Inc. All Rights Reserved.

#include "UnrealRmlUi.h"

#include "IImageWrapper.h"
#include "IImageWrapperModule.h"

#define LOCTEXT_NAMESPACE "FUnrealRmlUiModule"

void FUnrealRmlUiModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
}

void FUnrealRmlUiModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.
}

Rml::Input::KeyIdentifier FUnrealRmlUiModule::ConvertKey(FKey InKey)
{
	auto FoundKey = KeyConvertMap.Find(InKey);
	return FoundKey ? *FoundKey : Rml::Input::KeyIdentifier::KI_UNKNOWN;
}

int FUnrealRmlUiModule::GetKeyModifierState(FModifierKeysState& InState)
{
	int KeyModifier = 0;
	KeyModifier |= InState.IsControlDown()	? Rml::Input::KeyModifier::KM_CTRL		: 0;
	KeyModifier |= InState.IsShiftDown()	? Rml::Input::KeyModifier::KM_SHIFT		: 0;
	KeyModifier |= InState.IsAltDown()		? Rml::Input::KeyModifier::KM_ALT		: 0;
	KeyModifier |= InState.IsCommandDown()	? Rml::Input::KeyModifier::KM_META		: 0;
	KeyModifier |= InState.AreCapsLocked()	? Rml::Input::KeyModifier::KM_CAPSLOCK	: 0;
	return KeyModifier;
}

int FUnrealRmlUiModule::GetMouseKey(const FKey& InMouseEvent)
{
	return MouseConvertMap[InMouseEvent];
}

UTexture2D* FUnrealRmlUiModule::LoadTextureFromRaw(const uint8* InSource, FIntPoint InSize)
{
	// create texture 
	UTexture2D* Texture = UTexture2D::CreateTransient(InSize.X, InSize.Y, EPixelFormat::PF_R8G8B8A8);
	Texture->UpdateResource();

	// create region
	FUpdateTextureRegion2D* TextureRegion = new FUpdateTextureRegion2D(
		0,
		0,
		0,
		0,
		InSize.X,
		InSize.Y);

	// copy data 
	int32 Size = InSize.X * InSize.Y * 4;
	uint8* Data = new uint8[Size];
	FMemory::Memcpy(Data, InSource, Size);

	// clean up function 
	auto DataCleanup = [](uint8* Data, const FUpdateTextureRegion2D* UpdateRegion)
	{
		delete Data;
		delete UpdateRegion;
	};

	// copy region in RHI thread 
	Texture->UpdateTextureRegions(0, 1u, TextureRegion, 4 * InSize.X, 4, Data, DataCleanup);

	return Texture;
}

UTexture2D* FUnrealRmlUiModule::LoadTextureFromFile(const FString& InFilePath)
{
	// read file 
	TArray64<uint8>* Data = new TArray64<uint8>();
	FFileHelper::LoadFileToArray(*Data, *InFilePath);
	if (Data->Num() == 0) return nullptr;

	// get image format 
	static const FName MODULE_IMAGE_WRAPPER("ImageWrapper");
	IImageWrapperModule& ImageWrapperModule = FModuleManager::LoadModuleChecked<IImageWrapperModule>(MODULE_IMAGE_WRAPPER);
	EImageFormat ImageFormat = ImageWrapperModule.DetectImageFormat(Data->GetData(), Data->Num());
	if (ImageFormat == EImageFormat::Invalid) return nullptr;

	// decode image 
	FIntPoint Size;
	TSharedPtr<IImageWrapper> ImageWrapper = ImageWrapperModule.CreateImageWrapper(ImageFormat);
	if (!ImageWrapper->SetCompressed(Data->GetData(), Data->Num())) return nullptr;
	Size.X = ImageWrapper->GetWidth();
	Size.Y = ImageWrapper->GetHeight();
	ImageWrapper->GetRaw(ERGBFormat::RGBA, 8, *Data);

	// create texture 
	UTexture2D* LoadedTexture = UTexture2D::CreateTransient(Size.X, Size.Y, EPixelFormat::PF_R8G8B8A8);
	LoadedTexture->UpdateResource();

	// set up region 
	FUpdateTextureRegion2D* TextureRegion = new FUpdateTextureRegion2D(
		0,
		0,
		0,
		0,
		Size.X,
		Size.Y);

	// cleanup data 
	auto DataCleanup = [FileData=Data](uint8* Data, const FUpdateTextureRegion2D* UpdateRegion)
	{
		delete FileData;
		delete UpdateRegion;
	};
	LoadedTexture->UpdateTextureRegions(0, 1u, TextureRegion, 4 * Size.X, 4, Data->GetData(), DataCleanup);

	return LoadedTexture;
}

UTexture2D* FUnrealRmlUiModule::LoadTextureFromAsset(const FString& InAssetPath, UObject* InOuter)
{
	UObject* LoadedObj = StaticLoadObject(UObject::StaticClass(), InOuter, *InAssetPath);
	return LoadedObj ? (UTexture2D*)LoadedObj : nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FUnrealRmlUiModule, UnrealRmlUi)

DEFINE_LOG_CATEGORY(LogRml);