#include "pch.h"
#include "align_test.h"

#include "r2cm/r2cm_constant.h"

namespace align_test
{
	r2cm::iItem::TitleFuncT Align_0::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 0";
		};
	}
	r2cm::iItem::DoFuncT Align_0::GetDoFunction()
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


	r2cm::iItem::TitleFuncT Align_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 1";
		};
	}
	r2cm::iItem::DoFuncT Align_1::GetDoFunction()
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


	
	r2cm::iItem::TitleFuncT Align_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align 2";
		};
	}
	r2cm::iItem::DoFuncT Align_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				char buffer[] = "------------------------";
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