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
	const r2::iNode::TitleFunc CalculateFactorial::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Factorial";
		};
	}
	const r2::iNode::DoFunc CalculateFactorial::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ Factorial<2>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<2>();
				std::cout << "\t\t" << "result : " << Factorial<2>::f << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ Factorial<4>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<4>();
				std::cout << "\t\t" << "result : " << Factorial<4>::f << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ Factorial<10>::f" << r2::linefeed;

				std::cout << "\t\t" << "calc : ";
				FactorialPrinter<10>();
				std::cout << "\t\t" << "result : " << Factorial<10>::f << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}





namespace template_meta_programming_test
{
	template<char... chars>
	struct ConvertCharacter2String_1
	{
		static constexpr size_t size = sizeof...( chars );
		static constexpr const char c[size + 1] = { chars..., '\0' };
	};

	const r2::iNode::TitleFunc Character2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Character 2 String";
		};
	}
	const r2::iNode::DoFunc Character2String::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::size" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::size << r2::linefeed;

				std::cout << r2::linefeed;

				std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::c << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}





namespace
{
	template<int N>
	struct ConvertInteger2String_1
	{
		static std::string c;
	};
	template<int N> std::string ConvertInteger2String_1<N>::c = std::to_string( N );
}
namespace template_meta_programming_test
{
	const r2::iNode::TitleFunc Integer2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Integer 2 String";
		};
	}
	const r2::iNode::DoFunc Integer2String::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ ConvertInteger2String_1<2468>::c.c_str()" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertInteger2String_1<2468>::c.c_str() << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}




namespace
{
	template<int N>
	struct CalculatePlaceValue4Integer
	{
		static constexpr size_t place_value = ( N > 0 ? 1 : 0 ) + CalculatePlaceValue4Integer<N / 10>::place_value;
	};
	template<>
	struct CalculatePlaceValue4Integer<0>
	{
		static constexpr size_t place_value = 0;
	};
}
namespace template_meta_programming_test
{
	const r2::iNode::TitleFunc CalculatePlaceValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Place Value 4 Integer";
		};
	}
	const r2::iNode::DoFunc CalculatePlaceValue::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed << r2::linefeed;

			{
				std::cout << "\t" << "+ CalculatePlaceValue<1>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<1>::place_value << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ CalculatePlaceValue<100>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<100>::place_value << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ CalculatePlaceValue<123456>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<123456>::place_value << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}





namespace
{
	template<int U>
	struct ConvertUnits2Character
	{
		static constexpr const char c = '0' + U;
	};


	template<int N, char... Chars>
	struct ConvertInteger2String_2;

	template<char... Chars>
	struct ConvertInteger2String_2<0, Chars...>
	{
		static constexpr size_t size = ( sizeof...( Chars ) ) + 8 + 1;
		static constexpr const char c[size] = { Chars..., ' ', 'M', 'O', 'O', 'Y', 'A', 'H', 'O', '\0' };
		static constexpr const char* str = c;
	};

	template<int N, char... Chars>
	struct ConvertInteger2String_2
	{
		static constexpr size_t size = ConvertInteger2String_2<N / 10, ConvertUnits2Character<N % 10>::c, Chars...>::size;
		static constexpr const char* str = ConvertInteger2String_2<N / 10, ConvertUnits2Character<N % 10>::c, Chars...>::str;
	};
}
namespace template_meta_programming_test
{
	const r2::iNode::TitleFunc Integer2String_II::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Integer 2 String II";
		};
	}
	const r2::iNode::DoFunc Integer2String_II::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			{
				std::cout << "# TMP : Units 2 Character #" << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ ConvertUnits2Character<1>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<1>::c << r2::linefeed << r2::linefeed;


				std::cout << "\t" << "+ ConvertUnits2Character<9>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<9>::c << r2::linefeed << r2::linefeed;


				std::cout << "\t" << "+ ConvertUnits2Character<10>::c" << r2::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<10>::c << r2::linefeed << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			{
				std::cout << "# TMP : Integer 2 String II #" << r2::linefeed << r2::linefeed;

				std::cout << "\t" << "+ ConvertInteger2String_2<101010>" << r2::linefeed;
				std::cout << "\t\t" << "size : " << ConvertInteger2String_2<101010>::size << r2::linefeed;
				std::cout << "\t\t" << "string : " << ConvertInteger2String_2<101010>::str << r2::linefeed;
			}

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
	const r2::iNode::TitleFunc MultiTypePackage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TMP : Multi Type Package";
		};
	}
	const r2::iNode::DoFunc MultiTypePackage::GetDoFunction() const
	{
		return []()->r2::eTestResult
		{
			{
				std::cout << "# TMP : Multi Type Package #" << r2::linefeed;

				std::cout << "\t" << "+ MTPackage<int, float, char> mtp;" << r2::linefeed;

				MTPackage<int, float, char> mtp{ 1, 2.f, '3' };

				std::cout << "\t\t" << "result : " << mtp.val << r2::linefeed;
			}

			std::cout << r2::linefeed << r2::linefeed;

			return r2::eTestResult::RunTest;
		};
	}
}
