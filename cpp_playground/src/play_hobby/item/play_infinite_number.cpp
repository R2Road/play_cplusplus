#include "play_infinite_number.h"

#include "r2cm/r2cm_Inspector.h"
#include "r2cm/r2cm_ostream.h"

namespace
{
	//
	// > Bit ������ �޸𸮸� �Ҵ��� ����� ���� ������ primitive type�� Ȱ���ؾ� �Ѵ�.
	// > ���� ���� ��Ű�� ������ ��� ���� ������ �Ѿ���� �˻� �ؾ� �Ѵ�.
	// > ��� ���� ������ �Ѿ�ٸ� ���� �ʸ��� ó���� ���� �޸𸮸� �Ҵ� �ؾ� �Ѵ�.
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
				DECLARATION_MAIN( InfiniteNumber infinite_number );
				PROCESS_MAIN( infinite_number = 1999 );

				std::cout << r2cm::linefeed;


				OUTPUT_VALUE(infinite_number.Get() );
			}

			std::cout << r2cm::split;

			return r2cm::eItemLeaveAction::Pause;
		};
	}
}