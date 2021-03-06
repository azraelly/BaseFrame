//
//
// File: UnWindows.h
//
// Date: 2015/04/25 10:10
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

#ifndef __BASEFRAME_UNWINDOWS_H__
#define __BASEFRAME_UNWINDOWS_H__


// Reduce bloat
#if defined(_WIN32)
	#if !defined(WIN32_LEAN_AND_MEAN) && !defined(OPENSOFT_BLOATED_WIN32)
		#define WIN32_LEAN_AND_MEAN
	#endif
#endif


// Microsoft Visual C++ includes copies of the Windows header files 
// that were current at the time Visual C++ was released.
// The Windows header files use macros to indicate which versions 
// of Windows support many programming elements. Therefore, you must 
// define these macros to use new functionality introduced in each 
// major operating system release. (Individual header files may use 
// different macros; therefore, if compilation problems occur, check 
// the header file that contains the definition for conditional 
// definitions.) For more information, see SdkDdkVer.h.


#if !defined(_WIN32_WCE)
#if defined(_WIN32_WINNT)
	#if (_WIN32_WINNT < 0x0501)
		#error Unsupported Windows version.
	#endif
#elif defined(NTDDI_VERSION)
	#if (NTDDI_VERSION < 0x05010100)
		#error Unsupported Windows version.
	#endif
#elif !defined(_WIN32_WINNT)
	// Define minimum supported version.
	// This can be changed, if needed.
	// If allowed (see OPENSOFT_MIN_WINDOWS_OS_SUPPORT
	// below), Platform_WIN32.h will do its
	// best to determine the appropriate values
	// and may redefine these. See Platform_WIN32.h
	// for details.
	#define _WIN32_WINNT 0x0501
	#define NTDDI_VERSION 0x05010100
#endif
#endif


// To prevent Platform_WIN32.h to modify version defines,
// uncomment this, otherwise versions will be automatically
// discovered in Platform_WIN32.h.
// #define OPENSOFT_FORCE_MIN_WINDOWS_OS_SUPPORT


#include <windows.h>


#if !defined(OPENSOFT_NO_UNWINDOWS)
// A list of annoying macros to #undef.
// Extend as required.
#undef GetBinaryType
#undef GetShortPathName
#undef GetLongPathName
#undef GetEnvironmentStrings
#undef SetEnvironmentStrings
#undef FreeEnvironmentStrings
#undef FormatMessage
#undef EncryptFile
#undef DecryptFile
#undef CreateMutex
#undef OpenMutex
#undef CreateEvent
#undef OpenEvent
#undef CreateSemaphore
#undef OpenSemaphore
#undef LoadLibrary
#undef GetModuleFileName
#undef CreateProcess
#undef GetCommandLine
#undef GetEnvironmentVariable
#undef SetEnvironmentVariable
#undef ExpandEnvironmentStrings
#undef OutputDebugString
#undef FindResource
#undef UpdateResource
#undef FindAtom
#undef AddAtom
#undef GetSystemDirectory
#undef GetTempPath
#undef GetTempFileName
#undef SetCurrentDirectory
#undef GetCurrentDirectory
#undef CreateDirectory
#undef RemoveDirectory
#undef CreateFile
#undef DeleteFile
#undef SearchPath
#undef CopyFile
#undef MoveFile
#undef ReplaceFile
#undef GetComputerName
#undef SetComputerName
#undef GetUserName
#undef LogonUser
#undef GetVersion
#undef GetObject
#endif // OPENSOFT_NO_UNWINDOWS

#endif // __BASEFRAME_UNWINDOWS_H__
