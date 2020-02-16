# UnLuaWithLibs
##UnLua常用库集成

基于Unlua插件，在插件层级加了一些自己用到的第三方lua库的扩展。</br>
UnLua: https://github.com/Tencent/UnLua

## LuaSocket

集成方法参考BlueLua，这个库是基本直接copy过来的，如有需要接LuaPanda的同学也可自行从该工程添加</br>
BlueLua: https://github.com/jashking/Bluelua

## LuaCrypt

字符串的一些加密解密函数库

## LPeg

模式匹配库。

## Sproto

skynet的定制协议

## 如何使用

直接将Unlua文件夹拷贝到plugin目录下，重新编译你的工程</br>

##添加库（以lpeg库为例）</br>
1.在Plugins\UnLua\Source\ThirdParty\目录下新建文件夹LibLpeg</br>
2.从已有库复制相对应的.h、.cpp、.build.cs文件到LibLpeg目录下，并将文件名修改为LibLpeg.h、LibLpeg.cpp、LibLpeg.build.cs</br>
3.文件夹内放入Lpeg库源码，并将上一步的三个文件内的模块名替换成LibLpeg相关</br>
4.在UnLua.uplugin文件中添加新增模块的相应配置，在UnLua.Build.cs添加模块名LibLpeg</br>
5.extern "C" {}内添加源码头文件，在FLibLpegModule::SetupLibLpeg函数中注册函数</br>
```lua
	lua_pushcfunction(L, luaopen_lpeg);
	lua_setfield(L, -2, "lpeg");
```
6.删掉项目的sln文件，重新生成编译，根据报错内容对源码进行相应修改</br>
7.LuaContext.cpp的CreateState方法添加注册
```cpp
		//lualpeg
		if (FLibLpegModule::IsAvailable())
		{
			FLibLpegModule::Get().SetupLibLpeg(L);
			lua_pushboolean(L, true);
			lua_setglobal(L, "SupportLpeg");

			UE_LOG(LogUnLua, Log, TEXT("Lua state setup with LuaLpeg."));
		}
```

## 注意

* 目前只支持win64 debug，其他环境未测试，后续会陆续更新多平台的支持
* 这几个库的使用请查阅相关文档
