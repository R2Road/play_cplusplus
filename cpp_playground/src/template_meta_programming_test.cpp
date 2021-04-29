#include "pch.h"
#include "template_meta_programming_test.h"

#include <string>

#include "r2_eTestResult.h"

namespace
{
	template<int N>
	void FactorialPrinter()
	{
		std::cout << N << " * ";
		FactorialPrinter<N - 1>();
	};

	template<>
	void FactorialPrinter<1>()
	{
		std::cout << 1 << r2::linefeed;
	};


	template<int N>
	struct Factorial
	{
		static const int f = N * Factorial<N - 1>::f;
	};

	template<>
	struct Factorial<1>
	{
		static const int f = 1;
	};
}
namespace template_meta_programming_test
{
	const r2::iTest::TitleFunc CalculateFactorial::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Factorial";
		};
	}
	const r2::iTest::DoFunc CalculateFactorial::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Factorial<2>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<2>();
				std::cout << "\t\t" << "result : " << Factorial<2>::f << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Factorial<4>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<4>();
				std::cout << "\t\t" << "result : " << Factorial<4>::f << r2::linefeed;
			}

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ Factorial<10>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<10>();
				std::cout << "\t\t" << "result : " << Factorial<10>::f << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}





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
	const r2::iTest::TitleFunc MultiTypePackage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Multi Type Package( In Progress )";
		};
	}
	const r2::iTest::DoFunc MultiTypePackage::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()( ) << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				std::cout << "\t" << "+ MTPackage<int, float, char> mtp{ 1, 2.f, '3' };" << r2::linefeed;

				MTPackage<int, float, char> mtp{ 1, 2.f, '3' };

				std::cout << "\t\t" << "result : " << mtp.val << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestResult::RunTest;
		};
	}
}
