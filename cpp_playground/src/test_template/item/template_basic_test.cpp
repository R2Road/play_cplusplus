#include "template_basic_test.h"
#include "template_basic_test_helper.hpp"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace template_basic_test
{
	r2cm::iItem::TitleFunctionT MemberVariable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : MemberVariable";
		};
	}
	r2cm::iItem::DoFunctionT MemberVariable::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE_RANGE( "src/test_template/item/template_basic_test_helper.hpp", 1, 15 );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( MemberVariableTest_01<int> m );
				PROCESS_MAIN( m.t = 111 );
				OUTPUT_VALUE( m.t );
			}

			std::cout << r2cm::split;

			{
				MemberVariableTest_02<int, float> m;
				std::cout << "MemberVariableTest_02<int, float> m\n";
				PROCESS_MAIN( m.t1 = 111 );
				PROCESS_MAIN( m.t2 = 222 );
				OUTPUT_VALUE( m.t1 );
				OUTPUT_VALUE( m.t2 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Function_ReturnValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : Function - Return Value";
		};
	}
	r2cm::iItem::DoFunctionT Function_ReturnValue::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE_RANGE( "src/test_template/item/template_basic_test_helper.hpp", 1, 15 );

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( int i = Template_Fn_R_() );
				std::cout << "\t" "> " "������ �Ҵ��ϴ� ������ Template �� Ÿ�� �߷п� ������ ���� ���Ѵ�." << r2cm::linefeed;

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( int i = Template_Fn_R_<int>() );
				( i );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int i = Template_Fn_R_R1( 123 ) );
				( i );
				std::cout << "\t" "> " "�Լ� ���� Ÿ�԰� ��ȯ���� Ÿ���� ���ٸ� ���ڿ��� Ÿ���� �������Ƿ� Ÿ�� �߷п� �����Ѵ�." << r2cm::linefeed;

			}

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( int i = Template_Fn_R_A1( 123 ) );
				std::cout << "\t" "> " "�Լ� ���� Ÿ�԰� ��ȯ���� Ÿ���� �ٸ��ٸ� ��ȯ���� ���� �߷п� ������ ���� ���Ѵ�." << r2cm::linefeed;

			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Function::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : Function";
		};
	}
	r2cm::iItem::DoFunctionT Function::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE_RANGE( "src/test_template/item/template_basic_test_helper.hpp", 17, 40 );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FunctionTest_01 FT( FN_V_0 ) );
				PROCESS_MAIN( FT() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FunctionTest_01 FT( FN_R_0 ) );
				PROCESS_MAIN( FT() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FunctionTest_01 FT( FN_R_2 ) );
				PROCESS_MAIN( FT( 3, 5 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}