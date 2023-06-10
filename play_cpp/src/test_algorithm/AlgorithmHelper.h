#pragma once

#include <functional>

#include "r2/r2_Grid.h"

class AlgorithmHelper
{
private:
	AlgorithmHelper() = delete;

public:
	template<typename CellT>
	static void PrintGrid( const r2::Grid<CellT>& grid )
	{
		int x = 0;
		for( const auto& i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				std::cout << r2tm::linefeed;
			}

			std::cout << i << ' ';

			++x;
		}
	}

	template<typename CellT>
	static void PrintGrid( const r2::Grid<CellT>& grid, std::function<char(CellT)> evaluator )
	{
		int x = 0;
		for( const auto& i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				std::cout << r2tm::linefeed;
			}

			std::cout << evaluator( i ) << ' ';

			++x;
		}
	}
};