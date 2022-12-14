// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Widgets/SCompoundWidget.h"
#include "RmlUiFwd.h"

/**
 * 
 */
class UNREALRMLUI_API SRmlWidget : public SCompoundWidget
{
public:
	SLATE_BEGIN_ARGS(SRmlWidget)
		: _InitContext(nullptr)
		, _InitEnableRml(true)
	{}
		SLATE_ARGUMENT(Rml::Context*, InitContext)
		SLATE_ARGUMENT(bool, InitEnableRml)
	SLATE_END_ARGS()
	

	/** Constructs this widget with InArgs */
	void Construct(const FArguments& InArgs);


	void Context(Rml::Context* InContext) { BoundContext = InContext; }
	Rml::Context* Context() const { return BoundContext; }
protected:
	// ~Begin SWidget API
	virtual void Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime) override;
	virtual int32 OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect, FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle, bool bParentEnabled) const override;
	virtual FVector2D ComputeDesiredSize(float) const override { return FVector2D::ZeroVector; }
	
	virtual FReply OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;
	virtual FReply OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent) override;

	virtual FReply OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent) override;

	virtual FReply OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;
	virtual FReply OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent) override;

	virtual FCursorReply OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const override;

	virtual bool SupportsKeyboardFocus() const override { return true; }
	// ~End SWidget API
private:
	bool          bEnableRml;
	Rml::Context* BoundContext;
};
