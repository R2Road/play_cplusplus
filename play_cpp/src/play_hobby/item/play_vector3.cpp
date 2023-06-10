#include "play_vector3.h"

#include "r2tm/r2tm_Inspector.h"
#include "r2tm/r2tm_ostream.h"

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

namespace play_vector3
{
	r2tm::TitleFunctionT Declaration::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Declaration";
		};
	}
	r2tm::DoFunctionT Declaration::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT OperatorPlus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator+";
		};
	}
	r2tm::DoFunctionT OperatorPlus::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			std::cout << r2tm::tab << "+ Declaration" << r2tm::linefeed2;
			DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 2.1f, 0.f, 2.f ) );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const auto v3 = v1 + v2 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v3 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT OperatorPlusEqual::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator+=";
		};
	}
	r2tm::DoFunctionT OperatorPlusEqual::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( r2::Vector3 v1( 3.f, .2f, 1.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 1.4f, 1.3f, 1.5f ) );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( v1 += v2 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT OperatorMinus::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator-";
		};
	}
	r2tm::DoFunctionT OperatorMinus::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 2.1f, 0.f, 2.f ) );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const auto v3 = v1 - v2 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v3 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT OperatorMinusEqual::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator-=";
		};
	}
	r2tm::DoFunctionT OperatorMinusEqual::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( r2::Vector3 v1( 3.f, .2f, 1.2f ) );
			DECLARATION_MAIN( const r2::Vector3 v2( 1.4f, 1.3f, 1.5f ) );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( v1 -= v2 );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT OperatorMultiply_With_Scalar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator* Scalar";
		};
	}
	r2tm::DoFunctionT OperatorMultiply_With_Scalar::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( const r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const float scalar = 3.f );

			std::cout << r2tm::split;

			{
				DECLARATION_MAIN( const auto v3 = v1 * scalar );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v3 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}

	r2tm::TitleFunctionT OperatorMultiplyEqual_With_Scalar::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Vector3 : Operator*= Scalar";
		};
	}
	r2tm::DoFunctionT OperatorMultiplyEqual_With_Scalar::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			std::cout << r2tm::split;

			DECLARATION_MAIN( r2::Vector3 v1( 1.f, 1.1f, 2.2f ) );
			DECLARATION_MAIN( const float scalar = 3.f );

			std::cout << r2tm::split;

			{
				PROCESS_MAIN( v1 *= scalar );

				std::cout << r2tm::linefeed;

				OUTPUT_VALUE( v1 );
			}

			std::cout << r2tm::split;

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}