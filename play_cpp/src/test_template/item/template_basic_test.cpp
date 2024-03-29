#include "template_basic_test.h"
#include "template_basic_test_helper.hpp"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace template_basic_test
{
	r2tm::TitleFunctionT MemberVariable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : MemberVariable";
		};
	}
	r2tm::DoFunctionT MemberVariable::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE_RANGE( "src/test_template/item/template_basic_test_helper.hpp", 1, 15 );

			LS();

			{
				DECLARATION_MAIN( MemberVariableTest_01<int> m );
				PROCESS_MAIN( m.t = 111 );
				OUTPUT_VALUE( m.t );
			}

			LS();

			{
				MemberVariableTest_02<int, float> m;
				std::cout << "MemberVariableTest_02<int, float> m\n";
				PROCESS_MAIN( m.t1 = 111 );
				PROCESS_MAIN( m.t2 = 222 );
				OUTPUT_VALUE( m.t1 );
				OUTPUT_VALUE( m.t2 );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Function_ReturnValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : Function - Return Value";
		};
	}
	r2tm::DoFunctionT Function_ReturnValue::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE_RANGE( "src/test_template/item/template_basic_test_helper.hpp", 17, 36 );

			LS();

			{
				OUTPUT_CODE( int i = Template_Fn_R_() );
				std::cout << "\t" "> " "변수에 할당하는 행위는 Template 의 타입 추론에 영향을 주지 못한다." << r2tm::linefeed;

				LF();

				DECLARATION_MAIN( int i = Template_Fn_R_<int>() );
				( i );
			}

			LS();

			{
				DECLARATION_MAIN( int i = Template_Fn_R_R1( 123 ) );
				( i );
				std::cout << "\t" "> " "함수 인자 타입과 반환값의 타입이 같다면 인자에서 타입이 정해지므로 타입 추론에 성공한다." << r2tm::linefeed;

			}

			LS();

			{
				OUTPUT_CODE( int i = Template_Fn_R_A1( 123 ) );
				std::cout << "\t" "> " "함수 인자 타입과 반환값의 타입이 다르다면 반환값의 인자 추론에 영향을 주지 못한다." << r2tm::linefeed;

			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Function_Object::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : Function - Object";
		};
	}
	r2tm::DoFunctionT Function_Object::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE_RANGE( "src/test_template/item/template_basic_test_helper.hpp", 38, 61 );

			LS();

			{
				DECLARATION_MAIN( FunctionTest_01 FT( FN_V_0 ) );
				PROCESS_MAIN( FT() );
			}

			LS();

			{
				DECLARATION_MAIN( FunctionTest_01 FT( FN_R_0 ) );
				PROCESS_MAIN( FT() );
			}

			LS();

			{
				DECLARATION_MAIN( FunctionTest_01 FT( FN_R_2 ) );
				PROCESS_MAIN( FT( 3, 5 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	template<typename T>
	struct P
	{
		using type = T;
	};

	template<typename T>
	struct P<T*>
	{
		using type = T;
	};

	r2tm::TitleFunctionT RemovePointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : Remove Pointer";
		};
	}
	r2tm::DoFunctionT RemovePointer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				using PT1 = typename P<int*>::type;
				using PT2 = typename P<int*>::type;

			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}