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
			LS();

			DECLARATION_MAIN( struct InvokerFunctorTestStruct
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			} );

			LS();

			DECLARATION_MAIN( InvokerFunctorTestStruct ts );

			LS();

			{
				invoke_functor f( &InvokerFunctorTestStruct::Func );
				PROCESS_MAIN( f.Do( &ts ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}