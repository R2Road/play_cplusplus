#include "play_infinite_number.h"

#include <string>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	//
	// > Bit 단위로 메모리를 할당할 방법은 없기 때문에 primitive type을 활용해야 한다.
	// > 값을 변경 시키기 이전에 결과 값이 경계면을 넘어가는지 검사 해야 한다.
	// > 결과 값이 경계면을 넘어간다면 경계면 너머의 처리를 위해 메모리를 할당 해야 한다.
	//

	//
	// Short Range : -32,768 ~ 32,767
	//

	class InfiniteNumber
	{
	public:
		InfiniteNumber() : mValue( 0 )
		{}
		explicit InfiniteNumber( const short i )
		{}

		void operator=( const short new_value )
		{
			mValue = new_value;
		}

		InfiniteNumber operator+( const InfiniteNumber& other )
		{
			return InfiniteNumber();
		}

		operator int32_t()
		{
			return 0;
		}

		//
		//
		//
		short Get() const
		{
			return mValue;
		}

	private:
		short mValue;
	};
}

namespace play_infinite_number
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( InfiniteNumber infinite_number );
				PROCESS_MAIN( infinite_number = 1999 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE(infinite_number.Get() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( InfiniteNumber m( 123 ) );
				EXPECT_EQ( 123, m );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Operator_Plus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number : operator+";
		};
	}
	r2cm::iItem::DoFunctionT Operator_Plus::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto m = InfiniteNumber( 100 ) + InfiniteNumber( 23 ) );
				EXPECT_EQ( 123ll, m );
			}

			std::cout << r2cm::split;

			{
				unsigned int i = -1;
				unsigned int j = i % 10;
				OUTPUT_VALUE( j );

				std::cout << r2cm::linefeed;

				OUTPUT_BINARY( i );
				OUTPUT_BINARY( j );

				std::to_string( j );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}