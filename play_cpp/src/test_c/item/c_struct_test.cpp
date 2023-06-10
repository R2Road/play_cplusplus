#include "c_struct_test.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_struct_test
{
	r2tm::TitleFunctionT ByteAlignment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Byte Alignment";
		};
	}
	r2tm::DoFunctionT ByteAlignment::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct C { char c1; } );
				OUTPUT_VALUE( sizeof( C ) );
				OUTPUT_BINARY( C() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct C_C { char c1; char c2; } );
				OUTPUT_VALUE( sizeof( C_C ) );
				OUTPUT_BINARY( C_C() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct C_C_I { char c1 = -1; char c2 = -2; int i1 = -3; } );
				OUTPUT_VALUE( sizeof( C_C_I ) );
				OUTPUT_BINARY( C_C_I() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct I_C_I { int i1 = -1; char c1 = -2; int i2 = -3; } );
				OUTPUT_VALUE( sizeof( I_C_I ) );
				OUTPUT_BINARY( I_C_I() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct I_C_LL { int i1 = -1; char c1 = -2; long long ll1 = -3; } );
				OUTPUT_VALUE( sizeof( I_C_LL ) );
				OUTPUT_BINARY( I_C_LL() );
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct I_C_LL_I { int i1 = -1; char c1 = -2; long long ll1 = -3; int i2 = -4; } );
				OUTPUT_VALUE( sizeof( I_C_LL_I ) );
				OUTPUT_BINARY( I_C_LL_I() );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PragmaPack::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Pragma Pack";
		};
	}
	r2tm::DoFunctionT PragmaPack::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			OUTPUT_NOTE( "Byte Alignment 의 기준을 조정한다." );

			std::cout << r2tm::split;

			{
#pragma pack( push, 1 )
				OUTPUT_NOTE( "#pragma pack( push, 1 )" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct C { char c; }; );
				OUTPUT_VALUE( sizeof( C ) );
				OUTPUT_BINARY( C() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct I { int i; }; );
				OUTPUT_VALUE( sizeof( I ) );
				OUTPUT_BINARY( I() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct C_C { char c; char c2; }; );
				OUTPUT_VALUE( sizeof( C_C ) );
				OUTPUT_BINARY( C_C() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct C_I { char c; int i; }; );
				OUTPUT_VALUE( sizeof( C_I ) );
				OUTPUT_BINARY( C_I() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct LL_I_C { long long ll; int i; char c; }; );
				OUTPUT_VALUE( sizeof( LL_I_C ) );
				OUTPUT_BINARY( LL_I_C() );
#pragma pack( pop )
			}

			std::cout << r2tm::split;

			{
#pragma pack( push, 4 )
				OUTPUT_NOTE( "#pragma pack( push, 4 )" );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct C { char c; }; );
				OUTPUT_VALUE( sizeof( C ) );
				OUTPUT_BINARY( C() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct I { int i; }; );
				OUTPUT_VALUE( sizeof( I ) );
				OUTPUT_BINARY( I() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct C_C { char c; char c2; }; );
				OUTPUT_VALUE( sizeof( C_C ) );
				OUTPUT_BINARY( C_C() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct C_I { char c; int i; }; );
				OUTPUT_VALUE( sizeof( C_I ) );
				OUTPUT_BINARY( C_I() );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( struct LL_I_C { long long ll; int i; char c; }; );
				OUTPUT_VALUE( sizeof( LL_I_C ) );
				OUTPUT_BINARY( LL_I_C() );
#pragma pack( pop )
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Array_Size_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Array[0]";
		};
	}
	r2tm::DoFunctionT Array_Size_0::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Case_1 { int i; int arr[0]; } );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "struct 안에 길이가 0 인 배열이 선언된다." );
				OUTPUT_NOTE( "warning 4200 : ( 비표준 확장이 사용됨: 구조체/공용 구조체의 배열 크기가 0입니다. )" );
#pragma warning( pop )
			}

			std::cout << r2tm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Case_2 { int i; int arr[]; } );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "struct 안에 길이가 지정되지 않은 배열이 선언된다." );
				OUTPUT_NOTE( "warning 4200 : ( 비표준 확장이 사용됨: 구조체/공용 구조체의 배열 크기가 0입니다. )" );
#pragma warning( pop )
			}

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( struct Case_2 { int i; int arr[1]; } );

				std::cout << r2tm::linefeed;

				OUTPUT_NOTE( "안전하게 길이를 1 로 지정하자" );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_NOTE( "활용 예" );

				std::cout << r2tm::linefeed;

#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Dummy { int i; int arr[0]; } );

				std::cout << r2tm::linefeed;

				DECLARATION_MAIN( Dummy* dp = ( Dummy* )malloc( sizeof( Dummy ) + ( sizeof( int ) * 4 ) ) );
				PROCESS_MAIN( dp->arr[0] = 1 );
				PROCESS_MAIN( dp->arr[1] = 2 );
				PROCESS_MAIN( dp->arr[2] = 3 );
				PROCESS_MAIN( dp->arr[3] = 4 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( dp->arr[0] );
				OUTPUT_VALUE( dp->arr[1] );
				OUTPUT_VALUE( dp->arr[2] );
				OUTPUT_VALUE( dp->arr[3] );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( free( dp ) );
#pragma warning( pop )
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}