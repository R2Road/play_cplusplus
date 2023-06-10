#include "c_array_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace c_array_test
{
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

			{
				DECLARATION_MAIN( int array[5] );

				LF();

				std::cout << r2tm::tab << "Print :";
				for( auto i : array )
				{
					std::cout << " " << i;
				}
				LF();
			}

			LS();

			{
				int array[5] = { 0, };
				std::cout << r2tm::tab << "int array[10] = { 0, };" << r2tm::linefeed2;

				std::cout << r2tm::tab << "Print :";
				for( auto i : array )
				{
					std::cout << " " << i;
				}
				LF();
			}

			LS();

			{
				int array[5] = { '\0', };
				std::cout << r2tm::tab << "int array[10] = { \'\\0\', };" << r2tm::linefeed2;

				std::cout << r2tm::tab << "Print :";
				for( auto i : array )
				{
					std::cout << " " << i;
				}
				LF();
			}

			LS();

			{
				DECLARATION_MAIN( int array[5] = {} );

				LF();

				std::cout << r2tm::tab << "Print :";
				for( auto i : array )
				{
					std::cout << " " << i;
				}
				LF();
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}