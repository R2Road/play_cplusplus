#include "template_meta_programming_03_test.h"

#include "r2tm/r2tm_ostream.h"

namespace
{
	template<typename... Types>
	class MTPackage;

	template<>
	class MTPackage<>
	{};

	template<typename _This, typename... _Rest>
	class MTPackage<_This, _Rest...> : private MTPackage<_Rest...>
	{
	public:
		using ThisT = _This;
		using BaseT = MTPackage<_Rest...>;

		constexpr MTPackage() : BaseT(), val() {}

		template<class _This2, class... _Rest2>
		constexpr MTPackage( _This2 arg, _Rest2... args ) : BaseT( args... ), val( arg ) {}

		ThisT val;
	};
}
namespace template_meta_programming_test
{
	r2tm::TitleFunctionT MultiTypePackage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Multi Type Package( In Progress )";
		};
	}
	r2tm::DoFunctionT MultiTypePackage::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				std::cout << "\t" << "+ MTPackage<int, float, char> mtp{ 1, 2.f, '3' };" << r2tm::linefeed;

				MTPackage<int, float, char> mtp{ 1, 2.f, '3' };

				std::cout << "\t\t" << "result : " << mtp.val << r2tm::linefeed;
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
