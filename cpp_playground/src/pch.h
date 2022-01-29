﻿#ifndef PCH_H
#define PCH_H

#include <iostream>
#include <stdio.h>



#define	R2ASSERT( cond, message )					\
do {												\
	if( !( cond ) )									\
	{												\
		printf( "+ R2ASSERT" "\nMessage : %s" "\nFile : %s" "\nLine : %d" "\nFunction : %s", message, __FILE__, __LINE__, __FUNCTION__ ); \
		__debugbreak();								\
		throw std::runtime_error( message );		\
	}												\
} while( false )



namespace r2
{
	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		// insert newline
		_Ostr.put( _Ostr.widen( '\n' ) );
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed2( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << linefeed << linefeed;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& linefeed3( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << linefeed << linefeed << linefeed;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& split( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2::linefeed << "====================================================================" << r2::linefeed << r2::linefeed;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr.put( _Ostr.widen( '\t' ) );
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab2( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2::tab << r2::tab;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab3( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2::tab << r2::tab << r2::tab;
		return ( _Ostr );
	}

	template<class _Elem, class _Traits>
	inline std::basic_ostream<_Elem, _Traits>& tab4( std::basic_ostream<_Elem, _Traits>& _Ostr )
	{
		_Ostr << r2::tab << r2::tab << r2::tab << r2::tab;
		return ( _Ostr );
	}
}

#endif //PCH_H
