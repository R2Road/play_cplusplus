#pragma once

#include <list>

#include "r2/r2_Point.h"
#include "r2/r2_Grid.h"

namespace r2algorithm
{
	class AStarPathBuilder
	{
	public:
		AStarPathBuilder() = delete;

		static void Build( const r2::Point entry_point, const r2::Point exit_point, const r2::Grid<int>& grid, std::list<r2::Point>* out_result_path );
	};
}