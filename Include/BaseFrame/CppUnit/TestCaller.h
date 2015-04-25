//
// File: TestCaller.h
//
// Date: 2015/04/25 10:16
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

#ifndef CppUnit_TestCaller_INCLUDED
#define CppUnit_TestCaller_INCLUDED


#include "CppUnit.h"
#include "Guards.h"
#include "TestCase.h"
#include <memory>


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


/*
 * A test caller provides access to a test case method
 * on a test case class.  Test callers are useful when
 * you want to run an individual test or add it to a
 * suite.
 *
 * Here is an example:
 *
 * class MathTest : public TestCase {
 *         ...
 *     public:
 *         void         setUp ();
 *         void         tearDown ();
 *
 *         void         testAdd ();
 *         void         testSubtract ();
 * };
 *
 * Test *MathTest::suite () {
 *     TestSuite *suite = new TestSuite;
 *
 *     suite->addTest (new TestCaller<MathTest> ("testAdd", testAdd));
 *     return suite;
 * }
 *
 * You can use a TestCaller to bind any test method on a TestCase
 * class, as long as it returns accepts void and returns void.
 *
 * See TestCase
 */
template <class Fixture>
class TestCaller: public TestCase
{
	REFERENCEOBJECT (TestCaller)

	typedef void (Fixture::*TestMethod)();

public:
	TestCaller(const std::string& name, TestMethod test): 
		TestCase(name), 
		_test(test),
		_fixture(new Fixture(name))
	{
	}

protected:
	void runTest()
	{
		(_fixture.get()->*_test)();
	}

	void setUp()
	{
		_fixture.get()->setUp();
	}

	void tearDown()
	{
		_fixture.get()->tearDown();
	}

private:
	TestMethod             _test;
	std::auto_ptr<Fixture> _fixture;
};


} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft


#define CppUnit_addTest(suite, cls, mth) \
	suite->addTest(new CppUnit::TestCaller<cls>(#mth, &cls::mth))


#endif // CppUnit_TestCaller_INCLUDED
