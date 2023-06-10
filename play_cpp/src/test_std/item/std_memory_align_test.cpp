#include "std_memory_align_test.h"

#include <memory>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_memory_align_test
{
	void PrintResult( const void* const pb, const void* const presult, const std::size_t space )
	{ 
		std::cout << r2tm::tab << "- p : " << pb
			<< "    - result : " << presult
			<< "    - space : " << space
			<< r2tm::linefeed;
	}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << r2tm::tab << "+ Summury : std::align�� ó�� ����" << r2tm::linefeed2;
				std::cout << r2tm::tab << "> 1. ������ bound �� �°� �޸� ������ �������� �����Ѵ�." << r2tm::linefeed;
				std::cout << r2tm::tab2 << "char�� 3�� ���� �޸� ��ġ ���� int ���� ��û�ϴ� ���" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "���� �������� �޸� ������ �������� �����Ѵ�." << r2tm::linefeed;
				std::cout << r2tm::tab << "> 2. �޸� ���� �� ���� �޸� ������ size �� �����ϴ��� Ȯ��" << r2tm::linefeed;
				std::cout << r2tm::tab << "> 3. ������ �̵�, space ũ�� ����" << r2tm::linefeed;
				std::cout << r2tm::tab << "> 4. ������ �ʿ� ���� ���� ������ ����ϴٸ� ���ϴ� ���� ����." << r2tm::linefeed;
			}

			LS();

			DECLARATION_MAIN( int i = 1 );
			DECLARATION_MAIN( void* pb = &i );
			DECLARATION_MAIN( std::size_t space = sizeof( i ) );
			DECLARATION_MAIN( void* presult = nullptr );
			PrintResult( pb, presult, space );

			LS();

			{
				PROCESS_MAIN( presult = std::align( alignof( char ), sizeof( char ), pb, space ) );
				EXPECT_TRUE( presult );
				PrintResult( pb, presult, space );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Move" << r2tm::linefeed2;

				DECLARATION_MAIN( char* cp = static_cast<char*>( pb ) );
				PROCESS_MAIN( cp += sizeof( char ) );
				PROCESS_MAIN( pb = cp );
				PROCESS_MAIN( space -= sizeof( char ) );
				PROCESS_MAIN( presult = nullptr );

				PrintResult( pb, presult, space );
			}

			LS();

			{
				PROCESS_MAIN( presult = std::align( alignof( char ), sizeof( char ), pb, space ) );
				EXPECT_TRUE( presult );
				PrintResult( pb, presult, space );
			}

			LS();

			{
				PROCESS_MAIN( presult = std::align( alignof( int ), sizeof( char ), pb, space ) );
				EXPECT_FALSE( presult );
				PrintResult( pb, presult, space );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Bound::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Bound";
		};
	}
	r2tm::DoFunctionT Bound::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( char buffer[10] = { 0 } );
			DECLARATION_MAIN( void* pb = buffer );
			DECLARATION_MAIN( std::size_t space = sizeof( buffer ) );
			DECLARATION_MAIN( void* presult = nullptr );
			PrintResult( pb, presult, space );

			LS();

			{
				PROCESS_MAIN( pb = &buffer[1] );
				PROCESS_MAIN( space = sizeof( buffer ) - sizeof( char ) );
				PROCESS_MAIN( presult = nullptr );
				PrintResult( pb, presult, space );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( presult = std::align( alignof( char ), sizeof( char ), pb, space ) );
				PrintResult( pb, presult, space );
				std::cout << r2tm::tab << "Bound > " << ( static_cast<char*>( pb ) - &buffer[1] ) << r2tm::linefeed;
			}

			LS();

			{
				PROCESS_MAIN( pb = &buffer[1] );
				PROCESS_MAIN( space = sizeof( buffer ) - sizeof( char ) );
				PROCESS_MAIN( presult = nullptr );
				PrintResult( pb, presult, space );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( presult = std::align( alignof( int ), sizeof( char ), pb, space ) );
				PrintResult( pb, presult, space );
				std::cout << r2tm::tab << "Bound > " << ( static_cast<char*>( pb ) - &buffer[1] ) << r2tm::linefeed;
			}

			LS();

			{
				PROCESS_MAIN( pb = &buffer[1] );
				PROCESS_MAIN( space = sizeof( buffer ) - sizeof( char ) );
				PROCESS_MAIN( presult = nullptr );
				PrintResult( pb, presult, space );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( presult = std::align( alignof( double ), sizeof( char ), pb, space ) );
				PrintResult( pb, presult, space );
				std::cout << r2tm::tab << "Bound > " << ( static_cast<char*>( pb ) - &buffer[1] ) << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}


	
	r2tm::TitleFunctionT Play::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Play";
		};
	}
	r2tm::DoFunctionT Play::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "+ Ref : " << "https://en.cppreference.com/w/cpp/memory/align" << r2tm::linefeed;

			LS();

			DECLARATION_MAIN( char buffer[] = "---------" );
			DECLARATION_MAIN( void* pt = buffer );

			std::cout << r2tm::linefeed;

			DECLARATION_MAIN( std::size_t space = sizeof( buffer ) - 1u );
			std::cout << r2tm::tab << "> \\0 ����" << r2tm::linefeed;

			std::cout << r2tm::linefeed;

			DECLARATION_MAIN( void* presult = nullptr );

			LS();

			{
				std::cout << r2tm::tab << "+ orig : " << buffer << r2tm::linefeed;
				std::cout << r2tm::tab << "+ adress of pt : " << pt << r2tm::linefeed;
			}

			LS();

			{
				while( true )
				{
					PROCESS_MAIN( presult = std::align( alignof( int ), sizeof( char ), pt, space ) );
					std::cout << r2tm::tab << "> " << ( presult ? "success" : "failed" ) << r2tm::linefeed;
					if( !presult )
					{
						break;
					}

					std::cout << r2tm::tab2 << "- aligned adress of pt : " << pt << r2tm::linefeed;

					char* temp = static_cast<char*>( pt );
					*temp = '*';
					++temp;
					space -= sizeof( char );

					pt = temp;

					std::cout << r2tm::tab2 << "- edit : " << buffer << r2tm::linefeed;
					std::cout << r2tm::tab2 << "- new adress of pt : " << pt << r2tm::linefeed;
					std::cout << r2tm::linefeed;
				}

			}

			LS();

			std::cout << r2tm::tab << "result : " << buffer << r2tm::linefeed;

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}