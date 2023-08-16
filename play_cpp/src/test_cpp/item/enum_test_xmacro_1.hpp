namespace enum_test_xmacro_1
{

#define X_ENUMS				\
		X( XM1_First ),		\
		X( XM1_Second ),	\
		X( XM1_Third ),		\
		X( XM1_Max ),

	enum eTestEnum4XM1
	{
#define X( e ) e
		X_ENUMS
#undef X
	};

	const char* STR_TestEnum4XM1[] = {
#define X( e ) #e
		X_ENUMS
#undef X
	};

}