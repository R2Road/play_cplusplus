#include "enum_test.h"

#include <iostream>
#include <typeinfo> // typeid
#include <type_traits>

namespace enum_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Enum : Basic";
		};
	}
	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Enum ==" << std::endl << std::endl;

			{
				std::cout << "\t + " << "enum eTestOldEnum {};" << std::endl << std::endl;
				enum eTestOldEnum {};

				std::cout << "\t\t - " << "std::is_enum<eTestOldEnum>::value" << std::endl;
				std::cout << "\t\t\t - " << std::is_enum<eTestOldEnum>::value << std::endl;

				std::cout << "\t\t - " << "typeid( std::underlying_type<eTestEnum_1>::type ).name()" << std::endl;
				std::cout << "\t\t\t - " << typeid( std::underlying_type<eTestOldEnum>::type ).name() << std::endl;
			}

			std::cout << std::endl << std::endl;

			{
				std::cout << "\t + " << "enum class eTestNewEnum {};" << std::endl << std::endl;
				enum class eTestNewEnum {};

				std::cout << "\t\t - " << "std::is_enum<eTestNewEnum>::value" << std::endl;
				std::cout << "\t\t\t - " << std::is_enum<eTestNewEnum>::value << std::endl;

				std::cout << "\t\t - " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << std::endl;
				std::cout << "\t\t\t - " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << std::endl;
			}

			std::cout << std::endl << std::endl;

			{
				std::cout << "\t + " << "enum class eTestNewEnum : char {};" << std::endl << std::endl;
				enum class eTestNewEnum : char {};

				std::cout << "\t\t - " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << std::endl;
				std::cout << "\t\t\t - " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << std::endl;
			}

			return r2::eTestResult::RunTest;
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

	const r2::iNode::TitleFunc Convert::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Enum : Convert";
		};
	}
	const r2::iNode::DoFunc Convert::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Convert ==" << std::endl << std::endl;

			{
				std::cout << "\t" << "enum eNewEnum" << std::endl;
				std::cout << "\t" << "{" << std::endl;
				std::cout << "\t\t" << "one" << std::endl;
				std::cout << "\t\t" << ", two" << std::endl;
				std::cout << "\t\t" << ", three" << std::endl;
				std::cout << "\t" << "}" << std::endl << std::endl;

				enum eNewEnum
				{
					one
					, two
					, three
				};

				std::cout << "\t" << "template<typename EnumT>" << std::endl;
				std::cout << "\t" << "constexpr auto Enum2Value( EnumT e )" << std::endl;
				std::cout << "\t" << "{" << std::endl;
				std::cout << "\t\t" << "return static_cast<std::underlying_type_t<EnumT>>( e );" << std::endl;
				std::cout << "\t" << "}" << std::endl << std::endl;

				std::cout << "\t" << "+ " << "Enum2Value( eNewEnum::three )" << std::endl;
				std::cout << "\t\t" << "- " << Enum2Value( eNewEnum::three ) << std::endl;
			}

			return r2::eTestResult::RunTest;
		};
	}
}