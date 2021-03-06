// Fill out your copyright notice in the Description page of Project Settings.


#include "LobbyGS.h"
#include "LobbyPC.h"
#include "UI/LobbyWidgetBase.h"
#include "Kismet/GameplayStatics.h"
#include "Net/UnrealNetwork.h"
#include "UI/TeamSlot.h"

void ALobbyGS::OnRepConnectCount()
{
	ALobbyPC* PC = Cast<ALobbyPC>(UGameplayStatics::GetPlayerController(GetWorld(), 0));
	if (PC && PC->LobbyWidgetObject) {
		PC->LobbyWidgetObject->SetConnectCount(ConnectCount);
	}
}


void ALobbyGS::GetLifetimeReplicatedProps(TArray<FLifetimeProperty>& OutLifetimeProps) const
{
	Super::GetLifetimeReplicatedProps(OutLifetimeProps);

	DOREPLIFETIME(ALobbyGS, ConnectCount);
}
