#pragma once

namespace r2tm
{

	//
	// 2022.05.06 by R
	//
	// 무리하지 않고 즐겁게 작업을 이어나갈 수 있도록 모든 방안을 강구할 것.
	//

	constexpr struct
	{

		const char* const String4VersionRule =
					"### Version Rule ###"
			"\n"
			"\n"	"> " "1.0.0.0.0"  " : "  "완성?"
			"\n"	"> " "0.1.0.0.0"  " : "  "Road 완료"
			"\n"	"> " "0.0.1.0.0"  " : "  "Road 작업 목록 1개 완료"
			"\n"	"> " "0.0.0.1.0"  " : "  "버그 수정.기존 기능 개선"
			"\n"	"> " "0.0.0.0.1"  " : "  "사용자가 변경 사항을 몰라도 되는 변화"
		;



		const char VersionNumber_1 = '1';
		const char VersionNumber_2 = '7';
		const char VersionNumber_3 = '3';
		const char VersionNumber_4 = '2';
		const char VersionNumber_5 = '0';

		const char String4Version[18] = { 'r', '2', 't', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '.', VersionNumber_4, '.', VersionNumber_5, '\0' };



		const char* const String4Road2Version_1_8_0_0_0 =
					"### Road 2 Version 1.8.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update    function   : r2tm::Inspector - OUTPUT_NOTE"
			"\n"	"[o] " "update    struct     : r2tm::WindowsUtility::CursorPoint - 생성자 추가, 연산자 +, += 추가"
			"\n"	"[o] " "update    inspector  : Add - OUTPUT_SOURCE_READY, OUTPUT_SOURCE_BEGIN, OUTPUT_SOURCE_END"
			"\n"	"[o] " "update    inspector  : Add - OUTPUT_SOURCE_READY_N_BEGIN"
			"\n"	"[o] " "update    inspector  : DECLARATION_MAIN, DECLARATION_SUB - 문자 출력을 먼저 하고 코드 실행"
			"\n"	"[o] " "update    inspector  : EXPECT_FALSE, EXPECT_NE - 눈에 잘 보이는 색상으로 변경"
			"\n"	"[o] " "add class            : r2tm::CacheCleaner"
			"\n"	"[o] " "add method           : r2tm::SwtopWatch > Reset"
			"\n"	"[o] " "add method           : r2tm::SwtopWatch > PrintAverageTime_MilliSeconds, MicroSeconds, NanoSeconds, All"
			"\n"	"[o] " "update class         : r2tm::CacheCleaner : Add > 복사 생성자 추가, 대입 연산자 제거"
			"\n"	"[o] " "update inspector     : OUTPUT_SUBJECT: 출력 문자 변경  '+' > '#'"
			"\n"	"[o] " "update class         : enum r2tm::eColor > enum class 적용"
			"\n"	"[o] " "add method           : r2tm::ColorModifier > GetColor"
			"\n"	"[o] " "add method           : r2tm::StopWatch > GetAccumulateTime, GetAccumulateCount"
			"\n"	"[o] " "update inspector     : Add - WAIT_ANY_KEY"
			"\n"	"[o] " "update inspector     : r2tm::PrintBinary : 매개 변수 타입 변경 : 값 > 참조"
			"\n"	"[o] " "update    inspector  : Add - EXPECT_EP_EQ, EXPECT_EP_NE"
			"\n"	"[ ] " "..."
		;

		const char* const String4Road2Version_1_7_0_0_0 =
					"### Road 2 Version 1.7.0.0.0 ###"
			"\n"
			"\n"	"[o] " "add method           : r2tm::WindowsUtility::FillString"
			"\n"	"[o] " "update inspector     : Add - OUTPUT_STRING"
			"\n"	"[o] " "update inspector     : OUTPUT_SIZE - 크기 뒤에 byte 문자열 출력"
			"\n"	"[o] " "rename method        : r2tm::StopWatch - PrintMinAndMaxTime_NanoSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MilliSeconds"
			"\n"	"[o] " "add    method        : r2tm::StopWatch - PrintMinAndMaxTime_MicroSeconds"
			"\n"	"[o] " "update menuprocessor : 키, 메세지 텍스트의 백그라운드 색상 설정"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - FillString"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - MoveCursorPoint"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - FillCharacter"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - FillColor"
			"\n"	"[o] " "overload    method   : r2tm::WindowsUtility - MoveCursorPointWithClearBuffer"
		;

		const char* const String4Road2Version_1_6_0_0_0 =
					"### Road 2 Version 1.6.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SUBJECT"
			"\n"	"[o] " "update inspector : Add - OUTPUT_SIZE"
			"\n"	"[o] " "update ostream : Add - LF(), LF2(), LF3(), LS()"
			"\n"	"[o] " "update menuprocessor : Add - AddExit"
			"\n"	"[o] " "update inspector : Apply Color - OUTPUT_NOTE, OUTPUT_SUBJECT, OUTPUT_COMMENT, OUTPUT_CODE"
		;

		const char* const String4Road2Version_1_5_0_0_0 =
					"### Road 2 Version 1.5.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_GT, EXPECT_LT, EXPECT_GE, EXPECT_LE - 실패시 값 출력"
			"\n"	"[o] " "Split Menu And MenuProcessor"
		;
		
		const char* const String4Road2Version_1_4_0_0_0 =
					"### Road 2 Version 1.4.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update method : apply const - r2tm::iItem::GetDoFunction"
			"\n"	"[o] " "remove class : r2tm::SingleTon"
		;
		
		const char* const String4Road2Version_1_3_0_0_0 =
					"### Road 2 Version 1.3.0.0.0 ###"
			"\n"
			"\n"	"[o] " "update inspector : EXPECT_EQ, EXPECT_NE - 실패시 값 출력"
			"\n"	"[o] " "update inspector : OUTPUT_BINARY - 가시성 개선"
			"\n"	"[o] " "update inspector : inspector 의 debug break ON/OFF 설정"
			"\n"	"[o] " "update inspector : Add - OUTPUT_NOTE"
			"\n"	"[o] " "update inspector : Add - OUTPUT_COMMENT"
			"\n"	"[o] " "update inspector : OUTPUT_FILE 에서 line index 출력"
			"\n"	"[o] " "update inspector : Add - OUTPUT_FILE_RANGE"
		;
		
		const char* const String4Road2Version_1_2_0_0_0 =
					"### Road 2 Version 1.2.0.0.0 ###"
			"\n"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::ScrollBarVisible"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::MaximizeButtonEnable"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::ResizingByDraggingEnable"
			"\n"	"[o] " "add method : r2tm::WindowsUtility::QuickEditEnable"
		;
		
		const char* const String4Road2Version_1_1_0_0_0 =
					"### Road 2 Version 1.1.0.0.0 ###"
			"\n"
			"\n"	"[o] " "add class : r2tm::StopWatch"
			"\n"	"[o] " "update method : r2tm::Menu::AddItem - Item 제목에 컬러 적용"
			"\n"	"[o] " "update method : r2tm::Menu::Do - 메뉴 제목의 # 을 사용자가 입력하지 않아도 되도록 조정"
		;

		const char* const String4Road2Version_1_0_0_0_0 =
					"### Road 2 Version 1.0.0.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
			"\n"	"[o] " "Color Modifier"
		;



		const char* const String4Road2NextVersion = String4Road2Version_1_8_0_0_0;



		enum { VERSION_HISTORY_COUNT = 9 };
		const char* VersionHistory[VERSION_HISTORY_COUNT] = {
			  String4Road2Version_1_0_0_0_0
			, String4Road2Version_1_1_0_0_0
			, String4Road2Version_1_2_0_0_0
			, String4Road2Version_1_3_0_0_0
			, String4Road2Version_1_4_0_0_0
			, String4Road2Version_1_5_0_0_0
			, String4Road2Version_1_6_0_0_0
			, String4Road2Version_1_7_0_0_0
			, String4Road2Version_1_8_0_0_0
		};

	} VersionInfo;
}