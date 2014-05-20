#include "Poco/LeakDetector_OTHER.h"


namespace Poco {


LeakDetectorImpl::LeakDetectorImpl():_cpIndex(0), _hasLeaks(false)
{
//	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
//	_CrtSetReportMode(_CRT_ERROR, _CRTDBG_MODE_DEBUG);
}


LeakDetectorImpl::~LeakDetectorImpl()
{
}


void LeakDetectorImpl::checkPointImpl()
{
	if (0 == _cpIndex) resetImpl();

//	_CrtMemCheckpoint(&_state[_cpIndex]);
	if (1 == _cpIndex++)
	{
//		_hasLeaks = (0 != _CrtMemDifference(&_state[2], &_state[0], &_state[1]));
		_cpIndex = 0;
	}
}


void LeakDetectorImpl::resetImpl()
{
	_cpIndex = 0;
	_hasLeaks = false;
//	std::memset(_state, 0, sizeof(_CrtMemState) * CHECK_POINT_COUNT);
}


} // namespace Poco
