#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <vector>

namespace r2
{
	enum class eTestEndAction; 

	class iItem;
	class Director;

	using MenuUp = std::unique_ptr<class Menu>;
	class Menu
	{
	private:
		struct TestInfo
		{
			TestInfo(
				const char key_code
				, const std::function<const char*( )> name_function
				, const std::function<const r2::eTestEndAction()> test_function
			) :
				KeyCode( key_code )
				, NameFunction( name_function )
				, TestFunction( test_function )
			{}

			char KeyCode;
			std::function<const char*()> NameFunction;
			std::function<const r2::eTestEndAction()> TestFunction;
		};

		using TestContainerT = std::vector<TestInfo>;

	public:
		Menu( Director& director, const char* title_string, const char* description_string = "" );
		virtual ~Menu() {}

		void ShowMenu() const;

	private:
		void ShowTitle() const;
		void ShowDescription() const;
		void ShowItem() const;

	public:
		eTestEndAction Do( const int key_code );

		void AddItem( const char key_code, iItem& test_obj );
		void AddItem( const char key_code, const std::function<const char*( )> func_title, const std::function<const r2::eTestEndAction()> func_test );
		void AddLineFeed();
		void AddSplit();

	protected:
		Director& mDirector;
		std::string_view mTitleString;
		std::string_view mDescriptionString;

		TestContainerT mTests;
	};
}