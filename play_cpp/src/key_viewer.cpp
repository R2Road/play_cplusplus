#include "key_viewer.h"

#include "r2tm/r2tm_ColorModifier.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_WindowsUtility.h"

namespace key_viewer
{
	r2tm::TitleFunctionT View::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Key Code View";
		};
	}
	r2tm::DoFunctionT View::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				OUTPUT_SUBJECT( "[   ESC   ] End" );
				OUTPUT_SUBJECT( "[ Any Key ] ..." );
			}

			LS();

			{
				const auto start_point = r2tm::WindowsUtility::GetCursorPoint();
				const short line_limit = start_point.y + 30;

				r2tm::WindowsUtility::MoveCursorPoint( start_point.x, line_limit );
				LS();
				r2tm::WindowsUtility::MoveCursorPoint( start_point );

				int input = 0;
				do
				{

					input = GET_KEY;

					if( line_limit <= r2tm::WindowsUtility::GetCursorPoint().y )
					{
						r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( start_point );
					}

					std::cout << "> Key : " << clm( r2tm::eColor::FG_LightYellow ) << input << clm() << r2tm::linefeed;

				} while( 27 != input ); // ESC
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}