#include "play_cpp_enum.hpp"

#include <typeinfo> // typeid
#include <type_traits>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_cpp_enum
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

			OUT_NOTE( "enum의 기본형은 int" );

			LS();

			{
				OUT_SUBJECT( "Classic" );

				LF();

				DECL_MAIN( enum eTestOldEnum {} );

				LF();

				OUT_VALUE( std::is_enum<eTestOldEnum>::value );

				LF();

				OUT_VALUE( typeid( std::underlying_type<eTestOldEnum>::type ).name() );
			}

			LS();

			{
				OUT_SUBJECT( "enum class" );

				LF();

				DECL_MAIN( enum class eTestNewEnum {} );

				LF();

				OUT_VALUE( std::is_enum<eTestNewEnum>::value );

				LF();

				OUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
			}

			LS();

			{
				OUT_SUBJECT( "enum class + type" );

				LF();

				DECL_MAIN( enum class eTestNewEnum : char {} );

				LF();

				OUT_VALUE( std::is_enum<eTestNewEnum>::value );

				LF();

				OUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
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

			OUT_SOURCE_READY_N_BEGIN;
			enum class eTestEnum : uint32_t
			{
				one = 1
			};
			OUT_SOURCE_END;

			LS();

			{
				OUT_SUBJECT( "enum 의 범위에 없는 값을 강제 변환" );

				LF();

				DECL_MAIN( const eTestEnum te_1 = static_cast<eTestEnum>( 0 ) );

				LF();

				DECL_MAIN( eTestEnum te_2 );
				PROC_MAIN( te_2 = te_1 );
			}

			LS();

			{
				OUT_NOTE( "enum 범위에 없는 값을 강제 변환해서 넣어도 어떤 문제도 발생하지 않는다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "play_cpp_enum_helper___convert_with_template.hpp"

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

			OUT_FILE( "source/play_cpp/play_cpp_enum_helper___convert_with_template.hpp" );

			LF();

			DECL_MAIN( using namespace play_cpp_enum_helper___convert_with_template );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				enum eOldEnum
				{
					  one
					, two
					, three
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_EQ( 2, Enum2Value( eOldEnum::three ) );

				LF();

				OUT_VALUE( typeid( Enum2Value( eOldEnum::three ) ).name() );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				enum class eNewEnum : short
				{
					  hana
					, dul
					, set
				};
				OUT_SOURCE_END;

				LF();

				EXPECT_EQ( 1, Enum2Value( eNewEnum::dul ) );

				LF();

				OUT_VALUE( typeid( Enum2Value( eNewEnum::dul ) ).name() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "play_cpp_enum_helper___make_enum_with_macro.hpp"

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

			OUT_SUBJECT( "REF" );
			OUT_COMMENT(
				"https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings"
			);

			LS();
			
			OUT_FILE( "source/play_cpp/play_cpp_enum_helper___make_enum_with_macro.hpp" );

			LS();

			OUT_SOURCE_READY_N_BEGIN;
			MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max );
			OUT_SOURCE_END;

			LS();

			{
				OUT_STRING( "+ Output" );

				LF();

				PROC_MAIN( for( int i = 0; eMakeEnumTest::Max >= i; ++i ) { printf( "%d\n", i ); } );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "play_cpp_enum_helper___xmacro_1.hpp"

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

			OUT_SUBJECT( "REF" );
			OUT_COMMENT(
				"https://en.wikipedia.org/wiki/X_Macro"
			);
			OUT_COMMENT(
				"https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings"
			);


			LS();

			{
				OUT_FILE( "source/play_cpp/play_cpp_enum_helper___xmacro_1.hpp" );
			}

			LS();

			{
				using namespace play_cpp_enum_helper___xmacro_1;
				PROC_MAIN( for( int i = 0; i <= eXM1::XM1_Max; ++i ) { printf( "%d : %s\n", i, STR_XM1[i] ); } );
			}

			LS();

			{
				OUT_NOTE( "#define X 와 #undef X 를 활용 다양한 코드를 생성해낸다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



#include "play_cpp_enum_helper___xmacro_2.hpp"

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

			OUT_SUBJECT( "REF" );
			OUT_COMMENT(
				"https://en.wikipedia.org/wiki/X_Macro"
			);
			OUT_COMMENT(
				"https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings"
			);

			LS();

			{
				OUT_FILE( "source/play_cpp/play_cpp_enum_helper___xmacro_2.def" );

				LF();

				OUT_FILE( "source/play_cpp/play_cpp_enum_helper___xmacro_2.hpp" );
			}

			LS();

			{
				using namespace play_cpp_enum_helper___xmacro_2;
				PROC_MAIN( for( int i = 0; i <= eXM2::XM2_Max; ++i ) { printf( "%d : %s\n", i, STR_XM2[i] ); } );
			}

			LS();

			{
				OUT_NOTE( "데이터 파일을 분리해서 include 로 처리한다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}