//
// File: TestFailure.cpp
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


#include "BaseFrame/CppUnit/TestFailure.h"
#include "BaseFrame/CppUnit/Test.h"


namespace OpenSoft{
namespace BaseFrame{
namespace CppUnit {


// Returns a short description of the failure.
std::string TestFailure::toString()
{
	return _failedTest->toString () + ": " + _thrownException->what();
}

} // namespace CppUnit
} // namespace BaseFrame
} // namespace OpenSoft
