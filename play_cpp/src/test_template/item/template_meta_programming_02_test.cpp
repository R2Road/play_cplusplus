#include "template_meta_programming_02_test.h"

#include <string>

#include "r2tm/r2tm_ostream.h"

namespace template_meta_programming_test
{
	template<char... chars>
	struct ConvertCharacter2String_1
	{
		static constexpr size_t size = sizeof...( chars );
		static constexpr const char c[size + 1] = { chars..., '\0' };
	};

	r2tm::TitleFunctionT Character2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Character 2 String";
		};
	}
	r2tm::DoFunctionT Character2String::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::size" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::size << r2tm::linefeed;

				LF();

				std::cout << "\t" << "+ ConvertCharacter2String_1<'1', '2', '3'>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << ConvertCharacter2String_1<'1', '2', '3'>::c << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
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
	r2tm::TitleFunctionT Integer2String::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Integer 2 String";
		};
	}
	r2tm::DoFunctionT Integer2String::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "\t" << "+ ConvertInteger2String_1<2468>::c.c_str()" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << ConvertInteger2String_1<2468>::c.c_str() << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
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
	r2tm::TitleFunctionT CalculatePlaceValue::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Place Value 4 Integer";
		};
	}
	r2tm::DoFunctionT CalculatePlaceValue::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "\t" << "+ CalculatePlaceValue<1>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<1>::place_value << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ CalculatePlaceValue<100>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<100>::place_value << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ CalculatePlaceValue<123456>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << CalculatePlaceValue4Integer<123456>::place_value << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
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

	// 위의 ConvertInteger2String_2 의 전방 선언 코드를 지우고 가장 아래의 템플릿 코드를 가장 위로 올려도 정상 작동 한다.
	// 전방 선언은 템플릿 코드의 번역 순서에 따라 발생하는 문제를 해결해준다.
}
namespace template_meta_programming_test
{
	r2tm::TitleFunctionT Integer2String_II::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Integer 2 String II";
		};
	}
	r2tm::DoFunctionT Integer2String_II::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			{
				std::cout << "+ Units 2 Character" << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ ConvertUnits2Character<1>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<1>::c << r2tm::linefeed << r2tm::linefeed;


				std::cout << "\t" << "+ ConvertUnits2Character<9>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<9>::c << r2tm::linefeed << r2tm::linefeed;


				std::cout << "\t" << "+ ConvertUnits2Character<10>::c" << r2tm::linefeed;
				std::cout << "\t\t" << "result : " << ConvertUnits2Character<10>::c << r2tm::linefeed << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "+ Integer 2 String II" << r2tm::linefeed << r2tm::linefeed;

				std::cout << "\t" << "+ ConvertInteger2String_2<101010>" << r2tm::linefeed;
				std::cout << "\t\t" << "size : " << ConvertInteger2String_2<101010>::size << r2tm::linefeed;
				std::cout << "\t\t" << "string : " << ConvertInteger2String_2<101010>::str << r2tm::linefeed;
			}

			LS();

			{
				std::cout << "ConvertInteger2String_2 의 전방 선언 코드를 지우고 가장 아래의 템플릿 코드를 가장 위로 올려도 정상 작동 한다." << r2tm::linefeed;
				std::cout << "전방 선언은 템플릿 코드의 번역 순서에 따라 발생하는 문제를 해결해준다." << r2tm::linefeed;
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
