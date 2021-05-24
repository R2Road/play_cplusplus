#pragma once

#include <string_view>
#include <vector>

#include "r2_GridIndexConverter.h"
#include "r2_RectInt.h"

namespace r2
{
	class VisibleResource
	{
	public:
		using ValueT = char;
		using ContainerT = std::vector<ValueT>;
		using ConstIteratorT = typename ContainerT::const_iterator;

		VisibleResource( const std::string_view str );
		VisibleResource( const std::size_t width, const std::string_view str );
		VisibleResource( const std::size_t width, const std::size_t height );

	public:
		//
		// Iteration
		//
		ConstIteratorT begin() const { return mChars.begin(); }
		ConstIteratorT end() const { return mChars.end(); }

		//
		// Getter
		//
		int GetWidth() const { return mGridIndexConverter.GetWidth(); }
		int GetHeight() const { return mGridIndexConverter.GetHeight(); }
		const r2::RectInt& GetVisibleRect() const { return mVisibleRect; }
		const ContainerT& GetContainer() const { return mChars; }
		ValueT Get( const std::size_t x, const std::size_t y ) const;

		//
		//
		//
		void FillAll( const char c );
		void Fill( std::size_t x, std::size_t y, const char c );
		void SetVisibleRect( const r2::RectInt& rect ) { mVisibleRect = rect; }

	private:
		const GridIndexConverter mGridIndexConverter;
		ContainerT mChars;
		r2::RectInt mVisibleRect;
	};
}