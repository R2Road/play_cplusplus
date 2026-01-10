#include "menu_basic.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_basic.hpp"

#include "menu_basic___operator.hpp"
#include "menu_basic___union.hpp"
#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Basic::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Basic";
	};
}
r2tm::DescriptionFunctionT Menu_Basic::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Basic::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_basic::Primitive_Type_Size() );
		mp->AddItem( '2', play_basic::Pointer_Type_Size() );


		mp->AddLineFeed();


		mp->AddMenu( 'q', Menu_Basic___Operator() );
		mp->AddMenu( 'w', Menu_Basic___Union() );


		mp->AddSplit();


		mp->AddMenu( 27, Menu_Root() );
	};
}