#ifndef Foundation_LeakDetector_OTHER_INCLUDED
#define Foundation_LeakDetector_OTHER_INCLUDED


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
//	_CrtMemState _state[CHECK_POINT_COUNT];
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
//	_CrtMemDumpStatistics(&_state[2]);
}


} // namespace Poco


#endif // Foundation_LeakDetector_OTHER_INCLUDED
