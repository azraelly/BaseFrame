//
// File: TestCase.cpp
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


#include <stdexcept>
#include <math.h>
#include "BaseFrame/CppUnit/TestCase.h"
#include "BaseFrame/CppUnit/TestResult.h"
#include "BaseFrame/CppUnit/estring.h"
#include <typeinfo>
#include <iostream>


using namespace std;


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


// Create a default TestResult
TestResult* TestCase::defaultResult()
{
	return new TestResult;
}


// Check for a failed general assertion
void TestCase::assertImplementation(bool condition, const std::string& conditionExpression, long lineNumber, const std::string& fileName)
{
	if (!condition)
		throw CppUnitException(conditionExpression, lineNumber, fileName);
}


void TestCase::loop1assertImplementation(bool condition, const std::string& conditionExpression, long lineNumber, long data1lineNumber, const std::string& fileName)
{
	if (!condition)
		throw CppUnitException(conditionExpression, lineNumber, data1lineNumber, fileName);
}


void TestCase::loop2assertImplementation(bool condition, const std::string& conditionExpression, long lineNumber, long data1lineNumber, long data2lineNumber, const std::string& fileName)
{
	if (!condition)
		throw CppUnitException(conditionExpression, lineNumber, data1lineNumber, data2lineNumber, fileName);
}


// Check for a failed equality assertion
void TestCase::assertEquals(long expected, long actual, long lineNumber, const std::string& fileName)
{
	if (expected != actual)
		assertImplementation(false, notEqualsMessage(expected, actual), lineNumber, fileName);
}


// Check for a failed equality assertion
void TestCase::assertEquals(double expected, double actual, double delta, long lineNumber, const std::string& fileName)
{
	if (fabs(expected - actual) > delta)
		assertImplementation(false, notEqualsMessage(expected, actual), lineNumber, fileName);
}


// Check for a failed equality assertion
void TestCase::assertEquals(const void* expected, const void* actual, long lineNumber, const std::string& fileName)
{
	if (expected != actual)
		assertImplementation(false, notEqualsMessage(expected, actual), lineNumber, fileName);
}


// Check for a failed equality assertion
void TestCase::assertEquals(const std::string& expected, const std::string& actual, long lineNumber, const std::string& fileName)
{
	if (expected != actual)
		assertImplementation(false, notEqualsMessage(expected, actual), lineNumber, fileName);
}


void TestCase::assertNotNull(const void* pointer, const std::string& pointerExpression, long lineNumber, const std::string& fileName)
{
	if (pointer == NULL)
		throw CppUnitException(pointerExpression + " must not be NULL", lineNumber, fileName);
}


void TestCase::assertNull(const void* pointer, const std::string& pointerExpression, long lineNumber, const std::string& fileName)
{
	if (pointer != NULL)
		throw CppUnitException(pointerExpression + " must be NULL", lineNumber, fileName);
}


void TestCase::fail(const std::string& message, long lineNumber, const std::string& fileName)
{
	throw CppUnitException(std::string("fail: ") + message, lineNumber, fileName);
}


void TestCase::warn(const std::string& message, long lineNumber, const std::string& fileName)
{
	std::cout << "Warning [" << fileName << ':' << lineNumber << "]: " << message << std::endl;
}


// Run the test and catch any exceptions that are triggered by it
void TestCase::run(TestResult *result)
{
	result->startTest(this);

	setUp();
	try 
	{
		runTest();
	}
	catch (CppUnitException& e) 
	{
		CppUnitException* copy = new CppUnitException(e);
		result->addFailure(this, copy);
	}
	catch (std::exception& e)
	{
		std::string msg(typeid(e).name());
		msg.append(": ");
		msg.append(e.what());
		result->addError(this, new CppUnitException(msg));

	}
#if !defined(_WIN32)
	catch (...)
	{
		CppUnitException *e = new CppUnitException ("unknown exception");
		result->addError (this, e);
	}
#endif
	tearDown ();
	result->endTest(this);
}


// A default run method
TestResult* TestCase::run()
{
	TestResult* result = defaultResult();

	run(result);
	return result;
}


// All the work for runTest is deferred to subclasses
void TestCase::runTest()
{
}


// Build a message about a failed equality check
std::string TestCase::notEqualsMessage(long expected, long actual)
{
	return "expected: " + estring(expected) + " but was: " + estring(actual);
}


// Build a message about a failed equality check
std::string TestCase::notEqualsMessage(double expected, double actual)
{
	return "expected: " + estring(expected) + " but was: " + estring(actual);
}


// Build a message about a failed equality check
std::string TestCase::notEqualsMessage(const void* expected, const void* actual)
{
	return "expected: " + estring(expected) + " but was: " + estring(actual);
}


// Build a message about a failed equality check
std::string TestCase::notEqualsMessage(const std::string& expected, const std::string& actual)
{
	return "expected: \"" + expected + "\" but was: \"" + actual + "\"";
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft
