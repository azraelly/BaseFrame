//
// File: Error.h
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


#ifndef Foundation_Error_INCLUDED
#define Foundation_Error_INCLUDED


#include "BaseFrame/Core/Platform.h"
#include "BaseFrame/BaseFrame.h"

namespace OpenSoft{
namespace BaseFrame{


class BaseFrame_API Error
	/// The Error class provides utility functions
	/// for error reporting.
{
public:

#ifdef OPENSOFT_OS_FAMILY_WINDOWS
	static DWORD last();
		/// Utility function returning the last error.

	static std::string getMessage(DWORD errorCode);
		/// Utility function translating numeric error code to string.
#else
	static int last();
		/// Utility function returning the last error.

	static std::string getMessage(int errorCode);
		/// Utility function translating numeric error code to string.
#endif
};


} // namespace BaseFrame
} // namespace OpenSoft


#endif // Foundation_Error_INCLUDED
