#include "c_struct_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace c_struct_test
{
	r2cm::iItem::TitleFunctionT Array_Size_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Struct : Array[0]";
		};
	}
	r2cm::iItem::DoFunctionT Array_Size_0::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Case_1 { int i; int arr[0]; } );

				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "+ struct �ȿ� ���̰� 0 �� �迭�� ����ȴ�." << r2cm::linefeed;
				std::cout << r2cm::tab << "+ warning 4200 : ( ��ǥ�� Ȯ���� ����: ����ü/���� ����ü�� �迭 ũ�Ⱑ 0�Դϴ�. )" << r2cm::linefeed;
#pragma warning( pop )
			}

			std::cout << r2cm::split;

			{
#pragma warning( push )
#pragma warning( disable : 4200 )
				DECLARATION_MAIN( struct Case_2 { int i; int arr[]; } );

				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "+ struct �ȿ� ���̰� �������� ���� �迭�� ����ȴ�." << r2cm::linefeed;
				std::cout << r2cm::tab << "+ warning 4200 : ( ��ǥ�� Ȯ���� ����: ����ü/���� ����ü�� �迭 ũ�Ⱑ 0�Դϴ�. )" << r2cm::linefeed;
#pragma warning( pop )
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( struct Case_2 { int i; int arr[1]; } );

				std::cout << r2cm::linefeed;
				std::cout << r2cm::tab << "+ �����ϰ� ���̸� 1 �� ��������" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Ȱ�� ��" << r2cm::linefeed2;

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