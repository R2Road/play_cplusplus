#include "play_template_meta_programming_03.hpp"
#include "play_template_meta_programming_helper___type_index.hpp"
#include "play_template_meta_programming_helper___type_list.hpp"
#include "play_template_meta_programming_helper___type_package.hpp"
#include "play_template_meta_programming_helper___type_search.hpp"

#include "r2tm/r2tm_inspector.hpp"
#include "r2tm/r2tm_ostream.hpp"

namespace play_template_meta_programming_01
{
	r2tm::TitleFunctionT TypeList::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TypeList";
		};
	}
	r2tm::DoFunctionT TypeList::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "type을 저장하는 template을 만들어 쓰는 것으로 간결함을 얻을 수 있다." );
			OUT_SUBJECT( "같은 template 인자를 받더라도 특수화가 가능하다." );

			LS();

			OUT_FILE( "source/play_template/play_template_meta_programming_helper___type_list.hpp" );

			LS();

			{
				OUT_SOURCE_READY;

				OUT_SOURCE_BEGIN;
				using TL = Helper_TypeList<int, float, char, double, long>;

				using C1 = Helper_TypeList_Checker<TL>::type;
				using C2 = Helper_TypeList_Checker<int, float, char, double, long>::type;

				const auto result = std::is_same_v<C1, C2>;
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( ( result ? "true" : "false" ) );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT TypeSearch::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TypeSearch";
		};
	}
	r2tm::DoFunctionT TypeSearch::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "패턴 매칭으로 type list 에서 타입을 꺼낼 수 있다." );

			LS();

			OUT_FILE( "source/play_template/play_template_meta_programming_helper___type_search.hpp" );

			LS();

			{
				OUT_SOURCE_READY;

				OUT_SOURCE_BEGIN;
				using TL = Helper_TypeList<int, float, char>;
				OUT_SOURCE_END;

				SS();

				{
					OUT_SOURCE_BEGIN;
					const auto result = Helper_TypeSearch<int, TL>::value;
					OUT_SOURCE_END;

					LF();

					OUT_VALUE( ( result ? "true" : "false" ) );
				}

				SS();

				{
					OUT_SOURCE_BEGIN;
					const auto result = Helper_TypeSearch<char, TL>::value;
					OUT_SOURCE_END;

					LF();

					OUT_VALUE( ( result ? "true" : "false" ) );
				}

				SS();

				{
					OUT_SOURCE_BEGIN;
					const auto result = Helper_TypeSearch<double, TL>::value;
					OUT_SOURCE_END;

					LF();

					OUT_VALUE( ( result ? "true" : "false" ) );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}



	r2tm::TitleFunctionT TypeIndex::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "TypeIndex";
		};
	}
	r2tm::DoFunctionT TypeIndex::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{
			LS();

			OUT_SUBJECT( "패턴 매칭으로 type list 에서 타입을 꺼낼 수 있다." );

			LS();

			OUT_FILE( "source/play_template/play_template_meta_programming_helper___type_index.hpp" );

			LS();

			{
				OUT_SOURCE_READY;

				OUT_SOURCE_BEGIN;
				using TL = Helper_TypeList<int, float, char>;
				OUT_SOURCE_END;

				SS();

				{
					OUT_SOURCE_BEGIN;
					const auto index = Helper_GetTypeIndex<int, TL>::value;
					OUT_SOURCE_END;

					LF();

					OUT_VALUE( index );
				}

				SS();

				{
					OUT_SOURCE_BEGIN;
					const auto index = Helper_GetTypeIndex<char, TL>::value;
					OUT_SOURCE_END;

					LF();

					OUT_VALUE( index );
				}

				SS();

				{
					OUT_SOURCE_BEGIN;
					const auto index = Helper_GetTypeIndex<double, TL>::value;
					OUT_SOURCE_END;

					LF();

					OUT_VALUE( index );
				}
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}



namespace play_template_meta_programming_01
{
	r2tm::TitleFunctionT TypePackage::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Type Package";
		};
	}
	r2tm::DoFunctionT TypePackage::GetDoFunction() const
	{
		return []()->r2tm::eDoLeaveAction
		{

			LS();

			OUT_FILE( "source/play_template/play_template_meta_programming_helper___type_package.hpp" );

			LS();

			{

				OUT_SOURCE_READY;
				OUT_SOURCE_BEGIN;
				Helper_TypePackage<int, float, char> p{ 123, 345.678f, 'Q' };
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( p.get_from_type<int>() );
				OUT_VALUE( p.get_from_type<float>() );
				OUT_VALUE( p.get_from_type<char>() );

				LF();

				OUT_VALUE( p.get_from_index<0>() );
				OUT_VALUE( p.get_from_index<1>() );
				OUT_VALUE( p.get_from_index<2>() );
			}

			LS();

			{
				OUT_SOURCE_READY;
				OUT_SOURCE_BEGIN;
				const Helper_TypePackage<int, float, char> p{ 123, 345.678f, 'Q' };
				OUT_SOURCE_END;

				LF();

				OUT_VALUE( p.get_from_type<int>() );
				OUT_VALUE( p.get_from_type<float>() );
				OUT_VALUE( p.get_from_type<char>() );

				LF();

				OUT_VALUE( p.get_from_index<0>() );
				OUT_VALUE( p.get_from_index<1>() );
				OUT_VALUE( p.get_from_index<2>() );
			}

			LS();

			return r2tm::eDoLeaveAction::Pause;
		};
	}
}
