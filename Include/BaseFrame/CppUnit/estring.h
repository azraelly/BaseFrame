//
// File: estring.h
//
// Date: 2015/04/25 10:14
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

#ifndef CppUnit_estring_INCLUDED
#define CppUnit_estring_INCLUDED


#include "CppUnit.h"
#include <string>
#include <stdio.h>


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


// Create a std::string from a const char pointer
inline std::string estring(const char *cstring)
{
	return std::string(cstring);
}


// Create a std::string from a std::string (for uniformities' sake)
inline std::string estring(std::string& expandedString)
{
	return expandedString;
}


// Create a std::string from an int
inline std::string estring(int number)
{
	char buffer[50]; 
	sprintf(buffer, "%d", number); 
	return std::string (buffer); 
}


// Create a string from a long
inline std::string estring(long number)
{
	char buffer[50]; 
	sprintf(buffer, "%ld", number); 
	return std::string (buffer); 
}


// Create a std::string from a double
inline std::string estring(double number)
{
	char buffer[50]; 
	sprintf(buffer, "%lf", number); 
	return std::string(buffer);
}


// Create a std::string from a double
inline std::string estring(const void* ptr)
{
	char buffer[50]; 
	sprintf(buffer, "%p", ptr); 
	return std::string(buffer);
}


} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft


#endif // CppUnit_estring_INCLUDED
