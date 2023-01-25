#include "play_myint.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace play_myint
{
	struct MyInt
	{
		MyInt()
		{}
		explicit MyInt( const int i )
		{}

		char mBuffer[3] = {};

		MyInt operator+( const MyInt& other )
		{
			return MyInt();
		}

		operator int32_t()
		{
			return 0;
		}
	};

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MyInt";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( MyInt m );
				EXPECT_EQ( 0, m );

				OUTPUT_BINARY( m );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( MyInt m( 123 ) );
				EXPECT_EQ( 123, m );

				OUTPUT_BINARY( m );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Operator_Plus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "MyInt : operator+";
		};
	}
	r2cm::iItem::DoFunctionT Operator_Plus::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( auto m = MyInt( 100 ) + MyInt( 23 ) );
				EXPECT_EQ( 123ll, m );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}