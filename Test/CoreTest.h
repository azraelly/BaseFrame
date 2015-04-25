//
// File: CoreTest.h
//
// Date: 2015/04/25 12:16
//
// Library: TestSuite
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

#ifndef _TESTSUITE_CONNECTTEST_H_
#define _TESTSUITE_CONNECTTEST_H_


#include "BaseFrame/BaseFrame.h"
#include "BaseFrame/CppUnit/TestCase.h"

using namespace OpenSoft::BaseFrame;

class CoreTest : public CppUnit::TestCase
{
public:
	CoreTest(const std::string& name);
	~CoreTest();

	void testInt();
	void testComplexType();
	void testVector();
	
	void setUp();
	void tearDown();

	void testConnectMongo();
	static CppUnit::Test* suite();
};


#endif // AnyTest_INCLUDED
