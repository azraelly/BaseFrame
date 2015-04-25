//
// File: Config.h
//
// Date: 2015/04/25 12:04
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

#ifndef Foundation_Config_INCLUDED
#define Foundation_Config_INCLUDED


// Define to enable Windows Unicode (UTF-8) support
// NOTE: As of POCO C++ Libraries release 1.6.0, compiling POCO
// without OPENSOFT_WIN32_UTF8 defined on Windows is deprecated.
// #define OPENSOFT_WIN32_UTF8


// Define to enable C++11 support
// #define OPENSOFT_ENABLE_CPP11


// Define to disable implicit linking
// #define OPENSOFT_NO_AUTOMATIC_LIBS


// Define to disable automatic initialization
// Defining this will disable ALL automatic 
// initialization framework-wide (e.g. Net
// on Windows, all Data back-ends, etc).
// 
// #define OPENSOFT_NO_AUTOMATIC_LIB_INIT


// Define to disable FPEnvironment support
// #define OPENSOFT_NO_FPENVIRONMENT


// Define if std::wstring is not available
// #define OPENSOFT_NO_WSTRING


// Define to disable shared memory
// #define OPENSOFT_NO_SHAREDMEMORY


// Define if no <locale> header is available (such as on WinCE)
// #define OPENSOFT_NO_LOCALE


// Define to desired default thread stack size
// Zero means OS default
#ifndef OPENSOFT_THREAD_STACK_SIZE
	#define OPENSOFT_THREAD_STACK_SIZE 0
#endif


// Define to override system-provided
// minimum thread priority value on POSIX
// platforms (returned by Poco::Thread::getMinOSPriority()).
// #define OPENSOFT_THREAD_PRIORITY_MIN 0


// Define to override system-provided
// maximum thread priority value on POSIX
// platforms (returned by Poco::Thread::getMaxOSPriority()).
// #define OPENSOFT_THREAD_PRIORITY_MAX 31


// Define to disable small object optimization. If not 
// defined, Any and Dynamic::Var (and similar optimization
// candidates) will be auto-allocated on the stack in 
// cases when value holder fits into OPENSOFT_SMALL_OBJECT_SIZE
// (see below).
// 
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// !!! NOTE: Any/Dynamic::Var SOO will NOT work reliably   !!!
// !!! without C++11 (std::aligned_storage in particular). !!!
// !!! Only comment this out if your compiler has support  !!!
// !!! for std::aligned_storage.                           !!!
// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
// 
#define OPENSOFT_NO_SOO


// Small object size in bytes. When assigned to Any or Var,
// objects larger than this value will be alocated on the heap,
// while those smaller will be placement new-ed into an
// internal buffer.
#if !defined(OPENSOFT_SMALL_OBJECT_SIZE) && !defined(OPENSOFT_NO_SOO)
	#define OPENSOFT_SMALL_OBJECT_SIZE 32
#endif


// Define to disable compilation of DirectoryWatcher
// on platforms with no inotify.
// #define OPENSOFT_NO_INOTIFY


// Following are options to remove certain features
// to reduce library/executable size for smaller
// embedded platforms. By enabling these options,
// the size of a statically executable can be
// reduced by a few 100 Kbytes.


// No automatic registration of FileChannel in
// LoggingFactory - avoids FileChannel and friends 
// being linked to executable.
// #define OPENSOFT_NO_FILECHANNEL


// No automatic registration of SplitterChannel in
// LoggingFactory - avoids SplitterChannel being
// linked to executable.
// #define OPENSOFT_NO_SPLITTERCHANNEL


// No automatic registration of SyslogChannel in
// LoggingFactory - avoids SyslogChannel being
// linked to executable on Unix/Linux systems.
// #define OPENSOFT_NO_SYSLOGCHANNEL


// Define to enable MSVC secure warnings
// #define OPENSOFT_MSVC_SECURE_WARNINGS


// No support for INI file configurations in
// Poco::Util::Application.
// #define OPENSOFT_UTIL_NO_INIFILECONFIGURATION


// No support for JSON configuration in 
// Poco::Util::Application. Avoids linking of JSON
// library and saves a few 100 Kbytes.
// #define OPENSOFT_UTIL_NO_JSONCONFIGURATION


// No support for XML configuration in 
// Poco::Util::Application. Avoids linking of XML
// library and saves a few 100 Kbytes.
// #define OPENSOFT_UTIL_NO_XMLCONFIGURATION


// No IPv6 support
// Define to disable IPv6
// #define OPENSOFT_NET_NO_IPv6


// Windows CE has no locale support
#if defined(_WIN32_WCE)
	#define OPENSOFT_NO_LOCALE
#endif

// Enable the OPENSOFT_debug_* and OPENSOFT_trace_* macros
// even if the _DEBUG variable is not set.
// This allows the use of these macros in a release version.
// #define OPENSOFT_LOG_DEBUG

#endif // Foundation_Config_INCLUDED
