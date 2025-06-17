#pragma once

#include <functional>

#include "r2/r2_GridBasedOnVector.h"

#include "r2tm/r2tm_ostream.h"

class AlgorithmHelper
{
private:
	AlgorithmHelper() = delete;

public:
	template<typename CellT>
	static void PrintGrid( const r2::GridBasedOnVector<std::size_t, CellT>& grid )
	{
		int x = 0;
		for( const auto& i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				LF();
			}

			std::cout << i << ' ';

			++x;
		}
	}

	template<typename CellT>
	static void PrintGrid( const r2::GridBasedOnVector<std::size_t, CellT>& grid, std::function<char(CellT)> evaluator )
	{
		int x = 0;
		for( const auto& i : grid )
		{
			if( grid.GetWidth() <= x )
			{
				x = 0;
				LF();
			}

			std::cout << evaluator( i ) << ' ';

			++x;
		}
	}
};