#include "r2algorithm_astar_PathBuilder.h"

#include "r2/r2_Direction8.h"

namespace
{
	const int CELL_TYPE_ROAD = 0;
	const int CELL_TYPE_WALL = 1;
}

namespace r2algorithm_astar
{
	void AStarPathBuilder::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::list<r2::PointInt>* out_result_path )
	{
		using Node4AStarContainerT = std::list<Node4AStar>;
		Node4AStarContainerT open_list;
		Node4AStarContainerT close_list;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			Node4AStar new_node{ entry_point, r2::PointInt{ -1, -1 }, entry_point, exit_point };
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
			if( exit_point == current_node.GetPoint() )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_node.GetPoint() + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
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
		if( bSuccess )
		{
			out_result_path->clear();

			auto current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = exit_point]( const Node4AStar& other_node )->bool {
				return other_node.GetPoint() == target_point;
			} );
			out_result_path->push_back( current_itr->GetPoint() );

			while( -1 != current_itr->GetPreviousPoint().GetX() )
			{
				out_result_path->push_back( current_itr->GetPreviousPoint() );

				current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = current_itr->GetPreviousPoint()]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == target_point;
				} );
			}
		}
	}

	void AStarPathBuilder_Use_STDListSplice::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::list<r2::PointInt>* out_result_path )
	{
		using Node4AStarContainerT = std::list<Node4AStar>;
		Node4AStarContainerT open_list;
		Node4AStarContainerT close_list;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			Node4AStar new_node{ entry_point, r2::PointInt{ -1, -1 }, entry_point, exit_point };
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
			close_list.splice( close_list.begin(), open_list, min_itr );
			const Node4AStar current_node = *min_itr;

			// Found Exit
			if( exit_point == current_node.GetPoint() )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_node.GetPoint() + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
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
		if( bSuccess )
		{
			out_result_path->clear();

			auto current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = exit_point]( const Node4AStar& other_node )->bool {
				return other_node.GetPoint() == target_point;
			} );
			out_result_path->push_back( current_itr->GetPoint() );

			while( -1 != current_itr->GetPreviousPoint().GetX() )
			{
				out_result_path->push_back( current_itr->GetPreviousPoint() );

				current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = current_itr->GetPreviousPoint()]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == target_point;
				} );
			}
		}
	}



	void AStarPathBuilder_Use_STDListSplice_STDVectorResultPath::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path )
	{
		using Node4AStarContainerT = std::list<Node4AStar>;
		Node4AStarContainerT open_list;
		Node4AStarContainerT close_list;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			Node4AStar new_node{ entry_point, r2::PointInt{ -1, -1 }, entry_point, exit_point };
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
			close_list.splice( close_list.begin(), open_list, min_itr );
			const Node4AStar current_node = *min_itr;

			// Found Exit
			if( exit_point == current_node.GetPoint() )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_node.GetPoint() + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
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
		if( bSuccess )
		{
			out_result_path->clear();

			auto current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = exit_point]( const Node4AStar& other_node )->bool {
				return other_node.GetPoint() == target_point;
			} );
			out_result_path->push_back( current_itr->GetPoint() );

			while( -1 != current_itr->GetPreviousPoint().GetX() )
			{
				out_result_path->push_back( current_itr->GetPreviousPoint() );

				current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = current_itr->GetPreviousPoint()]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == target_point;
				} );
			}
		}
	}



	void AStarPathBuilder_Use_STDListSplice_DecreaseCloseList_STDVectorResultPath::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path )
	{
		using Node4AStarContainerT = std::list<Node4AStar>;
		Node4AStarContainerT open_list;
		Node4AStarContainerT close_list;
		Node4AStarContainerT garbage_list;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			Node4AStar new_node{ entry_point, r2::PointInt{ -1, -1 }, entry_point, exit_point };
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
			close_list.splice( close_list.begin(), open_list, min_itr );
			const Node4AStar current_node = *min_itr;

			// Found Exit
			if( exit_point == current_node.GetPoint() )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_node.GetPoint() + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
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
		if( bSuccess )
		{
			out_result_path->clear();

			auto current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = exit_point]( const Node4AStar& other_node )->bool {
				return other_node.GetPoint() == target_point;
			} );
			out_result_path->push_back( current_itr->GetPoint() );
			garbage_list.splice( garbage_list.begin(), close_list, current_itr );

			while( -1 != current_itr->GetPreviousPoint().GetX() )
			{
				out_result_path->push_back( current_itr->GetPreviousPoint() );

				current_itr = std::find_if( close_list.begin(), close_list.end(), [target_point = current_itr->GetPreviousPoint()]( const Node4AStar& other_node )->bool {
					return other_node.GetPoint() == target_point;
				} );
			}
		}
	}



	void AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath::Clear()
	{
		for( auto& c : cost_map )
		{
			c.Clear();
		}
	}
	void AStarPathBuilder_Use_CostMap_STDListSplice_STDVectorResultPath::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path )
	{
		using TargetContainerT = std::list<r2::PointInt>;
		TargetContainerT open_list;
		TargetContainerT close_list;
		r2::PointInt current_point;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			cost_map.Set( entry_point.GetX(), entry_point.GetY(), { entry_point, r2::PointInt{ -1, -1 }, entry_point, exit_point } );
			open_list.push_back( entry_point );
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
			TargetContainerT::iterator min_itr = open_list.begin();
			for( auto cur_itr = ( ++open_list.begin() ), end = open_list.end(); end != cur_itr; ++cur_itr )
			{
				if( cost_map.Get( min_itr->GetX(), min_itr->GetY() ).GetCost2End() > cost_map.Get( cur_itr->GetX(), cur_itr->GetY() ).GetCost2End() )
				{
					min_itr = cur_itr;
				}
			}

			// Move
			cost_map.Get( min_itr->GetX(), min_itr->GetY() ).Close();
			close_list.splice( close_list.begin(), open_list, min_itr );
			current_point = *min_itr;

			// Found Exit
			if( exit_point == current_point )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_point + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( Node4AStar::eStatus::None != cost_map.Get( temp_point.GetX(), temp_point.GetY() ).GetStatus() )
				{
					continue;
				}

				cost_map.Get( temp_point.GetX(), temp_point.GetY() ) = Node4AStar{ temp_point, current_point, entry_point, exit_point };
				open_list.push_back( temp_point );
			}
		}

		//
		// Save Path
		//
		if( bSuccess )
		{
			out_result_path->clear();

			auto path_point = exit_point;
			while( -1 != path_point.GetX() )
			{
				out_result_path->push_back( path_point );

				path_point = cost_map.Get( path_point.GetX(), path_point.GetY() ).GetPreviousPoint();
			}
		}
	}



	void AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath::Clear()
	{
		for( auto& c : cost_map )
		{
			c.Clear();
		}
	}
	void AStarPathBuilder_Use_TinyCostMap_STDListSplice_STDVectorResultPath::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path )
	{
		using TargetContainerT = std::list<r2::PointInt>;
		TargetContainerT open_list;
		TargetContainerT close_list;
		r2::PointInt current_point;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			cost_map.Set( entry_point.GetX(), entry_point.GetY(), { entry_point, r2::PointInt{ -1, -1 }, exit_point } );
			open_list.push_back( entry_point );
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
			TargetContainerT::iterator min_itr = open_list.begin();
			for( auto cur_itr = ( ++open_list.begin() ), end = open_list.end(); end != cur_itr; ++cur_itr )
			{
				if( cost_map.Get( min_itr->GetX(), min_itr->GetY() ).GetCost2End() > cost_map.Get( cur_itr->GetX(), cur_itr->GetY() ).GetCost2End() )
				{
					min_itr = cur_itr;
				}
			}

			// Move
			cost_map.Get( min_itr->GetX(), min_itr->GetY() ).Close();
			close_list.splice( close_list.begin(), open_list, min_itr );
			current_point = *min_itr;

			// Found Exit
			if( exit_point == current_point )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_point + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( TinyNode4AStar::eStatus::None != cost_map.Get( temp_point.GetX(), temp_point.GetY() ).GetStatus() )
				{
					continue;
				}

				cost_map.Get( temp_point.GetX(), temp_point.GetY() ) = TinyNode4AStar{ temp_point, current_point, exit_point };
				open_list.push_back( temp_point );
			}
		}

		//
		// Save Path
		//
		if( bSuccess )
		{
			out_result_path->clear();

			auto path_point = exit_point;
			while( -1 != path_point.GetX() )
			{
				out_result_path->push_back( path_point );

				path_point = cost_map.Get( path_point.GetX(), path_point.GetY() ).GetPreviousPoint();
			}
		}
	}



	void AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::Clear()
	{
		for( auto& c : cost_map )
		{
			c.Clear();
		}

		open_list.Clear();
		close_list.Clear();
	}
	void AStarPathBuilder_Use_ArrayBasedList_TinyCostMap_STDVectorResultPath::Build( const r2::PointInt entry_point, const r2::PointInt exit_point, const WorldMapT& grid, std::vector<r2::PointInt>* out_result_path )
	{
		r2::PointInt current_point;
		bool bSuccess = false;

		//
		// Ready
		//
		{
			cost_map.Set( entry_point.GetX(), entry_point.GetY(), { entry_point, r2::PointInt{ -1, -1 }, exit_point } );
			open_list.PushBack( entry_point );
		}

		//
		// Make Cost Map
		//
		while( true )
		{
			if( open_list.Empty() )
			{
				break;
			}

			// Select Min
			TargetContainerT::IteratorT min_itr = open_list.begin();
			for( auto cur_itr = ( ++open_list.begin() ), end = open_list.end(); end != cur_itr; ++cur_itr )
			{
				if( cost_map.Get( ( *min_itr ).GetX(), ( *min_itr ).GetY() ).GetCost2End() > cost_map.Get( ( *cur_itr ).GetX(), ( *cur_itr ).GetY() ).GetCost2End() )
				{
					min_itr = cur_itr;
				}
			}

			// Move
			cost_map.Get( ( *min_itr ).GetX(), ( *min_itr ).GetY() ).Close();
			current_point = *min_itr;
			open_list.Erase( min_itr );
			close_list.PushBack( current_point );

			// Found Exit
			if( exit_point == current_point )
			{
				bSuccess = true;
				break;
			}

			// Collect Open List
			r2::Direction8 dir8;
			r2::PointInt temp_point;
			for( int i = 0; 8 > i; ++i, dir8.Rotate( true, 1 ) )
			{
				temp_point = current_point + dir8.GetPoint();

				if( !grid.IsIn( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( CELL_TYPE_ROAD != grid.Get( temp_point.GetX(), temp_point.GetY() ) )
				{
					continue;
				}

				if( TinyNode4AStar::eStatus::None != cost_map.Get( temp_point.GetX(), temp_point.GetY() ).GetStatus() )
				{
					continue;
				}

				cost_map.Get( temp_point.GetX(), temp_point.GetY() ) = TinyNode4AStar{ temp_point, current_point, exit_point };
				open_list.PushBack( temp_point );
			}
		}

		//
		// Save Path
		//
		if( bSuccess )
		{
			out_result_path->clear();

			auto path_point = exit_point;
			while( -1 != path_point.GetX() )
			{
				out_result_path->push_back( path_point );

				path_point = cost_map.Get( path_point.GetX(), path_point.GetY() ).GetPreviousPoint();
			}
		}
	}
}
