#include "enum_test.h"

#include <iostream>
#include <typeinfo>

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
				std::cout << "\t + " << "enum class eTestEnum_1 {};" << std::endl;
				enum class eTestEnum_1 {};

				std::cout << "\t + " << "typeid( std::underlying_type<eTestEnum_1>::type ).name()" << std::endl;
				std::cout << "\t\t - " << typeid( std::underlying_type<eTestEnum_1>::type ).name() << std::endl;
			}

			return r2::eTestResult::RunTest;
		};
	}
}