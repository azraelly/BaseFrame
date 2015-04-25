//
// File: Exception.h
//
// Date: 2015/04/25 10:08
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

#ifndef Foundation_Exception_INCLUDED
#define Foundation_Exception_INCLUDED

#include "BaseFrame/BaseFrame.h"
#include <stdexcept>

namespace OpenSoft{
namespace BaseFrame{

class BaseFrame_API Exception : public std::exception
	/// This is the base class for all exceptions defined
	/// in the OpenSoft class library.
{
public:
	Exception(const std::string& msg, int code = 0);
	/// Creates an exception.

	Exception(const std::string& msg, const std::string& arg, int code = 0);
	/// Creates an exception.

	Exception(const std::string& msg, const Exception& nested, int code = 0);
	/// Creates an exception and stores a clone
	/// of the nested exception.

	Exception(const Exception& exc);
	/// Copy constructor.

	~Exception() throw();
	/// Destroys the exception and deletes the nested exception.

	Exception& operator = (const Exception& exc);
	/// Assignment operator.

	virtual const char* name() const throw();
	/// Returns a static string describing the exception.

	virtual const char* className() const throw();
	/// Returns the name of the exception class.

	virtual const char* what() const throw();
	/// Returns a static string describing the exception.
	///
	/// Same as name(), but for compatibility with std::exception.

	const Exception* nested() const;
	/// Returns a pointer to the nested exception, or
	/// null if no nested exception exists.

	const std::string& message() const;
	/// Returns the message text.

	int code() const;
	/// Returns the exception code if defined.

	std::string displayText() const;
	/// Returns a string consisting of the
	/// message name and the message text.

	virtual Exception* clone() const;
	/// Creates an exact copy of the exception.
	///
	/// The copy can later be thrown again by
	/// invoking rethrow() on it.

	virtual void rethrow() const;
	/// (Re)Throws the exception.
	///
	/// This is useful for temporarily storing a
	/// copy of an exception (see clone()), then
	/// throwing it again.

protected:
	Exception(int code = 0);
	/// Standard constructor.

	void message(const std::string& msg);
	/// Sets the message for the exception.

	void extendedMessage(const std::string& arg);
	/// Sets the extended message for the exception.

private:
	std::string _msg;
	Exception*  _pNested;
	int			_code;
};


//
// inlines
//
inline const Exception* Exception::nested() const
{
	return _pNested;
}


inline const std::string& Exception::message() const
{
	return _msg;
}


inline void Exception::message(const std::string& msg)
{
	_msg = msg;
}


inline int Exception::code() const
{
	return _code;
}


//
// Macros for quickly declaring and implementing exception classes.
// Unfortunately, we cannot use a template here because character
// pointers (which we need for specifying the exception name)
// are not allowed as template arguments.
//
#define OPENSOFT_DECLARE_EXCEPTION_CODE(API, CLS, BASE, CODE) \
class API CLS: public BASE														\
{																				\
public:																			\
	CLS(int code = CODE);														\
	CLS(const std::string& msg, int code = CODE);								\
	CLS(const std::string& msg, const std::string& arg, int code = CODE);		\
	CLS(const std::string& msg, const OpenSoft::BaseFrame::Exception& exc, int code = CODE);	\
	CLS(const CLS& exc);														\
	~CLS() throw();																\
	CLS& operator = (const CLS& exc);											\
	const char* name() const throw();											\
	const char* className() const throw();										\
	OpenSoft::BaseFrame::Exception* clone() const;											\
	void rethrow() const;														\
};

#define OPENSOFT_DECLARE_EXCEPTION(API, CLS, BASE) \
OPENSOFT_DECLARE_EXCEPTION_CODE(API, CLS, BASE, 0)

#define OPENSOFT_IMPLEMENT_EXCEPTION(CLS, BASE, NAME)													\
CLS::CLS(int code): BASE(code)																	\
{																								\
}																								\
CLS::CLS(const std::string& msg, int code): BASE(msg, code)										\
{																								\
}																								\
CLS::CLS(const std::string& msg, const std::string& arg, int code): BASE(msg, arg, code)		\
{																								\
}																								\
CLS::CLS(const std::string& msg, const OpenSoft::BaseFrame::Exception& exc, int code): BASE(msg, exc, code)	\
{																								\
}																								\
CLS::CLS(const CLS& exc): BASE(exc)																\
{																								\
}																								\
CLS::~CLS() throw()																				\
{																								\
}																								\
CLS& CLS::operator = (const CLS& exc)															\
{																								\
	BASE::operator = (exc);																		\
	return *this;																				\
}																								\
const char* CLS::name() const throw()															\
{																								\
	return NAME;																				\
}																								\
const char* CLS::className() const throw()														\
{																								\
	return typeid(*this).name();																\
}																								\
OpenSoft::BaseFrame::Exception* CLS::clone() const															\
{																								\
	return new CLS(*this);																		\
}																								\
void CLS::rethrow() const																		\
{																								\
	throw *this;																				\
}


//
// Standard exception classes
//
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, LogicException, Exception)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, AssertionViolationException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, NullPointerException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, NullValueException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, BugcheckException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, InvalidArgumentException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, NotImplementedException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, RangeException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, IllegalStateException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, InvalidAccessException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, SignalException, LogicException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, UnhandledException, LogicException)

OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, RuntimeException, Exception)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, NotFoundException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, ExistsException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, TimeoutException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, SystemException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, RegularExpressionException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, LibraryLoadException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, LibraryAlreadyLoadedException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, NoThreadAvailableException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, PropertyNotSupportedException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, PoolOverflowException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, NoPermissionException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, OutOfMemoryException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, DataException, RuntimeException)

OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, DataFormatException, DataException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, SyntaxException, DataException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, CircularReferenceException, DataException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, PathSyntaxException, SyntaxException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, IOException, RuntimeException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, ProtocolException, IOException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, FileException, IOException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, FileExistsException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, FileNotFoundException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, PathNotFoundException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, FileReadOnlyException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, FileAccessDeniedException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, CreateFileException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, OpenFileException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, WriteFileException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, ReadFileException, FileException)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, UnknownURISchemeException, RuntimeException)

OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, ApplicationException, Exception)
OPENSOFT_DECLARE_EXCEPTION(BaseFrame_API, BadCastException, RuntimeException)

} // namespace BaseFrame
} // namespace OpenSoft


#endif // Foundation_Exception_INCLUDED
