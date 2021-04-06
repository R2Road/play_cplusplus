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