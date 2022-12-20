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

	class Package : public State
	{
	public:
		Package() : mStateContainer()
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
	r2cm::iItem::TitleFunctionT Package_Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Package_Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Package p );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT Package_Add::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "fsm v1 : Package - Add";
		};
	}
	r2cm::iItem::DoFunctionT Package_Add::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( Package p );
				DECLARATION_MAIN( TestState* s = p.Add<TestState>() );
				OUTPUT_VALUE( s->i );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}