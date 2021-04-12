#include "pch.h"
#include "align_test.h"

#include <deque>
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



	const r2::iNode::TitleFunc MixedStruct::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align : Mixed Struct";
		};
	}
	const r2::iNode::DoFunc MixedStruct::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Mixed Struct ==" << std::endl << std::endl;

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
				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << std::endl;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << std::endl;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of DoubleStruct : " << alignof( DoubleStruct ) << std::endl;
				std::cout << "\t\t" << "- size of DoubleStruct : " << sizeof( DoubleStruct ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				std::cout << "\t" << "+ align of Mixed_1_Empty_N_CIF_Struct : " << alignof( Mixed_1_Empty_N_CIF_Struct ) << std::endl;
				std::cout << "\t\t" << "- size of Mixed_1_Empty_N_CIF_Struct : " << sizeof( Mixed_1_Empty_N_CIF_Struct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of Mixed_2_Empty_N_D_Struct : " << alignof( Mixed_2_Empty_N_D_Struct ) << std::endl;
				std::cout << "\t\t" << "- size of Mixed_2_Empty_N_D_Struct : " << sizeof( Mixed_2_Empty_N_D_Struct ) << std::endl << std::endl;

				std::cout << "\t" << "+ align of Mixed_3_Empty_N_CIF_D_Struct : " << alignof( Mixed_3_Empty_N_CIF_D_Struct ) << std::endl;
				std::cout << "\t\t" << "- size of Mixed_3_Empty_N_CIF_D_Struct : " << sizeof( Mixed_3_Empty_N_CIF_D_Struct ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc AlignAs::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align : Align As";
		};
	}
	const r2::iNode::DoFunc AlignAs::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Align As ==" << std::endl << std::endl;

			{
				std::cout << "\t" << "struct alignas( 32 ) EmptyStruct {};" << std::endl << std::endl;
				struct alignas( 32 ) EmptyStruct {};

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << std::endl;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				std::cout << "\t" << "struct alignas( 8 ) CharIntFloatStruct" << std::endl;
				std::cout << "\t" << "{" << std::endl;
				std::cout << "\t\t" << "char c;" << std::endl;
				std::cout << "\t\t" << "int i;" << std::endl;
				std::cout << "\t\t" << "float f;" << std::endl;
				std::cout << "\t" << "}" << std::endl << std::endl;
				struct alignas( 8 ) CharIntFloatStruct
				{
					char c;
					int i;
					float f;
				};

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << std::endl;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				std::cout << "\t" << "struct alignas( 0 ) IntStruct" << std::endl;
				std::cout << "\t" << "{" << std::endl;
				std::cout << "\t\t" << "int i;" << std::endl;
				std::cout << "\t" << "}" << std::endl << std::endl;
				struct alignas( 0 ) IntStruct
				{
					int i;
				};

				std::cout << "\t" << "+ align of IntStruct : " << alignof( IntStruct ) << std::endl;
				std::cout << "\t\t" << "- size of IntStruct : " << sizeof( IntStruct ) << std::endl << std::endl;

				std::cout << "\t" << "+ Ignore 0" << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl << std::endl;

			{
				std::cout << "\t" << "struct alignas( 1 ) IntStruct" << std::endl;
				std::cout << "\t" << "{" << std::endl;
				std::cout << "\t\t" << "int i;" << std::endl;
				std::cout << "\t" << "}" << std::endl << std::endl;
				//struct alignas( 1 ) IntStruct
				//{
				//	int i;
				//};

				std::cout << "\t" << "+ 1 is Error : At Least A Default Size Is Required" << std::endl << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}



	const r2::iNode::TitleFunc Align::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Align : Align";
		};
	}
	const r2::iNode::DoFunc Align::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "== Align ==" << std::ends << std::ends;

			//{
			//	std::cout << "\t" << "double d;" << std::endl;
			//	std::cout << "\t" << "void* dp = &d;" << std::endl;
			//	double d = 1;
			//	void* dp = &d;

			//	std::cout << "\t + " << "adress of dp " << std::endl;
			//	std::cout << "\t\t - " << dp << std::endl << std::endl;

			//	std::size_t space_size = sizeof( double );
			//	std::cout << "\t + " << "space size" << std::endl;
			//	std::cout << "\t\t - " << space_size << std::endl;

			//	const std::size_t align = alignof( int );
			//	auto ip3 = std::align( align, sizeof( int ), dp, space_size );

			//	std::cout << "\t + " << "space size" << std::endl;
			//	std::cout << "\t\t - " << space_size << std::endl;

			//	std::cout << "\t + " << "adress of ip3" << std::endl;
			//	std::cout << "\t\t - " << ip3 << std::endl;

			//	std::cout << "\t + " << "adress of dp" << std::endl;
			//	std::cout << "\t\t - " << dp << std::endl;
			//}

			{
				char buffer[] = "------------------------";
				void * pt = buffer;

				std::cout << "\t + " << "orig : " << buffer << std::endl;
				std::cout << "\t + " << "adress of pt : " << pt << std::endl << std::endl;

				std::cout << "\t + " << "Process" << std::endl;

				std::size_t space = sizeof( buffer ) - 1;
				while( std::align( alignof( int ), sizeof( char ), pt, space ) )
				{
					char* temp = static_cast<char*>( pt );
					*temp = '*';
					++temp;
					space -= sizeof( char );

					std::cout << "\t\t - " << "adress of pt : " << pt << std::endl;
					std::cout << "\t\t - " << "cvrt : " << buffer << std::endl << std::endl;

					pt = temp;
				}

				std::cout << "\t" << "result : " << buffer << std::endl;
			}

			std::cout << std::endl << std::endl;

			return r2::eTestResult::RunTest;
		};
	}
}