namespace cpp_class_test_helper_braces_2
{
	template<typename T>
	struct TS_1
	{
		int a;
		int b;
	};

	template<typename T>
	struct TS_2
	{
		TS_2( int _a, int _b ) : a( _a ), b( _b ) {}

		int a;
		int b;
	};

	template<typename T>
	struct TS_3
	{
		explicit TS_3( int _a, int _b ) : a( _a ), b( _b ) {}

		int a;
		int b;
	};
}