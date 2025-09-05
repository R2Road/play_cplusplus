#include "play_cpp_alignof.hpp"

#include <deque>
#include <memory>
#include <unordered_map>
#include <vector>

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_cpp_alignof
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
			LS();

			{
				OUT_VALUE( alignof( char ) );
				OUT_VALUE( sizeof( char ) );
			}

			LS();

			{
				OUT_VALUE( alignof( int ) );
				OUT_VALUE( sizeof( int ) );
			}

			LS();

			{
				OUT_VALUE( alignof( bool ) );
				OUT_VALUE( sizeof( bool ) );
			}

			LS();

			{
				OUT_VALUE( alignof( double ) );
				OUT_VALUE( sizeof( double ) );
			}

			LS();

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
			LS();

			{
				OUT_VALUE( alignof( std::list<char> ) );
				OUT_VALUE( sizeof( std::list<char> ) );
			}

			LS();

			{
				OUT_VALUE( alignof( std::list<int> ) );
				OUT_VALUE( sizeof( std::list<int> ) );
			}

			LS();

			{
				OUT_VALUE( alignof( std::vector<int> ) );
				OUT_VALUE( sizeof( std::vector<int> ) );
			}

			LS();

			{
				OUT_VALUE( alignof( std::unordered_map<int, int> ) );
				OUT_VALUE( sizeof( std::unordered_map<int, int> ) );
			}

			LS();

			{
				OUT_VALUE( alignof( std::deque<int> ) );
				OUT_VALUE( sizeof( std::deque<int> ) );
			}

			LS();

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

			LS();

			OUT_FILE_RANGE( __FILE__, 125, 158 );

			LS();

			{
				OUT_VALUE( alignof( EmptyStruct ) );
				OUT_VALUE( sizeof( EmptyStruct ) );

				LF();

				OUT_VALUE( alignof( IntFloatCharStruct ) );
				OUT_VALUE( sizeof( IntFloatCharStruct ) );

				LF();

				OUT_VALUE( alignof( CharCharCharStruct ) );
				OUT_VALUE( sizeof( CharCharCharStruct ) );

				LF();

				OUT_VALUE( alignof( CharDoubleStruct ) );
				OUT_VALUE( sizeof( CharDoubleStruct ) );

				LF();

				OUT_VALUE( alignof( CharBoolStruct ) );
				OUT_VALUE( sizeof( CharBoolStruct ) );

				LF();

				OUT_VALUE( alignof( CharIntDoubleStruct ) );
				OUT_VALUE( sizeof( CharIntDoubleStruct ) );
			}

			LS();

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
			LS();

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

			LS();

			{
				std::cout << "\t" << "+ align of Mixed_1_Empty_N_CIF_Struct : " << alignof( Mixed_1_Empty_N_CIF_Struct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_1_Empty_N_CIF_Struct : " << sizeof( Mixed_1_Empty_N_CIF_Struct ) << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ align of Mixed_2_Empty_N_D_Struct : " << alignof( Mixed_2_Empty_N_D_Struct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_2_Empty_N_D_Struct : " << sizeof( Mixed_2_Empty_N_D_Struct ) << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ align of Mixed_3_Empty_N_CIF_D_Struct : " << alignof( Mixed_3_Empty_N_CIF_D_Struct ) << r2tm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_3_Empty_N_CIF_D_Struct : " << sizeof( Mixed_3_Empty_N_CIF_D_Struct ) << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}