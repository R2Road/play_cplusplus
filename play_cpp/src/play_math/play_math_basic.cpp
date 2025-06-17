#include "play_math_basic.h"
#include "play_math___helper.h"

using namespace play_math;

namespace play_math_basic
{
	r2tm::TitleFunctionT Degree2Radian::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Degree 2 Radian";
		};
	}
	r2tm::DoFunctionT Degree2Radian::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			auto D2R = []( float degree )->float
			{
				static const float t = R_PI / 180.f;
				return ( degree * t );
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				EXPECT_EP_EQ( R_PI_4, D2R( 45 ) );

				LF();

				EXPECT_EP_EQ( R_PI_2, D2R( 90 ) );

				LF();

				EXPECT_EP_EQ( R_PI, D2R( 180 ) );

				LF();

				EXPECT_EP_EQ( R_2PI, D2R( 360 ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Radian2Degree::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Radian 2 Degree";
		};
	}
	r2tm::DoFunctionT Radian2Degree::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUTPUT_SOURCE_READY_N_BEGIN;
			auto R2D = []( float radian )->float
			{
				static const float t = 180.f / R_PI;
				return ( radian * t );
			};
			OUTPUT_SOURCE_END;

			LS();

			{
				EXPECT_EP_EQ( 45, R2D( R_PI_4 ) );

				LF();

				EXPECT_EP_EQ( 90, R2D( R_PI_2 ) );

				LF();

				EXPECT_EP_EQ( 180, R2D( R_PI ) );

				LF();

				EXPECT_EP_EQ( 360, R2D( R_2PI ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT Sine_Addition::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Sine Addition";
		};
	}
	r2tm::DoFunctionT Sine_Addition::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			OUTPUT_SOURCE_READY;

			LS();

			{
				OUTPUT_SUBJECT( "SineÀº ÀÏ¹ÝÀûÀÎ µ«¼ÀÀÌ ÀÛµ¿ÇÏÁö ¾Ê´Â´Ù." );

				LF();

				OUTPUT_SOURCE_BEGIN;
				const auto S = []( float degree )->float
				{
					return std::sin( Deg2Rad( degree ) );
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( S( 30 ) );

				LF();

				OUTPUT_VALUE( S( 40 ) );

				LF();

				OUTPUT_VALUE( S( 70 ) );

				LF();

				EXPECT_EP_NE( S( 70 ), S( 30 ) + S (40 ) );
			}

			LS();

			{
				OUTPUT_SUBJECT( "SineÀÇ µ¡¼À Á¤¸®" );
				OUTPUT_COMMENT( "Sin( A ) + Sin( B ) =" );
				OUTPUT_COMMENT( "( Sin( A ) * Cos( B ) ) + ( Cos( A ) * Sin( B ) )" );

				LF();

				OUTPUT_SOURCE_BEGIN;
				const auto S = []( float degree1, float degree2 )->float
				{
					const float rad1 = Deg2Rad( degree1 );
					const float rad2 = Deg2Rad( degree2 );

					return ( std::sin( rad1 ) * std::cos( rad2 ) )
						+ ( std::cos( rad1 ) * std::sin( rad2 ) );
				};
				OUTPUT_SOURCE_END;

				LF();

				OUTPUT_VALUE( S( 30, 40 ) );

				LF();

				OUTPUT_VALUE( std::sin( Deg2Rad( 70 ) ) );

				LF();

				EXPECT_EP_EQ( S( 30, 40 ), std::sin( Deg2Rad( 70 ) ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}