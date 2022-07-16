#include "std_align_test.h"

#include <memory>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace align_test
{
	void PrintResult( const void* const ip, const void* const resultp, const std::size_t space )
	{ 
		std::cout << r2cm::tab << "- ip : " << ip
			<< "    - resultp : " << resultp
			<< "    - space : " << space
			<< r2cm::linefeed;
	}

	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Basic";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Summury : std::align의 처리 순서" << r2cm::linefeed2;
				std::cout << r2cm::tab << "> 1. 지정한 bound 에 맞게 메모리 정렬이 가능한지 검토한다." << r2cm::linefeed;
				std::cout << r2cm::tab2 << "char가 3개 사용된 메모리 위치 에서 int 값을 요청하는 경우" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "남은 공간에서 메모리 정렬이 가능한지 검토한다." << r2cm::linefeed;
				std::cout << r2cm::tab << "> 2. 메모리 정렬 후 남은 메모리 공간이 size 를 만족하는지 확인" << r2cm::linefeed;
				std::cout << r2cm::tab << "> 3. 포인터 이동, space 크기 조정" << r2cm::linefeed;
				std::cout << r2cm::tab << "> 4. 정렬이 필요 없고 남은 공간도 충분하다면 변하는 것이 없다." << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			DECLARATION_MAIN( int i = 1 );
			DECLARATION_MAIN( void* ip = &i );
			DECLARATION_MAIN( std::size_t space = sizeof( i ) );
			DECLARATION_MAIN( void* resultp = nullptr );
			PrintResult( ip, resultp, space );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( resultp = std::align( alignof( char ), sizeof( char ), ip, space ) );
				EXPECT_TRUE( resultp );
				PrintResult( ip, resultp, space );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Move" << r2cm::linefeed2;

				DECLARATION_MAIN( char* cp = static_cast<char*>( ip ) );
				PROCESS_MAIN( cp += sizeof( char ) );
				PROCESS_MAIN( ip = cp );
				PROCESS_MAIN( space -= sizeof( char ) );
				PROCESS_MAIN( resultp = nullptr );

				PrintResult( ip, resultp, space );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( resultp = std::align( alignof( char ), sizeof( char ), ip, space ) );
				EXPECT_TRUE( resultp );
				PrintResult( ip, resultp, space );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( resultp = std::align( alignof( int ), sizeof( char ), ip, space ) );
				EXPECT_FALSE( resultp );
				PrintResult( ip, resultp, space );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}


	
	r2cm::iItem::TitleFunctionT Play::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Play";
		};
	}
	r2cm::iItem::DoFunctionT Play::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Ref : " << "https://en.cppreference.com/w/cpp/memory/align" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				char buffer[] = "-------------------------";
				void * pt = buffer;

				std::cout << r2cm::tab << "+ orig : " << buffer << r2cm::linefeed;
				std::cout << r2cm::tab << "+ adress of pt : " << pt << r2cm::linefeed << r2cm::linefeed;

				std::cout << r2cm::tab << "+ Process" << r2cm::linefeed;

				std::size_t space = sizeof( buffer ) - 1;
				while( std::align( alignof( int ), sizeof( char ), pt, space ) )
				{
					std::cout << r2cm::tab2 << "- old adress of pt : " << pt << r2cm::linefeed;

					if( !std::align( alignof( int ), sizeof( char ), pt, space ) )
					{
						break;
					}

					char* temp = static_cast<char*>( pt );
					*temp = '*';
					++temp;
					space -= sizeof( char );

					pt = temp;

					std::cout << r2cm::tab2 << "- convert : " << buffer << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- new adress of pt : " << pt << r2cm::linefeed;
					std::cout << r2cm::linefeed;
				}

				std::cout << r2cm::tab << "result : " << buffer << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}