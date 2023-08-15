namespace enum_test_make_enum_with_macro
{
	#define MAKE_ENUM( enum_name, ... ) enum enum_name { __VA_ARGS__ };
}