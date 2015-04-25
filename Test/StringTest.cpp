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


#include "StringTest.h"
#include "BaseFrame/CppUnit/TestCaller.h"
#include "BaseFrame/CppUnit/TestSuite.h"

using namespace OpenSoft::BaseFrame;

class SomeClass
{
public:
	int i;
	std::string str;
	SomeClass(int h, std::string s) : i(h), str(s)
	{
	};
	bool operator==(const SomeClass& other) const
	{
		return i == other.i && str == other.str;
	}
};


StringTest::StringTest(const std::string& name) : CppUnit::TestCase(name)
{
}


StringTest::~StringTest()
{
}


void StringTest::testInt()
{

}


void StringTest::testComplexType()
{

}

class TestPtr
{
public:
	TestPtr();
	~TestPtr();

private:

};

void StringTest::testVector()
{

}


void StringTest::setUp()
{
}


void StringTest::tearDown()
{
}
//1927 - 12 - 31 23:54 : 08
void StringTest::testConnectMongo()
{

}

CppUnit::Test* StringTest::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("StringTest");
	CppUnit_addTest(pSuite, StringTest, testConnectMongo);
	CppUnit_addTest(pSuite, StringTest, testInt);
	CppUnit_addTest(pSuite, StringTest, testComplexType);
	CppUnit_addTest(pSuite, StringTest, testVector);
	return pSuite;
}
