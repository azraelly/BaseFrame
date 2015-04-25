//
// File: BaseFrame.h
//
// Date: 2015/04/25 10:12
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

#ifndef __BASEFRAME_H__
#define __BASEFRAME_H__

#include "Core/Config.h"

//
// Ensure that OPENSOFT_DLL is default unless OPENSOFT_STATIC is defined
//
#if defined(_WIN32) && defined(_DLL)
#if !defined(OPENSOFT_DLL) && !defined(OPENSOFT_STATIC)
	#define OPENSOFT_DLL
	#endif
#endif


//
// The following block is the standard way of creating macros which make exporting 
// from a DLL simpler. All files within this DLL are compiled with the BaseFrame_EXPORTS
// symbol defined on the command line. this symbol should not be defined on any project
// that uses this DLL. This way any other project whose source files include this file see 
// Foundation_API functions as being imported from a DLL, wheras this DLL sees symbols
// defined with this macro as being exported.
//
#if defined(_WIN32) && defined(OPENSOFT_DLL)
	#if defined(BaseFrame_EXPORTS)
		#define BaseFrame_API __declspec(dllexport)
	#else
	#define BaseFrame_API __declspec(dllimport)	
	#endif
#endif


#if !defined(BaseFrame_API)
#define BaseFrame_API
#endif


//
// Automatically link Foundation library.
//
#if defined(_MSC_VER)
#if defined(OPENSOFT_DLL)
		#if defined(_DEBUG)
			#define OPENSOFT_LIB_SUFFIX "d.lib"
		#else
			#define OPENSOFT_LIB_SUFFIX ".lib"
		#endif
	#elif defined(_DLL)
		#if defined(_DEBUG)
			#define OPENSOFT_LIB_SUFFIX "mdd.lib"
		#else
			#define OPENSOFT_LIB_SUFFIX "md.lib"
		#endif
	#else
		#if defined(_DEBUG)
			#define OPENSOFT_LIB_SUFFIX "mtd.lib"
		#else
			#define OPENSOFT_LIB_SUFFIX "mt.lib"
		#endif
	#endif

#if !defined(OPENSOFT_NO_AUTOMATIC_LIBS) && !defined(BaseFrame_EXPORTS)
		#pragma comment(lib, "Lib/BaseFrame/win32/BaseFrame" OPENSOFT_LIB_SUFFIX)
	#endif
#endif


//
// Include platform-specific definitions
//
#include "Core/Platform.h"
#if defined(_WIN32)
#include "Core/Platform_WIN32.h"
#elif defined(OPENSOFT_OS_FAMILY_UNIX)
#include "Core/Platform_POSIX.h"
#endif


//
// Include alignment settings early
//
#include "Core/Alignment.h"

//
// Cleanup inconsistencies
//
#ifdef OPENSOFT_OS_FAMILY_WINDOWS
#if defined(OPENSOFT_WIN32_UTF8) && defined(OPENSOFT_NO_WSTRING)
#error OPENSOFT_WIN32_UTF8 and OPENSOFT_NO_WSTRING are mutually exclusive.
#endif
#else
#ifdef OPENSOFT_WIN32_UTF8
#undef OPENSOFT_WIN32_UTF8
#endif
#endif


//
// POCO_JOIN
//
// The following piece of macro magic joins the two
// arguments together, even when one of the arguments is
// itself a macro (see 16.3.1 in C++ standard).  The key
// is that macro expansion of macro arguments does not
// occur in OPENSOFT_DO_JOIN2 but does in OPENSOFT_DO_JOIN.
//
#define OPENSOFT_JOIN(X, Y) POCO_DO_JOIN(X, Y)
#define OPENSOFT_DO_JOIN(X, Y) POCO_DO_JOIN2(X, Y)
#define OPENSOFT_DO_JOIN2(X, Y) X##Y

//
// Pull in basic definitions
//
//#include "Poco/Bugcheck.h"
//#include "Poco/Types.h"
#include <string>

#endif // __BASEFRAME_H__
