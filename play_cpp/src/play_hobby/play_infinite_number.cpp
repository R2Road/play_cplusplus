#include "play_infinite_number.hpp"

#include <string>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

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
	r2tm::TitleFunctionT _999::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number : _999";
		};
	}
	r2tm::DoFunctionT _999::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SUBJECT( "short의 범위" );

				LF();

				OUT_VALUE( std::numeric_limits<short>::min() );
				OUT_VALUE( std::numeric_limits<short>::max() );
			}

			LS();

			{
				OUT_SUBJECT( "999 + 999 의 결과로 다음 자릿수에는 1이 추가 된다." );
				OUT_SUBJECT( "캐리값 처리에 편리하다." );

				LF();

				DECL_MAIN( const short s_1 = 999 );
				DECL_MAIN( const short s_2 = 999 );

				LF();

				OUT_VALUE( s_1 + s_2 );
			}

			LS();

			{
				OUT_SUBJECT( "기대 하고 있는 출력 방식" );

				LF();

				DECL_MAIN( const short s_1 = 999 );
				DECL_MAIN( const short s_2 = 999 );
				DECL_MAIN( const short s_3 = 999 );

				LF();

				PROC_MAIN( std::cout << s_1 << "," << s_2 << "," << s_3 << r2tm::linefeed );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( InfiniteNumber infinite_number );
				PROC_MAIN( infinite_number = 1999 );

				LF();

				OUT_VALUE(infinite_number.Get() );
			}

			LS();

			{
				DECL_MAIN( InfiniteNumber m( 123 ) );
				EXPECT_EQ( 123, m );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Operator_Plus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number : operator+";
		};
	}
	r2tm::DoFunctionT Operator_Plus::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				DECL_MAIN( auto m = InfiniteNumber( 100 ) + InfiniteNumber( 23 ) );
				EXPECT_EQ( 123ll, m );
			}

			LS();

			{
				unsigned int i = -1;
				unsigned int j = i % 10;
				OUT_VALUE( j );

				LF();

				OUT_BINARY( i );
				OUT_BINARY( j );

				std::to_string( j );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}