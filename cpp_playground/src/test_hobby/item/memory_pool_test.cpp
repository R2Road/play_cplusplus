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
		using SizeT = uint64_t;

		MemoryBlock() :
			size( N )
			, buffer()
			, pb( buffer )
		{
			memset( buffer, 0, sizeof( buffer ) );
		}

		template<typename T>
		T* New()
		{
			void* ret = nullptr;

			ret = std::align( alignof( T ), sizeof( T ), pb, size );
			if( ret )
			{
				pb = static_cast<ElementT*>( pb ) + sizeof( T );
				size -= sizeof( T );
			}

			return reinterpret_cast<T*>( ret );
		}

		SizeT size;
		ElementT buffer[N];
		void* pb;
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

			DECLARATION_MAIN( const uint32_t memory_block_size = 64u );
			DECLARATION_MAIN( r2::MemoryBlock<memory_block_size> memory_block );

			std::cout << r2cm::linefeed;

			{
				EXPECT_EQ( memory_block_size, memory_block.size );
				OUTPUT_VALUE( memory_block.size );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( memory_block.pb, memory_block.buffer );
				OUTPUT_VALUE( memory_block.pb );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.buffer )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MemoryBlock_New_FundamentalType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Block : New( Fundamental Type )";
		};
	}

	r2cm::iItem::DoFunctionT MemoryBlock_New_FundamentalType::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const uint32_t memory_block_size = 64u );
			DECLARATION_MAIN( r2::MemoryBlock<memory_block_size> memory_block );

			std::cout << r2cm::linefeed;

			{
				EXPECT_EQ( memory_block_size, memory_block.size );
				OUTPUT_VALUE( memory_block.size );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( memory_block.pb, memory_block.buffer );
				OUTPUT_VALUE( memory_block.pb );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto temp = memory_block.New<long long>() );
				PROCESS_MAIN( memset( temp, 1, sizeof( long long ) ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.buffer )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto temp = memory_block.New<long>() );
				PROCESS_MAIN( memset( temp, 2, sizeof( long ) ) );
			
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.buffer )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto temp = memory_block.New<char>() );
				PROCESS_MAIN( memset( temp, 3, sizeof( char ) ) );
			}

			{
				DECLARATION_MAIN( auto temp = memory_block.New<char>() );
				PROCESS_MAIN( memset( temp, 4, sizeof( char ) ) );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.buffer )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;
			{
				DECLARATION_MAIN( auto temp = memory_block.New<int>() );
				PROCESS_MAIN( memset( temp, 5, sizeof( int ) ) );
			
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.buffer )
				{
					std::cout << static_cast<int>( c );
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MemoryBlock_New_UserDefinedType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Memory Block : New( User-Defined Type )";
		};
	}

	r2cm::iItem::DoFunctionT MemoryBlock_New_UserDefinedType::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			DECLARATION_MAIN( const uint32_t memory_block_size = 64u );
			DECLARATION_MAIN( r2::MemoryBlock<memory_block_size> memory_block );

			std::cout << r2cm::linefeed;

			{
				EXPECT_EQ( memory_block_size, memory_block.size );
				OUTPUT_VALUE( memory_block.size );

				std::cout << r2cm::linefeed;

				EXPECT_EQ( memory_block.pb, memory_block.buffer );
				OUTPUT_VALUE( memory_block.pb );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct TestStruct1 { double d1; double d2; char c1; } );

				DECLARATION_MAIN( auto temp = memory_block.New<TestStruct1>() );
				PROCESS_MAIN( memset( temp, 1, sizeof( TestStruct1 ) ) );
				PROCESS_MAIN( temp->c1 = 2 );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "- Print : ";
				for( const auto c : memory_block.buffer )
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