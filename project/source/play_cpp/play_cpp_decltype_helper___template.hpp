#pragma once

namespace play_cpp_decltype
{
	//
	// C++ 14에 도입된 반환 타입 추론을 사용하는 함수
	//

	template<typename T, typename U>
	auto lambda_func_1( T t, U u ) -> decltype( t + u )
	{
		return t + u;
	}

	template<typename T, typename U>
	auto lambda_func_2( T t, U u ) -> auto
	{
		return t + u;
	}

	template<typename T, typename U>
	auto lambda_func_3( T t, U u )
	{
		return t + u;
	}
}