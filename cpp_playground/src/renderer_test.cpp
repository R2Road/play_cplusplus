#include "pch.h"
#include "renderer_test.h"

#include <functional>
#include <Windows.h>

#include "r2_eTestResult.h"

namespace renderer_test
{
	FrameBuffer_FillAll::FrameBuffer_FillAll() : mFrameBuffer( 30, 20 ) {}

	const r2::iTest::TitleFunc FrameBuffer_FillAll::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Frame Buffer - Fill All";
		};
	}
	const r2::iTest::DoFunc FrameBuffer_FillAll::GetDoFunction() const
	{
		GetInstance().mFrameBuffer.FillAll( '0' );

		const auto& fb = GetInstance().mFrameBuffer;

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



	FrameBuffer_Fill::FrameBuffer_Fill() : mFrameBuffer( 30, 20 ) {}

	const r2::iTest::TitleFunc FrameBuffer_Fill::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Frame Buffer - Fill";
		};
	}
	const r2::iTest::DoFunc FrameBuffer_Fill::GetDoFunction() const
	{
		GetInstance().mFrameBuffer.Fill( 0, 0, '0' );
		GetInstance().mFrameBuffer.Fill( GetInstance().mFrameBuffer.GetWidth() - 1u, 0, '0' );
		GetInstance().mFrameBuffer.Fill( GetInstance().mFrameBuffer.GetWidth() - 1u, GetInstance().mFrameBuffer.GetHeight() - 1u, '0' );
		GetInstance().mFrameBuffer.Fill( 0, GetInstance().mFrameBuffer.GetHeight() - 1u, '0' );

		const auto& fb = GetInstance().mFrameBuffer;

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



	FrameBuffer_DrawWithPosition::FrameBuffer_DrawWithPosition() : mFrameBuffer( 10, 10 ) {}

	const r2::iTest::TitleFunc FrameBuffer_DrawWithPosition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Frame Buffer - Draw With Position";
		};
	}
	const r2::iTest::DoFunc FrameBuffer_DrawWithPosition::GetDoFunction() const
	{
		GetInstance().mFrameBuffer.FillAll( '0' );

		const auto& fb = GetInstance().mFrameBuffer;

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



	FrameBuffer_InitWithChars::FrameBuffer_InitWithChars() : mFrameBuffer( "Init With Chars" ) {}

	const r2::iTest::TitleFunc FrameBuffer_InitWithChars::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Frame Buffer - Init With Chars";
		};
	}
	const r2::iTest::DoFunc FrameBuffer_InitWithChars::GetDoFunction() const
	{
		const auto& fb = GetInstance().mFrameBuffer;

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



	class TestRenderable : r2::Renderable
	{
		void Draw() override
		{

		}
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

		return [&rd]()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			rd.Draw();

			return r2::eTestResult::RunTest;
		};
	}
}