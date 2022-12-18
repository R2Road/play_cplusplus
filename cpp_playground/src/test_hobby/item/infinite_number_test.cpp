#include "infinite_number_test.h"

#include "r2cm/r2cm_ostream.h"

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
	r2cm::iItem::TitleFunctionT Basic::GetTitleFunction() const
	{
		return []()->const char*
		{
			return "Infinite Number( To do )";
		};
	}
	r2cm::iItem::DoFunctionT Basic::GetDoFunction() const
	{
		return []()->r2cm::eItemLeaveAction
		{
			std::cout << r2cm::split;

			{
				InfiniteNumber infinite_number;
				infinite_number = 1999;

				std::cout << r2cm::tab << "+ Variable" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "InfiniteNumber infinite_number;" << r2cm::linefeed;


				std::cout << r2cm::linefeed;


				std::cout << r2cm::tab << "+ Operation" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "infinite_number = 1999;" << r2cm::linefeed;


				std::cout << r2cm::linefeed;


				std::cout << r2cm::tab << "+ Result" << r2cm::linefeed2;
				std::cout << r2cm::tab2 << "infinite_number : " << infinite_number.Get() << r2cm::linefeed;
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}