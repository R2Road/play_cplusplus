#pragma once

#include <vector>

#include "r2_GridIndexConverter.h"

namespace r2
{
	template<typename T>
	class Grid
	{
	public:
		using CellT = T;
		using ContainerT = std::vector<CellT>;
		using IteratorT = typename ContainerT::iterator;
		using ConstIteratorT = typename ContainerT::const_iterator;

		Grid() :
			mWidth( 1 )
			, mHeight( 1 )
			, mContainer( 1 * 1 )
			, mIndexConverter( 1, 1 )
		{}

		Grid( const std::size_t new_width, const std::size_t new_height, const CellT value ) :
			mWidth( new_width )
			, mHeight( new_height )
			, mContainer( new_width * new_height, value )
			, mIndexConverter( static_cast<int>( new_width ), static_cast<int>( new_height ) )
		{}

		Grid( const std::size_t new_width, const std::size_t new_height, const std::initializer_list<CellT> data ) :
			mWidth( new_width )
			, mHeight( new_height )
			, mContainer( new_width * new_height )
			, mIndexConverter( static_cast<int>( new_width ), static_cast<int>( new_height ) )
		{
			memcpy_s(
				&mContainer[0], mContainer.size() * sizeof( CellT )
				, &( *data.begin() ), ( data.size() > mContainer.size() ? data.size() * sizeof( CellT ) : mContainer.size() * sizeof( CellT ) )
			);
		}

	public:
		std::size_t GetWidth() const { return mWidth; }
		std::size_t GetHeight() const { return mHeight; }
		bool IsIn( const std::size_t x, const std::size_t y ) const
		{
			return ( GetWidth() > x && GetHeight() > y );
		}

		//
		// Iteration
		//
		ConstIteratorT begin() const { return mContainer.begin(); }
		ConstIteratorT end() const { return mContainer.end(); }
		IteratorT begin() { return mContainer.begin(); }
		IteratorT end() { return mContainer.end(); }

		void Reset( const std::size_t new_width, const std::size_t new_height )
		{
			mWidth = new_width;
			mHeight = new_height;

			mContainer.clear();
			mContainer.resize( mWidth *  mHeight );

			mIndexConverter = r2::GridIndexConverter( static_cast<int>( mWidth ), static_cast<int>( mHeight ) );
		}
		void Reset( const std::size_t new_width, const std::size_t new_height, const std::initializer_list<CellT> data )
		{
			Reset( new_width, new_height );
			memcpy_s(
				&mContainer[0], mContainer.size() * sizeof( CellT )
				, &( *data.begin() ), min( data.size() * sizeof( CellT ), mContainer.size() * sizeof( CellT ) )
			);
		}

		//
		// Getter
		//
		CellT& Get( const std::size_t linear_idx )
		{
#if defined( DEBUG ) || defined( _DEBUG )
			if( linear_idx >= static_cast<int>( mContainer.size() ) )
			{
				static CellT dummy;
				return dummy;
			}
#endif

			return mContainer[linear_idx];
		}
		CellT& Get( const std::size_t x, const std::size_t y )
		{
			return Get( mIndexConverter.To_Linear( static_cast<int>( x ), static_cast<int>( y ) ) );
		}
		const CellT& Get( const std::size_t linear_idx ) const
		{
#if defined( DEBUG ) || defined( _DEBUG )
			if( linear_idx >= static_cast<int>( mContainer.size() ) )
			{
				static CellT dummy;
				return dummy;
			}
#endif

			return mContainer[linear_idx];
		}
		const CellT& Get( const std::size_t x, const std::size_t y ) const
		{
			return Get( mIndexConverter.To_Linear( static_cast<int>( x ), static_cast<int>( y ) ) );
		}

		//
		// Setter
		//
		void Set( const std::size_t linear_idx, const CellT& new_value )
		{
#if defined( DEBUG ) || defined( _DEBUG )
			if( linear_idx >= static_cast<int>( mContainer.size() ) )
			{
				return;
			}
#endif

			mContainer[linear_idx] = new_value;
		}
		void Set( const std::size_t x, const std::size_t y, const CellT& new_value )
		{
			Set(
				mIndexConverter.To_Linear( static_cast<int>( x ), static_cast<int>( y ) )
				, new_value
			);
		}

	private:
		std::size_t mWidth;
		std::size_t mHeight;
		ContainerT mContainer;

		r2::GridIndexConverter mIndexConverter;
	};
}