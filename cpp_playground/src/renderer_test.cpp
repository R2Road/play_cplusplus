#include "pch.h"
#include "renderer_test.h"

#include <functional>
#include <Windows.h>

#include "r2_eTestResult.h"

#include "r2_Point.h"

namespace renderer_test
{
	VisibleResource_FillAll::VisibleResource_FillAll() : mVisibleResource( 30, 20 ) {}

	const r2::iTest::TitleFunc VisibleResource_FillAll::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Fill All";
		};
	}
	const r2::iTest::DoFunc VisibleResource_FillAll::GetDoFunction() const
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

	const r2::iTest::TitleFunc VisibleResource_Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Fill";
		};
	}
	const r2::iTest::DoFunc VisibleResource_Fill::GetDoFunction() const
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

	const r2::iTest::TitleFunc VisibleResource_DrawWithPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Draw With Position";
		};
	}
	const r2::iTest::DoFunc VisibleResource_DrawWithPosition::GetDoFunction() const
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

	const r2::iTest::TitleFunc VisibleResource_InitWithChars::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Init With Chars";
		};
	}
	const r2::iTest::DoFunc VisibleResource_InitWithChars::GetDoFunction() const
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



	class TestRenderable : public r2::Renderable
	{
	public:
		TestRenderable() : mPoint( { 8, 5 } ), mVisibleResource( 6u, "######" "#    #" "#    #" "#    #" "#    #" "######" )
		{}

		void Draw() override
		{
			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD pos = { mPoint.x, mPoint.y };
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
		r2::Point mPoint;
		r2::VisibleResource mVisibleResource;
	};
	TestRenderer::TestRenderer() : mRenderer() {}

	const r2::iTest::TitleFunc TestRenderer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Renderer( In Progress )";
		};
	}
	const r2::iTest::DoFunc TestRenderer::GetDoFunction() const
	{
		auto& rd = GetInstance().mRenderer;

		static TestRenderable tr;
		rd.Add( &tr );

		return [&rd]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			rd.Draw();

			return r2::eTestResult::RunTest;
		};
	}
}