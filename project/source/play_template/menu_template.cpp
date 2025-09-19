#include "menu_template.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_template_basic.hpp"
#include "play_template_practice_02.hpp"
#include "play_template_specialization.hpp"
#include "play_template_type_extract.hpp"

#include "menu_template_meta_programming.hpp"
#include "menu_template_practice.hpp"
#include "menu_template_variadic.hpp"

#include "menu_root.hpp"

r2tm::TitleFunctionT Menu_Template::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Template";
	};
}
r2tm::DescriptionFunctionT Menu_Template::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT Menu_Template::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_template_basic::MemberVariable() );
		mp->AddItem( '2', play_template_basic::Function_ReturnValue() );
		mp->AddItem( '3', play_template_basic::Function_Object() );
		mp->AddItem( '4', play_template_basic::RemovePointer() );
		mp->AddItem( '5', play_template_basic::Constant() );
		mp->AddItem( '6', play_template_basic::Parentheses() );



		mp->AddLineFeed();



		mp->AddItem( '7', play_template_practice_02::Basic() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_template_specialization::Basic() );
		mp->AddItem( 'w', play_template_type_extract::TypeExtract_4_MemberPointer() );



		mp->AddLineFeed();



		mp->AddMenu( 'a', Menu_TemplateVariadic() );
		mp->AddMenu( 's', Menu_TemplateMetaProgramming() );
		mp->AddMenu( 'd', Menu_TemplatePractice() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_Root() );
	};
}