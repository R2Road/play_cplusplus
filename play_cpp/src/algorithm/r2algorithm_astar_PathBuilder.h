#pragma once

#include <list>
#include <vector>

#include "r2algorithm_astar_Constant.h"
#include "r2/r2_PointInt.h"
#include "r2/r2_Grid.h"
#include "r2/r2_ListBasedOnArray.h"

namespace r2algorithm_astar
{
	class Node4AStar
	{
	public:
		enum class eStatus
		{
			None,
			Open,
			Close,
		};

		Node4AStar() :
			mStatus( eStatus::None )
			, mCurrentPoint()
			, mPreviousPoint()
			, mCost2Start( calculateCost( {}, {} ) )
			, mCost2End( calculateCost( {}, {} ) )
			, mTotalCost( mCost2Start + mCost2End )
		{}

		Node4AStar( const r2::PointInt current_point, const r2::PointInt previous_point, const r2::PointInt start_point, const r2::PointInt end_point ) :
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
		r2::PointInt GetPoint() const { return mCurrentPoint; }
		r2::PointInt GetPreviousPoint() const { return mPreviousPoint; }
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
		int calculateCost( const r2::PointInt point_1, const r2::PointInt point_2 )
		{
			const auto distance_x = std::abs( point_1.GetX() - point_2.GetX() );
			const auto distance_y = std::abs( point_1.GetY() - point_2.GetY() );

			const auto gap = std::abs( distance_x - distance_y );

			const auto max_value = ( distance_x > distance_y ? distance_x : distance_y );
			const auto diagonal = max_value - gap;

			return ( gap * 10 ) + ( diagonal * 14 );
		}

	private:
		eStatus mStatus;
		r2::PointInt mCurrentPoint;
		r2::PointInt mPreviousPoint;
		int mCost2Start;
		int mCost2End;
		int mTotalCost;
	};

	class TinyNode4AStar
	{
	public:
		enum class eStatus : char16_t
		{
			None,
			Open,
			Close,
		};

		TinyNode4AStar() :
			mStatus( eStatus::None )
			, mCost2End( calculateCost( {}, {} ) )
			, mPreviousPoint()
		{}

		TinyNode4AStar( const r2::PointInt current_point, const r2::PointInt previous_point, const r2::PointInt end_point ) :
			mStatus( eStatus::Open )
			, mCost2End( calculateCost( current_point, end_point ) )
			, mPreviousPoint( previous_point )
		{}

		//
		// Getter
		//
		eStatus GetStatus() const { return mStatus; }
		r2::PointInt GetPreviousPoint() const { return mPreviousPoint; }
		int GetCost2End() const { return mCost2End; }

		void Clear()
		{
			mStatus = eStatus::None;
			mCost2End = 0;
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
		int16_t calculateCost( const r2::PointInt point_1, const r2::PointInt point_2 )
		{
			const auto distance_x = std::abs( point_1.GetX() - point_2.GetX() );
			const auto distance_y = std::abs( point_1.GetY() - point_2.GetY() );

			const auto gap = std::abs( distance_x - distance_y );

			const auto max_value = ( distance_x > distance_y ? distance_x : distance_y );
			const auto diagonal = max_value - gap;

			return static_cast<int16_t>( ( gap * 10 ) + ( diagonal * 14 ) );
		}

	private:
		eStatus mStatus;
		int16_t mCost2End;
		r2::PointInt mPreviousPoint;
	};

	class AStarPathBuilder
	{
	public:
		AStarPathBuilder() = delete;

		static void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::list<r2::PointInt>* out_result_path );
	};

	class AStarPathBuilder_Use_STDListSplice
	{
	public:
		AStarPathBuilder_Use_STDListSplice() = delete;

		static void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::list<r2::PointInt>* out_result_path );
	};

	class AStarPathBuilder_Use_STDListSplice_STDVectorResultPath
	{
	public:
		AStarPathBuilder_Use_STDListSplice_STDVectorResultPath() = delete;

		static void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path );
	};
	class AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath
	{
	public:
		AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath() = delete;

		static void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path );
	};

	class AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath
	{
	public:
		AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath( const std::size_t width, const std::size_t height ) : cost_map( width, height, Node4AStar() )
		{}

		void Clear();
		void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path );

		r2::Grid<Node4AStar> cost_map;
	};
	class AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath
	{
	public:
		AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath( const std::size_t width, const std::size_t height ) : cost_map( width, height, TinyNode4AStar() )
		{}

		void Clear();
		void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path );

		r2::Grid<TinyNode4AStar> cost_map;
	};

	class AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath
	{
	public:
		AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath( const std::size_t width, const std::size_t height ) : cost_map( width, height, TinyNode4AStar() )
		{}

		void Clear();
		void Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path );

		r2::Grid<TinyNode4AStar> cost_map;

		using TargetContainerT = r2::ListBasedOnArray<r2::PointInt, WORLD_MAP_WIDTH * WORLD_MAP_HEIGHT >;
		TargetContainerT open_list;
		TargetContainerT close_list;
	};
}
