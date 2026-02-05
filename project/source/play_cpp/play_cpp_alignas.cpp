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

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Zero_Byte::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align As : Zero Byte";
		};
	}
	r2tm::DoFunctionT Zero_Byte::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct alignas( 0 ) S
				{
					int i;
				};
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( alignof( S ) );

				LF();

				OUT_SIZE( S );

				LF();

				OUT_NOTE( "0은 무시된다." );
				OUT_NOTE( "경고/에러가 발생하지 않는다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Short_Byte::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align As : Short Byte";
		};
	}
	r2tm::DoFunctionT Short_Byte::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct alignas( 1 ) S
				{
					char i;
				};
				OUT_SOURCE_END;

				LF();

				OUT_SIZE( S );
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

				OUT_COMMENT( "E1881 : 본 객체 크기보다 작아선 안된다." );
				OUT_COMMENT( "작동 하지만 무시된다." );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Odd_Byte::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align As : Odd Byte";
		};
	}
	r2tm::DoFunctionT Odd_Byte::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "홀수 크기의 데이터 덩어리는 존재 하지 않는 것이 모두에게 이롭다." );

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct No_AlignAs
				{
					char a;
					char b;
					char c;
				};
				OUT_SOURCE_END;

				LF();

				OUT_SIZE( No_AlignAs );

				LF();

				OUT_COMMENT( "이런 녀석을 내버려 두지 마라." );
			}

			LS();

			{
				OUT_SOURCE_READY_N_BEGIN;
				struct alignas( int ) Yes_AlignAs
				{
					char a;
					char b;
					char c;
				};
				OUT_SOURCE_END;

				LF();

				OUT_SIZE( Yes_AlignAs );

				LF();

				OUT_COMMENT( "짝수로 맞춰라. 4, 8 byte가 최적. " );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}