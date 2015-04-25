//
// File: CppUnitException.h
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

#ifndef __BASEFRAME_CppUnitException_H__
#define __BASEFRAME_CppUnitException_H__

#include "CppUnit.h"
#include <exception>
#include <string>

namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {

class BaseFrame_API CppUnitException : public std::exception
	/// CppUnitException is an exception that serves
	/// descriptive strings through its what() method
{
public:
	CppUnitException(const std::string& message = "",
		long lineNumber = CPPUNIT_UNKNOWNLINENUMBER,
		const std::string& fileName = CPPUNIT_UNKNOWNFILENAME);
	CppUnitException(const std::string& message,
		long lineNumber,
		long data1lineNumber,
		const std::string& fileName);
	CppUnitException(const std::string& message,
		long lineNumber,
		long data1lineNumber,
		long data2lineNumber,
		const std::string& fileName);
	CppUnitException(const CppUnitException& other);
	virtual ~CppUnitException() throw();

	CppUnitException& operator = (const CppUnitException& other);

	const char* what() const throw ();

	long lineNumber() const;
	long data1LineNumber() const;
	long data2LineNumber() const;
	const std::string& fileName() const;

	static const std::string CPPUNIT_UNKNOWNFILENAME;
	static const int CPPUNIT_UNKNOWNLINENUMBER;

private:
	std::string _message;
	long        _lineNumber;
	long        _data1lineNumber;
	long        _data2lineNumber;
	std::string _fileName;
};


inline CppUnitException::CppUnitException(const CppUnitException& other) : exception(other)
{
	_message = other._message;
	_lineNumber = other._lineNumber;
	_data1lineNumber = other._data1lineNumber;
	_data2lineNumber = other._data2lineNumber;
	_fileName = other._fileName;
}


inline CppUnitException::CppUnitException(const std::string& message, long lineNumber, const std::string& fileName) : _message(message), _lineNumber(lineNumber), _data1lineNumber(CPPUNIT_UNKNOWNLINENUMBER), _data2lineNumber(CPPUNIT_UNKNOWNLINENUMBER), _fileName(fileName)
{
}


inline CppUnitException::CppUnitException(const std::string& message, long lineNumber, long data1lineNumber, const std::string& fileName) : _message(message), _lineNumber(lineNumber), _data1lineNumber(data1lineNumber), _data2lineNumber(CPPUNIT_UNKNOWNLINENUMBER), _fileName(fileName)
{
}


inline CppUnitException::CppUnitException(const std::string& message, long lineNumber, long data1lineNumber, long data2lineNumber, const std::string& fileName) : _message(message), _lineNumber(lineNumber), _data1lineNumber(data1lineNumber), _data2lineNumber(data2lineNumber), _fileName(fileName)
{
}


inline CppUnitException::~CppUnitException() throw()
{
}


inline CppUnitException& CppUnitException::operator = (const CppUnitException& other)
{
	exception::operator= (other);

	if (&other != this)
	{
		_message = other._message;
		_lineNumber = other._lineNumber;
		_data1lineNumber = other._data1lineNumber;
		_data2lineNumber = other._data2lineNumber;
		_fileName = other._fileName;
	}
	return *this;
}


inline const char* CppUnitException::what() const throw ()
{
	return _message.c_str();
}


inline long CppUnitException::lineNumber() const
{
	return _lineNumber;
}


inline long CppUnitException::data1LineNumber() const
{
	return _data1lineNumber;
}


inline long CppUnitException::data2LineNumber() const
{
	return _data2lineNumber;
}


// The file in which the error occurred
inline const std::string& CppUnitException::fileName() const
{
	return _fileName;
}


} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft

#endif // __BASEFRAME_CppUnitException_H__
