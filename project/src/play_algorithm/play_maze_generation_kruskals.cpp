#include "play_maze_generation_kruskals.hpp"

#include <algorithm>
#include <conio.h>
#include <iomanip>
#include <random>
#include <vector>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_windows_utility.hpp"

#include "r2/r2_assert.hpp"
#include "r2/r2_direction4_bitwise.hpp"
#include "r2/r2_grid_based_on_vector.hpp"
#include "r2/r2_point_int.hpp"
#include "r2/r2ext_direction4_bitwise_with_point.hpp"

namespace play_maze_generation_kruskals
{
	class Node
	{
	public:
		Node() : mParentNode( nullptr ), mIndex( 0 )
		{}

		Node* GetRoot()
		{
			return mParentNode ? mParentNode->GetRoot() : this;
		}
		const Node* GetRoot() const
		{
			return mParentNode ? mParentNode->GetRoot() : this;
		}

		void SetParentNode( Node* const other_node )
		{
			mParentNode = other_node;
		}

		void Connect( Node* const other_node )
		{
			R2ASSERT( nullptr != other_node, "Node::Connect : parent_node is nullptr" );

			other_node->GetRoot()->SetParentNode( this );
		}

		bool IsConnected( Node* other_node )
		{
			return GetRoot() == other_node->GetRoot();
		}

		int GetIndex() const
		{
			return mIndex;
		}
		void SetIndex( const int index )
		{
			mIndex = index;
		}

	private:
		Node* mParentNode;
		int mIndex;
	};

	void PrintGrid( const r2::GridBasedOnVector<std::size_t, int>& grid, const r2::GridBasedOnVector<std::size_t, Node>& sets )
	{
		const auto pivot_point = r2tm::WindowsUtility::GetCursorPoint();

		for( int y = 0; grid.GetHeight() > y; ++y )
		{
			for( int x = 0; grid.GetHeight() > x; ++x )
			{
				const r2tm::WindowsUtility::CursorPoint my_pivot_point(
					pivot_point.x + static_cast<short>( x * 5 ) + 2
					, pivot_point.y + static_cast<short>( y * 3 ) + 1
				);
				r2tm::WindowsUtility::MoveCursorPoint( my_pivot_point.x - 1, my_pivot_point.y );
				std::cout << "@@@";

				r2tm::WindowsUtility::MoveCursorPoint( my_pivot_point.x - 1, my_pivot_point.y );
				std::cout << sets.Get( x, y ).GetRoot()->GetIndex();

				r2::Direction4Bitwise dir4( r2::Direction4Bitwise::eState::Up );
				for( int i = 0; 4 > i; ++i, dir4.Rotate( true ) )
				{
					if( grid.Get( x, y ) & static_cast<int>( dir4.GetState() ) )
					{
						r2tm::WindowsUtility::CursorPoint current_point;

						if( ( static_cast<int>( r2::Direction4Bitwise::eState::Right ) | static_cast<int>( r2::Direction4Bitwise::eState::Left ) ) & static_cast<int>( dir4.GetState() ) )
						{
							current_point = r2tm::WindowsUtility::CursorPoint( my_pivot_point.x + static_cast<short>( dir4.GetX() * 2 ), my_pivot_point.y + static_cast<short>( dir4.GetY() ) );
						}
						else
						{
							current_point = r2tm::WindowsUtility::CursorPoint( my_pivot_point.x + static_cast<short>( dir4.GetX() ), my_pivot_point.y + static_cast<short>( dir4.GetY() ) );
						}

						r2tm::WindowsUtility::MoveCursorPoint( current_point );
						r2tm::WindowsUtility::FillColor( current_point, r2tm::WindowsUtility::eColor::BG_Aqua );
					}
				}
			}
		}
	}



