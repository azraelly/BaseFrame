//
// File: CoreTestSuite.cpp
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

#include "CoreTestSuite.h"
#include "CoreTest.h"
#include "StringTest.h"



CppUnit::Test* CoreTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("CoreTestSuite");

	pSuite->addTest(CoreTest::suite());
	pSuite->addTest(StringTest::suite());

	return pSuite;
}
