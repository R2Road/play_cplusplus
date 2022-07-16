#include "std_align_test.h"

#include <memory>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace align_test
{
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

			{
				std::cout << r2cm::tab << "- ip : " << ip
					<< "    - resultp : " << resultp
					<< "    - space : " << space
					<< r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( resultp = std::align( alignof( char ), sizeof( char ), ip, space ) );
				std::cout << r2cm::tab << ( resultp ? "- success" : "- failed" ) << r2cm::linefeed;
				std::cout << r2cm::tab << "- ip : " << ip
					<< "    - resultp : " << resultp
					<< "    - space : " << space
					<< r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Move" << r2cm::linefeed2;

				DECLARATION_MAIN( const int move_amount = 1 );
				DECLARATION_MAIN( char* cp = static_cast<char*>( ip ) );
				PROCESS_MAIN( cp += move_amount );
				PROCESS_MAIN( ip = cp );
				PROCESS_MAIN( space -= sizeof( char ) * move_amount );

				std::cout << r2cm::tab << "- ip : " << ip
					<< "    - resultp : " << resultp
					<< "    - space : " << space
					<< r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( resultp = std::align( alignof( char ), sizeof( char ), ip, space ) );
				std::cout << r2cm::tab << ( resultp ? "- success" : "- failed" ) << r2cm::linefeed;
				std::cout << r2cm::tab << "- ip : " << ip
					<< "    - resultp : " << resultp
					<< "    - space : " << space
					<< r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( resultp = std::align( alignof( int ), sizeof( char ), ip, space ) );
				std::cout << r2cm::tab << ( resultp ? "- success" : "- failed" ) << r2cm::linefeed;
				std::cout << r2cm::tab << "- ip : " << ip
					<< "    - resultp : " << resultp
					<< "    - space : " << space
					<< r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Align_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 0";
		};
	}
	r2cm::iItem::DoFunctionT Align_0::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int i = 1;
				void* ip = &i;
				std::size_t space = sizeof( i );

				std::cout << r2cm::tab << "int i = 1;" << r2cm::linefeed;
				std::cout << r2cm::tab << "void* ip = &i;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- adress of ip : " << ip << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- space : " << space << r2cm::linefeed;
				std::cout << r2cm::linefeed << r2cm::linefeed;

				{
					std::cout << r2cm::tab << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2cm::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << r2cm::tab2 << "- success" << r2cm::linefeed;
					}
					else
					{
						std::cout << r2cm::tab2 << "- failed" << r2cm::linefeed;
					}

					{
						std::cout << r2cm::tab2 << "- adress of ip : " << ip << r2cm::linefeed;
						std::cout << r2cm::tab2 << "- space : " << space << r2cm::linefeed;
					}
				}

				std::cout << r2cm::linefeed << r2cm::linefeed;

				{
					int move_amount = 3;

					char* cp = static_cast<char*>( ip );
					cp += move_amount;

					ip = cp;
					space -= sizeof( char ) * move_amount;

					std::cout << r2cm::tab << "move " << move_amount << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- adress of ip : " << ip << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- space : " << space << r2cm::linefeed;
					std::cout << r2cm::linefeed;

					std::cout << r2cm::tab << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2cm::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << r2cm::tab2 << "- success" << r2cm::linefeed;
					}
					else
					{
						std::cout << r2cm::tab2 << "- failed" << r2cm::linefeed;
					}

					{
						std::cout << r2cm::tab2 << "- adress of ip : " << ip << r2cm::linefeed;
						std::cout << r2cm::tab2 << "- space : " << space << r2cm::linefeed;
					}
				}

				std::cout << r2cm::linefeed << r2cm::linefeed;

				{
					int move_amount = 1;

					char* cp = static_cast<char*>( ip );
					cp += move_amount;

					ip = cp;
					space -= sizeof( char ) * move_amount;

					std::cout << r2cm::tab << "move " << move_amount << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- adress of ip : " << ip << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- space : " << space << r2cm::linefeed;
					std::cout << r2cm::linefeed;

					std::cout << r2cm::tab << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2cm::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << r2cm::tab2 << "- success" << r2cm::linefeed;
					}
					else
					{
						std::cout << r2cm::tab2 << "- failed" << r2cm::linefeed;
					}

					{
						std::cout << r2cm::tab2 << "- adress of ip : " << ip << r2cm::linefeed;
						std::cout << r2cm::tab2 << "- space : " << space << r2cm::linefeed;
						std::cout << r2cm::linefeed;
					}
				}

				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}


	r2cm::iItem::TitleFunctionT Align_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 1";
		};
	}
	r2cm::iItem::DoFunctionT Align_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				double d = 1;
				void* dp = &d;
				std::size_t space = sizeof( double );

				std::cout << r2cm::tab << "double d;" << r2cm::linefeed;
				std::cout << r2cm::tab << "void* dp = &d;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- adress of dp : " << dp << r2cm::linefeed;
				std::cout << r2cm::tab2 << "- space size : " << space << r2cm::linefeed;
				std::cout << r2cm::linefeed << r2cm::linefeed;

				{
					std::cout << r2cm::tab << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2cm::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << r2cm::tab2 << "- success" << r2cm::linefeed;
					}
					else
					{
						std::cout << r2cm::tab2 << "- failed" << r2cm::linefeed;
					}

					{
						std::cout << r2cm::tab2 << "- adress of dp : " << dp << r2cm::linefeed;
						std::cout << r2cm::tab2 << "- space size : " << space << r2cm::linefeed;
					}
				}

				std::cout << r2cm::linefeed << r2cm::linefeed;

				{
					const int move_amount = 1;

					char* cp = static_cast<char*>( dp );
					cp += move_amount;

					dp = cp;
					space -= sizeof( char );

					std::cout << r2cm::tab << "move " << move_amount << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- adress of dp : " << dp << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- space size : " << space << r2cm::linefeed;
					std::cout << r2cm::linefeed;

					std::cout << r2cm::tab << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2cm::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << r2cm::tab2 << "- success" << r2cm::linefeed;
					}
					else
					{
						std::cout << r2cm::tab2 << "- failed" << r2cm::linefeed;
					}

					{
						std::cout << r2cm::tab2 << "- adress of dp : " << dp << r2cm::linefeed;
						std::cout << r2cm::tab2 << "- space size : " << space << r2cm::linefeed;
					}
				}

				std::cout << r2cm::linefeed << r2cm::linefeed;

				{
					const int move_amount = 1;

					char* cp = static_cast<char*>( dp );
					cp += move_amount;

					dp = cp;
					space -= sizeof( char );

					std::cout << r2cm::tab << "move " << move_amount << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- adress of dp : " << dp << r2cm::linefeed;
					std::cout << r2cm::tab2 << "- space size : " << space << r2cm::linefeed;
					std::cout << r2cm::linefeed;

					std::cout << r2cm::tab << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2cm::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << r2cm::tab2 << "- success" << r2cm::linefeed;
					}
					else
					{
						std::cout << r2cm::tab2 << "- failed" << r2cm::linefeed;
					}

					{
						std::cout << r2cm::tab2 << "- adress of dp : " << dp << r2cm::linefeed;
						std::cout << r2cm::tab2 << "- space size : " << space << r2cm::linefeed;
						std::cout << r2cm::linefeed;
					}
				}
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}


	
	r2cm::iItem::TitleFunctionT Align_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 2";
		};
	}
	r2cm::iItem::DoFunctionT Align_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

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