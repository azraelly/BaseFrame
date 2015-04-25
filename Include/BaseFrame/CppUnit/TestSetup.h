//
// File: TestSetup.h
//
// Date: 2015/04/25 10:19
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


#ifndef CppUnit_TestSetup_INCLUDED
#define CppUnit_TestSetup_INCLUDED


#include "CppUnit.h"
#include "Guards.h"
#include "TestDecorator.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


class Test;
class TestResult;


class BaseFrame_API TestSetup: public TestDecorator
{
	REFERENCEOBJECT (TestSetup)

public:
	TestSetup(Test* test): TestDecorator(test) 
	{
	}
	
	void run(TestResult* result);

protected:
	void setUp() 
	{
	}
	
	void tearDown()
	{
	}
};


inline void TestSetup::run(TestResult* result)
{
	setUp();
	TestDecorator::run(result); 
	tearDown();
}


} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft


#endif // CppUnit_TestSetup_INCLUDED
