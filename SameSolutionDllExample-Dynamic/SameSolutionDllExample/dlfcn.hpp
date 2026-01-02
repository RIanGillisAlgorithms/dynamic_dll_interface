#pragma once
//adapted from
//https://github.com/wilderfield/dynamicLoad
#ifndef _WIN32
# include <dlfcn.h>
#else
# include <windows.h>
# define RTLD_LAZY 0
# define RTLD_GLOBAL 0
# define RTLD_NOW 0

inline void*
dlopen(const char* dllname, int)
{
	// Convert UTF-8 or ANSI char* to wide string for LoadLibraryW
	int len = MultiByteToWideChar(CP_ACP, 0, dllname, -1, nullptr, 0);
	wchar_t* wDllName = new wchar_t[len];
	MultiByteToWideChar(CP_ACP, 0, dllname, -1, wDllName, len);
	HMODULE hModule = LoadLibraryW(wDllName);
	delete[] wDllName;
	return hModule;
}

inline void
dlclose(void* handle)
{
	FreeLibrary(HMODULE(handle));
}

inline const char*
dlerror()
{
	return "";
}

inline void*
dlsym(void* handle, const char* symbol)
{
	return GetProcAddress(HMODULE(handle), symbol);
}

#endif
