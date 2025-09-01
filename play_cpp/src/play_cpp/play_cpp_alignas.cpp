#include "play_cpp_alignas.hpp"

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

#pragma warning( disable : 4324 )

namespace play_cpp_alignas
{
	r2tm::TitleFunctionT AlignAs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align As";
		};
	}
	r2tm::DoFunctionT AlignAs::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct alignas( 32 ) EmptyStruct {};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( alignof( EmptyStruct ) );
				OUT_SIZE( EmptyStruct );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct alignas( 8 ) CharIntFloatStruct
				{
					char c;
					int i;
					float f;
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( alignof( CharIntFloatStruct ) );
				OUT_SIZE( CharIntFloatStruct );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct alignas( 0 ) IntStruct
				{
					int i;
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( alignof( IntStruct ) );
				OUT_SIZE( IntStruct );

				LF();

				OUT_NOTE( "Ignore 0" );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				//struct alignas( 1 ) IntStruct
				//{
				//	int i;
				//};
				OUT_SOURCE_END;

				LF();

				OUT_NOTE( "1 is Error : At Least A Default Size Is Required" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}