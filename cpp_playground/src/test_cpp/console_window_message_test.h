#pragma once

#include "base/r2_iTest.h"
#include "base/r2_Singleton.h"

namespace console_window_message_test
{
	class ConsoleControlHandler : public r2::iTest, public r2::SingleTon<ConsoleControlHandler>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};

	class MessageHook : public r2::iTest, public r2::SingleTon<MessageHook>
	{
	public:
		TitleFunc GetTitleFunction() const override;
		DoFunc GetDoFunction() override;
	};
}