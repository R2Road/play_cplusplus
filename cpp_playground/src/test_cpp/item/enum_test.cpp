#include "enum_test.h"

#include <typeinfo> // typeid
#include <type_traits>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace enum_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( enum eTestOldEnum {} );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::is_enum<eTestOldEnum>::value );
				OUTPUT_VALUE( typeid( std::underlying_type<eTestOldEnum>::type ).name() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( enum class eTestNewEnum {} );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::is_enum<eTestNewEnum>::value );
				OUTPUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( enum class eTestNewEnum : char {} );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( std::is_enum<eTestNewEnum>::value );
				OUTPUT_VALUE( typeid( std::underlying_type<eTestNewEnum>::type ).name() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Cast::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Cast";
		};
	}
	r2cm::iItem::DoFunctionT Cast::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( enum class eTestEnum : uint32_t { one = 1 } );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( const eTestEnum te_1 = static_cast<eTestEnum>( 0 ) );
				DECLARATION_MAIN( eTestEnum te_2 );
				PROCESS_MAIN( te_2 = te_1 );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ enum 의 범위에 없는 값을 강제 변환해서 넣어도 어떤 문제도 발생하지 않는다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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

	r2cm::iItem::TitleFunctionT ConvertWithTemplate::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Convert with Template";
		};
	}
	r2cm::iItem::DoFunctionT ConvertWithTemplate::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "template<typename EnumT>" << r2cm::linefeed;
			std::cout << r2cm::tab << "constexpr auto Enum2Value( EnumT e )" << r2cm::linefeed;
			std::cout << r2cm::tab << "{" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "return static_cast<std::underlying_type_t<EnumT>>( e );" << r2cm::linefeed;
			std::cout << r2cm::tab << "}" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "enum eOldEnum" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "one" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ", two" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ", three" << r2cm::linefeed;
				std::cout << r2cm::tab << "}" << r2cm::linefeed << r2cm::linefeed;

				enum eOldEnum
				{
					one
					, two
					, three
				};

				std::cout << r2cm::tab << "+ " << "Enum2Value( eOldEnum::three )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << Enum2Value( eOldEnum::three ) << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << typeid( Enum2Value( eOldEnum::three ) ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "enum class eNewEnum : short" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "hana" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ", dul" << r2cm::linefeed;
				std::cout << r2cm::tab2 << ", set" << r2cm::linefeed;
				std::cout << r2cm::tab << "}" << r2cm::linefeed << r2cm::linefeed;

				enum class eNewEnum : short
				{
					hana
					, dul
					, set
				};

				std::cout << r2cm::tab << "+ " << "Enum2Value( eNewEnum::dul )" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << Enum2Value( eNewEnum::dul ) << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- " << typeid( Enum2Value( eNewEnum::dul ) ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace enum_test
{
#define MAKE_ENUM( enum_name, ... ) enum enum_name { __VA_ARGS__ };

	MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max4MakeEnumTest );

	r2cm::iItem::TitleFunctionT MakeEnumWithMacro::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Make Enum With Macro";
		};
	}
	r2cm::iItem::DoFunctionT MakeEnumWithMacro::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Ref" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "#define MAKE_ENUM( enum_name, ... ) enum enum_name { __VA_ARGS__, __COUNT };" << r2cm::linefeed2;

				std::cout << r2cm::tab << "MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max4MakeEnumTest );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ " << "Output" << r2cm::linefeed2;

				for( int i = 0; i <= eMakeEnumTest::Max4MakeEnumTest; ++i )
				{
					printf( "%d\n", i );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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

	r2cm::iItem::TitleFunctionT XMacro_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XMacro 1";
		};
	}
	r2cm::iItem::DoFunctionT XMacro_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Ref" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "https://en.wikipedia.org/wiki/X_Macro" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "#define X_ENUMS" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "X( XM1_First )," << r2cm::linefeed;
				std::cout << r2cm::tab2 << "X( XM1_Second )," << r2cm::linefeed;
				std::cout << r2cm::tab2 << "X( XM1_Third )," << r2cm::linefeed;
				std::cout << r2cm::tab2 << "X( XM1_Max )," << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "enum eTestEnum4XM1" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab << "#define X( e ) e" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "X_ENUMS" << r2cm::linefeed;
				std::cout << r2cm::tab << "#undef X" << r2cm::linefeed;
				std::cout << r2cm::tab << "};" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "const char* STR_TestEnum4XM1[] = {" << r2cm::linefeed;
				std::cout << r2cm::tab << "#define X( e ) #e" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "X_ENUMS" << r2cm::linefeed;
				std::cout << r2cm::tab << "#undef X" << r2cm::linefeed;
				std::cout << r2cm::tab << "};" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ " << "Output" << r2cm::linefeed2;

				for( int i = 0; i <= eTestEnum4XM1::XM1_Max; ++i )
				{
					printf( "%d : %s\n", i, STR_TestEnum4XM1[i] );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
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

	r2cm::iItem::TitleFunctionT XMacro_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XMacro 2";
		};
	}
	r2cm::iItem::DoFunctionT XMacro_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Ref" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "https://en.wikipedia.org/wiki/X_Macro" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "https://stackoverflow.com/questions/207976/how-to-easily-map-c-enums-to-strings" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				SHOW_FILE( "src/test_cpp/item/enum_test_xmacro_2.def" );

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "enum eTestEnum4XM2" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab << "#define X( e ) e" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "#include \"enum_test_xmacro_2.def\"" << r2cm::linefeed;
				std::cout << r2cm::tab << "#undef X" << r2cm::linefeed;
				std::cout << r2cm::tab << "};" << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab << "const char* STR_TestEnum4MX[] = {" << r2cm::linefeed;
				std::cout << r2cm::tab << "#define X( e ) #e" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "#include \"enum_test_xmacro_2.def\"" << r2cm::linefeed;
				std::cout << r2cm::tab << "#undef X" << r2cm::linefeed;
				std::cout << r2cm::tab << "};" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ " << "Output" << r2cm::linefeed2;

				for( int i = 0; i <= eTestEnum4XM2::XM2_Max; ++i )
				{
					printf( "%d : %s\n", i, STR_TestEnum4XM2[i] );
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}