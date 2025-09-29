#pragma once

namespace play_template_type_extract
{
	template<typename T>
	struct Helper___TypeExtracter___FunctionPointer;



	template<typename Return_T, typename Owner_T, typename ... Arguments_T>
	struct Helper___TypeExtracter___FunctionPointer<Return_T ( Owner_T::* )( Arguments_T ... )>
	{
		using ReturnT = Return_T;
		using OwnerT = Owner_T;
		using PointerT = Return_T( OwnerT::* )( Arguments_T ... );
	};

	template<typename Return_T, typename Owner_T, typename ... Arguments_T>
	struct Helper___TypeExtracter___FunctionPointer<Return_T ( Owner_T::* )( Arguments_T ... ) const>
	{
		using ReturnT = Return_T;
		using OwnerT = Owner_T;
		using PointerT = Return_T( OwnerT::* )( Arguments_T ... );
	};



	template<typename Return_T, typename ... Arguments_T>
	struct Helper___TypeExtracter___FunctionPointer<Return_T (*)( Arguments_T ... )>
	{
		using ReturnT = Return_T;
		using PointerT = Return_T(*)( Arguments_T ... );
	};
}