#pragma once

#include <type_traits>

namespace play_template_meta_programming_01
{
	template<typename... Types>
	class Helper_TypePackage;

	template<>
	class Helper_TypePackage<>
	{};

	template<typename This_T, typename ... Rest_T>
	class Helper_TypePackage<This_T, Rest_T ...> : private Helper_TypePackage<Rest_T ...>
	{
	public:
		using ThisT = This_T;
		using BaseT = Helper_TypePackage<Rest_T...>;

		constexpr Helper_TypePackage() = default;

		template<class This_T2, class... Rest_T2>
		constexpr Helper_TypePackage( This_T2&& arg, Rest_T2&& ... args ) : BaseT( std::forward<Rest_T2>( args ) ... ), val( std::forward<This_T2>( arg ) )
		{}

		template<typename T>
		constexpr T& get_from_type()
		{
			if constexpr( std::is_same_v<T, ThisT> )
			{
				return val;
			}
			else
			{
				return BaseT::template get_from_type<T>();
			}
		}

		template<typename T>
		constexpr const T& get_from_type() const
		{
			if constexpr( std::is_same_v<T, ThisT> )
			{
				return val;
			}
			else
			{
				return BaseT::template get_from_type<T>();
			}
		}

		template<int N>
		constexpr auto& get_from_index()
		{
			if constexpr( 0 == N )
			{
				return val;
			}
			else
			{
				return BaseT::template get_from_index<N - 1>();
			}
		}

		template<int N>
		constexpr const auto& get_from_index() const
		{
			if constexpr( 0 == N )
			{
				return val;
			}
			else
			{
				return BaseT::template get_from_index<N - 1>();
			}
		}

	private:
		ThisT val;
	};
}