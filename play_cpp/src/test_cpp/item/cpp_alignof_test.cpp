#include "cpp_alignof_test.h"

#include <deque>
#include <memory>
#include <unordered_map>
#include <vector>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace cpp_alignof_test
{
	r2tm::TitleFunctionT PrimitiveType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : PrimitiveType";
		};
	}
	r2tm::DoFunctionT PrimitiveType::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( char ) );
				OUTPUT_VALUE( sizeof( char ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( int ) );
				OUTPUT_VALUE( sizeof( int ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( bool ) );
				OUTPUT_VALUE( sizeof( bool ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( double ) );
				OUTPUT_VALUE( sizeof( double ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT STDContainer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : STDContainer";
		};
	}
	r2tm::DoFunctionT STDContainer::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( std::list<char> ) );
				OUTPUT_VALUE( sizeof( std::list<char> ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( std::list<int> ) );
				OUTPUT_VALUE( sizeof( std::list<int> ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( std::vector<int> ) );
				OUTPUT_VALUE( sizeof( std::vector<int> ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( std::unordered_map<int, int> ) );
				OUTPUT_VALUE( sizeof( std::unordered_map<int, int> ) );
			}

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( std::deque<int> ) );
				OUTPUT_VALUE( sizeof( std::deque<int> ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : Struct";
		};
	}
	r2tm::DoFunctionT Struct::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
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

			std::cout << r2tm::split;

			OUTPUT_FILE_RANGE( "src/test_cpp/item/cpp_alignof_test.cpp", 125, 158 );

			std::cout << r2tm::split;

			{
				OUTPUT_VALUE( alignof( EmptyStruct ) );
				OUTPUT_VALUE( sizeof( EmptyStruct ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( alignof( IntFloatCharStruct ) );
				OUTPUT_VALUE( sizeof( IntFloatCharStruct ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( alignof( CharCharCharStruct ) );
				OUTPUT_VALUE( sizeof( CharCharCharStruct ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( alignof( CharDoubleStruct ) );
				OUTPUT_VALUE( sizeof( CharDoubleStruct ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( alignof( CharBoolStruct ) );
				OUTPUT_VALUE( sizeof( CharBoolStruct ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( alignof( CharIntDoubleStruct ) );
				OUTPUT_VALUE( sizeof( CharIntDoubleStruct ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT MixedStruct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : Mixed Struct";
		};
	}
	r2tm::DoFunctionT MixedStruct::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			struct EmptyStruct {};

			struct CharIntFloatStruct
			{
				char c;
				int i;
				float f;
			};

			struct DoubleStruct
			{
				double d;
			};


			struct Mixed_1_Empty_N_CIF_Struct
			{
				EmptyStruct e;
				CharIntFloatStruct c;
			};

			struct Mixed_2_Empty_N_D_Struct
			{
				EmptyStruct e;
				DoubleStruct c;
			};

			struct Mixed_3_Empty_N_CIF_D_Struct
			{
				EmptyStruct e;
				CharIntFloatStruct c;
				DoubleStruct d;
			};

			{
				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ align of DoubleStruct : " << alignof( DoubleStruct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of DoubleStruct : " << sizeof( DoubleStruct ) << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			{
				std::cout << "\t" << "+ align of Mixed_1_Empty_N_CIF_Struct : " << alignof( Mixed_1_Empty_N_CIF_Struct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_1_Empty_N_CIF_Struct : " << sizeof( Mixed_1_Empty_N_CIF_Struct ) << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ align of Mixed_2_Empty_N_D_Struct : " << alignof( Mixed_2_Empty_N_D_Struct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_2_Empty_N_D_Struct : " << sizeof( Mixed_2_Empty_N_D_Struct ) << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ align of Mixed_3_Empty_N_CIF_D_Struct : " << alignof( Mixed_3_Empty_N_CIF_D_Struct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_3_Empty_N_CIF_D_Struct : " << sizeof( Mixed_3_Empty_N_CIF_D_Struct ) << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}