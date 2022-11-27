namespace template_basic_test
{
	template<typename T>
	struct MemberVariableTest_01
	{
		T t;
	};

	template<typename T1, typename T2>
	struct MemberVariableTest_02
	{
		T1 t1;
		T2 t2;
	};
}

namespace template_basic_test
{
	template<typename ReturnValueT>
	ReturnValueT R_()
	{
		return ReturnValueT();
	}

	template<typename ReturnValueT>
	ReturnValueT R_R1( ReturnValueT a1 )
	{
		return ReturnValueT( a1 );
	}

	template<typename ReturnValueT, typename ArgumentT1>
	ReturnValueT R_A1( ArgumentT1 a1 )
	{
		return ReturnValueT( a1 );
	}
}

namespace template_basic_test
{
	void FN_V_0() { puts( "void FN_V_0()" ); }

	int FN_R_0() { puts( "int FN_R_0()" ); return 0; }

	int FN_R_2( int x, int y ) { puts( "int FN_R_0()" ); return x + y; }

	template<typename Ret, typename ... Param>
	class FunctionTest_01
	{
	public:
		FunctionTest_01( Ret( *f )( Param... ) ) : mF( f )
		{}

		Ret operator()( Param... param )
		{
			return mF( param... );
		}

	private:
		Ret( *mF )( Param... );
	};
}