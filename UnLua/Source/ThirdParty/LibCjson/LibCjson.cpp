// Fill out your copyright notice in the Description page of Project Settings.
#include "LibCjson.h"

#include "lua.hpp"
//#include "fpconv.h"
//#include "strbuf.h"
//#include "fpconv.h"

extern "C" {
//#include "fpconv.h"
#include "lua_cjson.c"


}

IMPLEMENT_MODULE(FLibCjsonModule, LibCjson);

void FLibCjsonModule::StartupModule()
{

}

void FLibCjsonModule::ShutdownModule()
{

}

void FLibCjsonModule::SetupLibCjson(lua_State* L)
{
	luaL_getsubtable(L, LUA_REGISTRYINDEX, LUA_PRELOAD_TABLE);
	luaL_requiref(L, "cjson", luaopen_cjson, 1);
}

