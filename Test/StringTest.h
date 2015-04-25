//
// File: StringTest.h
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

#ifndef _TESTSUITE_STRINGTEST_H_
#define _TESTSUITE_STRINGTEST_H_


#include "BaseFrame/BaseFrame.h"
#include "BaseFrame/CppUnit/TestCase.h"

using namespace OpenSoft::BaseFrame;

class StringTest : public CppUnit::TestCase
{
public:
	StringTest(const std::string& name);
	~StringTest();

	void testInt();
	void testComplexType();
	void testVector();
	
	void setUp();
	void tearDown();

	void testConnectMongo();
	static CppUnit::Test* suite();
};


#endif // _TESTSUITE_STRINGTEST_H_
