#include "cpp_class_private_inheritance_test.h"
#include "cpp_class_test_helper_nvi.hpp"
#include "cpp_class_private_inheritance_test_helper_demo1.hpp"
#include "cpp_class_private_inheritance_test_helper_ienum.hpp"
#include "cpp_class_private_inheritance_test_helper_pure_virtual_interface.hpp"
#include "cpp_class_private_inheritance_test_helper_virtual_interface.hpp"

#include <iterator>
#include <numeric>
#include <string>

#include "r2cm/r2cm_ostream.h"
#include "r2cm/r2cm_Inspector.h"

namespace cpp_class_private_inheritance_test
{
	r2cm::iItem::TitleFunctionT VirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Virtual Interface";
		};
	}
	r2cm::iItem::DoFunctionT VirtualInterface::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_virtual_interface.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_virtual_interface::VP_Private t );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_virtual_interface::VP_Protected t );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_virtual_interface::VP_Public t );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PureVirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Pure Virtual Interface";
		};
	}
	r2cm::iItem::DoFunctionT PureVirtualInterface::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_pure_virtual_interface.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_pure_virtual_interface::PVP_Private t );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_pure_virtual_interface::PVP_Protected t );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_pure_virtual_interface::PVP_Public t );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PrivateInheritance_Demo1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Demo 1";
		};
	}
	r2cm::iItem::DoFunctionT PrivateInheritance_Demo1::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_demo1.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_demo1::T t );
				PROCESS_MAIN( t.Do() );
				PROCESS_MAIN( t.DoProcess() );
			}

			std::cout << r2cm::split;

			OUTPUT_NOTE( "mmm.... not good ( '_')y-~" );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PrivateInheritance_2::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance 2";
		};
	}
	r2cm::iItem::DoFunctionT PrivateInheritance_2::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			class iPrivateInheritance
			{
			public:
				virtual void Do()
				{
					std::cout << "Call : TestChild::DoProcess()" << r2cm::linefeed;
				}
			};
			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			std::cout << r2cm::tab2 << "class iPrivateInheritance" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "virtual void Do() = 0;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "{" << r2cm::linefeed;
			std::cout << r2cm::tab4 << "std::cout << \"Call : TestChild::DoProcess()\" << r2cm::linefeed;" << r2cm::linefeed;
			std::cout << r2cm::tab3 << "}" << r2cm::linefeed;
			std::cout << r2cm::tab2 << "}" << r2cm::linefeed;

			std::cout << r2cm::split;

			{
				class TestChild_1 : private iPrivateInheritance
				{
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestChild_1 : private iPrivateInheritance" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				std::cout << r2cm::tab << "+ Call" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "TestChild_1().Do();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> " << " Not Working : Do is Private";
				//TestChild_1.Do();
			}

			std::cout << r2cm::split;

			{
				class TestChild_2 : private iPrivateInheritance
				{
				public:
					using iPrivateInheritance::Do;
				};
				std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "class TestChild_2 : private iPrivateInheritance" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "{" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "public:" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "using iPrivateInheritance::Do;" << r2cm::linefeed;
				std::cout << r2cm::tab2 << "}" << r2cm::linefeed;


				std::cout << r2cm::linefeed2;


				std::cout << r2cm::tab << "+ Call" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "- " << "TestChild_2().Do();" << r2cm::linefeed;
				std::cout << r2cm::tab3 << "> ";
				TestChild_2().Do();
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT PrivateInheritance_iEnum::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : iEnum";
		};
	}
	r2cm::iItem::DoFunctionT PrivateInheritance_iEnum::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_ienum.hpp" );

			std::cout << r2cm::split;

			{
				OUTPUT_VALUE( sizeof( cpp_class_private_inheritance_test_helper_ienum::iEnum ) );
				OUTPUT_VALUE( sizeof( cpp_class_private_inheritance_test_helper_ienum::T ) );

				std::cout << r2cm::linefeed;

				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_ienum::T t );
				OUTPUT_VALUE( t.Do() );
			}

			std::cout << r2cm::split;

			OUTPUT_NOTE( "굳이 이런 짓을 해야만 하는가?" );

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT NoneVirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : NVI( None Virtual Interface )";
		};
	}
	r2cm::iItem::DoFunctionT NoneVirtualInterface::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_nvi.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_test_helper_nvi::D1 d1 );
				OUTPUT_VALUE( d1.Do() );
			}

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_test_helper_nvi::D2 d2 );
				OUTPUT_VALUE( d2.Do() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

}