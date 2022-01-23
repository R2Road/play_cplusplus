#include "pch.h"
#include "r2algorithm_AStarPathBuilder.h"

#include <algorithm>

#include "r2/r2_Direction8.h"

namespace
{
	const int CELL_TYPE_ROAD = 0;
	const int CELL_TYPE_WALL = 1;

	class Node4AStar
	{
	public:
		enum class eStatus
		{
			None,
			Open,
			Close,
		};

		Node4AStar( const r2::Point current_point, const r2::Point previous_point, const r2::Point start_point, const r2::Point end_point ) :
			mStatus( eStatus::Open )
			, mCurrentPoint( current_point )
			, mPreviousPoint( previous_point )
			, mCost2Start( calculateCost( current_point, start_point ) )
			, mCost2End( calculateCost( current_point, end_point ) )
			, mTotalCost( mCost2Start + mCost2End )
		{}

		//
		// Getter
		//
		eStatus GetStatus() const { return mStatus; }
		r2::Point GetPoint() const { return mCurrentPoint; }
		r2::Point GetPreviousPoint() const { return mPreviousPoint; }
		int GetCost2Start() const { return mCost2Start; }
		int GetCost2End() const { return mCost2End; }
		int GetTotalCost() const { return mTotalCost; }

		void Clear()
		{
			mStatus = eStatus::None;
			mCost2Start = 0;
			mCost2End = 0;
			mTotalCost = 0;
		};
		bool IsValid() const
		{
			return eStatus::None != mStatus;
		}

		void Close()
		{
			mStatus = eStatus::Close;
		}

	private:
		int calculateCost( const r2::Point point_1, const r2::Point point_2 )
		{
			const auto distance_x = std::abs( point_1.x - point_2.x );
			const auto distance_y = std::abs( point_1.y - point_2.y );

			const auto gap = std::abs( distance_x - distance_y );

			const auto max_value = std::max( distance_x, distance_y );
			const auto diagonal = max_value - gap;

			return ( gap * 10 ) + ( diagonal * 14 );
		}

	private:
		eStatus mStatus;
		r2::Point mCurrentPoint;
		r2::Point mPreviousPoint;
		int mCost2Start;
		int mCost2End;
		int mTotalCost;
	};
}

namespace r2algorithm
{
	void AStarPathBuilder::Build( const r2::Point entry_point, const r2::Point exit_point, const r2::Grid<int>& grid, std::list<r2::Point>* out_result_path )
	{
		using Node4AStarContainerT = std::list<Node4AStar>;
		Node4AStarContainerT open_list;
		Node4AStarContainerT close_list;
		r2::Point current_point;

		//
		// Ready
		//
		{
			Node4AStar new_node{ entry_point, r2::Point{ -1, -1 }, entry_point, exit_point };
			open_list.push_back( new_node );
		}

		//
		// Make Cost Map
		//
		while( true )
		{
			if( open_list.empty() )
			{
				break;
			}

			// Select Min
			Node4AStarContainerT::iterator min_itr = open_list.begin();
			for( auto cur = ( ++open_list.begin() ), end = open_list.end(); end != cur; ++cur )
			{
				if( min_itr->GetCost2End() > cur->GetCost2End() )
				{
					min_itr = cur;
				}
			}

			// Move
			min_itr->Close();
			const Node4AStar current_node = *min_itr;
			close_list.push_back( current_node );
			open_list.erase( min_itr );

			// Found Exit
			if( exit_point == current_point )
			{
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::Point temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_node.GetPoint() + dir8.GetPoint();

				if( !grid.IsIn( temp_point.x, temp_point.y ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.x, temp_point.y ) )
				{
					continue;
				}

				if( open_list.end() != std::find_if( open_list.begin(), open_list.end(), [temp_point]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == temp_point;
				} ) )
				{
					continue;
				}

				if( close_list.end() != std::find_if( close_list.begin(), close_list.end(), [temp_point]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == temp_point;
				} ) )
				{
					continue;
				}

				Node4AStar new_node{ temp_point, current_node.GetPoint(), entry_point, exit_point };
				open_list.push_back( new_node );
			}
		}

		//
		// Save Path
		//
		{
			auto current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = exit_point]( const Node4AStar& other_node )->bool {
				return other_node.GetPoint() == target_point;
			} );
			out_result_path->push_back( current_itr->GetPoint() );

			while( -1 != current_itr->GetPreviousPoint().x )
			{
				out_result_path->push_back( current_itr->GetPreviousPoint() );

				current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = current_itr->GetPreviousPoint()]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == target_point;
				} );
			}
		}
	}
}
