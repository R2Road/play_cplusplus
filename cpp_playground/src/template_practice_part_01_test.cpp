#include "pch.h"
#include "template_practice_part_01_test.h"

#include "r2_eTestResult.h"

namespace template_practice_part_01_test
{
	template<int N>
	struct Buffer
	{
		Buffer() :
			b()
			, size( N )
		{
			memset( b, 'a', sizeof( b ) );
		}

		char b[N];
		std::size_t size;
	};

	const r2::iNode::TitleFunc Practice01::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Template : Pracitce Part 01";
		};
	}

	const r2::iNode::DoFunc Practice01::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			std::cout << r2::split;

			{
				Buffer<64> buffer;
				std::cout << "\t + " << "Buffer<64> buffer" << r2::linefeed;

				std::cout << "\t\t";
				for( const auto c : buffer.b )
				{
					std::cout << c;
				}

				std::cout << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}