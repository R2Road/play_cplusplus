#include "r2_Scene.h"

#include <conio.h>
#include <iostream>
#include <sstream>

#include "r2_Director.h"
#include "r2_RandomTestScene.h"

#include "filesystem_test.h"
#include "shared_pointer_test.h"
#include "variadic_template_test.h"
#include "template_meta_programming_test.h"
#include "optional_test.h"
#include "variant_test.h"
#include "tuple_test.h"
#include "structured_binding_test.h"
#include "const_pointer_test.h"
#include "assert_test.h"
#include "string_view_test.h"


std::string MakeMenuString()
{
	std::stringstream ss;
	ss << "+ Menu" << std::endl;
	ss << "1 : " << filesystem_test::CurrentDirectory::GetTitle() << std::endl;
	ss << "2 : " << "Random" << std::endl;
	ss << "3 : " << shared_pointer_test::SharedPtr::GetTitle() << std::endl;
	ss << "4 : " << variadic_template_test::PrintValues::GetTitle() << std::endl;
	ss << "5 : " << variadic_template_test::SumValues::GetTitle() << std::endl;
	ss << "6 : " << variadic_template_test::SubtractValues::GetTitle() << std::endl;
	ss << "7 : " << template_meta_programming_test::CalculateFactorial::GetTitle() << std::endl;
	ss << "8 : " << template_meta_programming_test::Integer2String::GetTitle() << std::endl;
	ss << "9 : " << template_meta_programming_test::CalculatePlaceValue::GetTitle() << std::endl;
	ss << "Q : " << template_meta_programming_test::Integer2String_II::GetTitle() << std::endl;
	ss << "W : " << optional_test::Basic::GetTitle() << std::endl;
	ss << "E : " << variant_test::Basic::GetTitle() << std::endl;
	ss << "R : " << variadic_template_test::SizeOfArgs::GetTitle() << std::endl;
	ss << "T : " << tuple_test::Basic::GetTitle() << std::endl;
	ss << "Y : " << structured_binding_test::Basic::GetTitle() << std::endl;
	ss << "I : " << const_pointer_test::Basic::GetTitle() << std::endl;
	ss << "O : " << assert_test::Basic::GetTitle() << std::endl;
	ss << "P : " << template_meta_programming_test::MultiTypePackage::GetTitle() << std::endl;
	ss << "A : " << stringview_test::Basic::GetTitle() << std::endl;

	ss << std::endl << "Press Number" << std::endl;

	return std::string( ss.str() );
}

namespace r2
{
	Scene::Scene( Director& director ) : iScene( director ) {}

	SceneUp Scene::Create( Director& director )
	{
		return SceneUp( new ( std::nothrow ) MyT( director ) );
	}

	void Scene::ShowMenu()
	{
		static std::string menu_string( std::move( MakeMenuString() ) );
		std::cout << menu_string;
	}

	iScene::eResult Scene::Do( const int key_code )
	{
		switch( key_code )
		{
		case '1':
			filesystem_test::CurrentDirectory::Do();
			break;

		case '2':
			mDirector.Setup( r2::RandomTestScene::Create( mDirector ) );
			return iScene::eResult::ChangeScene;

		case '3':
			shared_pointer_test::SharedPtr::Do();
			break;
		case '4':
			variadic_template_test::PrintValues::Do();
			break;
		case '5':
			variadic_template_test::SumValues::Do();
			break;
		case '6':
			variadic_template_test::SubtractValues::Do();
			break;
		case '7':
			template_meta_programming_test::CalculateFactorial::Do();
			break;
		case '8':
			template_meta_programming_test::Integer2String::Do();
			break;
		case '9':
			template_meta_programming_test::CalculatePlaceValue::Do();
			break;
		case 'q':
			template_meta_programming_test::Integer2String_II::Do();
			break;
		case 'w':
			optional_test::Basic::Do();
			break;
		case 'e':
			variant_test::Basic::Do();
			break;
		case 'r':
			variadic_template_test::SizeOfArgs::Do();
			break;
		case 't':
			tuple_test::Basic::Do();
			break;
		case 'y':
			structured_binding_test::Basic::Do();
			break;
		case 'i':
			const_pointer_test::Basic::Do();
			break;
		case 'o':
			assert_test::Basic::Do();
			break;
		case 'p':
			template_meta_programming_test::MultiTypePackage::Do();
			break;

		case 'a':
			stringview_test::Basic::Do();
			break;

		case 27: // ESC
			return iScene::eResult::Exit;
		}

		return iScene::eResult::RunTest;
	}
}