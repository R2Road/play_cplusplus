#include "play_std_memory_align.hpp"

#include <memory>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_std_memory_align
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
				std::cout << r2tm::tab << "+ Summury : std::align의 처리 순서" << r2tm::linefeed2;
				std::cout << r2tm::tab << "> 1. 지정한 bound 에 맞게 메모리 정렬이 가능한지 검토한다." << r2tm::linefeed;
				std::cout << r2tm::tab2 << "char가 3개 사용된 메모리 위치 에서 int 값을 요청하는 경우" << r2tm::linefeed;
				std::cout << r2tm::tab2 << "남은 공간에서 메모리 정렬이 가능한지 검토한다." << r2tm::linefeed;
				std::cout << r2tm::tab << "> 2. 메모리 정렬 후 남은 메모리 공간이 size 를 만족하는지 확인" << r2tm::linefeed;
				std::cout << r2tm::tab << "> 3. 포인터 이동, space 크기 조정" << r2tm::linefeed;
				std::cout << r2tm::tab << "> 4. 정렬이 필요 없고 남은 공간도 충분하다면 변하는 것이 없다." << r2tm::linefeed;
			}

			LS();

			DECL_MAIN( int i = 1 );
			DECL_MAIN( void* pb = &i );
			DECL_MAIN( std::size_t space = sizeof( i ) );
			DECL_MAIN( void* presult = nullptr );
			PrintResult( pb, presult, space );

			LS();

			{
				PROC_MAIN( presult = std::align( alignof( char ), sizeof( char ), pb, space ) );
				EXPECT_TRUE( presult );
				PrintResult( pb, presult, space );
			}

			LS();

			{
				std::cout << r2tm::tab << "+ Move" << r2tm::linefeed2;

				DECL_MAIN( char* cp = static_cast<char*>( pb ) );
				PROC_MAIN( cp += sizeof( char ) );
				PROC_MAIN( pb = cp );
				PROC_MAIN( space -= sizeof( char ) );
				PROC_MAIN( presult = nullptr );

				PrintResult( pb, presult, space );
			}

			LS();

			{
				PROC_MAIN( presult = std::align( alignof( char ), sizeof( char ), pb, space ) );
				EXPECT_TRUE( presult );
				PrintResult( pb, presult, space );
			}

			LS();

			{
				PROC_MAIN( presult = std::align( alignof( int ), sizeof( char ), pb, space ) );
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

			DECL_MAIN( char buffer[10] = { 0 } );
			DECL_MAIN( void* pb = buffer );
			DECL_MAIN( std::size_t space = sizeof( buffer ) );
			DECL_MAIN( void* presult = nullptr );
			PrintResult( pb, presult, space );

			LS();

			{
				PROC_MAIN( pb = &buffer[1] );
				PROC_MAIN( space = sizeof( buffer ) - sizeof( char ) );
				PROC_MAIN( presult = nullptr );
				PrintResult( pb, presult, space );

				LF();

				PROC_MAIN( presult = std::align( alignof( char ), sizeof( char ), pb, space ) );
				PrintResult( pb, presult, space );
				std::cout << r2tm::tab << "Bound > " << ( static_cast<char*>( pb ) - &buffer[1] ) << r2tm::linefeed;
			}

			LS();

			{
				PROC_MAIN( pb = &buffer[1] );
				PROC_MAIN( space = sizeof( buffer ) - sizeof( char ) );
				PROC_MAIN( presult = nullptr );
				PrintResult( pb, presult, space );

				LF();

				PROC_MAIN( presult = std::align( alignof( int ), sizeof( char ), pb, space ) );
				PrintResult( pb, presult, space );
				std::cout << r2tm::tab << "Bound > " << ( static_cast<char*>( pb ) - &buffer[1] ) << r2tm::linefeed;
			}

			LS();

			{
				PROC_MAIN( pb = &buffer[1] );
				PROC_MAIN( space = sizeof( buffer ) - sizeof( char ) );
				PROC_MAIN( presult = nullptr );
				PrintResult( pb, presult, space );

				LF();

				PROC_MAIN( presult = std::align( alignof( double ), sizeof( char ), pb, space ) );
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

			DECL_MAIN( char buffer[] = "---------" );
			DECL_MAIN( void* pt = buffer );

			LF();

			DECL_MAIN( std::size_t space = sizeof( buffer ) - 1u );
			std::cout << r2tm::tab << "> \\0 제외" << r2tm::linefeed;

			LF();

			DECL_MAIN( void* presult = nullptr );

			LS();

			{
				std::cout << r2tm::tab << "+ orig : " << buffer << r2tm::linefeed;
				std::cout << r2tm::tab << "+ adress of pt : " << pt << r2tm::linefeed;
			}

			LS();

			{
				while( true )
				{
					PROC_MAIN( presult = std::align( alignof( int ), sizeof( char ), pt, space ) );
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
					LF();
				}

			}

			LS();

			std::cout << r2tm::tab << "result : " << buffer << r2tm::linefeed;

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}