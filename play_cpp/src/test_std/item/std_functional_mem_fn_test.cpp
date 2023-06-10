#include "std_functional_mem_fn_test.h"
#include "std_functional_mem_fn_test_helper.hpp"

#include <functional>

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace std_functional_mem_fn_test
{
	//template<class _Callable,
	//	class _Ty1,
	//	class _Decayed = typename std::decay<_Callable>::type,
	//	bool _Is_pmf = std::is_member_function_pointer<_Decayed>::value,
	//	bool _Is_pmd = std::is_member_object_pointer<_Decayed>::value>
	//	struct _Invoker1;



	//template<class _Callable,

	//	class _Ty1,

	//	class _Decayed>

	//	struct _Invoker1<_Callable, _Ty1, _Decayed, true, false>

	//	: std::_If<is_base_of<

	//	typename std::_Is_memfunptr<_Decayed>::_Class_type,

	//	typename std::decay<_Ty1>::type>::value,

	//	_Invoker_pmf_object,

	//	_Invoker_pmf_pointer>::type

	//{        // pointer to member function

	//};



	//template<class _Callable,

	//	class _Ty1,

	//	class _Decayed>

	//	struct _Invoker1<_Callable, _Ty1, _Decayed, false, true>

	//	: _If<is_base_of<

	//	typename _Is_member_object_pointer<_Decayed>::_Class_type,

	//	typename decay<_Ty1>::type>::value,

	//	_Invoker_pmd_object,

	//	_Invoker_pmd_pointer>::type

	//{        // pointer to member data

	//};



	//template<class _Callable,

	//	class _Ty1,

	//	class _Decayed>

	//	struct _Invoker1<_Callable, _Ty1, _Decayed, false, false>

	//	: _Invoker_functor

	//{        // function object

	//};

	//struct _Invoker_functor

	//{        // INVOKE a function object

	//	template<class _Callable, class... _Types>
	//	static auto _Call( _Callable&& _Obj, _Types&&... _Args )
	//	{        // INVOKE a function object

	//		return ( _STD forward<_Callable>( _Obj )(

	//			_STD forward<_Types>( _Args )... ) );

	//	}

	//};
	//template<class _Callable>
	//struct _Invoker : _Invoker_functor // zero arguments
	//{};

	//template<class _Callable, class _Ty1, class... _Types2>
	//struct _Invoker : _Invoker1<_Callable, _Ty1> // one or more arguments
	//{};


	//template<class _Callable, class... _Types> inline
	//auto invoke( _Callable&& _Obj, _Types&&... _Args ) // INVOKE a callable object
	//{
	//	return ( _Invoker<_Callable, _Types...>::_Call(
	//		std::forward<_Callable>( _Obj ), std::forward<_Types>( _Args )... )
	//	);
	//}

	void TT()
	{
		std::cout << "asdf\n";
	}

	r2tm::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "std::mem_fn : Basic";
		};
	}
	r2tm::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_FILE( "src/test_std/item/std_functional_mem_fn_test_helper.hpp" );

			LS();

			DECLARATION_MAIN( TestStruct t );
			PROCESS_MAIN( t.a = 123 );

			LS();

			{
				DECLARATION_MAIN( auto do_fn =  std::mem_fn( &TestStruct::Do ) );
				OUTPUT_VALUE( sizeof( do_fn ) );

				std::cout << r2tm::linefeed;

				PROCESS_MAIN( do_fn( &t ) );
			}

			LS();

			{
				DECLARATION_MAIN( auto do_mv = std::mem_fn( &TestStruct::a ) );
				OUTPUT_VALUE( sizeof( do_mv ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( do_mv( &t ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}