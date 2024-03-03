// To make text Literal, Use LOCTEXT macro.

#include "SMainMenuWidget.h"
#include "MenuHUD.h"
#include "GameFramework/PlayerController.h"
#include "Kismet/GameplayStatics.h"

#define LOCTEXT_NAMESPACE "MainMenu"


void SMainMenuWidget::Construct(const FArguments& InArgs)
{
	OwningHUD = InArgs._OwningHUD;
	
	// Content Padding
	const FMargin ContentPadding = FMargin(600.f, 200.f);
	const FMargin ButtonPadding = FMargin(50.f);

	const FText TItleText = LOCTEXT("GameTitle", "Lost Zelda");
	const FText PlayText = LOCTEXT("PlayGame", "Play");
	const FText SettingsText = LOCTEXT("Settings", "Settings");
	const FText QuitText = LOCTEXT("QuitGame", "Quit Game");

	FSlateFontInfo ButtonTextStyle = FCoreStyle::Get().GetFontStyle("EmbossedText");
	ButtonTextStyle.Size = 40.f;

	FSlateFontInfo TitleTextStyle = ButtonTextStyle;
	TitleTextStyle.Size = 60.f;


	ChildSlot
		[
			/** Add and Align Overlay */
			SNew(SOverlay)
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				[
					SNew(SImage)
						.ColorAndOpacity(FColor::Black)
					
				]
				/** Add and Align Overlay */
				+ SOverlay::Slot()
				.HAlign(HAlign_Fill)
				.VAlign(VAlign_Fill)
				.Padding(ContentPadding)
				[
					SNew(SVerticalBox)
						//Title text
						+ SVerticalBox::Slot()
						[
							SNew(STextBlock)
								.Font(TitleTextStyle)
								.Text(TItleText)
								.Justification(ETextJustify::Center)
						]

						// Play Button
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SButton)
								.OnClicked(this, &SMainMenuWidget::OnPlayClicked)
								[
									SNew(STextBlock)
										.Font(ButtonTextStyle)
										.Text(PlayText)
										.Justification(ETextJustify::Center)
								]
						]

						// Settings Button
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SButton)
								[
									SNew(STextBlock)
										.Font(ButtonTextStyle)
										.Text(SettingsText)
										.Justification(ETextJustify::Center)
								]
						]

						// Quit Button
						+ SVerticalBox::Slot()
						.Padding(ButtonPadding)
						.HAlign(HAlign_Center)
						.VAlign(VAlign_Center)
						[
							SNew(SButton)
								.OnClicked(this, &SMainMenuWidget::OnQuitClicked)
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


FReply SMainMenuWidget::OnPlayClicked() const
{
	UWorld* World = GEngine->GetWorldContextFromGameViewport(GEngine->GameViewport)->World();
	UGameplayStatics::OpenLevel(World, TEXT("/Game/Forest/Map/Map_01"));

	return FReply::Handled();
}
FReply SMainMenuWidget::OnQuitClicked() const
{
	if (OwningHUD.IsValid())
	{
		if (APlayerController* PC = OwningHUD->PlayerOwner)
		{
			PC->ConsoleCommand("quit");
		}
	}
	// like function return handled
	return FReply::Handled();
}
// Unset the namespace definition
#undef LOCTEXT_NAMESPACE