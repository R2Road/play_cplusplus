#include "enum_test.h"

#include <typeinfo> // typeid
#include <type_traits>

#include "r2cm/r2cm_constant.h"

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