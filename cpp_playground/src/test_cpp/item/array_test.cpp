#include "array_test.h"

#include <list>
#include <numeric> // std::iota
#include <stdint.h>

#include "r2cm/r2cm_constant.h"

namespace array_test
{
	r2cm::iItem::TitleFuncT Init::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Array : Init";
		};
	}
	r2cm::iItem::DoFuncT Init::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				int array[10];
				std::cout << r2cm::tab2 << "int array[10];" << r2cm::linefeed;

				std::cout << r2cm::tab2 << "Print : ";
				for( auto i : array )
				{
					std::cout << i;
				}
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				int array[10] = { 0, };
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
				int array[10] = { '\0', };
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
				int array[10] = {};
				std::cout << r2cm::tab2 << "int array[10] = {};" << r2cm::linefeed;

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