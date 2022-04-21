#ifndef R2ASSERT_H
#define R2ASSERT_H

#include <stdio.h>

#define	R2ASSERT( condition, message )																										\
do {																																		\
	if( !( condition ) )																													\
	{																																		\
		printf( "+ R2ASSERT" "\nMessage : %s" "\nFile : %s" "\nLine : %d" "\nFunction : %s", message, __FILE__, __LINE__, __FUNCTION__ );	\
		__debugbreak();																														\
		throw std::runtime_error( message );																								\
	}																																		\
} while( false )


#endif //R2ASSERT_H
