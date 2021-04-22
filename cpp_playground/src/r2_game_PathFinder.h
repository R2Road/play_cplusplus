#pragma once

#include "r2_iNode.h"
#include "r2_Singleton.h"

namespace r2_game
{
	class PathFinder : public r2::iNode, public r2::SingleTon<PathFinder>
	{
	public:
		const TitleFunc GetTitleFunction() const override;
		const DoFunc GetDoFunction() const override;
	};
}