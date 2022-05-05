#pragma once

#include "r2cm/r2cm_iItem.h"
#include "r2/r2_Singleton.h"

namespace windows_sound_test
{
	class PlaySoundTest : public r2cm::iItem, public r2::SingleTon<PlaySoundTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};

	class BeepTest : public r2cm::iItem, public r2::SingleTon<BeepTest>
	{
	public:
		TitleFuncT GetTitleFunction() const override;
		DoFuncT GetDoFunction() override;
	};
}