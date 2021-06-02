#include "pch.h"
#include "visibleresource_test.h"

#include <Windows.h>

#include "base/r2_eTestResult.h"

#include "renderer/r2_Camera.h"
#include "renderer/r2_iRenderable.h"

namespace visibleresource_test
{
	FillAll::FillAll() : mVisibleResource( 30, 20 ) {}

	r2::iTest::TitleFunc FillAll::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Fill All";
		};
	}
	r2::iTest::DoFunc FillAll::GetDoFunction()
	{
		GetInstance().mVisibleResource.FillAll( '0' );

		const auto& vr = GetInstance().mVisibleResource;

		return [vr]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::size_t x = 0;
			for( const char element : vr )
			{
				std::cout << element;

				++x;
				if( vr.GetWidth() <= x )
				{
					x = 0u;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	Fill::Fill() : mVisibleResource( 30, 20 ) {}

	r2::iTest::TitleFunc Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Fill";
		};
	}
	r2::iTest::DoFunc Fill::GetDoFunction()
	{
		GetInstance().mVisibleResource.Fill( 0, 0, '0' );
		GetInstance().mVisibleResource.Fill( GetInstance().mVisibleResource.GetWidth() - 1u, 0, '0' );
		GetInstance().mVisibleResource.Fill( GetInstance().mVisibleResource.GetWidth() - 1u, GetInstance().mVisibleResource.GetHeight() - 1u, '0' );
		GetInstance().mVisibleResource.Fill( 0, GetInstance().mVisibleResource.GetHeight() - 1u, '0' );

		const auto& vr = GetInstance().mVisibleResource;

		return [vr]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			std::size_t x = 0;
			for( const char element : vr )
			{
				std::cout << element;

				++x;
				if( vr.GetWidth() <= x )
				{
					x = 0u;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}



	DrawWithPosition::DrawWithPosition() : mVisibleResource( 10, 10 ) {}

	r2::iTest::TitleFunc DrawWithPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Draw With Position";
		};
	}
	r2::iTest::DoFunc DrawWithPosition::GetDoFunction()
	{
		GetInstance().mVisibleResource.FillAll( '0' );

		const auto& vr = GetInstance().mVisibleResource;

		return [vr]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			HANDLE stdHandle = GetStdHandle( STD_OUTPUT_HANDLE );
			COORD pos = { 10, 5 };
			SetConsoleCursorPosition( stdHandle, pos );

			int count = 0;
			for( const char element : vr )
			{
				std::cout << element;

				++count;
				if( vr.GetWidth() <= count )
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



	InitWithChars::InitWithChars() :
		mVisibleResource1( "Init With Chars" )
		, mVisibleResource2( 5, "aaaaaaaaabbbbbbbbbbcccccdddddddeeeeeeeeeeeeeeeefffggg" )
	{}

	r2::iTest::TitleFunc InitWithChars::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Init With Chars";
		};
	}
	r2::iTest::DoFunc InitWithChars::GetDoFunction()
	{
		const auto& vr1 = GetInstance().mVisibleResource1;
		const auto& vr2 = GetInstance().mVisibleResource2;

		return [vr1, vr2]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			std::size_t x = 0;

			{
				for( const char element : vr1 )
				{
					std::cout << element;

					++x;
					if( vr1.GetWidth() <= x )
					{
						x = 0u;
						std::cout << r2::linefeed;
					}
				}
			}

			std::cout << r2::split;

			{
				x = 0;
				for( const char element : vr2 )
				{
					std::cout << element;

					++x;
					if( vr2.GetWidth() <= x )
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



	VisibleRect::VisibleRect() :
		mVisibleResource( 5, "aaaaaaaaabbbbbbbbbbcccccdddddddeeeeeeeeeeeeeeeefffggg" )
	{}

	r2::iTest::TitleFunc VisibleRect::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Visible Resource - Visible Rect";
		};
	}
	r2::iTest::DoFunc VisibleRect::GetDoFunction()
	{
		auto visible_rect = GetInstance().mVisibleResource.GetVisibleRect();
		visible_rect.SetOrigin( visible_rect.GetOrigin().GetX() + 2, visible_rect.GetOrigin().GetY() + 1 );
		visible_rect.SetSize( visible_rect.GetSize().GetWidth() - 2, visible_rect.GetSize().GetHeight() - 1 );
		GetInstance().mVisibleResource.SetVisibleRect( visible_rect );


		return [&vr = GetInstance().mVisibleResource]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::size_t x = 0;
				for( const char element : vr )
				{
					std::cout << element;

					++x;
					if( vr.GetWidth() <= x )
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

			{
				for( int y = vr.GetVisibleRect().GetMinY(); y < vr.GetVisibleRect().GetMaxY(); ++y )
				{
					for( int x = vr.GetVisibleRect().GetMinX(); x < vr.GetVisibleRect().GetMaxX(); ++x )
					{
						std::cout << vr.Get( x, y );
					}

					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}