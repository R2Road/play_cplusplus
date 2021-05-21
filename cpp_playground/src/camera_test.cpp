#include "pch.h"
#include "camera_test.h"

#include <conio.h>
#include <Windows.h>

#include "r2_eTestResult.h"

#include "r2_iRenderable.h"
#include "r2_PointInt.h"
#include "r2_VisibleResource.h"

namespace camera_test
{
	CameraRect::CameraRect() : mCamera()
	{}
	r2::iTest::TitleFunc CameraRect::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Camera Rect";
		};
	}
	r2::iTest::DoFunc CameraRect::GetDoFunction()
	{
		GetInstance().mCamera.SetPoint( { 2, 2 } );

		return[rect = GetInstance().mCamera.GetRect()]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );

			for( int y = rect.GetMinY(); rect.GetMaxY() > y; ++y )
			{
				for( int x = rect.GetMinX(); rect.GetMaxX() > x; ++x )
				{
					SetConsoleCursorPosition( stdHandle, { static_cast<short>( x ), static_cast<short>( y ) } );

					std::cout << '#';
				}
			}

			std::cout << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}


namespace camera_test
{
	class TempRenderable : public r2::iRenderable
	{
	public:
		TempRenderable( const int x, const int y, const std::size_t width, const char* chars ) :
			mPoint( { x, y } )
			, mVisibleResource( width, chars )
		{}

		void Draw( const r2::Camera* const camera ) override
		{
			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD pos = { mPoint.GetX() - camera->GetPoint().GetX() , mPoint.GetY() - camera->GetPoint().GetY() };
			SetConsoleCursorPosition( stdHandle, pos );

			int count = 0;
			for( const char element : mVisibleResource )
			{
				std::cout << element;

				++count;
				if( mVisibleResource.GetWidth() <= count )
				{
					count = 0;
					pos.Y += 1;
					SetConsoleCursorPosition( stdHandle, pos );
				}
			}
		}

	private:
		r2::PointInt mPoint;
		r2::VisibleResource mVisibleResource;
	};

	CameraMove1::CameraMove1() : mCamera(), mRenderer()
	{}
	r2::iTest::TitleFunc CameraMove1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Camera Move 1";
		};
	}
	r2::iTest::DoFunc CameraMove1::GetDoFunction()
	{
		GetInstance().mRenderer.Clear();


		GetInstance().mRenderer.SetCamera( &mCamera );

		{
			std::string str( "# " );
			str += GetInstance().GetTitleFunction()( );
			str += " #";
			static TempRenderable tr( 0, 0, str.length(), str.c_str() );
			GetInstance().mRenderer.Add( &tr );
		}

		{
			std::string_view str( "[ESC] Return to Root" );
			static TempRenderable tr( 0, 1, str.length(), str.data() );
			GetInstance().mRenderer.Add( &tr );
		}

		{
			std::string_view str( "[W,A,S,D] Move Camera" );
			static TempRenderable tr( 0, 2, str.length(), str.data() );
			GetInstance().mRenderer.Add( &tr );
		}

		{
			static TempRenderable tr( 2, 4, 3u, "###" "# #" "###" );
			GetInstance().mRenderer.Add( &tr );
		}

		{
			static TempRenderable tr( 11, 7, 7u, "#######" "#     #" "#     #" "#     #" "#     #" "#######" );
			GetInstance().mRenderer.Add( &tr );
		}


		return [&rd = GetInstance().mRenderer, &cam = mCamera]()->r2::eTestResult
		{
			int x = 0;
			int y = 0;
			bool process = true;
			while( process )
			{
				rd.Draw();

				switch( _getch() )
				{
				case 'w': // up
					y -= 1;
					break;
				case 's': // down
					y += 1;
					break;
				case 'a': // left
					x -= 1;
					break;
				case 'd': // right
					x += 1;
					break;

				case 27: // ESC
					process = false;
					break;
				}

				cam.SetPoint( x, y );
			}

			return r2::eTestResult::RunTest_Without_Pause;
		};
	}
}