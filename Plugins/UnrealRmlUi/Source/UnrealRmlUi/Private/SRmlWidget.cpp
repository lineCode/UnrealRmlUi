// Fill out your copyright notice in the Description page of Project Settings.


#include "SRmlWidget.h"
#include "UnrealRmlUi.h"
#include "SlateOptMacros.h"
#include "RmlSystemInterface.h"

BEGIN_SLATE_FUNCTION_BUILD_OPTIMIZATION

void SRmlWidget::Construct(const FArguments& InArgs)
{
	/*
	ChildSlot
	[
		// Populate the widget
	];
	*/
}

void SRmlWidget::Tick(const FGeometry& AllottedGeometry, const double InCurrentTime, const float InDeltaTime)
{
	SCompoundWidget::Tick(AllottedGeometry, InCurrentTime, InDeltaTime);
}

int32 SRmlWidget::OnPaint(const FPaintArgs& Args, const FGeometry& AllottedGeometry, const FSlateRect& MyCullingRect,
	FSlateWindowElementList& OutDrawElements, int32 LayerId, const FWidgetStyle& InWidgetStyle,
	bool bParentEnabled) const
{
	return SCompoundWidget::OnPaint(Args, AllottedGeometry, MyCullingRect, OutDrawElements, LayerId, InWidgetStyle,
	                                bParentEnabled);
}

FReply SRmlWidget::OnKeyDown(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();
	// reroute key event 
	auto ModifierState = InKeyEvent.GetModifierKeys();
	return BoundContext->ProcessKeyDown(FUnrealRmlUiModule::ConvertKey(InKeyEvent.GetKey()), FUnrealRmlUiModule::GetKeyModifierState(ModifierState)) ? FReply::Unhandled() : FReply::Handled();
}

FReply SRmlWidget::OnKeyUp(const FGeometry& MyGeometry, const FKeyEvent& InKeyEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();
	// reroute key event 
	auto ModifierState = InKeyEvent.GetModifierKeys();
	return BoundContext->ProcessKeyUp(FUnrealRmlUiModule::ConvertKey(InKeyEvent.GetKey()), FUnrealRmlUiModule::GetKeyModifierState(ModifierState)) ? FReply::Unhandled() : FReply::Handled();
}

FReply SRmlWidget::OnKeyChar(const FGeometry& MyGeometry, const FCharacterEvent& InCharacterEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();

	// get input character  
	TCHAR Ch = InCharacterEvent.GetCharacter();

	// process windows new line 
	if (Ch == TEXT('\r'))
	{
		return BoundContext->ProcessTextInput(Rml::Character(TEXT('\n'))) ? FReply::Unhandled() : FReply::Handled();
	}
	
	// filter control character input 
	if (!FChar::IsPrint(Ch)) return FReply::Unhandled();
	
	// reroute Character input
	return BoundContext->ProcessTextInput(Rml::Character(Ch)) ? FReply::Unhandled() : FReply::Handled();
}

FReply SRmlWidget::OnMouseMove(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();

	// get screen pos 
	auto MousePos = MouseEvent.GetScreenSpacePosition();

	// screen space -> rml local space 
	MousePos = MyGeometry.GetAccumulatedRenderTransform().Inverse().TransformPoint(MousePos);

	// reroute ANIS input 
	auto ModifierState = MouseEvent.GetModifierKeys();
	return BoundContext->ProcessMouseMove(MousePos.X, MousePos.Y, FUnrealRmlUiModule::GetKeyModifierState(ModifierState)) ? FReply::Unhandled() : FReply::Handled();
}

FReply SRmlWidget::OnMouseButtonDown(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();

	// reroute mouse input 
	auto ModifierState = MouseEvent.GetModifierKeys();
	return BoundContext->ProcessMouseButtonDown(FUnrealRmlUiModule::GetMouseKey(MouseEvent.GetEffectingButton()), FUnrealRmlUiModule::GetKeyModifierState(ModifierState)) ? FReply::Unhandled() : FReply::Handled();
}

FReply SRmlWidget::OnMouseButtonUp(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();

	// reroute mouse input 
	auto ModifierState = MouseEvent.GetModifierKeys();
	return BoundContext->ProcessMouseButtonUp(FUnrealRmlUiModule::GetMouseKey(MouseEvent.GetEffectingButton()), FUnrealRmlUiModule::GetKeyModifierState(ModifierState)) ? FReply::Unhandled() : FReply::Handled();
}

FReply SRmlWidget::OnMouseWheel(const FGeometry& MyGeometry, const FPointerEvent& MouseEvent)
{
	if (!bEnableRml || !BoundContext) return FReply::Unhandled();

	// reroute mouse input 
	auto ModifierState = MouseEvent.GetModifierKeys();
	return BoundContext->ProcessMouseWheel(-MouseEvent.GetWheelDelta(), FUnrealRmlUiModule::GetKeyModifierState(ModifierState)) ? FReply::Unhandled() : FReply::Handled();
}

FCursorReply SRmlWidget::OnCursorQuery(const FGeometry& MyGeometry, const FPointerEvent& CursorEvent) const
{
	if (!bEnableRml || !BoundContext) return FCursorReply::Unhandled();

	// find interface 
	FRmlSystemInterface* SystemInterface = (FRmlSystemInterface*)Rml::GetSystemInterface();

	// return cursor style 
	return FCursorReply::Cursor(SystemInterface->CachedCursorState());
}

END_SLATE_FUNCTION_BUILD_OPTIMIZATION
