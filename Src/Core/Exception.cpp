//
// File: Exception.cpp
//
// Date: 2015/04/25 10:13
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

#include "BaseFrame/Core/Exception.h"
#include <typeinfo>


namespace OpenSoft {
namespace BaseFrame{

Exception::Exception(int code): _pNested(0), _code(code)
{
}


Exception::Exception(const std::string& msg, int code): _msg(msg), _pNested(0), _code(code)
{
}


Exception::Exception(const std::string& msg, const std::string& arg, int code): _msg(msg), _pNested(0), _code(code)
{
	if (!arg.empty())
	{
		_msg.append(": ");
		_msg.append(arg);
	}
}


Exception::Exception(const std::string& msg, const Exception& nested, int code): _msg(msg), _pNested(nested.clone()), _code(code)
{
}


Exception::Exception(const Exception& exc):
	std::exception(exc),
	_msg(exc._msg),
	_code(exc._code)
{
	_pNested = exc._pNested ? exc._pNested->clone() : 0;
}

	
Exception::~Exception() throw()
{
	delete _pNested;
}


Exception& Exception::operator = (const Exception& exc)
{
	if (&exc != this)
	{
		Exception* newPNested = exc._pNested ? exc._pNested->clone() : 0;
		delete _pNested;
		_msg     = exc._msg;
		_pNested = newPNested;
		_code    = exc._code;
	}
	return *this;
}


const char* Exception::name() const throw()
{
	return "Exception";
}


const char* Exception::className() const throw()
{
	return typeid(*this).name();
}

	
const char* Exception::what() const throw()
{
	return name();
}

	
std::string Exception::displayText() const
{
	std::string txt = name();
	if (!_msg.empty())
	{
		txt.append(": ");
		txt.append(_msg);
	}
	return txt;
}


void Exception::extendedMessage(const std::string& arg)
{
	if (!arg.empty())
	{
		if (!_msg.empty()) _msg.append(": ");
		_msg.append(arg);
	}
}


Exception* Exception::clone() const
{
	return new Exception(*this);
}


void Exception::rethrow() const
{
	throw *this;
}


OPENSOFT_IMPLEMENT_EXCEPTION(LogicException, Exception, "Logic exception")
OPENSOFT_IMPLEMENT_EXCEPTION(AssertionViolationException, LogicException, "Assertion violation")
OPENSOFT_IMPLEMENT_EXCEPTION(NullPointerException, LogicException, "Null pointer")
OPENSOFT_IMPLEMENT_EXCEPTION(NullValueException, LogicException, "Null value")
OPENSOFT_IMPLEMENT_EXCEPTION(BugcheckException, LogicException, "Bugcheck")
OPENSOFT_IMPLEMENT_EXCEPTION(InvalidArgumentException, LogicException, "Invalid argument")
OPENSOFT_IMPLEMENT_EXCEPTION(NotImplementedException, LogicException, "Not implemented")
OPENSOFT_IMPLEMENT_EXCEPTION(RangeException, LogicException, "Out of range")
OPENSOFT_IMPLEMENT_EXCEPTION(IllegalStateException, LogicException, "Illegal state")
OPENSOFT_IMPLEMENT_EXCEPTION(InvalidAccessException, LogicException, "Invalid access")
OPENSOFT_IMPLEMENT_EXCEPTION(SignalException, LogicException, "Signal received")
OPENSOFT_IMPLEMENT_EXCEPTION(UnhandledException, LogicException, "Unhandled exception")

OPENSOFT_IMPLEMENT_EXCEPTION(RuntimeException, Exception, "Runtime exception")
OPENSOFT_IMPLEMENT_EXCEPTION(NotFoundException, RuntimeException, "Not found")
OPENSOFT_IMPLEMENT_EXCEPTION(ExistsException, RuntimeException, "Exists")
OPENSOFT_IMPLEMENT_EXCEPTION(TimeoutException, RuntimeException, "Timeout")
OPENSOFT_IMPLEMENT_EXCEPTION(SystemException, RuntimeException, "System exception")
OPENSOFT_IMPLEMENT_EXCEPTION(RegularExpressionException, RuntimeException, "Error in regular expression")
OPENSOFT_IMPLEMENT_EXCEPTION(LibraryLoadException, RuntimeException, "Cannot load library")
OPENSOFT_IMPLEMENT_EXCEPTION(LibraryAlreadyLoadedException, RuntimeException, "Library already loaded")
OPENSOFT_IMPLEMENT_EXCEPTION(NoThreadAvailableException, RuntimeException, "No thread available")
OPENSOFT_IMPLEMENT_EXCEPTION(PropertyNotSupportedException, RuntimeException, "Property not supported")
OPENSOFT_IMPLEMENT_EXCEPTION(PoolOverflowException, RuntimeException, "Pool overflow")
OPENSOFT_IMPLEMENT_EXCEPTION(NoPermissionException, RuntimeException, "No permission")
OPENSOFT_IMPLEMENT_EXCEPTION(OutOfMemoryException, RuntimeException, "Out of memory")
OPENSOFT_IMPLEMENT_EXCEPTION(DataException, RuntimeException, "Data error")

OPENSOFT_IMPLEMENT_EXCEPTION(DataFormatException, DataException, "Bad data format")
OPENSOFT_IMPLEMENT_EXCEPTION(SyntaxException, DataException, "Syntax error")
OPENSOFT_IMPLEMENT_EXCEPTION(CircularReferenceException, DataException, "Circular reference")
OPENSOFT_IMPLEMENT_EXCEPTION(PathSyntaxException, SyntaxException, "Bad path syntax")
OPENSOFT_IMPLEMENT_EXCEPTION(IOException, RuntimeException, "I/O error")
OPENSOFT_IMPLEMENT_EXCEPTION(ProtocolException, IOException, "Protocol error")
OPENSOFT_IMPLEMENT_EXCEPTION(FileException, IOException, "File access error")
OPENSOFT_IMPLEMENT_EXCEPTION(FileExistsException, FileException, "File exists")
OPENSOFT_IMPLEMENT_EXCEPTION(FileNotFoundException, FileException, "File not found")
OPENSOFT_IMPLEMENT_EXCEPTION(PathNotFoundException, FileException, "Path not found")
OPENSOFT_IMPLEMENT_EXCEPTION(FileReadOnlyException, FileException, "File is read-only")
OPENSOFT_IMPLEMENT_EXCEPTION(FileAccessDeniedException, FileException, "Access to file denied")
OPENSOFT_IMPLEMENT_EXCEPTION(CreateFileException, FileException, "Cannot create file")
OPENSOFT_IMPLEMENT_EXCEPTION(OpenFileException, FileException, "Cannot open file")
OPENSOFT_IMPLEMENT_EXCEPTION(WriteFileException, FileException, "Cannot write file")
OPENSOFT_IMPLEMENT_EXCEPTION(ReadFileException, FileException, "Cannot read file")
OPENSOFT_IMPLEMENT_EXCEPTION(UnknownURISchemeException, RuntimeException, "Unknown URI scheme")


OPENSOFT_IMPLEMENT_EXCEPTION(ApplicationException, Exception, "Application exception")
OPENSOFT_IMPLEMENT_EXCEPTION(BadCastException, RuntimeException, "Bad cast exception")

} // namespace BaseFrame
} // namespace OpenSoft