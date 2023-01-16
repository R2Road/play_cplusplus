#include "c_struct_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_struct_test
{
	r2cm::iItem::TitleFunctionT ByteAlignment::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Byte Alignment";
		};
	}
	r2cm::iItem::DoFunctionT ByteAlignment::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct C { char c1; } );
				OUTPUT_VALUE( sizeof( C ) );
				OUTPUT_BINARY( C() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct C_C { char c1; char c2; } );
				OUTPUT_VALUE( sizeof( C_C ) );
				OUTPUT_BINARY( C_C() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct C_C_I { char c1 = -1; char c2 = -2; int i1 = -3; } );
				OUTPUT_VALUE( sizeof( C_C_I ) );
				OUTPUT_BINARY( C_C_I() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct I_C_I { int i1 = -1; char c1 = -2; int i2 = -3; } );
				OUTPUT_VALUE( sizeof( I_C_I ) );
				OUTPUT_BINARY( I_C_I() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct I_C_LL { int i1 = -1; char c1 = -2; long long ll1 = -3; } );
				OUTPUT_VALUE( sizeof( I_C_LL ) );
				OUTPUT_BINARY( I_C_LL() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct I_C_LL_I { int i1 = -1; char c1 = -2; long long ll1 = -3; int i2 = -4; } );
				OUTPUT_VALUE( sizeof( I_C_LL_I ) );
				OUTPUT_BINARY( I_C_LL_I() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PragmaPack::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Pragma Pack";
		};
	}
	r2cm::iItem::DoFunctionT PragmaPack::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << "#pragma pack( push, 4 )" << r2cm::linefeed;

			std::cout << r2cm::split;

			// #pragma pack( 4 )
#pragma pack( push, 4 )
			{
				struct
				{
					int i;
				} test_struct;

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "int i;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				OUTPUT_VALUE( sizeof( test_struct ) );
			}

			std::cout << r2cm::split;

			{
				struct
				{
					long long ll;
				} test_struct;

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "long long ll;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				OUTPUT_VALUE( sizeof( test_struct ) );
			}

			std::cout << r2cm::split;

			{
				struct
				{
					long long ll;
					char c;
				} test_struct;

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "long long ll;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char c;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				OUTPUT_VALUE( sizeof( test_struct ) );
			}

			std::cout << r2cm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4121 )
				struct
				{
					char c;
					long long ll; // warning 4121
					char c2;
				} test_struct;
#pragma warning( pop )

				std::cout << r2cm::tab << "struct" << r2cm::linefeed;
				std::cout << r2cm::tab << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char c;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "long long ll;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char c2;" << r2cm::linefeed;
				std::cout << r2cm::tab << "} test_struct;" << r2cm::linefeed2;

				OUTPUT_VALUE( sizeof( test_struct ) );
			}
#pragma pack( pop )

			std::cout << r2cm::split;

			std::cout << "#pragma pack( pop )" << r2cm::linefeed;

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Array_Size_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Array[0]";
		};
	}
	r2cm::iItem::DoFunctionT Array_Size_0::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Case_1 { int i; int arr[0]; } );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "struct 안에 길이가 0 인 배열이 선언된다." );
				OUTPUT_NOTE( "warning 4200 : ( 비표준 확장이 사용됨: 구조체/공용 구조체의 배열 크기가 0입니다. )" );
#pragma warning( pop )
			}

			std::cout << r2cm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Case_2 { int i; int arr[]; } );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "struct 안에 길이가 지정되지 않은 배열이 선언된다." );
				OUTPUT_NOTE( "warning 4200 : ( 비표준 확장이 사용됨: 구조체/공용 구조체의 배열 크기가 0입니다. )" );
#pragma warning( pop )
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct Case_2 { int i; int arr[1]; } );

				std::cout << r2cm::linefeed;

				OUTPUT_NOTE( "안전하게 길이를 1 로 지정하자" );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_NOTE( "활용 예" );

				std::cout << r2cm::linefeed;

#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Dummy { int i; int arr[0]; } );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( Dummy* dp = ( Dummy* )malloc( sizeof( Dummy ) + ( sizeof( int ) * 4 ) ) );
				PROCESS_MAIN( dp->arr[0] = 1 );
				PROCESS_MAIN( dp->arr[1] = 2 );
				PROCESS_MAIN( dp->arr[2] = 3 );
				PROCESS_MAIN( dp->arr[3] = 4 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( dp->arr[0] );
				OUTPUT_VALUE( dp->arr[1] );
				OUTPUT_VALUE( dp->arr[2] );
				OUTPUT_VALUE( dp->arr[3] );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( free( dp ) );
#pragma warning( pop )
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}