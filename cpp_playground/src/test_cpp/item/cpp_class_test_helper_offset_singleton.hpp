#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

template<typename T>
class ST
{
public:
	ST()
	{
		// dynamic_cast<T*>( this );
		// > dynamic_cast 는 작동하지 않는다.

		std::cout << r2cm::clm( r2cm::eColor::FG_Green );
		std::cout << "[START] ST::ST()" << r2cm::linefeed;
		std::cout << r2cm::clm();

		OUTPUT_VALUE( this );

		std::cout << r2cm::linefeed;

		OUTPUT_VALUE( int64_t( (T*)1 ) );
		OUTPUT_VALUE( int64_t( ( ST<T>* )( T* )1 ) );

		std::cout << r2cm::linefeed;

		DECLARATION_MAIN( auto offset = int64_t( (T*)1 ) - int64_t( ( ST<T>* )( T* )1 ) );
		OUTPUT_VALUE( this + offset );

		std::cout << r2cm::clm( r2cm::eColor::FG_Green );
		std::cout << "[End]" << r2cm::clm() << r2cm::linefeed2;
		std::cout << r2cm::clm();
	}
};

class A {};
class B {};
class A_B_ST : public A, public B, public ST<A_B_ST> {};