#include "pch.h"
#include "struct_member_alignment_test.h"

#include "base/r2_eTestResult.h"

namespace struct_member_alignment_test
{
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct Member Alignment Test";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			std::cout << "#pragma pack( push, 4 )" << r2::linefeed;

			std::cout << r2::split;

// #pragma pack( 4 )
#pragma pack( push, 4 )
			{
				struct
				{
					int i;
				} test_struct;

				std::cout << r2::tab << "struct" << r2::linefeed;
				std::cout << r2::tab << "{" << r2::linefeed;
				std::cout << r2::tab2 << "int i;" << r2::linefeed;
				std::cout << r2::tab << "} test_struct;" << r2::linefeed2;

				std::cout << r2::tab2 << "- sizeof : " << sizeof( test_struct ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				struct
				{
					long long ll;
				} test_struct;

				std::cout << r2::tab << "struct" << r2::linefeed;
				std::cout << r2::tab << "{" << r2::linefeed;
				std::cout << r2::tab2 << "long long ll;" << r2::linefeed;
				std::cout << r2::tab << "} test_struct;" << r2::linefeed2;

				std::cout << r2::tab2 << "- sizeof : " << sizeof( test_struct ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				struct
				{
					long long ll;
					char c;
				} test_struct;

				std::cout << r2::tab << "struct" << r2::linefeed;
				std::cout << r2::tab << "{" << r2::linefeed;
				std::cout << r2::tab2 << "long long ll;" << r2::linefeed;
				std::cout << r2::tab2 << "char c;" << r2::linefeed;
				std::cout << r2::tab << "} test_struct;" << r2::linefeed2;

				std::cout << r2::tab2 << sizeof( test_struct ) << r2::linefeed;
			}

			std::cout << r2::split;

			{
				struct
				{
					char c;
					long long ll;
					char c2;
				} test_struct;

				std::cout << r2::tab << "struct" << r2::linefeed;
				std::cout << r2::tab << "{" << r2::linefeed;
				std::cout << r2::tab2 << "char c;" << r2::linefeed;
				std::cout << r2::tab2 << "long long ll;" << r2::linefeed;
				std::cout << r2::tab2 << "char c2;" << r2::linefeed;
				std::cout << r2::tab << "} test_struct;" << r2::linefeed2;

				std::cout << r2::tab2 << sizeof( test_struct ) << r2::linefeed;
			}
#pragma pack( pop )

			std::cout << r2::split;

			std::cout << "#pragma pack( pop )" << r2::linefeed;

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}