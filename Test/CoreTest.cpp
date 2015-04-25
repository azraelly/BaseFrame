//
// File: CoreTest.cpp
//
// Date: 2015/04/25 12:17
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

#include<time.h>
#include <vector>

#include "CoreTest.h"
#include "BaseFrame/CppUnit/TestCaller.h"
#include "BaseFrame/CppUnit/TestSuite.h"

using namespace OpenSoft::BaseFrame;

class SomeClass
{
public:
	int i;
	std::string str;
	SomeClass(int h, std::string s): i (h), str(s)
	{
	};
	bool operator==(const SomeClass& other) const
	{
		return i == other.i && str == other.str;
	}
};


CoreTest::CoreTest(const std::string& name) : CppUnit::TestCase(name)
{
}


CoreTest::~CoreTest()
{
}


void CoreTest::testInt()
{
	
}


void CoreTest::testComplexType()
{
	
}

class TestPtr
{
public:
	TestPtr();
	~TestPtr();

private:

};

void CoreTest::testVector()
{
	
}


void CoreTest::setUp()
{
}


void CoreTest::tearDown()
{
}
//1927 - 12 - 31 23:54 : 08
void CoreTest::testConnectMongo()
{
	
}

CppUnit::Test* CoreTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("CoreTest");
	CppUnit_addTest(pSuite, CoreTest, testConnectMongo);
	CppUnit_addTest(pSuite, CoreTest, testInt);
	CppUnit_addTest(pSuite, CoreTest, testComplexType);
	CppUnit_addTest(pSuite, CoreTest, testVector);
	return pSuite;
}
