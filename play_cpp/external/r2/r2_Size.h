//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.06.15 PM.03.48
// # Version			: 1.0.0
//

#pragma once

#include "r2_TypeTraits.h"

namespace r2
{
	template<typename T>
	class Size
	{
	public:
		static_assert(
			   r2::is_same_v<T, char>
			|| r2::is_same_v<T, unsigned char>

			|| r2::is_same_v<T, short>

			|| r2::is_same_v<T, int>

			|| r2::is_same_v<T, long long int>
			|| r2::is_same_v<T, unsigned long long int>

			|| r2::is_same_v<T, float>

			|| r2::is_same_v<T, double>
			, "r2r::Size - Not Allowed Type"
		);

		using ValueT = T;
		using MyT = Size<ValueT>;



		//
		//
		//
		static MyT GetZero()
		{
			return MyT();
		}



		//
		//
		//
		Size() : mWidth( 0 ), mHeight( 0 )
		{}
		Size( const ValueT& width, const ValueT& height ) : mWidth( width ), mHeight( height )
		{}



		//
		//
		//
		bool operator== ( const MyT& other ) const
		{
			return Equal( other.mWidth, other.mHeight );
		}
		bool operator!= ( const MyT& other ) const
		{
			return !Equal( other.mWidth, other.mHeight );
		}

		MyT operator+ ( const MyT& other ) const
		{
			return MyT( mWidth + other.mWidth, mHeight + other.mHeight );
		}

		inline MyT& operator+=( const MyT& right )
		{
			mWidth += right.mWidth;
			mHeight += right.mHeight;
			return *this;
		}
		inline MyT& operator-=( const MyT& right )
		{
			mWidth -= right.mWidth;
			mHeight -= right.mHeight;
			return *this;
		}



		bool Equal( const ValueT& width, const ValueT& height ) const
		{
			return ( width == mWidth ) && ( height == mHeight );
		}



		//
		//
		//
		inline ValueT GetWidth() const
		{
			return mWidth;
		}
		inline ValueT GetHeight() const
		{
			return mHeight;
		}



		//
		//
		//
		inline void Set( const ValueT& width, const ValueT& height )
		{
			mWidth = width;
			mHeight = height;
		}
		inline void SetWidth( const ValueT& width )
		{
			mWidth = width;
		}
		inline void SetHeight( const ValueT& height )
		{
			mHeight = height;
		}



		//
		//
		//
		inline void Plus( const ValueT& width, const ValueT& height )
		{
			mWidth += width;
			mHeight += height;
		}
		inline void PlusWidth( const ValueT& width )
		{
			mWidth += width;
		}
		inline void PlusHeight( const ValueT& height )
		{
			mHeight += height;
		}



	private:
		ValueT mWidth;
		ValueT mHeight;
	};
}