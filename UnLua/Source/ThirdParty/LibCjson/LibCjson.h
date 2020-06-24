// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

struct lua_State;

class LIBCJSON_API FLibCjsonModule : public IModuleInterface
{
public:

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;

	void SetupLibCjson(lua_State* L);

	static inline FLibCjsonModule& Get()
	{
		return FModuleManager::LoadModuleChecked<FLibCjsonModule>("LibCjson");
	}

	static inline bool IsAvailable()
	{
		return FModuleManager::Get().IsModuleLoaded("LibCjson");
	}

protected:

};
