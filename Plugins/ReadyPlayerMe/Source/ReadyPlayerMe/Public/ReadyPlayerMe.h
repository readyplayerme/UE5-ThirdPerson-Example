// Copyright © 2021++ Ready Player Me

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FReadyPlayerMeModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};
