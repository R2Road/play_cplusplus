#include "play_template_type_extract.hpp"
#include "play_template_type_extract_helper___type_extractor_4_member_pointer.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_template_type_extract
{
	r2tm::TitleFunctionT TypeExtract_4_MemberPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Type Extract 4 Member Pointer";
		};
	}
	r2tm::DoFunctionT TypeExtract_4_MemberPointer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "개괄" );
			OUT_COMMENT( "Template 인자가 여러 타입의 합성으로 만들어졌다면." );
			OUT_COMMENT( "특수화를 통해 타입을 분리할 수 있다." );

			LS();

			OUT_FILE( "source/play_template/play_template_type_extract_helper___type_extractor_4_member_pointer.hpp" );

			LS();

			{
				DECL_MAIN( struct S
				{
					int i = 77;
				} );

				LF();

				DECL_MAIN( using TT = Helper_TypeExtracter_4_MemberPointer<int S::*> );

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
}