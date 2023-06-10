#include "windows_terminal_flickering_research.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h> // HANDLE, COORD, SetConsoleCursorPosition()

#include "r2tm/r2tm_ostream.h"

#include "utility/r2utility_CharacterBuffer.h"

namespace windows_terminal_flickering_research
{
	r2tm::TitleFunctionT OneByOne::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print One By One";
		};
	}
	r2tm::DoFunctionT OneByOne::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2utility::CharacterBuffer visible_resource( 19, 19 );
			visible_resource.FillAll( 'a' );

			bool process = true;
			do
			{
				system( "cls" );

				std::cout << "[Any Key] End" << r2tm::linefeed;

				std::cout << r2tm::split;

				int current_x = 0;
				for( const auto v : visible_resource )
				{
					if( visible_resource.GetWidth() <= current_x )
					{
						std::cout << r2tm::linefeed;
						current_x = 0;
					}

					std::cout << v;

					++current_x;
				}

				std::cout << r2tm::linefeed << r2tm::split;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2tm::eDoLeaveAction::None;
		};
	}
	r2tm::TitleFunctionT OneByOne_WithOut_CLS::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print One By One WithOut CLS";
		};
	}
	r2tm::DoFunctionT OneByOne_WithOut_CLS::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			std::cout << "[Any Key] End" << r2tm::linefeed;

			std::cout << r2tm::split;
			std::cout << r2tm::linefeed3 << r2tm::linefeed3 << r2tm::linefeed3 << r2tm::linefeed3 << r2tm::linefeed3 << r2tm::linefeed3 << r2tm::linefeed;
			std::cout << r2tm::split;

			r2utility::CharacterBuffer visible_resource( 19, 19 );
			visible_resource.FillAll( 'a' );

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			const COORD pos = { 0, 6 };

			bool process = true;
			do
			{
				SetConsoleCursorPosition( stdHandle, pos );

				int current_x = 0;
				for( const auto v : visible_resource )
				{
					if( visible_resource.GetWidth() <= current_x )
					{
						std::cout << r2tm::linefeed;
						current_x = 0;
					}

					std::cout << v;

					++current_x;
				}

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT LineByLine::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Line By Line";
		};
	}
	r2tm::DoFunctionT LineByLine::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2utility::CharacterBuffer visible_resource( 19, 19 );
			visible_resource.FillAll( 'a' );

			bool process = true;
			do
			{
				system( "cls" );

				std::cout << "[Any Key] End" << r2tm::linefeed;

				std::cout << r2tm::split;

				for( int current_y = 0; visible_resource.GetHeight() > current_y; ++current_y )
				{
					std::cout << visible_resource.GetLine( current_y ) << r2tm::linefeed;
				}

				std::cout << r2tm::split;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT PageByPage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Page By Page";
		};
	}
	r2tm::DoFunctionT PageByPage::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2utility::CharacterBuffer character_buffer( 100, 40 );
			character_buffer.FillAll( 'c' );

			bool process = true;
			do
			{
				system( "cls" );

				std::cout << "[Any Key] End" << r2tm::linefeed;

				std::cout << r2tm::split;

				std::cout << &( *character_buffer.begin() );

				std::cout << r2tm::split;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT PageByPage_WithOut_CLS_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Page By Page Without CLS 1";
		};
	}
	r2tm::DoFunctionT PageByPage_WithOut_CLS_1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2utility::CharacterBuffer character_buffer( 100, 40 );
			character_buffer.FillAll( 'c' );

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			const COORD pos = { 0, 0 };

			bool process = true;
			do
			{
				SetConsoleCursorPosition( stdHandle, pos );

				std::cout << &( *character_buffer.begin() );

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2tm::eDoLeaveAction::None;
		};
	}



	r2tm::TitleFunctionT PageByPage_WithOut_CLS_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Page By Page Without CLS 2";
		};
	}
	r2tm::DoFunctionT PageByPage_WithOut_CLS_2::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			r2utility::CharacterBuffer character_buffer_1( 100, 40 );
			character_buffer_1.FillAll( 'c' );

			r2utility::CharacterBuffer character_buffer_2( 100, 40 );
			character_buffer_2.FillAll( 'a' );

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			const COORD pos = { 0, 0 };
			bool bDrawTarget = true;

			bool process = true;
			do
			{
				SetConsoleCursorPosition( stdHandle, pos );

				if( bDrawTarget )
				{
					std::cout << &( *character_buffer_1.begin() );
				}
				else
				{
					std::cout << &( *character_buffer_2.begin() );
				}

				bDrawTarget = !bDrawTarget;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2tm::eDoLeaveAction::None;
		};
	}
}