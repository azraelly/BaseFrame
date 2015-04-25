//
// File: TestDecorator.h
//
// Date: 2015/04/25 10:17
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

#ifndef CppUnit_TestDecorator_INCLUDED
#define CppUnit_TestDecorator_INCLUDED


#include "CppUnit.h"
#include "Guards.h"
#include "Test.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


class TestResult;


/*
 * A Decorator for Tests
 *
 * Does not assume ownership of the test it decorates
 *
 */
class BaseFrame_API TestDecorator: public Test
{
	REFERENCEOBJECT(TestDecorator)

public:
	TestDecorator(Test* test);

	virtual ~TestDecorator();

	int countTestCases();

	void run(TestResult* result);

	std::string toString();

protected:
	Test* _test;
};


} // namespace CppUnit} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft

#endif // CppUnit_TestDecorator_INCLUDED
