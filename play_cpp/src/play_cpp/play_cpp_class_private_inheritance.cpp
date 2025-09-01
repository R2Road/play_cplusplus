#include "play_cpp_class_private_inheritance.hpp"
#include "play_cpp_class_helper___nvi.hpp"
#include "play_cpp_class_private_inheritance_helper___demo1.hpp"
#include "play_cpp_class_private_inheritance_helper___ienum.hpp"
#include "play_cpp_class_private_inheritance_helper___pure_virtual_interface.hpp"
#include "play_cpp_class_private_inheritance_helper___virtual_interface.hpp"

#include <iterator>
#include <numeric>
#include <string>

#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_inspector.hpp"

namespace play_cpp_class_private_inheritance
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

			OUT_FILE( "src/play_cpp/play_cpp_class_private_inheritance_helper___virtual_interface.hpp" );

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___virtual_interface::VP_Private t );
				PROC_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___virtual_interface::VP_Protected t );
				PROC_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___virtual_interface::VP_Public t );
				PROC_MAIN( t.DoProcess() );
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

			OUT_FILE( "src/play_cpp/play_cpp_class_private_inheritance_helper___pure_virtual_interface.hpp" );

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___pure_virtual_interface::PVP_Private t );
				PROC_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___pure_virtual_interface::PVP_Protected t );
				PROC_MAIN( t.DoProcess() );
			}

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___pure_virtual_interface::PVP_Public t );
				PROC_MAIN( t.DoProcess() );
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

			OUT_FILE( "src/play_cpp/play_cpp_class_private_inheritance_helper___demo1.hpp" );

			LS();

			{
				DECL_MAIN( play_cpp_class_private_inheritance_helper___demo1::T t );
				DECL_MAIN( play_cpp_class_private_inheritance_helper___demo1::iPublic* pt = &t );
				PROC_MAIN( pt->Do() );
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

			DECL_MAIN( class iPrivate
			{
			public:
				void Do() {}
				int i = 10;
			} );

			DECL_MAIN( class T1 : private iPrivate
			{
			} );

			DECL_MAIN( class T2 : private iPrivate
			{
			public:
				using iPrivate::Do;
				using iPrivate::i;
			} );

			LS();

			{
				OUT_CODE( T1().Do() );
				OUT_COMMENT( "Not Working" );
				OUT_CODE( T1().i );
				OUT_COMMENT( "Not Working" );
			}

			LS();

			{
				PROC_MAIN( T2().Do() );
				OUT_VALUE( T2().i );
			}

			LS();

			OUT_NOTE( "private 상속한 멤버를 using 으로 열어줄 수 있다." );

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

			OUT_FILE( "src/play_cpp/play_cpp_class_private_inheritance_helper___ienum.hpp" );

			LS();

			{
				OUT_VALUE( sizeof( play_cpp_class_private_inheritance_helper___ienum::iEnum ) );
				OUT_VALUE( sizeof( play_cpp_class_private_inheritance_helper___ienum::T ) );

				LF();

				DECL_MAIN( play_cpp_class_private_inheritance_helper___ienum::T t );
				OUT_VALUE( t.Do() );
			}

			LS();

			OUT_NOTE( "굳이 이런 짓을 해야만 하는가?" );

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

			OUT_FILE( "src/play_cpp/play_cpp_class_helper___nvi.hpp" );

			LS();

			{
				DECL_MAIN( play_cpp_class_helper___nvi::D1 d1 );
				OUT_VALUE( d1.Do() );
			}

			LS();

			{
				DECL_MAIN( play_cpp_class_helper___nvi::D2 d2 );
				OUT_VALUE( d2.Do() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}

}