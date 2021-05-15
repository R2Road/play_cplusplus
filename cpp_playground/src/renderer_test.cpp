#include "pch.h"
#include "renderer_test.h"

#include <Windows.h>

#include "r2_eTestResult.h"

#include "r2_Camera.h"
#include "r2_iRenderable.h"

namespace renderer_test
{
	VisibleResource_FillAll::VisibleResource_FillAll() : mVisibleResource( 30, 20 ) {}

	r2::iTest::TitleFunc VisibleResource_FillAll::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Fill All";
		};
	}
	r2::iTest::DoFunc VisibleResource_FillAll::GetDoFunction()
	{
		GetInstance().mVisibleResource.FillAll( '0' );

		const auto& fb = GetInstance().mVisibleResource;

		return [fb]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::size_t x = 0;
			for( const char element : fb )
			{
				std::cout << element;

				++x;
				if( fb.GetWidth() <= x )
				{
					x = 0u;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	VisibleResource_Fill::VisibleResource_Fill() : mVisibleResource( 30, 20 ) {}

	r2::iTest::TitleFunc VisibleResource_Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Fill";
		};
	}
	r2::iTest::DoFunc VisibleResource_Fill::GetDoFunction()
	{
		GetInstance().mVisibleResource.Fill( 0, 0, '0' );
		GetInstance().mVisibleResource.Fill( GetInstance().mVisibleResource.GetWidth() - 1u, 0, '0' );
		GetInstance().mVisibleResource.Fill( GetInstance().mVisibleResource.GetWidth() - 1u, GetInstance().mVisibleResource.GetHeight() - 1u, '0' );
		GetInstance().mVisibleResource.Fill( 0, GetInstance().mVisibleResource.GetHeight() - 1u, '0' );

		const auto& fb = GetInstance().mVisibleResource;

		return [fb]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			std::size_t x = 0;
			for( const char element : fb )
			{
				std::cout << element;

				++x;
				if( fb.GetWidth() <= x )
				{
					x = 0u;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	VisibleResource_DrawWithPosition::VisibleResource_DrawWithPosition() : mVisibleResource( 10, 10 ) {}

	r2::iTest::TitleFunc VisibleResource_DrawWithPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Draw With Position";
		};
	}
	r2::iTest::DoFunc VisibleResource_DrawWithPosition::GetDoFunction()
	{
		GetInstance().mVisibleResource.FillAll( '0' );

		const auto& fb = GetInstance().mVisibleResource;

		return [fb]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD pos = { 10, 5 };
			SetConsoleCursorPosition( stdHandle, pos );

			int count = 0;
			for( const char element : fb )
			{
				std::cout << element;

				++count;
				if( fb.GetWidth() <= count )
				{
					count = 0;
					pos.Y += 1;
					SetConsoleCursorPosition( stdHandle, pos );
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	VisibleResource_InitWithChars::VisibleResource_InitWithChars() :
		mVisibleResource1( "Init With Chars" )
		, mVisibleResource2( 5, "aaaaaaaaabbbbbbbbbbcccccdddddddeeeeeeeeeeeeeeeefffggg" )
	{}

	r2::iTest::TitleFunc VisibleResource_InitWithChars::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Init With Chars";
		};
	}
	r2::iTest::DoFunc VisibleResource_InitWithChars::GetDoFunction()
	{
		const auto& fb1 = GetInstance().mVisibleResource1;
		const auto& fb2 = GetInstance().mVisibleResource2;

		return [fb1, fb2]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::size_t x = 0;

			{
				for( const char element : fb1 )
				{
					std::cout << element;

					++x;
					if( fb1.GetWidth() <= x )
					{
						x = 0u;
						std::cout << r2::linefeed;
					}
				}
			}

			std::cout << r2::split;

			{
				x = 0;
				for( const char element : fb2 )
				{
					std::cout << element;

					++x;
					if( fb2.GetWidth() <= x )
					{
						x = 0u;
						std::cout << r2::linefeed;
					}
				}
				if( 0u != x )
				{
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



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