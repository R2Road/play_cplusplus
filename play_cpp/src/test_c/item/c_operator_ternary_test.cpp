#include "c_operator_ternary_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

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
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "��ȯ���� ��� �ȴ�." );

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
	r2cm::iItem::DoFunctionT Comma::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "���� �������� ������� ��ǥ�� ������ ������ ���� �� �ִ�." );
			OUTPUT_NOTE( "�̰� 20�� ���� �˾ҳ�. 2022.05.18" );

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



	r2cm::iItem::TitleFunctionT Void::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Void";
		};
	}
	r2cm::iItem::DoFunctionT Void::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "���� �����ڿ��� ��ȯ�� ���� �Լ��� ȣ���ϴ� ��� void() �� ���� �� �ִ�." );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::function<void()> Do = []() {} );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( 1 == 1 ? Do() : void() );
				PROCESS_MAIN( 1 == 2 ? Do() : void() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}