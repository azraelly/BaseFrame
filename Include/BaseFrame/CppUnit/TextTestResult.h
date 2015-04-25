//
// File: TextTestResult.h
//
// Date: 2015/04/25 10:20
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

#ifndef CppUnit_TextTestResult_INCLUDED
#define CppUnit_TextTestResult_INCLUDED


#include "CppUnit.h"
#include "TestResult.h"
#include <set>
#include <ostream>


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


class BaseFrame_API TextTestResult: public TestResult
{
public:
	TextTestResult();
	TextTestResult(std::ostream& ostr);
	
	virtual void addError(Test* test, CppUnitException* e);
	virtual void addFailure(Test* test, CppUnitException* e);
	virtual void startTest(Test* test);
	virtual void print(std::ostream& stream);
	virtual void printErrors(std::ostream& stream);
	virtual void printFailures(std::ostream& stream);
	virtual void printHeader(std::ostream& stream);
	
protected:
	std::string shortName(const std::string& testName);
	void setup();

private:
	std::ostream& _ostr;
	std::set<std::string> _ignored;
};


/* insertion operator for easy output */
inline std::ostream& operator<< (std::ostream& stream, TextTestResult& result)
{
	result.print(stream);
	return stream;
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft


#endif // CppUnit_TextTestResult_INCLUDED
