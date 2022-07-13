#include "memory_pool_test.h"

#include <cassert>
#include <stdint.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace r2
{
	template<std::size_t N>
	struct MemoryBlock
	{
		using ElementT = int8_t;

		MemoryBlock() :
			b()
			, size( N )
		{
			memset( b, 0, sizeof( b ) );
		}

		ElementT b[N];
		const std::size_t size;
	};

	class MemoryPool
	{
	public:
		MemoryPool() {}
	};
}

namespace memory_pool_test
{
	r2cm::iItem::TitleFunctionT MemoryAllocation::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Pool : Memory Allocation";
		};
	}

	r2cm::iItem::DoFunctionT MemoryAllocation::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( r2::MemoryBlock<63> memory_block );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.b )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MemoryPool_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Pool : Declaration";
		};
	}

	r2cm::iItem::DoFunctionT MemoryPool_Declaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( r2::MemoryPool memory_pool );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}