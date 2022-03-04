#include "pch.h"
#include "infinite_number_test.h"

#include "base/r2_eTestEndAction.h"

namespace
{
	//
	// Short Range : -32,768 ~ 32,767
	//

	class InfiniteNumber
	{
	public:
		InfiniteNumber() : mValue( 0 )
		{}

		void operator=( const short new_value )
		{
			mValue = new_value;
		}

		short Get() const
		{
			return mValue;
		}

	private:
		short mValue;
	};
}

namespace infinite_number_test
{
	r2::iItem::TitleFunc Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number( To do )";
		};
	}
	r2::iItem::DoFunc Basic::GetDoFunction()
	{
		return []()->r2::eTestEndAction
		{
			std::cout << "# " << GetInstance().GetTitleFunction()() << " #" << r2::linefeed;

			std::cout << r2::split;

			{
				InfiniteNumber infinite_number;
				infinite_number = 1999;

				std::cout << r2::tab << "+ Variable" << r2::linefeed2;
				std::cout << r2::tab2 << "InfiniteNumber infinite_number;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Operation" << r2::linefeed2;
				std::cout << r2::tab2 << "infinite_number = 1999;" << r2::linefeed;


				std::cout << r2::linefeed;


				std::cout << r2::tab << "+ Result" << r2::linefeed2;
				std::cout << r2::tab2 << "infinite_number : " << infinite_number.Get() << r2::linefeed;
			}

			std::cout << r2::split;

			return r2::eTestEndAction::Pause;
		};
	}
}