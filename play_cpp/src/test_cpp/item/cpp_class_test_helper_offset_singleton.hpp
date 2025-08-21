#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"
#include "r2tm/r2tm_color_modifier.hpp"

template<typename T>
class ST
{
public:
	ST()
	{
		// dynamic_cast<T*>( this );
		// > dynamic_cast 는 작동하지 않는다.

		std::cout << clm( r2tm::eColor::FG_Green );
		std::cout << "[START] ST::ST()" << r2tm::linefeed;
		std::cout << clm();

		OUTPUT_VALUE( this );

		LF();

		OUTPUT_VALUE( int64_t( (T*)1 ) );
		OUTPUT_VALUE( int64_t( ( ST<T>* )( T* )1 ) );

		LF();

		DECL_MAIN( auto offset = int64_t( (T*)1 ) - int64_t( ( ST<T>* )( T* )1 ) );
		OUTPUT_VALUE( this + offset );

		std::cout << clm( r2tm::eColor::FG_Green );
		std::cout << "[End]" << r2tm::linefeed2;
		std::cout << clm();
	}
};

class A {};
class B {};
class A_B_ST : public A, public B, public ST<A_B_ST> {};