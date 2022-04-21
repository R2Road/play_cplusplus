#ifndef R2ASSERT_H
#define R2ASSERT_H

#include <stdio.h>

#define	R2ASSERT( condition, message )		\
do {										\
	if( !( condition ) )					\
	{										\
		printf( "+ R2ASSERT" "\nCondition : %s" "\nMessage : %s", #condition, message );	\
		__debugbreak();\
		throw std::runtime_error( message );\
	}										\
} while( false )


#endif //R2ASSERT_H
