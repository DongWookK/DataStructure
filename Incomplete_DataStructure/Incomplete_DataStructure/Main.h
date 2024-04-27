#pragma once
#include <stdio.h>
#include <vector>
#include <array>
#include <iostream>


#ifdef _DEBUG
	#define FNL_ASSERT(pExp, pMsg)														\
	{																					\
		bool aExp = static_cast<bool>(pExp);											\
		if (false == aExp)																\
		{																				\
			DWORD aLastError = ::GetLastError();										\
			int aRetry = _CrtDbgReport(__FILEW__, __LINE__);							\
			::SetLastError(aLastError);													\
			if (1 == aRetry)															\
			{																			\
				__debugbreak();															\
			}																			\
		}																				\
	}
#endif