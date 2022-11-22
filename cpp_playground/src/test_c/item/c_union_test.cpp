#include "c_union_test.h"
#include "c_union_test_helper_unnamedunion_with_struct.hpp"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_union_test
{
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( union { int32_t a; int64_t b; } u );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &u.a );
				OUTPUT_VALUE( &u.b );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Unnamed_Union_With_Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Union : Unnamed Union with Struct";
		};
	}
	r2cm::iItem::DoFunctionT Unnamed_Union_With_Struct::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_NOTE( "struct 안의 익명 공용체는 공용체 안에 선언된 멤버들을 struct 의 멤버처럼 접근하게 해준다." );

			std::cout << r2cm::split;

			SHOW_FILE( "src/test_c/item/c_union_test_helper_unnamedunion_with_struct.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( c_union_test_helper_unnamedunion_with_struct::TestStruct s );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( &s.b );
				OUTPUT_VALUE( &s.i );
				OUTPUT_VALUE( &s.ll );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}