//
// LeakDetector_WIN32.h
//
// $Id: //poco/Main/Foundation/include/Poco/LeakDetector_WIN32.h#8 $
//
// Library: Foundation
// Package: Core
// Module:  LeakDetector
//
// Definition of the LeakDetectorImpl class for WIN32.
//
// Copyright (c) 2004-2009, Applied Informatics Software Engineering GmbH.
// and Contributors.
//
// Permission is hereby granted, free of charge, to any person or organization
// obtaining a copy of the software and accompanying documentation covered by
// this license (the "Software") to use, reproduce, display, distribute,
// execute, and transmit the Software, and to prepare derivative works of the
// Software, and to permit third-parties to whom the Software is furnished to
// do so, all subject to the following:
// 
// The copyright notices in the Software and this entire statement, including
// the above license grant, this restriction and the following disclaimer,
// must be included in all copies of the Software, in whole or in part, and
// all derivative works of the Software, unless such copies or derivative
// works are solely in the form of machine-executable object code generated by
// a source language processor.
// 
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE, TITLE AND NON-INFRINGEMENT. IN NO EVENT
// SHALL THE COPYRIGHT HOLDERS OR ANYONE DISTRIBUTING THE SOFTWARE BE LIABLE
// FOR ANY DAMAGES OR OTHER LIABILITY, WHETHER IN CONTRACT, TORT OR OTHERWISE,
// ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER
// DEALINGS IN THE SOFTWARE.
//


#ifndef Foundation_LeakDetector_WIN32_INCLUDED
#define Foundation_LeakDetector_WIN32_INCLUDED


#include "Poco/Foundation.h"
#include "Poco/UnWindows.h"

// http://msdn.microsoft.com/en-us/library/x98tx3cf.aspx
#define _CRTDBG_MAP_ALLOC
#include <stdlib.h>
#include <crtdbg.h>
#ifdef _DEBUG   
	#ifndef DBG_NEW      
		#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )      
		#define new DBG_NEW   
	#endif
#endif  // _DEBUG


namespace Poco {


class Foundation_API LeakDetectorImpl
{
protected:
	static const std::size_t CHECK_POINT_COUNT = 3;

	LeakDetectorImpl();				
	~LeakDetectorImpl();

	void checkPointImpl();
	bool hasLeaksImpl();
	void resetImpl();
	void dumpImpl();

private:
	_CrtMemState _state[CHECK_POINT_COUNT];
	std::size_t  _cpIndex;
	bool         _hasLeaks;
};


//
// inlines
//
inline bool LeakDetectorImpl::hasLeaksImpl()
{
	return _hasLeaks;
}


inline void LeakDetectorImpl::dumpImpl()
{
	_CrtMemDumpStatistics(&_state[2]);
}


} // namespace Poco


#endif // Foundation_LeakDetector_WIN32_INCLUDED
