//
// File: Debugger.cpp
//
// Date: 2015/04/25 12:05
//
// Library: BaseFrame
//
// Brief: Basic definitions for the OpenSoft Basic library.
// 
//
// Copyright (c) 2011-2015, Applied Informatics Software azraelly.
// and opensoft.
//
// Author: linyang
// Contact: 119745743@qq.com
//
// SPDX-License-Identifier:	BSL-1.0
//


#include "BaseFrame/Core/Debugger.h"
#include <sstream>
#include <cstdlib>
#include <cstdio>
#if defined(OPENSOFT_OS_FAMILY_WINDOWS)
	#include "BaseFrame/Core/UnWindows.h"
#elif defined(OPENSOFT_OS_FAMILY_UNIX) && !defined(OPENSOFT_VXWORKS)
	#include <unistd.h>
	#include <signal.h>
#elif defined(OPENSOFT_OS_FAMILY_VMS)
	#include <lib$routines.h>
	#include <ssdef.h>
#endif
#if defined(OPENSOFT_WIN32_UTF8) && !defined(OPENSOFT_NO_WSTRING)
#include "Poco/UnicodeConverter.h"
#endif


// NOTE: In this module, we use the C library functions (fputs) for,
// output since, at the time we're called, the C++ iostream objects std::cout, etc.
// might not have been initialized yet.

namespace OpenSoft{
namespace BaseFrame{

bool Debugger::isAvailable()
{
#if defined(_DEBUG)
	#if defined(OPENSOFT_OS_FAMILY_WINDOWS)
		#if defined(_WIN32_WCE)
			#if (_WIN32_WCE >= 0x600)
				BOOL isDebuggerPresent;
				if (CheckRemoteDebuggerPresent(GetCurrentProcess(), &isDebuggerPresent))
				{
					return isDebuggerPresent ? true : false;
				}
				return false;
			#else
				return false;
			#endif
		#else
			return IsDebuggerPresent() ? true : false;
		#endif
	#elif defined(OPENSOFT_VXWORKS)
		return false;
	#elif defined(OPENSOFT_OS_FAMILY_UNIX)
		return std::getenv("OPENSOFT_ENABLE_DEBUGGER") ? true : false;
	#elif defined(OPENSOFT_OS_FAMILY_VMS)
		return true;
	#endif
#else
	return false;
#endif
}


void Debugger::message(const std::string& msg)
{
#if defined(_DEBUG)
	std::fputs("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", stderr);
	std::fputs(msg.c_str(), stderr);
	std::fputs("\n%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%\n", stderr);
	#if defined(OPENSOFT_OS_FAMILY_WINDOWS)
	if (isAvailable())
	{
#if defined(OPENSOFT_WIN32_UTF8) && !defined(OPENSOFT_NO_WSTRING)
		std::wstring umsg;
		UnicodeConverter::toUTF16(msg, umsg);
		umsg += '\n';
		OutputDebugStringW(umsg.c_str());
#else
		OutputDebugStringA(msg.c_str());
		OutputDebugStringA("\n");
#endif
	}
	#elif defined(OPENSOFT_OS_FAMILY_UNIX)
	#elif defined(OPENSOFT_OS_FAMILY_VMS)
	#endif
#endif
}


void Debugger::message(const std::string& msg, const char* file, int line)
{
#if defined(_DEBUG)
	std::ostringstream str;
	str << msg << " [in file \"" << file << "\", line " << line << "]";
	message(str.str());
#endif
}


void Debugger::enter()
{
#if defined(_DEBUG)
	#if defined(OPENSOFT_OS_FAMILY_WINDOWS)
	if (isAvailable())
	{
		DebugBreak();
	}
	#elif defined(OPENSOFT_VXWORKS)
	{
		// not supported
	}
	#elif defined(OPENSOFT_OS_FAMILY_UNIX)
	if (isAvailable())
	{
		kill(getpid(), SIGINT);
	}
	#elif defined(OPENSOFT_OS_FAMILY_VMS)
	{
		const char* cmd = "\012SHOW CALLS";
		lib$signal(SS$_DEBUG, 1, cmd);
	}
	#endif
#endif
}


void Debugger::enter(const std::string& msg)
{
#if defined(_DEBUG)
	message(msg);
	enter();
#endif
}


void Debugger::enter(const std::string& msg, const char* file, int line)
{
#if defined(_DEBUG)
	message(msg, file, line);
	enter();
#endif
}


void Debugger::enter(const char* file, int line)
{
#if defined(_DEBUG)
	message("BREAK", file, line);
	enter();
#endif
}

} // namespace BaseFrame
} // namespace OpenSoft