	r2tm::TitleFunctionT ViewTest::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Kruskals : ViewTest";
		};
	}
	r2tm::DoFunctionT ViewTest::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			using Grid = r2::GridBasedOnVector<std::size_t, int>;
			using Sets = r2::GridBasedOnVector<std::size_t, Node>;

			DECL_MAIN( Grid grid( 2, 2, static_cast<int>( r2::Direction4Bitwise::eState::NONE ) ) );
			PROC_MAIN( grid.Set( 1, 0, static_cast<int>( r2::Direction4Bitwise::eState::Up ) | static_cast<int>( r2::Direction4Bitwise::eState::Down ) ) );
			PROC_MAIN( grid.Set( 1, 1, static_cast<int>( r2::Direction4Bitwise::eState::Left ) | static_cast<int>( r2::Direction4Bitwise::eState::Right ) ) );
			PROC_MAIN( grid.Set( 0, 1, static_cast<int>( r2::Direction4Bitwise::eState::Left ) | static_cast<int>( r2::Direction4Bitwise::eState::Right ) | static_cast<int>( r2::Direction4Bitwise::eState::Up ) ) );

			DECL_MAIN( Sets sets( 2, 2, Node{} ) );

			LS();

			{
				PrintGrid( grid, sets );
				std::cout << r2tm::linefeed2;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Kruskals : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			std::cout << r2tm::tab << "# REF" << r2tm::linefeed2;
			std::cout << r2tm::tab << "1. https://en.wikipedia.org/wiki/Kruskal's_algorithm" << r2tm::linefeed;
			std::cout << r2tm::tab << "2. http://weblog.jamisbuck.org/2011/1/3/maze-generation-kruskal-s-algorithm" << r2tm::linefeed;
			std::cout << r2tm::tab << "3. https://gmlwjd9405.github.io/2018/08/29/algorithm-kruskal-mst.html" << r2tm::linefeed;
			std::cout << r2tm::tab << "4. https://gmlwjd9405.github.io/2018/08/31/algorithm-union-find.html" << r2tm::linefeed;

			std::cout << r2tm::linefeed2;

			std::cout << r2tm::tab << "# 이해를 위해 반드시 알아둬야 할 것들" << r2tm::linefeed2;
			std::cout << r2tm::tab << "1. Kruskal's Algorithm" << r2tm::linefeed;
			std::cout << r2tm::tab << "2. Union Find Algorithm : 연결 과정에서 사용" << r2tm::linefeed;

			LS();

			using Grid = r2::GridBasedOnVector<std::size_t, int>;
			using Sets = r2::GridBasedOnVector<std::size_t, Node>;

			DECL_MAIN( const int width = 3 );
			DECL_MAIN( const int height = 3 );
			DECL_MAIN( Grid grid( width, height, static_cast<int>( r2::Direction4Bitwise::eState::NONE ) ) );
			DECL_MAIN( Sets sets( width, height, Node{} ) );
			{
				int temp_index = 0;
				for( auto& n : sets ) { n.SetIndex( temp_index ); ++temp_index; }
			}

			struct Edge
			{
				r2::PointInt point;
				r2::Direction4Bitwise::eState dir;
			};
			DECL_MAIN( std::vector<Edge> edges );

			LS();

			const auto pivot_point = r2tm::WindowsUtility::GetCursorPoint();

			{
				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_point );
				std::cout << r2tm::tab << "+ Grid" << r2tm::linefeed2;

				PrintGrid( grid, sets );
				std::cout << r2tm::linefeed2;
				_getch();
			}

			LS();

			{
				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_point );
				std::cout << r2tm::tab << "+ Make Edges" << r2tm::linefeed2;

				edges.reserve( grid.GetSize() * 2u );
				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetHeight() > x; ++x )
					{
						if( x > 0 )
						{
							edges.push_back( { r2::PointInt{ x, y }, r2::Direction4Bitwise::eState::Left } );
						}
						if( y > 0 )
						{
							edges.push_back( { r2::PointInt{ x, y }, r2::Direction4Bitwise::eState::Down } );
						}
					}
				}

				static std::random_device random_device;
				static std::mt19937 random_engine( random_device() );
				std::shuffle( edges.begin(), edges.end(), random_engine );
				_getch();
			}

			LS();

			{
				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_point );
				std::cout << r2tm::tab << "+ Connect" << r2tm::linefeed2;

				const auto pivot_point_4_connect = r2tm::WindowsUtility::GetCursorPoint();

				r2::PointInt next_point;
				r2::Direction4Bitwise current_dir( r2::Direction4Bitwise::eState::Up );
				for( const auto& e : edges )
				{
					r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_point_4_connect );

					next_point = e.point + r2::dir2point<int>( e.dir );

					auto& current_node = sets.Get( e.point.GetX(), e.point.GetY() );
					auto& next_node = sets.Get( next_point.GetX(), next_point.GetY() );
					if( current_node.IsConnected( &next_node ) )
					{
						continue;
					}

					//
					// Connect
					//
					current_node.Connect( &next_node );
					

					//
					// Direction
					//
					grid.Get( e.point.GetX(), e.point.GetY() ) |= static_cast<int>( e.dir );

					//
					//  Reverse Direction
					//
					current_dir.SetState( e.dir );
					current_dir.Rotate( true );
					current_dir.Rotate( true );
					grid.Get( next_point.GetX(), next_point.GetY() ) |= static_cast<int>( current_dir.GetState() );

					PrintGrid( grid, sets );
					std::cout << r2tm::linefeed2;
					if( 27 == _getch() )
					{
						break;
					}
				}

				r2tm::WindowsUtility::MoveCursorPointWithClearBuffer( pivot_point_4_connect );
				PrintGrid( grid, sets );
				std::cout << r2tm::linefeed2;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}