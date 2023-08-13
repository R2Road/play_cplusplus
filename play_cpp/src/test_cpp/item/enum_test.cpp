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

			{
				OUTPUT_SUBJECT( "Classic" );

				LF();

				DECLARATION_MAIN( enum eTestOldEnum {} );

				LF();

				OUTPUT_VALUE( std::is_enum<eTestOldEnum>::value );
				OUTPUT_VALUE( typeid( std::underlying_type<eTestOldEnum>::type ).name() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "enum class" );

				LF();

				DECLARATION_MAIN( enum class eTestNewEnum {} );

				LF();

				OUTPUT_VALUE( std::is_enum<eTestNewEnum>::value );
				OUTPUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
			}

			LS();

			{
				OUTPUT_SUBJECT( "enum class + type" );

				LF();

				DECLARATION_MAIN( enum class eTestNewEnum : char {} );

				LF();

				OUTPUT_VALUE( std::is_enum<eTestNewEnum>::value );
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
}


namespace enum_test
{
	template<typename EnumT>
	constexpr auto Enum2Value( EnumT e )
	{
		return static_cast<std::underlying_type_t<EnumT>>( e );
	}

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

			std::cout << r2tm::tab << "template<typename EnumT>" << r2tm::linefeed;
			std::cout << r2tm::tab << "constexpr auto Enum2Value( EnumT e )" << r2tm::linefeed;
			std::cout << r2tm::tab << "{" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "return static_cast<std::underlying_type_t<EnumT>>( e );" << r2tm::linefeed;
			std::cout << r2tm::tab << "}" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "enum eOldEnum" << r2tm::linefeed;
				std::cout << r2tm::tab << "{" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "one" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ", two" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ", three" << r2tm::linefeed;
				std::cout << r2tm::tab << "}" << r2tm::linefeed << r2tm::linefeed;

				enum eOldEnum
				{
					one
					, two
					, three
				};

				std::cout << r2tm::tab << "+ " << "Enum2Value( eOldEnum::three )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << Enum2Value( eOldEnum::three ) << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << typeid( Enum2Value( eOldEnum::three ) ).name() << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "enum class eNewEnum : short" << r2tm::linefeed;
				std::cout << r2tm::tab << "{" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "hana" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ", dul" << r2tm::linefeed;
				std::cout << r2tm::tab2 << ", set" << r2tm::linefeed;
				std::cout << r2tm::tab << "}" << r2tm::linefeed << r2tm::linefeed;

				enum class eNewEnum : short
				{
					hana
					, dul
					, set
				};

				std::cout << r2tm::tab << "+ " << "Enum2Value( eNewEnum::dul )" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << Enum2Value( eNewEnum::dul ) << r2tm::linefeed;
				std::cout << r2tm::tab2 << "- " << typeid( Enum2Value( eNewEnum::dul ) ).name() << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace enum_test
{
#define MAKE_ENUM( enum_name, ... ) enum enum_name { __VA_ARGS__ };

	MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max4MakeEnumTest );

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

			std::cout << r2tm::tab << "+ Ref" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "#define MAKE_ENUM( enum_name, ... ) enum enum_name { __VA_ARGS__, __COUNT };" << r2tm::linefeed2;

				std::cout << r2tm::tab << "MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max4MakeEnumTest );" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ " << "Output" << r2tm::linefeed2;

				for( int i = 0; i <= eMakeEnumTest::Max4MakeEnumTest; ++i )
				{
					printf( "%d\n", i );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace enum_test
{
#define X_ENUMS				\
		X( XM1_First ),		\
		X( XM1_Second ),	\
		X( XM1_Third ),		\
		X( XM1_Max ),

	enum eTestEnum4XM1
	{
#define X( e ) e
		X_ENUMS
#undef X
	};

	const char* STR_TestEnum4XM1[] = {
#define X( e ) #e
		X_ENUMS
#undef X
	};

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

			std::cout << r2tm::tab << "+ Ref" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "https://en.wikipedia.org/wiki/X_Macro" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings" << r2tm::linefeed;

			LS();

			{
				std::cout << r2tm::tab << "#define X_ENUMS" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "X( XM1_First )," << r2tm::linefeed;
				std::cout << r2tm::tab2 << "X( XM1_Second )," << r2tm::linefeed;
				std::cout << r2tm::tab2 << "X( XM1_Third )," << r2tm::linefeed;
				std::cout << r2tm::tab2 << "X( XM1_Max )," << r2tm::linefeed;

				LF();

				std::cout << r2tm::tab << "enum eTestEnum4XM1" << r2tm::linefeed;
				std::cout << r2tm::tab << "{" << r2tm::linefeed;
				std::cout << r2tm::tab << "#define X( e ) e" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "X_ENUMS" << r2tm::linefeed;
				std::cout << r2tm::tab << "#undef X" << r2tm::linefeed;
				std::cout << r2tm::tab << "};" << r2tm::linefeed;

				LF();

				std::cout << r2tm::tab << "const char* STR_TestEnum4XM1[] = {" << r2tm::linefeed;
				std::cout << r2tm::tab << "#define X( e ) #e" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "X_ENUMS" << r2tm::linefeed;
				std::cout << r2tm::tab << "#undef X" << r2tm::linefeed;
				std::cout << r2tm::tab << "};" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ " << "Output" << r2tm::linefeed2;

				for( int i = 0; i <= eTestEnum4XM1::XM1_Max; ++i )
				{
					printf( "%d : %s\n", i, STR_TestEnum4XM1[i] );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace enum_test
{
	enum eTestEnum4XM2
	{
#define X( e ) e,
		#include "enum_test_xmacro_2.def"
#undef X
	};

	const char* STR_TestEnum4XM2[] = {
#define X( e ) #e,
		#include "enum_test_xmacro_2.def"
#undef X
	};

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

			std::cout << r2tm::tab << "+ Ref" << r2tm::linefeed2;
			std::cout << r2tm::tab2 << "https://en.wikipedia.org/wiki/X_Macro" << r2tm::linefeed;
			std::cout << r2tm::tab2 << "https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings" << r2tm::linefeed;

			LS();

			{
				OUTPUT_FILE( "src/test_cpp/item/enum_test_xmacro_2.def" );

				LF();

				std::cout << r2tm::tab << "enum eTestEnum4XM2" << r2tm::linefeed;
				std::cout << r2tm::tab << "{" << r2tm::linefeed;
				std::cout << r2tm::tab << "#define X( e ) e" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "#include \"enum_test_xmacro_2.def\"" << r2tm::linefeed;
				std::cout << r2tm::tab << "#undef X" << r2tm::linefeed;
				std::cout << r2tm::tab << "};" << r2tm::linefeed;

				LF();

				std::cout << r2tm::tab << "const char* STR_TestEnum4MX[] = {" << r2tm::linefeed;
				std::cout << r2tm::tab << "#define X( e ) #e" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "#include \"enum_test_xmacro_2.def\"" << r2tm::linefeed;
				std::cout << r2tm::tab << "#undef X" << r2tm::linefeed;
				std::cout << r2tm::tab << "};" << r2tm::linefeed;
			}

			LS();

			{
				std::cout << r2tm::tab << "+ " << "Output" << r2tm::linefeed2;

				for( int i = 0; i <= eTestEnum4XM2::XM2_Max; ++i )
				{
					printf( "%d : %s\n", i, STR_TestEnum4XM2[i] );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}