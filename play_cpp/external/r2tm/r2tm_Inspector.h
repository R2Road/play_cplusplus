#pragma once

#include <iostream>
#include <stdint.h>

#include "r2tm_PrintBinary.h"
#include "r2tm_PrintFile.h"

#define R2TM_ENABLE_DEBUG_BREAK 0

#if defined( R2TM_ENABLE_DEBUG_BREAK ) && R2TM_ENABLE_DEBUG_BREAK == 1
	#define R2TM_DEBUG_BREAK ( __debugbreak() )
#else
	#define R2TM_DEBUG_BREAK
#endif // R2TM_ENABLE_DEBUG_BREAK



//
//
//
#define	EXPECT_TRUE( condition )																\
do {																							\
	if( ( condition ) )																			\
	{																							\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );				\
	}																							\
	else																						\
	{																							\
		R2TM_DEBUG_BREAK;																		\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_TRUE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_FALSE( condition )																\
do {																							\
	if( !( condition ) )																		\
	{																							\
		printf( "\x1B[94m" "[PASS]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
	else																						\
	{																							\
		R2TM_DEBUG_BREAK;																		\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_FALSE( %s )\n", #condition );			\
	}																							\
} while( false )

#define	EXPECT_EQ( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) == ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_EQ( %s == %s )\n", #condition_1, #condition_2 );		\
		OUTPUT_VALUE( ( condition_1 ) );																		\
		OUTPUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_NE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) != ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[94m" "[PASS]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_NE( %s != %s )\n", #condition_1, #condition_2 );		\
		OUTPUT_VALUE( ( condition_1 ) );																		\
		OUTPUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_GT( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) > ( condition_2 ) )																		\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_GT( %s > %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_GT( %s > %s )\n", #condition_1, #condition_2 );		\
		OUTPUT_VALUE( ( condition_1 ) );																		\
		OUTPUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_LT( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) < ( condition_2 ) )																		\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_LT( %s < %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_LT( %s < %s )\n", #condition_1, #condition_2 );		\
		OUTPUT_VALUE( ( condition_1 ) );																		\
		OUTPUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_GE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) >= ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_GE( %s >= %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_GE( %s >= %s )\n", #condition_1, #condition_2 );		\
		OUTPUT_VALUE( ( condition_1 ) );																		\
		OUTPUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )

#define	EXPECT_LE( condition_1, condition_2 )																	\
do {																											\
	if( ( condition_1 ) <= ( condition_2 ) )																	\
	{																											\
		printf( "\x1B[92m" "[PASS]" "\033[0m" " EXPECT_LE( %s <= %s )\n", #condition_1, #condition_2 );			\
	}																											\
	else																										\
	{																											\
		R2TM_DEBUG_BREAK;																						\
		printf( "\x1B[91m" "[FAILED]" "\033[0m" " EXPECT_LE( %s <= %s )\n", #condition_1, #condition_2 );		\
		OUTPUT_VALUE( ( condition_1 ) );																		\
		OUTPUT_VALUE( ( condition_2 ) );																		\
	}																											\
} while( false )




//
// Important Process Code
//
#define	PROCESS_MAIN( condition )															\
do {																						\
	printf( "\x1B[96m" "[PROCESS]" "\033[0m" " %s\n", #condition );							\
	{ condition; }																			\
} while( false )
//
// Sub Process Code
//
#define	PROCESS_SUB( condition )															\
do {																						\
	printf( "\x1B[90m" "[PROCESS]" " %s" "\033[0m" "\n", #condition );						\
	{ condition; }																			\
} while( false )




//
// Important Declaration Code
//
#define	DECLARATION_MAIN( condition )														\
printf( "\x1B[93m" "[DECLARATION]" "\033[0m" " %s\n", #condition );							\
condition;
//
// Sub Declaration Code
//
#define	DECLARATION_SUB( condition )														\
printf( "\x1B[90m" "[DECLARATION]" " %s" "\033[0m" "\n", #condition );						\
condition;




//
// Output Value
//
#define	OUTPUT_VALUE( condition )															\
do {																						\
	printf( "[VALUE]" " %s" "\n", #condition );												\
	std::cout << "\t> " << condition << "\n";												\
} while( false )




//
// Output Binary
//
#define	OUTPUT_BINARY( condition )															\
do {																						\
	printf( "[BINARY]" " %s", #condition );													\
	r2tm::PrintBinary( ( condition ) );														\
	printf( "\n" );																			\
} while( false )

//
// + example : int a[4];
// pointer : int*
// size : 4
//
#define	OUTPUT_BINARIES( pointer, size )													\
do {																						\
	printf( "[BINARIES]" " %s" ", %s", #pointer, #size );									\
	r2tm::PrintBinary( ( pointer ), ( size ) );												\
	printf( "\n" );																			\
} while( false )




//
// Output Code
//
#define	OUTPUT_CODE( condition )															\
do {																						\
	printf( "[CODE]"  "\x1B[90m"  " %s"  "\033[0m"  "\n", #condition );						\
} while( false )




//
// Output Size
//
#if _WIN64 == 1

#define	OUTPUT_SIZE( condition )															\
do {																						\
	printf( "[SIZE]" " %s" "\n" "\t> %llu" " byte" "\n", #condition, sizeof( condition ) );	\
} while( false )

#else

#define	OUTPUT_SIZE( condition )															\
do {																						\
	printf( "[SIZE]" " %s" "\n" "\t> %u" " byte" "\n", #condition, sizeof( condition ) );	\
} while( false )

#endif




//
// Output ETC
//
#define	OUTPUT_STRING( str )																\
do {																						\
	printf( "%s"  "\n", str );																\
} while( false )

#define	OUTPUT_NOTE( str )																	\
do {																						\
	printf( "\t"  "\x1B[91m"  "[ NOTE ] "  "%s"  "\033[0m"  "\n", str );					\
} while( false )

#define	OUTPUT_SUBJECT( str )																\
do {																						\
	printf( "\t"  "\x1B[92m"  "# "  "%s"  "\033[0m"  "\n", str );							\
} while( false )

#define	OUTPUT_COMMENT( str )																\
do {																						\
	printf( "\t"  "\x1B[93m"  "> " "%s"  "\033[0m"  "\n", str );							\
} while( false )




//
// File
//
#define OUTPUT_FILE( file_path )															\
do {																						\
	r2tm::PrintFile( file_path );															\
} while( false )

#define OUTPUT_FILE_RANGE( file_path, min, max )											\
do {																						\
	r2tm::PrintFile( file_path, min, max );													\
} while( false )

#define OUTPUT_SOURCE_READY		int src_begin, src_end = -1
#define OUTPUT_SOURCE_BEGIN		do { src_begin = __LINE__ + 1; } while( false )
#define OUTPUT_SOURCE_END		do { src_end = __LINE__ - 1; r2tm::PrintFile( __FILE__, src_begin, src_end ); } while( false )

#define OUTPUT_SOURCE_READY_N_BEGIN		OUTPUT_SOURCE_READY; OUTPUT_SOURCE_BEGIN