#include "play_property.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

namespace play_property
{
	template<typename C, typename F>
	struct invoke_functor
	{
		F C::* f;

		invoke_functor( F C::* _f ) : f( _f )
		{}

		void Do( C* p )
		{
			( p->*f )( );
		}
	};

	r2tm::TitleFunctionT Functor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Property : Functor";
		};
	}
	r2tm::DoFunctionT Functor::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( struct InvokerFunctorTestStruct
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			} );

			std::cout << r2tm::split;

			DECLARATION_MAIN( InvokerFunctorTestStruct ts );

			std::cout << r2tm::split;

			{
				invoke_functor f( &InvokerFunctorTestStruct::Func );
				PROCESS_MAIN( f.Do( &ts ) );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}