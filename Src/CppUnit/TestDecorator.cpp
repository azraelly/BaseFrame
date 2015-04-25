//
// File: TestDecorator.cpp
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


#include "BaseFrame/CppUnit/TestDecorator.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


TestDecorator::TestDecorator(Test* test)
{
	_test = test;
}


TestDecorator::~TestDecorator()
{
}


int TestDecorator::countTestCases()
{
	return _test->countTestCases();
}


void TestDecorator::run(TestResult* result)
{
	_test->run(result);
} 


std::string TestDecorator::toString()
{
	return _test->toString();
}


} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft
