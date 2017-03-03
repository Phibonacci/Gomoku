#include <stdexcept>

#include "Condition.hpp"

namespace ia
{
	Condition::Condition( uint32_t time, uint32_t depht,
		uint32_t rootDepht )
	{
		init( time, depht, rootDepht );
	}

	void		Condition::init( uint32_t time, uint32_t depht,
		uint32_t rootDepht )
	{
		_start = std::chrono::steady_clock::now();
		_maxTime = time;
		_maxDepht = depht;
		_rootDepht = rootDepht;
	}

	bool		Condition::isValidTime()
	{
		if ( _maxTime == 0 ) {
			return true;
		}
		std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
		if ( std::chrono::duration_cast<std::chrono::microseconds>( end - _start ).count() > _maxTime ) {
			return false;
		}
		return true;
	}

	bool		Condition::isValidDepht( uint32_t depht )
	{
		if ( depht < _rootDepht ) {
			throw std::logic_error("the depht of a tree cannot be inferior to the depht of its root; check your Condition class parameters");
		}
		if ( depht - _rootDepht > _maxDepht ) {
			return false;
		}
		return true;
	}

	bool		Condition::isValid( uint32_t depht )
	{
		if ( !isValidTime() || !isValidDepht( depht ) ) {
			return false;
		}
		return true;
	}
}
