#include "pch.h"
#include "memory_pool_test.h"

#include <cassert>

#include "r2_eTestResult.h"

namespace
{
	template<std::size_t N>
	struct CharBuffer
	{
		CharBuffer() :
			b()
			, size( N )
		{
			memset( b, 0, sizeof( b ) );
		}

		char b[N];
		const std::size_t size;
	};

	using MemoryBlock = CharBuffer<64>;
}

namespace memory_pool_test
{
	r2::iTest::TitleFunc Step01::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Pool : Step 01";
		};
	}

	r2::iTest::DoFunc Step01::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				MemoryBlock memory_block;
				std::cout << "\t + " << "MemoryBlock memory_block;" << r2::linefeed;

				std::cout << "\t\t - Print : ";
				for( const auto c : memory_block.b )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}