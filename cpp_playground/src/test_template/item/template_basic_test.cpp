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
				DECLARATION_MAIN( FunctionTest_01 FT( V_0 ) );
				PROCESS_MAIN( FT() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FunctionTest_01 FT( R_0 ) );
				PROCESS_MAIN( FT() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( FunctionTest_01 FT( R_2 ) );
				PROCESS_MAIN( FT( 3, 5 ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}