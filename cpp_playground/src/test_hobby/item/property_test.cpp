#include "property_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace property_test
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

	r2cm::iItem::TitleFunctionT Functor::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Property : Functor";
		};
	}
	r2cm::iItem::DoFunctionT Functor::GetDoFunction()
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( struct InvokerFunctorTestStruct
			{
				void Func() { printf( "\t" "> " "[Call] Func" "\n" ); }
			} );

			std::cout << r2cm::split;

			DECLARATION_MAIN( InvokerFunctorTestStruct ts );

			std::cout << r2cm::split;

			{
				invoke_functor f( &InvokerFunctorTestStruct::Func );
				PROCESS_MAIN( f.Do( &ts ) );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}