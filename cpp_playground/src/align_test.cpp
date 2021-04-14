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
			std::cout << "# Basic #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ align of char : " << alignof( char ) << r2::linefeed;
				std::cout << "\t\t" << "- size of char : " << sizeof( char ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of int : " << alignof( int ) << r2::linefeed;
				std::cout << "\t\t" << "- size of int : " << sizeof( int ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of bool : " << alignof( bool ) << r2::linefeed;
				std::cout << "\t\t" << "- size of bool : " << sizeof( bool ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of double : " << alignof( double ) << r2::linefeed;
				std::cout << "\t\t" << "- size of double : " << sizeof( double ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

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

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of IntFloatCharStruct : " << alignof( IntFloatCharStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of IntFloatCharStruct : " << sizeof( IntFloatCharStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharCharCharStruct : " << alignof( CharCharCharStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharCharCharStruct : " << sizeof( CharCharCharStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharDoubleStruct : " << alignof( CharDoubleStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharDoubleStruct : " << sizeof( CharDoubleStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharBoolStruct : " << alignof( CharBoolStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharBoolStruct : " << sizeof( CharBoolStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharIntDoubleStruct : " << alignof( CharIntDoubleStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharIntDoubleStruct : " << sizeof( CharIntDoubleStruct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ align of std::list<char> : " << alignof( std::list<char> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::list<char> : " << sizeof( std::list<char> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::list<int> : " << alignof( std::list<int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::list<int> : " << sizeof( std::list<int> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::vector<int> : " << alignof( std::vector<int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::vector<int> : " << sizeof( std::vector<int> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::alignof( std::unordered_map<int, int> ) : " << alignof( std::unordered_map<int, int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::unordered_map<int, int> : " << sizeof( std::unordered_map<int, int> ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of std::alignof( std::deque<int> ) : " << alignof( std::deque<int> ) << r2::linefeed;
				std::cout << "\t\t" << "- size of std::deque<int> : " << sizeof( std::deque<int> ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

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
			std::cout << "# Mixed Struct #" << r2::linefeed << r2::linefeed;

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
				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of DoubleStruct : " << alignof( DoubleStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of DoubleStruct : " << sizeof( DoubleStruct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ align of Mixed_1_Empty_N_CIF_Struct : " << alignof( Mixed_1_Empty_N_CIF_Struct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of Mixed_1_Empty_N_CIF_Struct : " << sizeof( Mixed_1_Empty_N_CIF_Struct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of Mixed_2_Empty_N_D_Struct : " << alignof( Mixed_2_Empty_N_D_Struct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of Mixed_2_Empty_N_D_Struct : " << sizeof( Mixed_2_Empty_N_D_Struct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ align of Mixed_3_Empty_N_CIF_D_Struct : " << alignof( Mixed_3_Empty_N_CIF_D_Struct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of Mixed_3_Empty_N_CIF_D_Struct : " << sizeof( Mixed_3_Empty_N_CIF_D_Struct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

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
			std::cout << "# Align As #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 32 ) EmptyStruct {};" << r2::linefeed << r2::linefeed;
				struct alignas( 32 ) EmptyStruct {};

				std::cout << "\t" << "+ align of EmptyStruct : " << alignof( EmptyStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of EmptyStruct : " << sizeof( EmptyStruct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 8 ) CharIntFloatStruct" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "char c;" << r2::linefeed;
				std::cout << "\t\t" << "int i;" << r2::linefeed;
				std::cout << "\t\t" << "float f;" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;
				struct alignas( 8 ) CharIntFloatStruct
				{
					char c;
					int i;
					float f;
				};

				std::cout << "\t" << "+ align of CharIntFloatStruct : " << alignof( CharIntFloatStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of CharIntFloatStruct : " << sizeof( CharIntFloatStruct ) << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 0 ) IntStruct" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "int i;" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;
				struct alignas( 0 ) IntStruct
				{
					int i;
				};

				std::cout << "\t" << "+ align of IntStruct : " << alignof( IntStruct ) << r2::linefeed;
				std::cout << "\t\t" << "- size of IntStruct : " << sizeof( IntStruct ) << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ Ignore 0" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "struct alignas( 1 ) IntStruct" << r2::linefeed;
				std::cout << "\t" << "{" << r2::linefeed;
				std::cout << "\t\t" << "int i;" << r2::linefeed;
				std::cout << "\t" << "}" << r2::linefeed << r2::linefeed;
				//struct alignas( 1 ) IntStruct
				//{
				//	int i;
				//};

				std::cout << "\t" << "+ 1 is Error : At Least A Default Size Is Required" << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

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
			std::cout << "# Align #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "double d;" << r2::linefeed;
				std::cout << "\t" << "void* dp = &d;" << r2::linefeed;
				double d = 1;

				void* dp = &d;
				std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;

				std::size_t space = sizeof( double );
				std::cout << "\t\t - " << "space size : " << space << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
				if( std::align( alignof( int ), sizeof( int ), dp, space ) )
				{
					std::cout << "\t\t - " << "success" << r2::linefeed;
				}
				else
				{
					std::cout << "\t\t - " << "failed" << r2::linefeed;
				}

				{
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					char* cp = static_cast<char*>( dp );
					++cp;

					dp = cp;
					space -= sizeof( char );

					std::cout << "\t" << "move" << r2::linefeed;
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << "\t" << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
				if( std::align( alignof( int ), sizeof( int ), dp, space ) )
				{
					std::cout << "\t\t - " << "success" << r2::linefeed;
				}
				else
				{
					std::cout << "\t\t - " << "failed" << r2::linefeed;
				}

				{
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << r2::linefeed;

				{
					char* cp = static_cast<char*>( dp );
					++cp;

					dp = cp;
					space -= sizeof( char );

					std::cout << "\t" << "move" << r2::linefeed;
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << "\t" << "std::align( alignof( int ), sizeof( int ), dp, space )" << r2::linefeed;
				if( std::align( alignof( int ), sizeof( int ), dp, space ) )
				{
					std::cout << "\t\t - " << "success" << r2::linefeed;
				}
				else
				{
					std::cout << "\t\t - " << "failed" << r2::linefeed;
				}

				{
					std::cout << "\t\t - " << "adress of dp : " << dp << r2::linefeed;
					std::cout << "\t\t - " << "space size : " << space << r2::linefeed;
					std::cout << r2::linefeed;
				}
			}

			std::cout << r2::split;

			{
				char buffer[] = "------------------------";
				void * pt = buffer;

				std::cout << "\t + " << "orig : " << buffer << r2::linefeed;
				std::cout << "\t + " << "adress of pt : " << pt << r2::linefeed << r2::linefeed;

				std::cout << "\t + " << "Process" << r2::linefeed;

				std::size_t space = sizeof( buffer ) - 1;
				while( std::align( alignof( int ), sizeof( char ), pt, space ) )
				{
					std::cout << "\t\t - " << "old adress of pt : " << pt << r2::linefeed;

					if( !std::align( alignof( int ), sizeof( char ), pt, space ) )
					{
						break;
					}

					char* temp = static_cast<char*>( pt );
					*temp = '*';
					++temp;
					space -= sizeof( char );

					pt = temp;

					std::cout << "\t\t - " << "convert : " << buffer << r2::linefeed;
					std::cout << "\t\t - " << "new adress of pt : " << pt << r2::linefeed;
					std::cout << r2::linefeed;
				}

				std::cout << "\t" << "result : " << buffer << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}