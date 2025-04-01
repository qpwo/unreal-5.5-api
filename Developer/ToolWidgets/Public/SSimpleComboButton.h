// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Framework/SlateDelegates.h"
#include "SActionButton.h"
#include "Widgets/DeclarativeSyntaxSupport.h"
#include "Widgets/Input/SComboButton.h"
#include "Widgets/SCompoundWidget.h"

class TOOLWIDGETS_API SSimpleComboButton
	: public SComboButton
	, public IActionButton
{
public:
	SLATE_BEGIN_ARGS(SSimpleComboButton)
		: _HasDownArrow(false)
		, _UsesSmallText(false)
	{}
		/** The text to display in the button. */
		SLATE_ATTRIBUTE(FText, Text)

		SLATE_ATTRIBUTE(const FSlateBrush*, Icon)
	
		/** The static menu content widget. */
		SLATE_NAMED_SLOT(FArguments, MenuContent)

		SLATE_EVENT(FOnGetContent, OnGetMenuContent)
		SLATE_EVENT(FOnComboBoxOpened, OnComboBoxOpened)
		SLATE_EVENT(FOnIsOpenChanged, OnMenuOpenChanged)
		SLATE_ARGUMENT(bool, HasDownArrow)
		SLATE_ARGUMENT(bool, UsesSmallText)
	SLATE_END_ARGS()

	SSimpleComboButton() = default;

	void Construct(const FArguments& InArgs);

	//~ Begin IActionButton
	virtual void SetMenuContentWidgetToFocus(TWeakPtr<SWidget> InWidget) override;
	virtual void SetIsMenuOpen(bool bInIsOpen, bool bInIsFocused) override;
	//~ End IActionButton
};
