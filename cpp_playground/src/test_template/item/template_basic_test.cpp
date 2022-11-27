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
}