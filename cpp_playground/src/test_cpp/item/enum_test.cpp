#include "enum_test.h"

#include <typeinfo> // typeid
#include <type_traits>

#include "r2cm/r2cm_constant.h"
#include "r2cm/r2cm_Inspector.h"

namespace enum_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ " << "enum eTestOldEnum {};" << r2cm::linefeed << r2cm::linefeed;
				enum eTestOldEnum {};

				std::cout << r2cm::tab2 << "- " << "std::is_enum<eTestOldEnum>::value" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- " << std::is_enum<eTestOldEnum>::value << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- " << "typeid( std::underlying_type<eTestEnum_1>::type ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- " << typeid( std::underlying_type<eTestOldEnum>::type ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ " << "enum class eTestNewEnum {};" << r2cm::linefeed << r2cm::linefeed;
				enum class eTestNewEnum {};

				std::cout << r2cm::tab2 << "- " << "std::is_enum<eTestNewEnum>::value" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- " << std::is_enum<eTestNewEnum>::value << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ " << "enum class eTestNewEnum : char {};" << r2cm::linefeed << r2cm::linefeed;
				enum class eTestNewEnum : char {};

				std::cout << r2cm::tab2 << "- " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "- " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << r2cm::linefeed;
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

	r2cm::iItem::TitleFuncT Convert::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Convert";
		};
	}
	r2cm::iItem::DoFuncT Convert::GetDoFunction()
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
#define MAKE_ENUM( enum_name, ... ) enum enum_name { __VA_ARGS__, __COUNT };

	MAKE_ENUM( eMakeEnumTest, One, Two, Three, Max4MakeEnumTest );

	r2cm::iItem::TitleFuncT MakeEnumWithMacro::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Make Enum With Macro";
		};
	}
	r2cm::iItem::DoFuncT MakeEnumWithMacro::GetDoFunction()
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

	r2cm::iItem::TitleFuncT XMacro_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XMacro 1";
		};
	}
	r2cm::iItem::DoFuncT XMacro_1::GetDoFunction()
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

	r2cm::iItem::TitleFuncT XMacro_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "XMacro 2";
		};
	}
	r2cm::iItem::DoFuncT XMacro_2::GetDoFunction()
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