#include "c_array_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_array_test
{
	void print_array( const int length, const int array[] )
	{
		std::cout << r2tm::tab << "Print :";
		for( int i = 0; length > i; ++i )
		{
			std::cout << " " << array[i];
		}
		LF();
	}

	r2tm::TitleFunctionT Init::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "array : Init";
		};
	}
	r2tm::DoFunctionT Init::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( const int length = 5 );

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				int array[length];
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[length] = { 0 };
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[5] = { 0, };
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[5] = { '\0', };
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			{
				OUTPUT_SOURCE_READY_N_BEGIN;
				const int array[5] = {};
				OUTPUT_SOURCE_END;

				LF();

				print_array( length, array );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}