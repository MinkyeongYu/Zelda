// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SlateBasics.h"
#include "SlateExtras.h"

/**
 * 
 */
class SMainMenuWidget : public SCompoundWidget //SCompoundWidget/Slate Widget is not UObjects. which don't use GC.
{
public:
	/**Declare Variable Argument, System to parse information to the HUD*/
	SLATE_BEGIN_ARGS(SMainMenuWidget) {}
	// Type, name. 
	SLATE_ARGUMENT(TWeakObjectPtr<class AMenuHUD>, OwningHUD)
	//end
	SLATE_END_ARGS()

	/** every widget neesds a construction function*/
	void Construct(const FArguments& InArgs);

	FReply OnPlayClicked() const;
	FReply OnQuitClicked() const;


	/**The HUD that created this widget, perform validation, manage memory*/
	TWeakObjectPtr<class AMenuHUD> OwningHUD;

	virtual bool SupportsKeyboardFocus() const override { return true; };
};
