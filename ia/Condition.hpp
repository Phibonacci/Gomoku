#ifndef CONDITION_HPP
#define CONDITION_HPP

#include <ctime>
#include <chrono>

namespace ia
{

	class Condition
	{
		uint32_t									_depht;
		uint32_t									_maxDepht;
		uint32_t									_rootDepht;
		std::chrono::steady_clock::time_point		_start;
		uint32_t									_maxTime;

		bool										isValidTime();
		bool										isValidDepht( uint32_t depht );
	public:
		Condition( uint32_t time,
			uint32_t depht,
			uint32_t rootDepht = 0 );

		void										init( uint32_t time, uint32_t depht, uint32_t rootDepht );
		bool										isValid( uint32_t depht );
	};

}

#endif // !CONDITION_HPP
