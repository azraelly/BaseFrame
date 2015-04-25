//
// File: BaseFrameTestSuite.cpp
//
// Date: 2015/04/25 12:10
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
#include "BaseFrameTestSuite.h"


CppUnit::Test* BaseFrameTestSuite::suite()
{
	CppUnit::TestSuite* pSuite = new CppUnit::TestSuite("BaseFrameTestSuite");

	pSuite->addTest(CoreTestSuite::suite());

	return pSuite;
}
