#include "cpp_class_private_inheritance_test.h"
#include "cpp_class_test_helper_nvi.hpp"
#include "cpp_class_private_inheritance_test_helper_demo1.hpp"
#include "cpp_class_private_inheritance_test_helper_ienum.hpp"
#include "cpp_class_private_inheritance_test_helper_pure_virtual_interface.hpp"
#include "cpp_class_private_inheritance_test_helper_virtual_interface.hpp"

#include <iterator>
#include <numeric>
#include <string>

#include "r2tm/r2tm_ostream.h"
#include "r2tm/r2tm_Inspector.h"

namespace cpp_class_private_inheritance_test
{
	r2tm::TitleFunctionT VirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Virtual Interface";
		};
	}
	r2tm::DoFunctionT VirtualInterface::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_virtual_interface.hpp" );

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_virtual_interface::VP_Private t );
				PROCESS_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_virtual_interface::VP_Protected t );
				PROCESS_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_virtual_interface::VP_Public t );
				PROCESS_MAIN( t.DoProcess() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PureVirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Pure Virtual Interface";
		};
	}
	r2tm::DoFunctionT PureVirtualInterface::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_pure_virtual_interface.hpp" );

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_pure_virtual_interface::PVP_Private t );
				PROCESS_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_pure_virtual_interface::PVP_Protected t );
				PROCESS_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_pure_virtual_interface::PVP_Public t );
				PROCESS_MAIN( t.DoProcess() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Demo1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Demo 1";
		};
	}
	r2tm::DoFunctionT Demo1::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_demo1.hpp" );

			LS();

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_demo1::T t );
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_demo1::iPublic* pt = &t );
				PROCESS_MAIN( pt->Do() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Using::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Using";
		};
	}
	r2tm::DoFunctionT Using::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			DECLARATION_MAIN( class iPrivate
			{
			public:
				void Do() {}
				int i = 10;
			} );

			DECLARATION_MAIN( class T1 : private iPrivate
			{
			} );

			DECLARATION_MAIN( class T2 : private iPrivate
			{
			public:
				using iPrivate::Do;
				using iPrivate::i;
			} );

			LS();

			{
				OUTPUT_CODE( T1().Do() );
				OUTPUT_COMMENT( "Not Working" );
				OUTPUT_CODE( T1().i );
				OUTPUT_COMMENT( "Not Working" );
			}

			LS();

			{
				PROCESS_MAIN( T2().Do() );
				OUTPUT_VALUE( T2().i );
			}

			LS();

			OUTPUT_NOTE( "private 상속한 멤버를 using 으로 열어줄 수 있다." );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT PrivateInheritance_iEnum::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : iEnum";
		};
	}
	r2tm::DoFunctionT PrivateInheritance_iEnum::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_ienum.hpp" );

			LS();

			{
				OUTPUT_VALUE( sizeof( cpp_class_private_inheritance_test_helper_ienum::iEnum ) );
				OUTPUT_VALUE( sizeof( cpp_class_private_inheritance_test_helper_ienum::T ) );

				LF();

				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_ienum::T t );
				OUTPUT_VALUE( t.Do() );
			}

			LS();

			OUTPUT_NOTE( "굳이 이런 짓을 해야만 하는가?" );

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT NoneVirtualInterface::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : NVI( None Virtual Interface )";
		};
	}
	r2tm::DoFunctionT NoneVirtualInterface::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_test_helper_nvi.hpp" );

			LS();

			{
				DECLARATION_MAIN( cpp_class_test_helper_nvi::D1 d1 );
				OUTPUT_VALUE( d1.Do() );
			}

			LS();

			{
				DECLARATION_MAIN( cpp_class_test_helper_nvi::D2 d2 );
				OUTPUT_VALUE( d2.Do() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

}