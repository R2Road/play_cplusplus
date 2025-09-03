#include "play_template_basic.hpp"
#include "play_template_basic_helper.hpp"
#include "play_template_basic_helper___parentheses.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_template_basic
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

			OUT_FILE_RANGE( "src/play_template/play_template_basic_helper.hpp", 1, 15 );

			LS();

			{
				DECL_MAIN( MemberVariableTest_01<int> m );
				PROC_MAIN( m.t = 111 );
				OUT_VALUE( m.t );
			}

			LS();

			{
				MemberVariableTest_02<int, float> m;
				std::cout << "MemberVariableTest_02<int, float> m\n";
				PROC_MAIN( m.t1 = 111 );
				PROC_MAIN( m.t2 = 222 );
				OUT_VALUE( m.t1 );
				OUT_VALUE( m.t2 );
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

			OUT_FILE_RANGE( "src/play_template/play_template_basic_helper.hpp", 17, 36 );

			LS();

			{
				OUT_CODE( int i = Template_Fn_R_() );
				std::cout << "\t" "> " "변수에 할당하는 행위는 Template 의 타입 추론에 영향을 주지 못한다." << r2tm::linefeed;

				LF();

				DECL_MAIN( int i = Template_Fn_R_<int>() );
				( i );
			}

			LS();

			{
				DECL_MAIN( int i = Template_Fn_R_R1( 123 ) );
				( i );
				std::cout << "\t" "> " "함수 인자 타입과 반환값의 타입이 같다면 인자에서 타입이 정해지므로 타입 추론에 성공한다." << r2tm::linefeed;

			}

			LS();

			{
				OUT_CODE( int i = Template_Fn_R_A1( 123 ) );
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

			OUT_FILE_RANGE( "src/play_template/play_template_basic_helper.hpp", 38, 61 );

			LS();

			{
				DECL_MAIN( FunctionTest_01 FT( FN_V_0 ) );
				PROC_MAIN( FT() );
			}

			LS();

			{
				DECL_MAIN( FunctionTest_01 FT( FN_R_0 ) );
				PROC_MAIN( FT() );
			}

			LS();

			{
				DECL_MAIN( FunctionTest_01 FT( FN_R_2 ) );
				PROC_MAIN( FT( 3, 5 ) );
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



	template<typename T, T N>
	class ConstantContainer
	{
	public:
		using CT = T;

		const CT operator()() const { return N; }
	};
	r2tm::TitleFunctionT Constant::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : Constant";
		};
	}
	r2tm::DoFunctionT Constant::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				ConstantContainer<int, 2> c;

				OUT_VALUE( c() );

			}

			LS();

			{
				//ConstantContainer<float, 2.2> c;

				LF();

				OUT_NOTE( "error C7592: 'float' 형식의 비형식 템플릿 매개 변수에는 최소한 '/std:c++20'이(가) 필요합니다." );

			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Parentheses::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic : ()";
		};
	}
	r2tm::DoFunctionT Parentheses::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_FILE( "src/play_template/play_template_basic_helper___parentheses.hpp" );
			}

			LS();

			{
				PROC_MAIN( Do_ParenthesesHelper() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}