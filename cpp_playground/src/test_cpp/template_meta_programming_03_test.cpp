#include "pch.h"
#include "template_meta_programming_03_test.h"

#include "base/r2cm_eTestEndAction.h"

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
	r2cm::iItem::TitleFuncT MultiTypePackage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Multi Type Package( In Progress )";
		};
	}
	r2cm::iItem::DoFuncT MultiTypePackage::GetDoFunction()
	{
		return []()->r2cm::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ MTPackage<int, float, char> mtp{ 1, 2.f, '3' };" << r2::linefeed;

				MTPackage<int, float, char> mtp{ 1, 2.f, '3' };

				std::cout << "\t\t" << "result : " << mtp.val << r2::linefeed;
			}

			std::cout << r2::split;

			return r2cm::eTestEndAction::Pause;
		};
	}
}
