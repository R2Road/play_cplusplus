#include "vector3_test.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace r2
{
	struct Vector3
	{
		Vector3( float new_x, float new_y, float new_z ) : x( new_x ), y( new_y ), z( new_z ) {}

		float x = 0.f;
		float y = 0.f;
		float z = 0.f;
	};

	Vector3 operator+( const Vector3& v1, const Vector3& v2 )
	{
		return Vector3{ v1.x + v2.x, v1.y + v2.y, v1.z + v2.z };
	}
	void operator+=( Vector3& v1, const Vector3& v2 )
	{
		v1.x += v2.x;
		v1.y += v2.y;
		v1.z += v2.z;
	}

	Vector3 operator-( const Vector3& v1, const Vector3& v2 )
	{
		return Vector3{ v1.x - v2.x, v1.y - v2.y, v1.z - v2.z };
	}
	void operator-=( Vector3& v1, const Vector3& v2 )
	{
		v1.x -= v2.x;
		v1.y -= v2.y;
		v1.z -= v2.z;
	}

	Vector3 operator*( const Vector3& v1, const float scalar )
	{
		return Vector3{ v1.x * scalar, v1.y * scalar, v1.z * scalar };
	}
	void operator*=( Vector3& v1, const float scalar )
	{
		v1.x *= scalar;
		v1.y *= scalar;
		v1.z *= scalar;
	}

	std::ostream& operator<<( std::ostream& os, const Vector3& v )
	{
		os << "x : " << v.x << "     y : " << v.y << "     z : " << v.z;
		return os;
	}
}

namespace vector3_test
{
	r2cm::iItem::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Declaration";
		};
	}
	r2cm::iItem::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT OperatorPlus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator+";
		};
	}
	r2cm::iItem::DoFunctionT OperatorPlus::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			std::cout << r2cm::tab << "+ Declaration" << r2cm::linefeed2;
			DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 2.1f, 0.f, 2.f ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto v3 = v1 + v2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v3 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT OperatorPlusEqual::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator+=";
		};
	}
	r2cm::iItem::DoFunctionT OperatorPlusEqual::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::Vector3 v1( 3.f, .2f, 1.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 1.4f, 1.3f, 1.5f ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( v1 += v2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT OperatorMinus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator-";
		};
	}
	r2cm::iItem::DoFunctionT OperatorMinus::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 2.1f, 0.f, 2.f ) );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto v3 = v1 - v2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v3 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT OperatorMinusEqual::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator-=";
		};
	}
	r2cm::iItem::DoFunctionT OperatorMinusEqual::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::Vector3 v1( 3.f, .2f, 1.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 1.4f, 1.3f, 1.5f ) );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( v1 -= v2 );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}



	r2cm::iItem::TitleFunctionT OperatorMultiply_With_Scalar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator* Scalar";
		};
	}
	r2cm::iItem::DoFunctionT OperatorMultiply_With_Scalar::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const float scalar = 3.f );

			std::cout << r2cm::split;

			{
				DECLARATION_MAIN( const auto v3 = v1 * scalar );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v3 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}

	r2cm::iItem::TitleFunctionT OperatorMultiplyEqual_With_Scalar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator*= Scalar";
		};
	}
	r2cm::iItem::DoFunctionT OperatorMultiplyEqual_With_Scalar::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			DECLARATION_MAIN( r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const float scalar = 3.f );

			std::cout << r2cm::split;

			{
				PROCESS_MAIN( v1 *= scalar );

				std::cout << r2cm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}