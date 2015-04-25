//
// File: CoreTestSuite.h
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

#ifndef CoreTestSuite_INCLUDED
#define CoreTestSuite_INCLUDED

#include "BaseFrame/CppUnit/TestSuite.h"

using namespace OpenSoft::BaseFrame;

class CoreTestSuite
{
public:
	static CppUnit::Test* suite();
};


#endif // CoreTestSuite_INCLUDED
