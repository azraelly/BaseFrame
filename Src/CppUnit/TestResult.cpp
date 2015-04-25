//
// File: TestResult.cpp
//
// Date: 2015/04/25 10:21
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


#include "BaseFrame/CppUnit/TestResult.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


// Destroys a test result
TestResult::~TestResult()
{
	std::vector<TestFailure*>::iterator it;

	for (it = _errors.begin(); it != _errors.end(); ++it)
		delete *it;

	for (it = _failures.begin(); it != _failures.end(); ++it)
		delete *it;

	delete _syncObject;
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft
