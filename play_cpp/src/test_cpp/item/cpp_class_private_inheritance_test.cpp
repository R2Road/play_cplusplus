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
	r2cm::iItem::DoFunctionT VirtualInterface::GetDoFunction() const
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
	r2cm::iItem::DoFunctionT PureVirtualInterface::GetDoFunction() const
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



	r2cm::iItem::TitleFunctionT Demo1::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Demo 1";
		};
	}
	r2cm::iItem::DoFunctionT Demo1::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			OUTPUT_FILE( "src/test_cpp/item/cpp_class_private_inheritance_test_helper_demo1.hpp" );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_demo1::T t );
				DECLARATION_MAIN( cpp_class_private_inheritance_test_helper_demo1::iPublic* pt = &t );
				PROCESS_MAIN( pt->Do() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Using::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Class : Private Inheritance : Using";
		};
	}
	r2cm::iItem::DoFunctionT Using::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

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

			std::cout << r2cm::split;

			{
				OUTPUT_CODE( T1().Do() );
				OUTPUT_COMMENT( "Not Working" );
				OUTPUT_CODE( T1().i );
				OUTPUT_COMMENT( "Not Working" );
			}

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( T2().Do() );
				OUTPUT_VALUE( T2().i );
			}

			std::cout << r2cm::split;

			OUTPUT_NOTE( "private ����� ����� using ���� ������ �� �ִ�." );

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
	r2cm::iItem::DoFunctionT PrivateInheritance_iEnum::GetDoFunction() const
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

			OUTPUT_NOTE( "���� �̷� ���� �ؾ߸� �ϴ°�?" );

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
	r2cm::iItem::DoFunctionT NoneVirtualInterface::GetDoFunction() const
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