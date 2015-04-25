//
// File: Error.cpp
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

//#include "Poco/UnicodeConverter.h"
#include "BaseFrame/Core/Error.h"
#include <string>
#include <string.h>
#include <errno.h>


namespace OpenSoft{
namespace BaseFrame{


#ifdef OPENSOFT_OS_FAMILY_WINDOWS
	DWORD Error::last()
	{
		return GetLastError();
	}


	std::string Error::getMessage(DWORD errorCode)
	{
		std::string errMsg;
		DWORD dwFlg = FORMAT_MESSAGE_ALLOCATE_BUFFER | FORMAT_MESSAGE_FROM_SYSTEM | FORMAT_MESSAGE_IGNORE_INSERTS;
	#if defined(OPENSOFT_WIN32_UTF8) && !defined(OPENSOFT_NO_WSTRING)
		LPWSTR lpMsgBuf = 0;
		if (FormatMessageW(dwFlg, 0, errorCode, 0, (LPWSTR) & lpMsgBuf, 0, NULL))
			//TODO utf8×ª»»ÎÊÌâ
			//UnicodeConverter::toUTF8(lpMsgBuf, errMsg);
	#else
		LPTSTR lpMsgBuf = 0;
		if (FormatMessageA(dwFlg, 0, errorCode, 0, (LPTSTR) & lpMsgBuf, 0, NULL))
			errMsg = lpMsgBuf;
	#endif
		LocalFree(lpMsgBuf);
		return errMsg;
	}

#else
	int Error::last()
	{
		return errno;
	}


	std::string Error::getMessage(int errorCode)
	{
		/* Reentrant version of `strerror'.
		   There are 2 flavors of `strerror_r', GNU which returns the string
		   and may or may not use the supplied temporary buffer and POSIX one
		   which fills the string into the buffer.
		   To use the POSIX version, -D_XOPEN_SOURCE=600 or -D_POSIX_C_SOURCE=200112L
		   without -D_GNU_SOURCE is needed, otherwise the GNU version is
		   preferred.
		*/
#if defined _GNU_SOURCE && !OPENSOFT_ANDROID
		char errmsg[256] = "";
		return std::string(strerror_r(errorCode, errmsg, 256));
#elif (_XOPEN_SOURCE >= 600) || OPENSOFT_ANDROID
		char errmsg[256] = "";
		strerror_r(errorCode, errmsg, 256);
		return errmsg;
#else
		return std::string(strerror(errorCode));
#endif
	}

#endif


} // namespace BaseFrame
} // namespace OpenSoft
