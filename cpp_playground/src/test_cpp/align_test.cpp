#include "pch.h"
#include "align_test.h"

#include "base/r2_eTestEndAction.h"

namespace align_test
{
	r2::iItem::TitleFuncT Align_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 0";
		};
	}
	r2::iItem::DoFunc Align_0::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				int i = 1;
				void* ip = &i;
				std::size_t space = sizeof( i );

				std::cout << r2::tab << "int i = 1;" << r2::linefeed;
				std::cout << r2::tab << "void* ip = &i;" << r2::linefeed;
				std::cout << r2::tab2 << "- adress of ip : " << ip << r2::linefeed;
				std::cout << r2::tab2 << "- space : " << space << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				{
					std::cout << r2::tab << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << r2::tab2 << "- success" << r2::linefeed;
					}
					else
					{
						std::cout << r2::tab2 << "- failed" << r2::linefeed;
					}

					{
						std::cout << r2::tab2 << "- adress of ip : " << ip << r2::linefeed;
						std::cout << r2::tab2 << "- space : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					int move_amount = 3;

					char* cp = static_cast<char*>( ip );
					cp += move_amount;

					ip = cp;
					space -= sizeof( char ) * move_amount;

					std::cout << r2::tab << "move " << move_amount << r2::linefeed;
					std::cout << r2::tab2 << "- adress of ip : " << ip << r2::linefeed;
					std::cout << r2::tab2 << "- space : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << r2::tab << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << r2::tab2 << "- success" << r2::linefeed;
					}
					else
					{
						std::cout << r2::tab2 << "- failed" << r2::linefeed;
					}

					{
						std::cout << r2::tab2 << "- adress of ip : " << ip << r2::linefeed;
						std::cout << r2::tab2 << "- space : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					int move_amount = 1;

					char* cp = static_cast<char*>( ip );
					cp += move_amount;

					ip = cp;
					space -= sizeof( char ) * move_amount;

					std::cout << r2::tab << "move " << move_amount << r2::linefeed;
					std::cout << r2::tab2 << "- adress of ip : " << ip << r2::linefeed;
					std::cout << r2::tab2 << "- space : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << r2::tab << "std::align( alignof( char ), sizeof( char ), ip, space )" << r2::linefeed;
					if( std::align( alignof( char ), sizeof( char ), ip, space ) )
					{
						std::cout << r2::tab2 << "- success" << r2::linefeed;
					}
					else
					{
						std::cout << r2::tab2 << "- failed" << r2::linefeed;
					}

					{
						std::cout << r2::tab2 << "- adress of ip : " << ip << r2::linefeed;
						std::cout << r2::tab2 << "- space : " << space << r2::linefeed;
						std::cout << r2::linefeed;
					}
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}


	r2::iItem::TitleFuncT Align_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 1";
		};
	}
	r2::iItem::DoFunc Align_1::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				double d = 1;
				void* dp = &d;
				std::size_t space = sizeof( double );

				std::cout << r2::tab << "double d;" << r2::linefeed;
				std::cout << r2::tab << "void* dp = &d;" << r2::linefeed;
				std::cout << r2::tab2 << "- adress of dp : " << dp << r2::linefeed;
				std::cout << r2::tab2 << "- space size : " << space << r2::linefeed;
				std::cout << r2::linefeed << r2::linefeed;

				{
					std::cout << r2::tab << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << r2::tab2 << "- success" << r2::linefeed;
					}
					else
					{
						std::cout << r2::tab2 << "- failed" << r2::linefeed;
					}

					{
						std::cout << r2::tab2 << "- adress of dp : " << dp << r2::linefeed;
						std::cout << r2::tab2 << "- space size : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					const int move_amount = 1;

					char* cp = static_cast<char*>( dp );
					cp += move_amount;

					dp = cp;
					space -= sizeof( char );

					std::cout << r2::tab << "move " << move_amount << r2::linefeed;
					std::cout << r2::tab2 << "- adress of dp : " << dp << r2::linefeed;
					std::cout << r2::tab2 << "- space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << r2::tab << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << r2::tab2 << "- success" << r2::linefeed;
					}
					else
					{
						std::cout << r2::tab2 << "- failed" << r2::linefeed;
					}

					{
						std::cout << r2::tab2 << "- adress of dp : " << dp << r2::linefeed;
						std::cout << r2::tab2 << "- space size : " << space << r2::linefeed;
					}
				}

				std::cout << r2::linefeed << r2::linefeed;

				{
					const int move_amount = 1;

					char* cp = static_cast<char*>( dp );
					cp += move_amount;

					dp = cp;
					space -= sizeof( char );

					std::cout << r2::tab << "move " << move_amount << r2::linefeed;
					std::cout << r2::tab2 << "- adress of dp : " << dp << r2::linefeed;
					std::cout << r2::tab2 << "- space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;

					std::cout << r2::tab << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
					if( std::align( alignof( int ), sizeof( int ), dp, space ) )
					{
						std::cout << r2::tab2 << "- success" << r2::linefeed;
					}
					else
					{
						std::cout << r2::tab2 << "- failed" << r2::linefeed;
					}

					{
						std::cout << r2::tab2 << "- adress of dp : " << dp << r2::linefeed;
						std::cout << r2::tab2 << "- space size : " << space << r2::linefeed;
						std::cout << r2::linefeed;
					}
				}
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}


	
	r2::iItem::TitleFuncT Align_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 2";
		};
	}
	r2::iItem::DoFunc Align_2::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				char buffer[] = "------------------------";
				void * pt = buffer;

				std::cout << r2::tab << "+ orig : " << buffer << r2::linefeed;
				std::cout << r2::tab << "+ adress of pt : " << pt << r2::linefeed << r2::linefeed;

				std::cout << r2::tab << "+ Process" << r2::linefeed;

				std::size_t space = sizeof( buffer ) - 1;
				while( std::align( alignof( int ), sizeof( char ), pt, space ) )
				{
					std::cout << r2::tab2 << "- old adress of pt : " << pt << r2::linefeed;

					if( !std::align( alignof( int ), sizeof( char ), pt, space ) )
					{
						break;
					}

					char* temp = static_cast<char*>( pt );
					*temp = '*';
					++temp;
					space -= sizeof( char );

					pt = temp;

					std::cout << r2::tab2 << "- convert : " << buffer << r2::linefeed;
					std::cout << r2::tab2 << "- new adress of pt : " << pt << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << r2::tab << "result : " << buffer << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}