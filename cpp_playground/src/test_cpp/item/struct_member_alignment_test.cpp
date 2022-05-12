#include "struct_member_alignment_test.h"

#include "r2cm/r2cm_constant.h"

namespace struct_member_alignment_test
{
	r2cm::iItem::TitleFuncT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct Member Alignment Test";
		};
	}
	r2cm::iItem::DoFuncT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << "#pragma pack( push, 4 )" << r2cm::linefeed;

			std::cout << r2cm::split;

// #pragma pack( 4 )
#pragma pack( push, 4 )
			{
				struct
				{
					int i;
				} test_struct;

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int i;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "- sizeof : " << sizeof( test_struct ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				struct
				{
					long long ll;
				} test_struct;

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "long long ll;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << "- sizeof : " << sizeof( test_struct ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				struct
				{
					long long ll;
					char c;
				} test_struct;

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "long long ll;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char c;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << sizeof( test_struct ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4121 )
				struct
				{
					char c;
					long long ll; // warning 4121
					char c2;
				} test_struct;
#pragma warning( pop )

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char c;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "long long ll;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char c2;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				std::cout << r2cm::tab2 << sizeof( test_struct ) << r2cm::linefeed;
			}
#pragma pack( pop )

			std::cout << r2cm::split;

			std::cout << "#pragma pack( pop )" << r2cm::linefeed;

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}