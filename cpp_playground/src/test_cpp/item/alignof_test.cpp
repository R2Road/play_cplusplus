#include "alignof_test.h"

#include <deque>
#include <memory>
#include <unordered_map>
#include <vector>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace alignof_test
{
	r2cm::iItem::TitleFunctionT PrimitiveType::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : PrimitiveType";
		};
	}
	r2cm::iItem::DoFunctionT PrimitiveType::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( char ) );
				OUTPUT_VALUE( sizeof( char ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( int ) );
				OUTPUT_VALUE( sizeof( int ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( bool ) );
				OUTPUT_VALUE( sizeof( bool ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( double ) );
				OUTPUT_VALUE( sizeof( double ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT STDContainer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : STDContainer";
		};
	}
	r2cm::iItem::DoFunctionT STDContainer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( std::list<char> ) );
				OUTPUT_VALUE( sizeof( std::list<char> ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( std::list<int> ) );
				OUTPUT_VALUE( sizeof( std::list<int> ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( std::vector<int> ) );
				OUTPUT_VALUE( sizeof( std::vector<int> ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( std::unordered_map<int, int> ) );
				OUTPUT_VALUE( sizeof( std::unordered_map<int, int> ) );
			}

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( alignof( std::deque<int> ) );
				OUTPUT_VALUE( sizeof( std::deque<int> ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Struct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : Struct";
		};
	}
	r2cm::iItem::DoFunctionT Struct::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
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

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of IntFloatCharStruct : " << alignof( IntFloatCharStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of IntFloatCharStruct : " << sizeof( IntFloatCharStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of CharCharCharStruct : " << alignof( CharCharCharStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of CharCharCharStruct : " << sizeof( CharCharCharStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of CharDoubleStruct : " << alignof( CharDoubleStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of CharDoubleStruct : " << sizeof( CharDoubleStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of CharBoolStruct : " << alignof( CharBoolStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of CharBoolStruct : " << sizeof( CharBoolStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of CharIntDoubleStruct : " << alignof( CharIntDoubleStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of CharIntDoubleStruct : " << sizeof( CharIntDoubleStruct ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT MixedStruct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "alignof : Mixed Struct";
		};
	}
	r2cm::iItem::DoFunctionT MixedStruct::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

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
				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of DoubleStruct : " << alignof( DoubleStruct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of DoubleStruct : " << sizeof( DoubleStruct ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << "\t" << "+ align of Mixed_1_Empty_N_CIF_Struct : " << alignof( Mixed_1_Empty_N_CIF_Struct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_1_Empty_N_CIF_Struct : " << sizeof( Mixed_1_Empty_N_CIF_Struct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of Mixed_2_Empty_N_D_Struct : " << alignof( Mixed_2_Empty_N_D_Struct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_2_Empty_N_D_Struct : " << sizeof( Mixed_2_Empty_N_D_Struct ) << r2cm::linefeed << r2cm::linefeed;

				std::cout << "\t" << "+ align of Mixed_3_Empty_N_CIF_D_Struct : " << alignof( Mixed_3_Empty_N_CIF_D_Struct ) << r2cm::linefeed;
				std::cout << "\t\t" << "- size of Mixed_3_Empty_N_CIF_D_Struct : " << sizeof( Mixed_3_Empty_N_CIF_D_Struct ) << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}