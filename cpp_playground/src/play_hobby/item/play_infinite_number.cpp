#include "play_infinite_number.h"

#include "r2cm/r2cm_ostream.h"

namespace
{
	//
	// > Bit 단위로 메모리를 할당할 방법은 없기 때문에 primitive type을 활용해야 한다.
	// > 값을 변경 시키기 이전에 결과 값이 경계면을 넘어가는지 검사 해야 한다.
	// > 결과 값이 경계면을 넘어간다면 경계면 너머의 처리를 위해 메모리를 할당 해야 한다.
	//

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

namespace play_infinite_number
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