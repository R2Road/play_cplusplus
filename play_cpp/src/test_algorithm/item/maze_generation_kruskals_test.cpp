#include "maze_generation_kruskals_test.h"

#include <algorithm>
#include <conio.h>
#include <iomanip>
#include <random>
#include <vector>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_WindowUtility.h"

#include "r2/r2_Assert.h"
#include "r2/r2_Direction4.h"
#include "r2/r2_Grid.h"

namespace maze_generation_kruskals_test
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

	void PrintGrid( const r2::Grid<int>& grid, const r2::Grid<Node>& sets )
	{
		const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

		for( int y = 0; grid.GetHeight() > y; ++y )
		{
			for( int x = 0; grid.GetHeight() > x; ++x )
			{
				const r2tm::WindowUtility::CursorPoint my_pivot_point = {
					pivot_point.x + static_cast<short>( x * 5 ) + 2
					, pivot_point.y + static_cast<short>( y * 3 ) + 1
				};
				r2tm::WindowUtility::MoveCursorPoint( { my_pivot_point.x - 1, my_pivot_point.y } );
				std::cout << "@@@";

				r2tm::WindowUtility::MoveCursorPoint( { my_pivot_point.x - 1, my_pivot_point.y } );
				std::cout << sets.Get( x, y ).GetRoot()->GetIndex();

				r2::Direction4 dir4;
				for( int i = 0; 4 > i; ++i, dir4.Rotate( true ) )
				{
					if( grid.Get( x, y ) & dir4.GetState() )
					{
						r2tm::WindowUtility::CursorPoint current_point;

						if( ( r2::Direction4::eState::Right | r2::Direction4::eState::Left ) & dir4.GetState() )
						{
							current_point = { my_pivot_point.x + static_cast<short>( dir4.GetPoint().GetX() * 2 ), my_pivot_point.y + static_cast<short>( dir4.GetPoint().GetY() ) };
						}
						else
						{
							current_point = { my_pivot_point.x + static_cast<short>( dir4.GetPoint().GetX() ), my_pivot_point.y + static_cast<short>( dir4.GetPoint().GetY() ) };
						}

						r2tm::WindowUtility::MoveCursorPoint( current_point );
						r2tm::WindowUtility::FillColor( current_point, r2tm::WindowUtility::eColor::BG_Aqua );
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

			DECLARATION_MAIN( r2::Grid<int> grid( 2, 2, r2::Direction4::eState::None ) );
			PROCESS_MAIN( grid.Set( 1, 0, r2::Direction4::eState::Up | r2::Direction4::eState::Down ) );
			PROCESS_MAIN( grid.Set( 1, 1, r2::Direction4::eState::Left | r2::Direction4::eState::Right ) );
			PROCESS_MAIN( grid.Set( 0, 1, r2::Direction4::eState::Left | r2::Direction4::eState::Right | r2::Direction4::eState::Up ) );

			DECLARATION_MAIN( r2::Grid<Node> sets( 2, 2, Node{} ) );

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

			DECLARATION_MAIN( const int width = 3 );
			DECLARATION_MAIN( const int height = 3 );
			DECLARATION_MAIN( r2::Grid<int> grid( width, height, r2::Direction4::eState::None ) );
			DECLARATION_MAIN( r2::Grid<Node> sets( width, height, Node{} ) );
			{
				int temp_index = 0;
				for( auto& n : sets ) { n.SetIndex( temp_index ); ++temp_index; }
			}

			struct Edge
			{
				r2::PointInt point;
				r2::Direction4::eState dir;
			};
			DECLARATION_MAIN( std::vector<Edge> edges );

			LS();

			const auto pivot_point = r2tm::WindowUtility::GetCursorPoint();

			{
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );
				std::cout << r2tm::tab << "+ Grid" << r2tm::linefeed2;

				PrintGrid( grid, sets );
				std::cout << r2tm::linefeed2;
				_getch();
			}

			LS();

			{
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );
				std::cout << r2tm::tab << "+ Make Edges" << r2tm::linefeed2;

				edges.reserve( grid.GetSize() * 2u );
				for( int y = 0; grid.GetHeight() > y; ++y )
				{
					for( int x = 0; grid.GetHeight() > x; ++x )
					{
						if( x > 0 )
						{
							edges.push_back( { { x, y }, r2::Direction4::eState::Left } );
						}
						if( y > 0 )
						{
							edges.push_back( { { x, y }, r2::Direction4::eState::Down } );
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
				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point );
				std::cout << r2tm::tab << "+ Connect" << r2tm::linefeed2;

				const auto pivot_point_4_connect = r2tm::WindowUtility::GetCursorPoint();

				r2::PointInt next_point;
				r2::Direction4 current_dir;
				for( const auto& e : edges )
				{
					r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point_4_connect );

					next_point = e.point + r2::Direction4( e.dir ).GetPoint();

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
					grid.Get( e.point.GetX(), e.point.GetY() ) |= e.dir;

					//
					//  Reverse Direction
					//
					current_dir.SetState( e.dir );
					current_dir.Rotate( true );
					current_dir.Rotate( true );
					grid.Get( next_point.GetX(), next_point.GetY() ) |= current_dir.GetState();

					PrintGrid( grid, sets );
					std::cout << r2tm::linefeed2;
					if( 27 == _getch() )
					{
						break;
					}
				}

				r2tm::WindowUtility::MoveCursorPointWithClearBuffer( pivot_point_4_connect );
				PrintGrid( grid, sets );
				std::cout << r2tm::linefeed2;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}