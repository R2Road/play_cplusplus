//
// # Version Rule
// - 1.0.0 : 사용 가능
// - 0.1.0 : 사용자가 코드를 바꿀 정도의 변화
// - 0.0.1 : 자잘한 변화
//
// # Last Update		: 2023.08.06 PM.03.00
// # Version			: 1.0.0
//

#include <stdio.h>


//
// Debug Break
//
#define R2ASSERT_ENABLE_DEBUG_BREAK 1

#if defined( R2ASSERT_ENABLE_DEBUG_BREAK ) && R2ASSERT_ENABLE_DEBUG_BREAK == 1
	#define R2ASSERT_DEBUG_BREAK ( __debugbreak() )
#else
	#define R2ASSERT_DEBUG_BREAK
#endif



//
// Assertion
//
#define R2ASSERT_ENABLE_ASSERTION 0

#if defined( R2ASSERT_ENABLE_ASSERTION ) && R2ASSERT_ENABLE_ASSERTION == 1
	#include <cassert>
	#define R2ASSERT_ASSERTION( condition ) assert( condition )
#else
	#define R2ASSERT_ASSERTION( condition ) do {} while ( 0 )
#endif



//
// Exception
//
#define R2ASSERT_ENABLE_EXCEPTION 0

#if defined( R2ASSERT_ENABLE_EXCEPTION ) && R2ASSERT_ENABLE_EXCEPTION == 1
	#define R2ASSERT_EXCEPTION( message ) throw std::runtime_error( message )
#else
	#define R2ASSERT_EXCEPTION( message ) do {} while ( 0 )
#endif



//
//
//
#define	R2ASSERT( condition, message )																\
do {																								\
	if( !( condition ) )																			\
	{																								\
		printf( "[R2ASSERT]" "\n" "Condition : %s" "\n" "Message : %s" "\n", #condition, message );	\
		R2ASSERT_DEBUG_BREAK;																		\
		R2ASSERT_EXCEPTION( message );																\
	}																								\
																									\
	R2ASSERT_ASSERTION( condition );																\
} while( false )

#define	R2ASSERT_FORCED( message )																	\
do {																								\
	printf( "[R2ASSERT_FORCED]" "\n" "Message : %s" "\n", message );								\
	R2ASSERT_DEBUG_BREAK;																			\
	R2ASSERT_EXCEPTION( message );																	\
																									\
	R2ASSERT_ASSERTION( false );																\
} while( false )
