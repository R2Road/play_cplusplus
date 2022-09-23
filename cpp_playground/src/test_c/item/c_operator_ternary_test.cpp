#include "c_operator_ternary_test.h"

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace c_operator_ternary_test
{
	void void_func() {}

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ ��ȯ���� ��� �ȴ�." << r2cm::linefeed2;

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( ( true ? void_func() : void_func() ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Comma::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Comma";
		};
	}
	r2cm::iItem::DoFunctionT Comma::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ ���� �������� ������� ��ǥ�� ������ ������ ���� �� �ִ�." << r2cm::linefeed;
			std::cout << r2cm::tab << "+ �̰� 20�� ���� �˾ҳ�. 2022.05.18" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = 0 );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( (
					false
					? ++i, ++j
					: ++i
				) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( j );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( (
					true
					? ++i, ++j
					: ++i
				) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( j );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}