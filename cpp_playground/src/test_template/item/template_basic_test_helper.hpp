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
	void V_0() { puts( "void V_0()" ); }

	int R_0() { puts( "int R_0()" ); return 0; }

	int R_2( int x, int y ) { puts( "int R_0()" ); return x + y; }

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