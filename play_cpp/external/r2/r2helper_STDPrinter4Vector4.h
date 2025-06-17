#pragma once

#include <iomanip>
#include <ostream>

#include "r2_NoneCopyable.h"
#include "r2_Vector4.h"

namespace r2helper
{
	class STDPrinter4Vector4 : private r2::NoneCopyable
	{
	private:
		STDPrinter4Vector4() = delete;

	public:
		inline static void Print( const r2::Vector4& v )
		{
			static const int w = 10;

			std::cout
				<< std::left

				<< "\t" "Vector4"

				<< "   "
				   "x : " << std::setw( w ) << v.x
				<< "   "
				   "y : " << std::setw( w ) << v.y
				<< "   "
				   "z : " << std::setw( w ) << v.z
				<< "   "
				   "w : " << std::setw( w ) << v.w

				<< "\n"

				<< std::right;
		}
	};
}

inline std::ostream& operator<<( std::ostream& o, const r2::Vector4& v )
{
	static const int w = 10;

	return o
		<< std::left

		<< "\t"

		<< std::setw( w ) << v.x
		<< "   "
		<< std::setw( w ) << v.y
		<< "   "
		<< std::setw( w ) << v.z
		<< "   "
		<< std::setw( w ) << v.w

		<< std::right;
}