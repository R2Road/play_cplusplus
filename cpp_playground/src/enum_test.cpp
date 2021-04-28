#include "pch.h"
#include "enum_test.h"

#include <typeinfo> // typeid
#include <type_traits>

#include "r2_eTestResult.h"

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
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t + " << "enum eTestOldEnum {};" << r2::linefeed << r2::linefeed;
				enum eTestOldEnum {};

				std::cout << "\t\t - " << "std::is_enum<eTestOldEnum>::value" << r2::linefeed;
				std::cout << "\t\t\t - " << std::is_enum<eTestOldEnum>::value << r2::linefeed;

				std::cout << "\t\t - " << "typeid( std::underlying_type<eTestEnum_1>::type ).name()" << r2::linefeed;
				std::cout << "\t\t\t - " << typeid( std::underlying_type<eTestOldEnum>::type ).name() << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t + " << "enum class eTestNewEnum {};" << r2::linefeed << r2::linefeed;
				enum class eTestNewEnum {};

				std::cout << "\t\t - " << "std::is_enum<eTestNewEnum>::value" << r2::linefeed;
				std::cout << "\t\t\t - " << std::is_enum<eTestNewEnum>::value << r2::linefeed;

				std::cout << "\t\t - " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << r2::linefeed;
				std::cout << "\t\t\t - " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t + " << "enum class eTestNewEnum : char {};" << r2::linefeed << r2::linefeed;
				enum class eTestNewEnum : char {};

				std::cout << "\t\t - " << "typeid( std::underlying_type<eTestNewEnum>::type ).name()" << r2::linefeed;
				std::cout << "\t\t\t - " << typeid( std::underlying_type<eTestNewEnum>::type ).name() << r2::linefeed;
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
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << "\t" << "template<typename EnumT>" << r2::linefeed;
			std::cout << "\t" << "constexpr auto Enum2Value( EnumT e )" << r2::linefeed;
			std::cout << "\t" << "{" << r2::linefeed;
			std::cout << "\t\t" << "return static_cast<std::underlying_type_t<EnumT>>( e );" << r2::linefeed;
			std::cout << "\t" << "}" << r2::linefeed;

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "enum eOldEnum" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "one" << r2::linefeed;
				std::cout << "\t\t" << ", two" << r2::linefeed;
				std::cout << "\t\t" << ", three" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;

				enum eOldEnum
				{
					one
					, two
					, three
				};

				std::cout << "\t" << "+ " << "Enum2Value( eOldEnum::three )" << r2::linefeed;
				std::cout << "\t\t" << "- " << Enum2Value( eOldEnum::three ) << r2::linefeed;
				std::cout << "\t\t" << "- " << typeid( Enum2Value( eOldEnum::three ) ).name() << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "enum class eNewEnum : short" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "hana" << r2::linefeed;
				std::cout << "\t\t" << ", dul" << r2::linefeed;
				std::cout << "\t\t" << ", set" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;

				enum class eNewEnum : short
				{
					hana
					, dul
					, set
				};

				std::cout << "\t" << "+ " << "Enum2Value( eNewEnum::dul )" << r2::linefeed;
				std::cout << "\t\t" << "- " << Enum2Value( eNewEnum::dul ) << r2::linefeed;
				std::cout << "\t\t" << "- " << typeid( Enum2Value( eNewEnum::dul ) ).name() << r2::linefeed;
			}

			return r2::eTestResult::RunTest;
		};
	}
}