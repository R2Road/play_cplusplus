#include "array_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace array_test
{
	r2cm::iItem::TitleFunctionT Init::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Init";
		};
	}
	r2cm::iItem::DoFunctionT Init::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int array[5] );

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int array[5] = { 0, };
				std::cout << r2cm::tab2 << "int array[10] = { 0, };" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int array[5] = { '\0', };
				std::cout << r2cm::tab2 << "int array[10] = { \'\\0\', };" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( int array[5] = {} );

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}