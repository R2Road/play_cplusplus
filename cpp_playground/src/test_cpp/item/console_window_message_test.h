#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace console_window_message_test
{
	class ConsoleControlHandler : public r2cm::iItem, public r2::SingleTon<ConsoleControlHandler>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class MessageHook : public r2cm::iItem, public r2::SingleTon<MessageHook>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}