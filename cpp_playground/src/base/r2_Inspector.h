#pragma once

#define	EXPECT_TRUE( condition )									\
do {																\
	if( !( condition ) )											\
	{																\
		__debugbreak();												\
		printf( "FAILED : EXPECT_TRUE : %s\n", , #condition );		\
	}																\
	else															\
	{																\
		printf( "PASS : EXPECT_TRUE : %s\n", #condition );			\
	}																\
} while( false )

#define	EXPECT_FALSE( condition )									\
do {																\
	if( ( condition ) )												\
	{																\
		__debugbreak();												\
		printf( "FAILED : EXPECT_FALSE : %s\n", #condition );		\
	}																\
	else															\
	{																\
		printf( "PASS : EXPECT_FALSE : %s\n", #condition );			\
	}																\
} while( false )

#define	EXPECT_EQ( condition_1, condition_2 )											\
do {																					\
	if( ( condition_1 ) != ( condition_2 ) )											\
	{																					\
		__debugbreak();																	\
		printf( "FAILED : EXPECT_EQ : %s == %s\n", #condition_1, #condition_2 );		\
	}																					\
	else																				\
	{																					\
		printf( "PASS : EXPECT_EQ : %s == %s\n", #condition_1, #condition_2 );			\
	}																					\
} while( false )

#define	EXPECT_NEQ( condition_1, condition_2 )											\
do {																					\
	if( ( condition_1 ) == ( condition_2 ) )											\
	{																					\
		__debugbreak();																	\
		printf( "FAILED : EXPECT_EQ : %s != %s\n", #condition_1, #condition_2 );		\
	}																					\
	else																				\
	{																					\
		printf( "PASS : EXPECT_EQ : %s == %s\n", #condition_1, #condition_2 );			\
	}																					\
} while( false )