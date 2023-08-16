#include "enum_test.h"

#include <typeinfo> // typeid
#include <type_traits>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace enum_test
{
	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_NOTE( "enum의 기본형은 int" );

			LS();

			{
				OUTPUT_SUBJECT( "Classic" );

				LF();

				DECLARATION_MAIN( enum eTestOldEnum {} );

				LF();

				OUTPUT_VALUE( std::is_enum<eTestOldEnum>::value );

				LF();

				OUTPUT_VALUE( typeid( std::underlying_type<eTestOldEnum>::type ).name() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "enum class" );

				LF();

				DECLARATION_MAIN( enum class eTestNewEnum {} );

				LF();

				OUTPUT_VALUE( std::is_enum<eTestNewEnum>::value );

				LF();

				OUTPUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "enum class + type" );

				LF();

				DECLARATION_MAIN( enum class eTestNewEnum : char {} );

				LF();

				OUTPUT_VALUE( std::is_enum<eTestNewEnum>::value );

				LF();

				OUTPUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Cast::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cast";
		};
	}
	r2tm::DoFunctionT Cast::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			enum class eTestEnum : uint32_t
			{
				one = 1
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				OUTPUT_SUBJECT( "enum 의 범위에 없는 값을 강제 변환" );

				LF();

				DECLARATION_MAIN( const eTestEnum te_1 = static_cast<eTestEnum>( 0 ) );

				LF();

				DECLARATION_MAIN( eTestEnum te_2 );
				PROCESS_MAIN( te_2 = te_1 );
			}

			LS();

			{
				OUTPUT_NOTE( "enum 범위에 없는 값을 강제 변환해서 넣어도 어떤 문제도 발생하지 않는다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "enum_test_convert_with_template.hpp"

	r2tm::TitleFunctionT ConvertWithTemplate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Convert with Template";
		};
	}
	r2tm::DoFunctionT ConvertWithTemplate::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_cpp/item/enum_test_convert_with_template.hpp" );

			LF();

			DECLARATION_MAIN( using namespace enum_test_convert_with_template );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				enum eOldEnum
				{
					  one
					, two
					, three
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( 2, Enum2Value( eOldEnum::three ) );

				LF();

				OUTPUT_VALUE( typeid( Enum2Value( eOldEnum::three ) ).name() );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				enum class eNewEnum : short
				{
					  hana
					, dul
					, set
				};
				OUTPUT_SOURCE_END;

				LF();

				EXPECT_EQ( 1, Enum2Value( eNewEnum::dul ) );

				LF();

				OUTPUT_VALUE( typeid( Enum2Value( eNewEnum::dul ) ).name() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "enum_test_make_enum_with_macro.hpp"

	r2tm::TitleFunctionT MakeEnumWithMacro::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Make Enum With Macro";
		};
	}
	r2tm::DoFunctionT MakeEnumWithMacro::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "REF" );
			OUTPUT_COMMENT(
				"https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings"
			);

			LS();
			
			OUTPUT_FILE( "src/test_cpp/item/enum_test_make_enum_with_macro.hpp" );

			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max );
			OUTPUT_SOURCE_END;

			LS();

			{
				OUTPUT_STRING( "+ Output" );

				LF();

				PROCESS_MAIN( for( int i = 0; eMakeEnumTest::Max >= i; ++i ) { printf( "%d\n", i ); } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "enum_test_xmacro_1.hpp"

	r2tm::TitleFunctionT XMacro_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XMacro 1";
		};
	}
	r2tm::DoFunctionT XMacro_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "REF" );
			OUTPUT_COMMENT(
				"https://en.wikipedia.org/wiki/X_Macro"
			);
			OUTPUT_COMMENT(
				"https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings"
			);


			LS();

			{
				OUTPUT_FILE( "src/test_cpp/item/enum_test_xmacro_1.hpp" );
			}

			LS();

			{
				using namespace enum_test_xmacro_1;
				PROCESS_MAIN( for( int i = 0; i <= eXM1::XM1_Max; ++i ) { printf( "%d : %s\n", i, STR_XM1[i] ); } );
			}

			LS();

			{
				OUTPUT_NOTE( "#define X 와 #undef X 를 활용 다양한 코드를 생성해낸다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "enum_test_xmacro_2.hpp"

	r2tm::TitleFunctionT XMacro_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XMacro 2";
		};
	}
	r2tm::DoFunctionT XMacro_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SUBJECT( "REF" );
			OUTPUT_COMMENT(
				"https://en.wikipedia.org/wiki/X_Macro"
			);
			OUTPUT_COMMENT(
				"https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings"
			);

			LS();

			{
				OUTPUT_FILE( "src/test_cpp/item/enum_test_xmacro_2.def" );

				LF();

				OUTPUT_FILE( "src/test_cpp/item/enum_test_xmacro_2.hpp" );
			}

			LS();

			{
				using namespace enum_test_xmacro_2;
				PROCESS_MAIN( for( int i = 0; i <= eXM2::XM2_Max; ++i ) { printf( "%d : %s\n", i, STR_XM2[i] ); } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}