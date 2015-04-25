//
// File: Platform_POSIX.h
//
// Date: 2015/04/25 10:09
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

#ifndef __BASEFRAME_PLATFORM_POSIX_H__
#define __BASEFRAME_PLATFORM_POSIX_H__


//
// PA-RISC based HP-UX platforms have some issues...
//
#if defined(hpux) || defined(_hpux)
	#if defined(__hppa) || defined(__hppa__)
		#define OPENSOFT_NO_SYS_SELECT_H 1
		#if defined(__HP_aCC)
			#define OPENSOFT_NO_TEMPLATE_ICOMPARE 1
		#endif
	#endif
#endif


//
// Thread-safety of local static initialization
//
#if __cplusplus >= 201103L || __GNUC__ >= 4 || defined(__clang__)
	#ifndef OPENSOFT_LOCAL_STATIC_INIT_IS_THREADSAFE
		#define OPENSOFT_LOCAL_STATIC_INIT_IS_THREADSAFE 1
	#endif
#endif


#ifdef __GNUC__
	#ifndef __THROW
		#ifndef __GNUC_PREREQ
			#define __GNUC_PREREQ(maj, min) (0)
		#endif
		#if defined __cplusplus && __GNUC_PREREQ (2,8)
			#define __THROW throw ()
		#else
			#define __THROW
		#endif
	#endif

// 
// GCC diagnostics enable/disable by Patrick Horgan, see
// http://dbp-consulting.com/tutorials/SuppressingGCCWarnings.html
// use example: GCC_DIAG_OFF(unused-variable)
// 
#if defined(OPENSOFT_COMPILER_GCC) && (((__GNUC__ * 100) + __GNUC_MINOR__) >= 406)

	#ifdef GCC_DIAG_OFF
		#undef GCC_DIAG_OFF
	#endif
	#ifdef GCC_DIAG_ON
		#undef GCC_DIAG_ON
	#endif
	#define GCC_DIAG_STR(s) #s
	#define GCC_DIAG_JOINSTR(x,y) GCC_DIAG_STR(x ## y)
	#define GCC_DIAG_DO_PRAGMA(x) _Pragma (#x)
	#define GCC_DIAG_PRAGMA(x) GCC_DIAG_DO_PRAGMA(GCC diagnostic x)
	#if ((__GNUC__ * 100) + __GNUC_MINOR__) >= 406
		#define GCC_DIAG_OFF(x) GCC_DIAG_PRAGMA(push) \
		GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x))
		#define GCC_DIAG_ON(x) GCC_DIAG_PRAGMA(pop)
	#else
		#define GCC_DIAG_OFF(x) GCC_DIAG_PRAGMA(ignored GCC_DIAG_JOINSTR(-W,x))
		#define GCC_DIAG_ON(x)  GCC_DIAG_PRAGMA(warning GCC_DIAG_JOINSTR(-W,x))
	#endif
	#else
		#define GCC_DIAG_OFF(x)
		#define GCC_DIAG_ON(x)
	#endif

#endif // __GNUC__


//
// No syslog.h on QNX/BB10
//
#if defined(__QNXNTO__)
	#define OPENSOFT_NO_SYSLOGCHANNEL
#endif


#endif // __BASEFRAME_PLATFORM_POSIX_H__
