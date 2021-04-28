#pragma once

#include "r2_iTest.h"
#include "r2_Singleton.h"

#include "r2_FrameBuffer.h"

namespace r2_game
{
	class PathFinder : public r2::iTest, public r2::SingleTon<PathFinder>
	{
	public:
		PathFinder();

	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;

	private:
		r2::FrameBuffer mFrameBuffer;
	};
}