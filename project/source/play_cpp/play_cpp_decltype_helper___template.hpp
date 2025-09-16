#pragma once

namespace play_cpp_decltype
{
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
}