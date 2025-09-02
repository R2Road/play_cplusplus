#pragma once

#include <iomanip>
#include <ostream>

#include "r2_none_copyable.hpp"
#include "r2_direction4_bitwise.hpp"

inline std::ostream& operator<<( std::ostream& o, const r2::Direction4Bitwise& v )
{
	static const int w = 5;

	return o
		<< std::left

		<< "     "

		<< "state : " << std::setw( w ) << static_cast<int>( v.GetState() )

		<< "   "

		<< "x : " << std::setw( w ) << static_cast<int>( v.GetX() )

		<< "   "

		<< "y : " << std::setw( w ) << static_cast<int>( v.GetY() )

		<< std::right
	;
}

namespace r2printer
{
	class STD_Direction4Bitwise : private r2::NoneCopyable
	{
	private:
		STD_Direction4Bitwise() = delete;

	public:
		inline static void Print( const r2::Direction4Bitwise& v )
		{
			std::cout
				<< "\t" "Direction4Bitwise"

				<< v

				<< "\n";
		}
	};
}
