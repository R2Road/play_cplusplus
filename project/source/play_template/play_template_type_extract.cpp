#include "play_template_type_extract.hpp"
#include "play_template_type_extract_helper___member_value_pointer.hpp"
#include "play_template_type_extract_helper___function_pointer.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_template_type_extract
{
	r2tm::TitleFunctionT Member_Value_Pointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Type Extract : Member Value Pointer";
		};
	}
	r2tm::DoFunctionT Member_Value_Pointer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "개괄" );
			OUT_COMMENT( "Template 인자가 여러 타입의 합성으로 만들어졌다면." );
			OUT_COMMENT( "특수화를 통해 타입을 분리할 수 있다." );

			LS();

			OUT_FILE( "source/play_template/play_template_type_extract_helper___member_value_pointer.hpp" );

			LS();

			{
				DECL_MAIN( struct S
				{
					int i = 77;
				} );

				LF();

				DECL_MAIN( using TT = Helper___TypeExtracter___MemberValuePointer<int S::*> );

				LF();

				OUT_SOURCE_READY_N_BEGIN;
				std::cout << ( std::is_same<TT::RetT, int>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
				std::cout << ( std::is_same<TT::ClassT, S>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
				OUT_SOURCE_END;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Function_Pointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Type Extract : Function Pointer";
		};
	}
	r2tm::DoFunctionT Function_Pointer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "개괄" );
			OUT_COMMENT( "Template 인자가 여러 타입의 합성으로 만들어졌다면." );
			OUT_COMMENT( "특수화를 통해 타입을 분리할 수 있다." );

			LS();

			OUT_FILE( "source/play_template/play_template_type_extract_helper___function_pointer.hpp" );

			LS();

			{
				DECL_MAIN( struct S
				{
					void v() {}
					static int i()
					{
						return 77;
					}
					float f( float t )
					{
						return 77.f + t;
					}
				} );

				LF();

				{
					DECL_MAIN( using TT = Helper___TypeExtracter___FunctionPointer<float ( S::* )( float )> );

					LF();

					OUT_SOURCE_READY_N_BEGIN;
					std::cout << ( std::is_same<TT::ReturnT, float>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
					std::cout << ( std::is_same<TT::OwnerT, S>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
					std::cout << ( std::is_same<TT::PointerT, decltype( &S::f )>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
					OUT_SOURCE_END;
				}

				LF();

				{
					DECL_MAIN( using TT = Helper___TypeExtracter___FunctionPointer<decltype(&S::i)>);

					LF();

					OUT_SOURCE_READY_N_BEGIN;
					std::cout << ( std::is_same<TT::ReturnT, int>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
					std::cout << ( std::is_same<TT::PointerT, decltype( &S::i )>::value ? "SUCCESS" : "FAILED" ) << r2tm::linefeed;
					OUT_SOURCE_END;
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}