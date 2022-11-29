#include "cpp_alignas_test.h"

#include "r2cm/r2cm_ostream.h"

#pragma warning( disable : 4324 )

namespace cpp_align_test
{
	r2cm::iItem::TitleFunctionT AlignAs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align As";
		};
	}
	r2cm::iItem::DoFunctionT AlignAs::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << "\t" << "struct alignas( 32 ) EmptyStruct {};" << r2cm::linefeed << r2cm::linefeed;
				struct alignas( 32 ) EmptyStruct {};

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2cm::linefeed << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "\t" << "struct alignas( 8 ) CharIntFloatStruct" << r2cm::linefeed;
				std::cout << "\t" << "{" << r2cm::linefeed;
				std::cout << "\t\t" << "char c;" << r2cm::linefeed;
				std::cout << "\t\t" << "int i;" << r2cm::linefeed;
				std::cout << "\t\t" << "float f;" << r2cm::linefeed;
				std::cout << "\t" << "}" << r2cm::linefeed << r2cm::linefeed;
				struct alignas( 8 ) CharIntFloatStruct
				{
					char c;
					int i;
					float f;
				};

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2cm::linefeed << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "\t" << "struct alignas( 0 ) IntStruct" << r2cm::linefeed;
				std::cout << "\t" << "{" << r2cm::linefeed;
				std::cout << "\t\t" << "int i;" << r2cm::linefeed;
				std::cout << "\t" << "}" << r2cm::linefeed << r2cm::linefeed;
				struct alignas( 0 ) IntStruct
				{
					int i;
				};

				std::cout << "\t" << "+ align of IntStruct : " << alignof( IntStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of IntStruct : " << sizeof( IntStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ Ignore 0" << r2cm::linefeed << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "\t" << "struct alignas( 1 ) IntStruct" << r2cm::linefeed;
				std::cout << "\t" << "{" << r2cm::linefeed;
				std::cout << "\t\t" << "int i;" << r2cm::linefeed;
				std::cout << "\t" << "}" << r2cm::linefeed << r2cm::linefeed;
				//struct alignas( 1 ) IntStruct
				//{
				//	int i;
				//};

				std::cout << "\t" << "+ 1 is Error : At Least A Default Size Is Required" << r2cm::linefeed << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}