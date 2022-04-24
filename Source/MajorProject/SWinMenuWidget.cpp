// Fill out your copyright notice in the Description page of Project Settings.


#include "SWinMenuWidget.h"
#include "MenuHUD.h"
#include "GameFramework/PlayerController.h"
#include "MenuPlayerController.h"

#define LOCTEXT_NAMESPACE "MainMenu"

void SWinMenuWidget::Construct(const FArguments & InArgs)
{
	bCanSupportFocus = true;
	
	OwningHUD = InArgs._OwningHUD;

	const FMargin ContentPadding = FMargin(500.f, 300.f);
	const FMargin ButtonPadding = FMargin(10.f);

	const FText TitleText = LOCTEXT("GameTitle", "Victory!");
	const FText PlayText = LOCTEXT("PlayGame", "Next Level");
	const FText SettingsText = LOCTEXT("Settings", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;

	ChildSlot
		[
			SNew(SOverlay)
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			//[
			//	SNew(SImage)
			//	.ColorAndOpacity(FColor::Black)
			//]
			+ SOverlay::Slot()
			.HAlign(HAlign_Fill)
			.VAlign(VAlign_Fill)
			.Padding(ContentPadding)
			[
				//Title text
				SNew(SVerticalBox)
				+ SVerticalBox::Slot()
				[
					SNew(STextBlock)
					.Font(TitleTextStyle)
					.Text(TitleText)
					.Justification(ETextJustify::Center)
				]

				//Play button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SWinMenuWidget::OnPlayClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(PlayText)
						.Justification(ETextJustify::Center)
					]
				]

				//Settings button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(SettingsText)
						.Justification(ETextJustify::Center)
					]
				]

				//Quit button
				+ SVerticalBox::Slot()
				.Padding(ButtonPadding)
				[
					SNew(SButton)
					.OnClicked(this, &SWinMenuWidget::OnQuitClicked)
					[
						SNew(STextBlock)
						.Font(ButtonTextStyle)
						.Text(QuitText)
						.Justification(ETextJustify::Center)
					]
				]
			]
		];

}

FReply SWinMenuWidget::OnPlayClicked() const
{
	/*if (OwningHUD.IsValid())
	{
		OwningHUD->RemoveWinMenu();
		for (TObjectIterator<AMenuPlayerController> Itr; Itr; ++Itr)
		{
			if (Itr->IsA(AMenuPlayerController::StaticClass()))
			{
				AMenuPlayerController* actorClass = *Itr;
				actorClass->FinalLevel();
			}
		}
	}*/
	
	return FReply::Handled();
}

FReply SWinMenuWidget::OnQuitClicked() const
{
	/*if (OwningHUD.IsValid())
	{
		if (APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
*/
	return FReply::Handled();
}

#undef LOCTEXT_NAMESPACE
