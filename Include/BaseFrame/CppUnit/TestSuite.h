//
// File: TestSuite.h
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

#ifndef CppUnit_TestSuite_INCLUDED
#define CppUnit_TestSuite_INCLUDED


#include "CppUnit.h"
#include "Guards.h"
#include "Test.h"
#include <vector>
#include <string>


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


class TestResult;


/*
 * A TestSuite is a Composite of Tests.
 * It runs a collection of test cases. Here is an example.
 *
 * TestSuite *suite= new TestSuite();
 * suite->addTest(new TestCaller<MathTest> ("testAdd", testAdd));
 * suite->addTest(new TestCaller<MathTest> ("testDivideByZero", testDivideByZero));
 *
 * Note that TestSuites assume lifetime
 * control for any tests added to them.
 *
 * see Test and TestCaller
 */
class BaseFrame_API TestSuite: public Test
{
	REFERENCEOBJECT (TestSuite)

public:
	TestSuite(const std::string& name = "");
	~TestSuite();

	void run(TestResult* result);
	int countTestCases();
	void addTest(Test* test);
	std::string toString();

	virtual void deleteContents();
	
	const std::vector<Test*> tests() const;

private:
	std::vector<Test*> _tests;
	const std::string _name;
};


// Default constructor
inline TestSuite::TestSuite(const std::string& name): _name(name)
{
}


// Destructor
inline TestSuite::~TestSuite()
{
	deleteContents();
}


// Adds a test to the suite.
inline void TestSuite::addTest(Test* test)
{
	_tests.push_back(test);
}


// Returns a std::string representation of the test suite.
inline std::string TestSuite::toString()
{
	return "suite " + _name; 
}


// Returns all tests
inline const std::vector<Test*> TestSuite::tests() const
{
	return _tests;
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft


#endif // CppUnit_TestSuite_INCLUDED
