#pragma once

#include <iostream>

namespace r2tm
{
	enum class eColor : char
	{
		None = 0,

		FG_Black = 30,
		FG_Red,
		FG_Green,
		FG_Yellow,
		FG_Blue,
		FG_Purple,
		FG_Aqua,
		FG_White,

		FG_Gray = 90,
		FG_LightRed,
		FG_LightGreen,
		FG_LightYellow,
		FG_LightBlue,
		FG_LightPurple,
		FG_LightAqua,
		FG_BrightWhite,

		BG_Black = 40,
		BG_Red,
		BG_Green,
		BG_Yellow,
		BG_Blue,
		BG_Purple,
		BG_Aqua,
		BG_White,

		BG_Gray = 100,
		BG_LightRed,
		BG_LightGreen,
		BG_LightYellow,
		BG_LightBlue,
		BG_LightPurple,
		BG_LightAqua,
		BG_BrightWhite,
	};
}