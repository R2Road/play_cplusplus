#include "std_memory_test.h"
#include "std_memory_test_helper_up_and_forward_declaration.h"

#include <memory>
#include <utility>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace std_memory_test
{
	r2cm::iItem::TitleFunctionT SharedPointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Shared Pointer";
		};
	}
	r2cm::iItem::DoFunctionT SharedPointer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( std::shared_ptr<int> test_sp( new int( 10 ) ) );
				OUTPUT_VALUE( *test_sp );
			}

			std::cout << r2cm::split;
			
			{
				OUTPUT_NOTE( "const sp 는 [* const] 에 가깝다." );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( std::shared_ptr<int> sp1( new int( 10 ) ) );
				DECLARATION_MAIN( const auto sp2 = sp1 );
				OUTPUT_CODE( sp2 = nullptr );
				OUTPUT_COMMENT( "지정된 pointer 변경 불가." );

				std::cout << r2cm::linefeed;

				PROCESS_MAIN( *sp2 = 11 );
				OUTPUT_VALUE( *sp2 );
				OUTPUT_COMMENT( "값 변경 가능" );
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Shared Pointer Has Const Value" << r2cm::linefeed << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Make Sp Has Const Value" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "std::shared_ptr<const int> test_sp( new int( 10 ) )" << r2cm::linefeed;
				std::shared_ptr<const int> const_test_sp( new int( 10 ) );

				std::cout << r2cm::tab4 << "- Print : " << *const_test_sp << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				std::cout << r2cm::tab2 << "- Failed : Change Value" << r2cm::linefeed;
				std::cout << r2cm::linefeed;

				//*const_test_sp = 11;
				//std::cout << r2cm::tab << "+ Change Value with Sp Has Const Value" << r2cm::linefeed;
				//std::cout << r2cm::tab2 << *const_test_sp << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			{
				std::cout << r2cm::tab << "+ Make Shared" << r2cm::linefeed << r2cm::linefeed;

				std::cout << r2cm::tab2 << "auto test_sp = std::make_shared<int>( 10 );" << r2cm::linefeed;
				auto test_sp = std::make_shared<int>( 10 );

				std::cout << r2cm::tab3 << "- Print : " << *test_sp << r2cm::linefeed;
				std::cout << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}



namespace std_memory_test
{
	r2cm::iItem::TitleFunctionT UniquePointer::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unique Pointer";
		};
	}
	r2cm::iItem::DoFunctionT UniquePointer::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				auto test_up = std::unique_ptr<int>( new int( 3 ) );

				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto test_up = std::unique_ptr<int>( new int( 3 ) );" << r2cm::linefeed;


				std::cout << r2cm::linefeed;


				//auto test_up_2 = test_up;

				std::cout << r2cm::tab << "+ Move : Failed" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto test_up_2 = test_up;" << r2cm::linefeed;


				std::cout << r2cm::linefeed;


				auto test_up_2 = std::move( test_up );

				std::cout << r2cm::tab << "+ Move : Success" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "auto test_up_2 = std::move( test_up );" << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT UniquePointer_FowardDeclaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Unique Pointer : Forward Declaration";
		};
	}
	r2cm::iItem::DoFunctionT UniquePointer_FowardDeclaration::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				std_memory_test_helper_up_and_forward_declaration::Processor p;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}