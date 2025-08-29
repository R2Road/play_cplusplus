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
				OUTPUT_SOURCE_READY_N_BEGIN;
				struct alignas( 32 ) EmptyStruct {};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( alignof( EmptyStruct ) );
				OUTPUT_SIZE( EmptyStruct );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				struct alignas( 8 ) CharIntFloatStruct
				{
					char c;
					int i;
					float f;
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( alignof( CharIntFloatStruct ) );
				OUTPUT_SIZE( CharIntFloatStruct );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				struct alignas( 0 ) IntStruct
				{
					int i;
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( alignof( IntStruct ) );
				OUTPUT_SIZE( IntStruct );

				LF();

				OUTPUT_NOTE( "Ignore 0" );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				//struct alignas( 1 ) IntStruct
				//{
				//	int i;
				//};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_NOTE( "1 is Error : At Least A Default Size Is Required" );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}