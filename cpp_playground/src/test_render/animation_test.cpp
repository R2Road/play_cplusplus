#include "pch.h"
#include "animation_test.h"

#include <conio.h>
#include <Windows.h>

#include "base/r2_eTestResult.h"

#include "renderer/r2_FrameManager.h"
#include "renderer/r2_iRenderable.h"
#include "renderer/r2_VisibleResource.h"

namespace animation_test
{
	class Renderable4AnimationTest : public r2::iRenderable
	{
	public:
		Renderable4AnimationTest( const int x, const int y, const std::size_t width, const char* chars ) :
			mVisibleResource( width, chars )
			, mRect( { x, y, mVisibleResource.GetWidth(), mVisibleResource.GetHeight() } )
		{}

		void Draw( const r2::Camera* const camera ) override
		{
			if( !camera->GetRect().IntersectsRect( mRect ) )
			{
				return;
			}

			const auto visible_rect = camera->GetRect().IntersectsWithRect( mRect );

			const COORD pivot_pos = {
				static_cast<short>( visible_rect.GetMinX() - camera->GetX() )
				, static_cast<short>( visible_rect.GetMinY() - camera->GetY() )
			};

			const int resource_offset_y = visible_rect.GetMinY() - mRect.GetMinY();
			const int resource_offset_x = visible_rect.GetMinX() - mRect.GetMinX();

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			for( int y = 0; y < visible_rect.GetHeight(); ++y )
			{
				for( int x = 0; x < visible_rect.GetWidth(); ++x )
				{
					SetConsoleCursorPosition( stdHandle, {
						pivot_pos.X + static_cast<short>( x )
						, pivot_pos.Y + static_cast<short>( y ) }
					);

					std::cout << mVisibleResource.Get(
						resource_offset_x + x
						, resource_offset_y + y
					);
				}
			}
		}

	private:
		r2::VisibleResource mVisibleResource;
		r2::RectInt mRect;
	};

	Basic::Basic() : mCamera(), mRenderer()
	{}
	r2::iTest::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Animation - Basic";
		};
	}
	r2::iTest::DoFunc Basic::GetDoFunction()
	{
		GetInstance().mRenderer.Clear();
		GetInstance().mRenderer.SetCamera( &mCamera );

		{
			static Renderable4AnimationTest tr( 8, 5, 6u, "######" "#    #" "#    #" "#    #" "#    #" "######" );
			GetInstance().mRenderer.Add( &tr );
		}

		{
			static Renderable4AnimationTest tr( 8, 5, 6u, " #### " " #  # " " #  # " " #  # " " #  # " " #### " );
			GetInstance().mRenderer.Add( &tr );
		}

		{
			static Renderable4AnimationTest tr( 8, 5, 6u, "  ##  " "  ##  " "  ##  " "  ##  " "  ##  " "  ##  " );
			GetInstance().mRenderer.Add( &tr );
		}

		return [&rd = GetInstance().mRenderer, &cam = mCamera]()->r2::eTestResult
		{
			r2::FrameManager frame_manager( 30u );
			frame_manager.Reset();

			int x = 0;
			int y = 0;
			bool process = true;
			while( process )
			{
				if( frame_manager.Update() )
				{
					rd.Draw();
				}

				if( _kbhit() )
				{
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
				}

				cam.SetPoint( x, y );
			}

			return r2::eTestResult::RunTest;
		};
	}
}