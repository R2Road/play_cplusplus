#pragma once

#include "base/r2_iTest.h"
#include "r2/r2_Singleton.h"

namespace console_window_message_test
{
	class ConsoleControlHandler : public r2::iItem, public r2::SingleTon<ConsoleControlHandler>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class MessageHook : public r2::iItem, public r2::SingleTon<MessageHook>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}