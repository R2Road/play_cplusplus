#include "menu_lambda.hpp"

#include "r2tm/r2tm_menu_processor.hpp"

#include "play_cpp_lambda.hpp"

#include "menu_cpp.hpp"

r2tm::TitleFunctionT menu_lambda::GetTitleFunction() const
{
	return []()->const char*
	{
		return "Lambda";
	};
}
r2tm::DescriptionFunctionT menu_lambda::GetDescriptionFunction() const
{
	return []()->const char* { return ""; };
}
r2tm::WriteFunctionT menu_lambda::GetWriteFunction() const
{
	return[]( r2tm::MenuProcessor* mp )
	{
		mp->AddItem( '1', play_cpp_lambda::Basic() );
		mp->AddItem( '2', play_cpp_lambda::CaptureValue() );
		mp->AddItem( '3', play_cpp_lambda::CaptureValueWithMutable() );
		mp->AddItem( '4', play_cpp_lambda::CaptureReference() );
		mp->AddItem( '5', play_cpp_lambda::CaptureUniquePtr() );
		mp->AddItem( '6', play_cpp_lambda::CaptureValueWithAssign() );



		mp->AddLineFeed();



		mp->AddItem( 'q', play_cpp_lambda::Size_Basic() );
		mp->AddItem( 'w', play_cpp_lambda::Size_CopyCapture() );
		mp->AddItem( 'e', play_cpp_lambda::Size_ReferenceCapture() );
		mp->AddItem( 'r', play_cpp_lambda::Size_ThisCapture() );
		mp->AddItem( 't', play_cpp_lambda::Size_With_STDFunction() );



		mp->AddSplit();



		mp->AddMenu( 27, Menu_CPP() );
	};
}