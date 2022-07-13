#include "memory_pool_test.h"

#include <cassert>
#include <stdint.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace r2
{
	template<uint32_t N>
	struct MemoryBlock
	{
		using ElementT = int8_t;
		using SizeT = uint32_t;

		MemoryBlock() :
			b()
			, size( N )
		{
			memset( b, 0, sizeof( b ) );
		}

		ElementT b[N];
		const SizeT size;
	};

	class MemoryPool
	{
	public:
		MemoryPool() : mBlock()
		{}

		template<typename T>
		T* New()
		{
			return nullptr;
		}

	private:
		MemoryBlock<64u> mBlock;
	};
}

namespace memory_pool_test
{
	r2cm::iItem::TitleFunctionT MemoryBlock_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Block : Declaration";
		};
	}

	r2cm::iItem::DoFunctionT MemoryBlock_Declaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const uint32_t memory_block_size = 63 );
				DECLARATION_MAIN( r2::MemoryBlock<memory_block_size> memory_block );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( memory_block_size, memory_block.size );

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



	r2cm::iItem::TitleFunctionT MemoryPool_New::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Pool : New";
		};
	}

	r2cm::iItem::DoFunctionT MemoryPool_New::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::MemoryPool pool );

			std::cout << r2cm::split;

			{
				EXPECT_EQ( nullptr, pool.New<char>() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}