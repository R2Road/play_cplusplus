#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2cm/r2cm_Singleton.h"

namespace windows_sound_test
{
	class PlaySoundTest : public r2cm::iItem, public r2cm::SingleTon<PlaySoundTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};

	class BeepTest : public r2cm::iItem, public r2cm::SingleTon<BeepTest>
	{
	public:
		TitleFunctionT GetTitleFunction() const override;
		DoFunctionT GetDoFunction() override;
	};
}