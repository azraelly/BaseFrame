//
// File: Bugcheck.cpp
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

#include "BaseFrame/Core/Bugcheck.h"
#include "BaseFrame/Core/Debugger.h"
#include "BaseFrame/Core/Exception.h"
#include <sstream>


namespace OpenSoft{
namespace BaseFrame{

void Bugcheck::assertion(const char* cond, const char* file, int line, const char* text)
{
	std::string message("Assertion violation: ");
	message += cond;
	if (text)
	{
		message += " (";
		message += text;
		message += ")";
	}
	Debugger::enter(message, file, line);
	throw AssertionViolationException(what(cond, file, line, text));
}


void Bugcheck::nullPointer(const char* ptr, const char* file, int line)
{
	Debugger::enter(std::string("NULL pointer: ") + ptr, file, line);
	throw NullPointerException(what(ptr, file, line));
}


void Bugcheck::bugcheck(const char* file, int line)
{
	Debugger::enter("Bugcheck", file, line);
	throw BugcheckException(what(0, file, line));
}


void Bugcheck::bugcheck(const char* msg, const char* file, int line)
{
	std::string m("Bugcheck");
	if (msg)
	{
		m.append(": ");
		m.append(msg);
	}
	Debugger::enter(m, file, line);
	throw BugcheckException(what(msg, file, line));
}


void Bugcheck::unexpected(const char* file, int line)
{
#ifdef _DEBUG
	try
	{
		std::string msg("Unexpected exception in noexcept function or destructor: ");
		try
		{
			throw;
		}
		catch (BaseFrame::Exception& exc)
		{
			msg += exc.displayText();
		}
		catch (std::exception& exc)
		{
			msg += exc.what();
		}
		catch (...)
		{
			msg += "unknown exception";
		}
		Debugger::enter(msg, file, line);
	}
	catch (...)
	{
	}
#endif	
}


void Bugcheck::debugger(const char* file, int line)
{
	Debugger::enter(file, line);
}


void Bugcheck::debugger(const char* msg, const char* file, int line)
{
	Debugger::enter(msg, file, line);
}


std::string Bugcheck::what(const char* msg, const char* file, int line, const char* text)
{
	std::ostringstream str;
	if (msg) str << msg << " ";
   if (text != NULL) str << "(" << text << ") ";
	str << "in file \"" << file << "\", line " << line;
	return str.str();
}

} // namespace BaseFrame
} // namespace OpenSoft
