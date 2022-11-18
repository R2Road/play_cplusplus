#include "r2cm_BinaryPrint.h"

void Uint8BinaryPrint( const uint8_t value )
{
	uint8_t temp_value = 0;
	bool temp_bit_flag = false;
	for( int32_t position = 7; 0 <= position; --position )
	{
		temp_value = ( value >> position );
		temp_bit_flag = ( temp_value & 1 );

		printf( "%d", temp_bit_flag );
	}
}