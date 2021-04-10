#include "align_test.h"

#include <deque>
#include <iostream>
#include <memory>
#include <unordered_map>
#include <vector>

#include "r2_eTestResult.h"

namespace align_test
{
	const r2::iNode::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align : Basic";
		};
	}

	const r2::iNode::DoFunc Basic::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Basic ==" << std::endl << std::endl;

			{
				std::cout << "\t" << "+ align of char : " << alignof( char ) << std::endl;
				std::cout << "\t\t" << "- size of char : " << sizeof( char ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of int : " << alignof( int ) << std::endl;
				std::cout << "\t\t" << "- size of int : " << sizeof( int ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of bool : " << alignof( bool ) << std::endl;
				std::cout << "\t\t" << "- size of bool : " << sizeof( bool ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of double : " << alignof( double ) << std::endl;
				std::cout << "\t\t" << "- size of double : " << sizeof( double ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				struct EmptyStruct {};

				struct IntFloatCharStruct
				{
					int i;
					float f;
					char c;
				};

				struct CharCharCharStruct
				{
					char c1;
					char c2;
					char c3;
				};

				struct CharDoubleStruct
				{
					char c;
					double d;
				};

				struct CharBoolStruct
				{
					char c;
					bool b;
				};

				struct CharIntDoubleStruct
				{
					char c;
					int i;
					double d;
				};

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << std::endl;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of IntFloatCharStruct : " << alignof( IntFloatCharStruct ) << std::endl;
				std::cout << "\t\t" << "- size of IntFloatCharStruct : " << sizeof( IntFloatCharStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of CharCharCharStruct : " << alignof( CharCharCharStruct ) << std::endl;
				std::cout << "\t\t" << "- size of CharCharCharStruct : " << sizeof( CharCharCharStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of CharDoubleStruct : " << alignof( CharDoubleStruct ) << std::endl;
				std::cout << "\t\t" << "- size of CharDoubleStruct : " << sizeof( CharDoubleStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of CharBoolStruct : " << alignof( CharBoolStruct ) << std::endl;
				std::cout << "\t\t" << "- size of CharBoolStruct : " << sizeof( CharBoolStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of CharIntDoubleStruct : " << alignof( CharIntDoubleStruct ) << std::endl;
				std::cout << "\t\t" << "- size of CharIntDoubleStruct : " << sizeof( CharIntDoubleStruct ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				std::cout << "\t" << "+ align of std::list<char> : " << alignof( std::list<char> ) << std::endl;
				std::cout << "\t\t" << "- size of std::list<char> : " << sizeof( std::list<char> ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of std::list<int> : " << alignof( std::list<int> ) << std::endl;
				std::cout << "\t\t" << "- size of std::list<int> : " << sizeof( std::list<int> ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of std::vector<int> : " << alignof( std::vector<int> ) << std::endl;
				std::cout << "\t\t" << "- size of std::vector<int> : " << sizeof( std::vector<int> ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of std::alignof( std::unordered_map<int, int> ) : " << alignof( std::unordered_map<int, int> ) << std::endl;
				std::cout << "\t\t" << "- size of std::unordered_map<int, int> : " << sizeof( std::unordered_map<int, int> ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of std::alignof( std::deque<int> ) : " << alignof( std::deque<int> ) << std::endl;
				std::cout << "\t\t" << "- size of std::deque<int> : " << sizeof( std::deque<int> ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}
}