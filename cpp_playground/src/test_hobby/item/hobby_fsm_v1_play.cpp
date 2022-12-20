#include "hobby_fsm_v1_play.h"

#include <memory>
#include <vector>

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	class State
	{
	};
	class Machine
	{
	public:
		Machine() : mStateContainer()
		{}

		template<typename T>
		T* Add()
		{
			std::unique_ptr<T> up = std::make_unique<T>();
			T* ret = up.get();

			mStateContainer.emplace_back( std::move( up ) );

			return ret;
		}

	private:
		using StateUp = std::unique_ptr<State>;
		using StateContainer = std::vector<StateUp>;
		StateContainer mStateContainer;
	};
}

namespace
{
	class TestState : public State
	{
	public:
		int i = 10;
	};
}

namespace hobby_fsm_v1_play
{
	r2cm::iItem::TitleFunctionT Machine_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Machine - Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Machine_Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Machine m );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Machine_Add::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Machine - Add";
		};
	}
	r2cm::iItem::DoFunctionT Machine_Add::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Machine m );
				DECLARATION_MAIN( TestState* s = m.Add<TestState>() );
				OUTPUT_VALUE( s->i );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}