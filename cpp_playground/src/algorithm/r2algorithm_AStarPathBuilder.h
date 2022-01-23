#pragma once

#include <list>
#include <vector>

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

	class AStarPathBuilder2
	{
	public:
		AStarPathBuilder2() = delete;

		static void Build( const r2::Point entry_point, const r2::Point exit_point, const r2::Grid<int>& grid, std::list<r2::Point>* out_result_path );
	};

	class AStarPathBuilder2_UseSTDVectorResultPath
	{
	public:
		AStarPathBuilder2_UseSTDVectorResultPath() = delete;

		static void Build( const r2::Point entry_point, const r2::Point exit_point, const r2::Grid<int>& grid, std::vector<r2::Point>* out_result_path );
	};
}
