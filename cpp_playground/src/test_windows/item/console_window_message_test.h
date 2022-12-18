#pragma once

#include "r2cm/r2cm_iItem.h"

namespace console_window_message_test
{
	class ConsoleControlHandler : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};

	class MessageHook : public r2cm::iItem
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() const override;
	};
}