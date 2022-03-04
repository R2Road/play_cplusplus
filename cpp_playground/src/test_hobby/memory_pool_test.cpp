#include "pch.h"
#include "memory_pool_test.h"

#include <cassert>

#include "base/r2_eTestEndAction.h"

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
	r2::iItem::TitleFuncT Step01::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Pool : Step 01( To do )";
		};
	}

	r2::iItem::DoFuncT Step01::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				MemoryBlock memory_block;
				std::cout << r2::tab << "+ MemoryBlock memory_block;" << r2::linefeed;

				std::cout << r2::tab2 << "- Print : ";
				for( const auto c : memory_block.b )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}