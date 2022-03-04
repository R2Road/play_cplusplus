#include "pch.h"
#include "enum_test.h"

#include <typeinfo> // typeid
#include <type_traits>

#include "base/r2_eTestEndAction.h"

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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ " << "enum eTestOldEnum {};" << r2::linefeed << r2::linefeed;
				enum eTestOldEnum {};

				std::cout << r2::tab2 << "- " << "std::is_enum<eTestOldEnum>::value" << r2::linefeed;
				std::cout << r2::tab3 << "- " << std::is_enum<eTestOldEnum>::value << r2::linefeed;

				std::cout << r2::tab2 << "- " << "typeid( std::underlying_type<eTestEnum_1>::type ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "- " << typeid( std::underlying_type<eTestOldEnum>::type ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ " << "enum class eTestNewEnum {};" << r2::linefeed << r2::linefeed;
				enum class eTestNewEnum {};

				std::cout << r2::tab2 << "- " << "std::is_enum<eTestNewEnum>::value" << r2::linefeed;
				std::cout << r2::tab3 << "- " << std::is_enum<eTestNewEnum>::value << r2::linefeed;

				std::cout << r2::tab2 << "- " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "- " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "+ " << "enum class eTestNewEnum : char {};" << r2::linefeed << r2::linefeed;
				enum class eTestNewEnum : char {};

				std::cout << r2::tab2 << "- " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << r2::linefeed;
				std::cout << r2::tab3 << "- " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
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
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << r2::tab << "template<typename EnumT>" << r2::linefeed;
			std::cout << r2::tab << "constexpr auto Enum2Value( EnumT e )" << r2::linefeed;
			std::cout << r2::tab << "{" << r2::linefeed;
			std::cout << r2::tab2 << "return static_cast<std::underlying_type_t<EnumT>>( e );" << r2::linefeed;
			std::cout << r2::tab << "}" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << r2::tab << "enum eOldEnum" << r2::linefeed;
				std::cout << r2::tab << "{" << r2::linefeed;
				std::cout << r2::tab2 << "one" << r2::linefeed;
				std::cout << r2::tab2 << ", two" << r2::linefeed;
				std::cout << r2::tab2 << ", three" << r2::linefeed;
				std::cout << r2::tab << "}" << r2::linefeed << r2::linefeed;

				enum eOldEnum
				{
					one
					, two
					, three
				};

				std::cout << r2::tab << "+ " << "Enum2Value( eOldEnum::three )" << r2::linefeed;
				std::cout << r2::tab2 << "- " << Enum2Value( eOldEnum::three ) << r2::linefeed;
				std::cout << r2::tab2 << "- " << typeid( Enum2Value( eOldEnum::three ) ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << r2::tab << "enum class eNewEnum : short" << r2::linefeed;
				std::cout << r2::tab << "{" << r2::linefeed;
				std::cout << r2::tab2 << "hana" << r2::linefeed;
				std::cout << r2::tab2 << ", dul" << r2::linefeed;
				std::cout << r2::tab2 << ", set" << r2::linefeed;
				std::cout << r2::tab << "}" << r2::linefeed << r2::linefeed;

				enum class eNewEnum : short
				{
					hana
					, dul
					, set
				};

				std::cout << r2::tab << "+ " << "Enum2Value( eNewEnum::dul )" << r2::linefeed;
				std::cout << r2::tab2 << "- " << Enum2Value( eNewEnum::dul ) << r2::linefeed;
				std::cout << r2::tab2 << "- " << typeid( Enum2Value( eNewEnum::dul ) ).name() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}