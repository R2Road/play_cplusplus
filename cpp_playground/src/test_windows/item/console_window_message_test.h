#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace console_window_message_test
{
	class ConsoleControlHandler : public r2cm::iItem, public r2cm::SingleTon<ConsoleControlHandler>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class MessageHook : public r2cm::iItem, public r2cm::SingleTon<MessageHook>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}