#include "template_meta_programming_test.h"

#include <iostream>
#include <string>

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
		std::cout << 1 << std::endl;
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
	void CalculateFactorial::Do()
	{
		std::cout << "== TMP : Calculate Factorial ==" << std::endl;

		{
			std::cout << "\t" << "+ Factorial<2>::f" << std::endl;

			std::cout << "\t\t" << "calc : ";
			FactorialPrinter<2>();
			std::cout << "\t\t" << "result : " << Factorial<2>::f << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ Factorial<4>::f" << std::endl;

			std::cout << "\t\t" << "calc : ";
			FactorialPrinter<4>();
			std::cout << "\t\t" << "result : " << Factorial<4>::f << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ Factorial<10>::f" << std::endl;

			std::cout << "\t\t" << "calc : ";
			FactorialPrinter<10>();
			std::cout << "\t\t" << "result : " << Factorial<10>::f << std::endl;
		}

		std::cout << std::endl << std::endl;
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

	template<char... chars>
	struct ConvertCharacter2String_1
	{
		static constexpr size_t size = sizeof...( chars );
		static constexpr const char c[size + 1] = { chars..., '\0' };
	};
}
namespace template_meta_programming_test
{
	void Integer2String::Do()
	{
		std::cout << "== TMP : Integer 2 String ==" << std::endl;

		{
			std::cout << "\t" << "+ ConvertInteger2String_1<2>::c.c_str()" << std::endl;

			std::cout << "\t\t" << "result : " << ConvertInteger2String_1<2>::c.c_str() << std::endl;
		}

		std::cout << std::endl << std::endl;

		{
			std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::size" << std::endl;

			std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::size << std::endl;


			std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::c" << std::endl;

			std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::c << std::endl;
		}

		std::cout << std::endl << std::endl;
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
	void CalculatePlaceValue::Do()
	{
		std::cout << "== TMP : Calculate Place Value 4 Integer ==" << std::endl;

		{
			std::cout << "\t" << "+ CalculatePlaceValue<1>::c" << std::endl;
			std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<1>::place_value << std::endl;

			std::cout << "\t" << "+ CalculatePlaceValue<100>::c" << std::endl;
			std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<100>::place_value << std::endl;

			std::cout << "\t" << "+ CalculatePlaceValue<123456>::c" << std::endl;
			std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<123456>::place_value << std::endl;
		}

		std::cout << std::endl << std::endl;
	}
}





namespace
{
	template<int U>
	struct ConvertUnits2Character
	{
		static constexpr const char c = '0' + U;
	};

	template<int N>
	struct ConvertInteger2String_2
	{
		static constexpr size_t size = CalculatePlaceValue4Integer<N>::place_value;
	};
}
namespace template_meta_programming_test
{
	void Integer2String_II::Do()
	{
		std::cout << "== TMP : Units 2 Character ==" << std::endl;

		{
			std::cout << "\t" << "+ << ConvertUnits2Character<1>::c" << std::endl;

			std::cout << "\t\t" << "result : " << ConvertUnits2Character<1>::c << std::endl;


			std::cout << "\t" << "+ << ConvertUnits2Character<9>::c" << std::endl;

			std::cout << "\t\t" << "result : " << ConvertUnits2Character<9>::c << std::endl;


			std::cout << "\t" << "+ << ConvertUnits2Character<10>::c" << std::endl;

			std::cout << "\t\t" << "result : " << ConvertUnits2Character<10>::c << std::endl;
		}

		std::cout << std::endl << std::endl;

		std::cout << "== TMP : Integer 2 String II ==" << std::endl;

		{
			std::cout << "\t" << "+ ConvertInteger2String_2<101010>::size" << std::endl;
			std::cout << "\t\t" << "result : " << ConvertInteger2String_2<101010>::size << std::endl;
		}
	}
}
