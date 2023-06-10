#include "c_operator_ternary_test.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_operator_ternary_test
{
	void void_func() {}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "��ȯ���� ��� �ȴ�." );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( ( true ? void_func() : void_func() ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Comma::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Comma";
		};
	}
	r2tm::DoFunctionT Comma::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "���� �������� ������� ��ǥ�� ������ ������ ���� �� �ִ�." );
			OUTPUT_NOTE( "�̰� 20�� ���� �˾ҳ�. 2022.05.18" );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( int i = 0 );
				DECLARATION_MAIN( int j = 0 );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( (
					false
					? ++i, ++j
					: ++i
				) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( j );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( (
					true
					? ++i, ++j
					: ++i
				) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( i );
				OUTPUT_VALUE( j );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Void::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "operator ternary : Void";
		};
	}
	r2tm::DoFunctionT Void::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "���� �����ڿ��� ��ȯ�� ���� �Լ��� ȣ���ϴ� ��� void() �� ���� �� �ִ�." );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( std::function<void()> Do = []() {} );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( 1 == 1 ? Do() : void() );
				PROCESS_MAIN( 1 == 2 ? Do() : void() );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}