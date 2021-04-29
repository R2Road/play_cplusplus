#include "pch.h"
#include "alignas_test.h"

#include "r2_eTestResult.h"

#pragma warning( disable : 4324 )

namespace align_test
{
	const r2::iTest::TitleFunc AlignAs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align : Align As";
		};
	}
	const r2::iTest::DoFunc AlignAs::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 32 ) EmptyStruct {};" << r2::linefeed << r2::linefeed;
				struct alignas( 32 ) EmptyStruct {};

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 8 ) CharIntFloatStruct" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "char c;" << r2::linefeed;
				std::cout << "\t\t" << "int i;" << r2::linefeed;
				std::cout << "\t\t" << "float f;" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;
				struct alignas( 8 ) CharIntFloatStruct
				{
					char c;
					int i;
					float f;
				};

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 0 ) IntStruct" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "int i;" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;
				struct alignas( 0 ) IntStruct
				{
					int i;
				};

				std::cout << "\t" << "+ align of IntStruct : " << alignof( IntStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of IntStruct : " << sizeof( IntStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ Ignore 0" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 1 ) IntStruct" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "int i;" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;
				//struct alignas( 1 ) IntStruct
				//{
				//	int i;
				//};

				std::cout << "\t" << "+ 1 is Error : At Least A Default Size Is Required" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}