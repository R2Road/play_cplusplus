#include "pch.h"
#include "renderer_test.h"

#include <Windows.h>

#include "r2_eTestResult.h"

#include "r2_Camera.h"
#include "r2_iRenderable.h"

namespace renderer_test
{
	class TempRenderable : public r2::iRenderable
	{
	public:
		TempRenderable( const int x, const int y, const std::size_t width, const char* chars) :
			mPoint( { x, y } )
			, mVisibleResource( width, chars )
		{}

		void Draw( const r2::Camera* const camera ) override
		{
			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD pos = {
				static_cast<short>( mPoint.GetX() - camera->GetPoint().GetX() )
				, static_cast<short>( mPoint.GetY() - camera->GetPoint().GetY() )
			};
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

	r2::iTest::TitleFunc TestRenderable::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Renderable";
		};
	}
	r2::iTest::DoFunc TestRenderable::GetDoFunction()
	{
		static TempRenderable tr( 8, 5, 6u, "######" "#    #" "#    #" "#    #" "#    #" "######" );
		auto& tr2 = tr;

		return [&tr2]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			r2::Camera camera;
			tr2.Draw( &camera);

			return r2::eTestResult::RunTest;
		};
	}



	TestRenderer::TestRenderer() : mRenderer() {}

	r2::iTest::TitleFunc TestRenderer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Renderer";
		};
	}
	r2::iTest::DoFunc TestRenderer::GetDoFunction()
	{
		auto& rd = GetInstance().mRenderer;
		rd.Clear();


		static r2::Camera dummy_camera;
		rd.SetCamera( &dummy_camera );


		std::string str( "# " );
		str += GetInstance().GetTitleFunction()();
		str += " #";
		static TempRenderable tr0( 0, 0, str.length(), str.c_str() );
		rd.Add( &tr0 );

		static TempRenderable tr1( 2, 2, 3u, "###" "# #" "###" );
		rd.Add( &tr1 );

		static TempRenderable tr2( 8, 3, 6u, "######" "#    #" "#    #" "#    #" "#    #" "######" );
		rd.Add( &tr2 );

		static TempRenderable tr3( 11, 5, 7u, "#######" "#     #" "#     #" "#     #" "#     #" "#######" );
		rd.Add( &tr3 );

		return [&rd]()->r2::eTestResult
		{
			rd.Draw();

			return r2::eTestResult::RunTest;
		};
	}
}