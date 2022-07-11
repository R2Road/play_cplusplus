#include "flickering_research.h"

#include <conio.h> // _kbhit(), _getch()
#include <Windows.h> // HANDLE, COORD, SetConsoleCursorPosition()

#include "r2cm/r2cm_ostream.h"

#include "utility/r2utility_CharacterBuffer.h"

namespace flickering_research
{
	r2cm::iItem::TitleFunctionT OneByOne::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print One By One";
		};
	}
	r2cm::iItem::DoFunctionT OneByOne::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			r2utility::CharacterBuffer visible_resource( 19, 19 );
			visible_resource.FillAll( 'a' );

			bool process = true;
			do
			{
				system( "cls" );

				std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
				std::cout << "[Any Key] End" << r2cm::linefeed;

				std::cout << r2cm::split;

				int current_x = 0;
				for( const auto v : visible_resource )
				{
					if( visible_resource.GetWidth() <= current_x )
					{
						std::cout << r2cm::linefeed;
						current_x = 0;
					}

					std::cout << v;

					++current_x;
				}

				std::cout << r2cm::linefeed << r2cm::split;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2cm::eItemLeaveAction::None;
		};
	}
	r2cm::iItem::TitleFunctionT OneByOne_WithOut_CLS::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print One By One WithOut CLS";
		};
	}
	r2cm::iItem::DoFunctionT OneByOne_WithOut_CLS::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
			std::cout << "[Any Key] End" << r2cm::linefeed;

			std::cout << r2cm::split;
			std::cout << r2cm::linefeed3 << r2cm::linefeed3 << r2cm::linefeed3 << r2cm::linefeed3 << r2cm::linefeed3 << r2cm::linefeed3 << r2cm::linefeed;
			std::cout << r2cm::split;

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
						std::cout << r2cm::linefeed;
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

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT LineByLine::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Line By Line";
		};
	}
	r2cm::iItem::DoFunctionT LineByLine::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			r2utility::CharacterBuffer visible_resource( 19, 19 );
			visible_resource.FillAll( 'a' );

			bool process = true;
			do
			{
				system( "cls" );

				std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
				std::cout << "[Any Key] End" << r2cm::linefeed;

				std::cout << r2cm::split;

				for( int current_y = 0; visible_resource.GetHeight() > current_y; ++current_y )
				{
					std::cout << visible_resource.GetLine( current_y ) << r2cm::linefeed;
				}

				std::cout << r2cm::split;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT PageByPage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Page By Page";
		};
	}
	r2cm::iItem::DoFunctionT PageByPage::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			r2utility::CharacterBuffer character_buffer( 100, 40 );
			character_buffer.FillAll( 'c' );

			bool process = true;
			do
			{
				system( "cls" );

				std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed2;
				std::cout << "[Any Key] End" << r2cm::linefeed;

				std::cout << r2cm::split;

				std::cout << &( *character_buffer.begin() );

				std::cout << r2cm::split;

				//
				// Input
				//
				if( _kbhit() )
				{
					_getch(); // need
					process = false;
				}

			} while( process );

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT PageByPage_WithOut_CLS_1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Page By Page Without CLS 1";
		};
	}
	r2cm::iItem::DoFunctionT PageByPage_WithOut_CLS_1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
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

			return r2cm::eItemLeaveAction::None;
		};
	}



	r2cm::iItem::TitleFunctionT PageByPage_WithOut_CLS_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Flickering : Print Page By Page Without CLS 2";
		};
	}
	r2cm::iItem::DoFunctionT PageByPage_WithOut_CLS_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
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

			return r2cm::eItemLeaveAction::None;
		};
	}
}