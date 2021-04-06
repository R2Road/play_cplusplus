#pragma once

#include <functional>
#include <memory>
#include <string_view>
#include <tuple>
#include <vector>

namespace r2
{
	enum class eTestResult; 

	class iNode;
	class Director;

	using SceneUp = std::unique_ptr<class Scene>;
	class Scene
	{
	public:
		Scene( Director& director, const char* title_string );
		virtual ~Scene() {}

		void ShowTitle() const;
		void ShowMenu() const;

		eTestResult Do( const int key_code );

		void AddChild( const char key_code, const iNode& node );
		void AddChild( const char key_code, const std::function<const char*( )> func_title, const std::function<const r2::eTestResult()> func_test );

	protected:
		Director& mDirector;
		std::string_view mTitleString;

		std::vector<std::tuple<char, std::function<const char*()>, std::function<const r2::eTestResult()>>> mTests;
	};
}