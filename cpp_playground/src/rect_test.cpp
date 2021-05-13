#include "pch.h"
#include "rect_test.h"

#include <algorithm>	
#include <conio.h>
#include <Windows.h>

#include "r2_eTestResult.h"
#include "r2_RectInt.h"

namespace rect_test
{
	void DrawRect( const r2::RectInt& rect, const char c )
	{
		HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

		for( int y = rect.GetMinY(); rect.GetMaxY() > y; ++y )
		{
			for( int x = rect.GetMinX(); rect.GetMaxX() > x; ++x )
			{
				SetConsoleCursorPosition( stdHandle, { static_cast<short>( x ), static_cast<short>( y ) } );

				std::cout << c;
			}
		}
	}
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Rect : Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			{
				const r2::RectInt rect_1( 4, 4, 6, 6 );
				const r2::RectInt rect_2( 6, 6, 6, 6 );

				DrawRect( rect_1, '1' );
				DrawRect( rect_2, '2' );

				const auto rect_3 = rect_1.IntersectsWithRect( rect_2 );

				DrawRect( rect_3, '3' );

				SetConsoleCursorPosition(
					stdHandle
					, { 0, static_cast<short>( std::max( { rect_1.GetMaxY(), rect_2.GetMaxY(), rect_3.GetMaxY() } ) ) }
				);
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}