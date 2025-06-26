#include "menu_play_rendering_pipeline.h"

#include "r2tm/r2tm_MenuProcessor.h"

#include "menu_play_math.h"

#include "play_math_basic.h"
#include "play_math_vector2_transform.h"
#include "play_math_vector3.h"
#include "play_math_vector3_transform.h"
#include "play_math_rendering_pipeline.h"

r2tm::TitleFunctionT Menu_Play_Rendering_Pipeline::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Rendering Pipeline";
	};
}
r2tm::DescriptionFunctionT Menu_Play_Rendering_Pipeline::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Play_Rendering_Pipeline::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddMessage( "REF : https://learnopengl.com/Getting-started/Camera", r2tm::eColor::FG_LightGreen );
		mp->AddItem( '1', play_math_rendering_pipeline::ViewMatrix_Step1() );
		mp->AddItem( '2', play_math_rendering_pipeline::ViewMatrix_Step2() );
		mp->AddItem( '3', play_math_rendering_pipeline::ViewMatrix_Step3() );



		mp->AddLineFeed();



		mp->AddMessage( "REF : https://github.com/g-truc/glm/blob/2d4c4b4dd31fde06cfffad7915c2b3006402322f/glm/ext/matrix_clip_space.inl", r2tm::eColor::FG_LightGreen );
		mp->AddItem( 'q', play_math_rendering_pipeline::ProjectionMatrix_Orthographic_Step1() );
		mp->AddItem( 'w', play_math_rendering_pipeline::ProjectionMatrix_Orthographic_Step2() );
		mp->AddItem( 'e', play_math_rendering_pipeline::ProjectionMatrix_Frustum_Step1() );
		mp->AddItem( 'r', play_math_rendering_pipeline::ProjectionMatrix_Frustum_Step2() );



		mp->AddLineFeed();



		mp->AddItem( 'a', play_math_rendering_pipeline::ProjectionMatrix_Perspective_Step1() );
		mp->AddItem( 's', play_math_rendering_pipeline::ProjectionMatrix_Perspective_Step2() );
		mp->AddItem( 'd', play_math_rendering_pipeline::ProjectionMatrix_Perspective_Step3() );



		mp->AddLineFeed();



		mp->AddItem( 'z', play_math_rendering_pipeline::Viewport_Matrix_Step1() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Play_Math() );
	};
}