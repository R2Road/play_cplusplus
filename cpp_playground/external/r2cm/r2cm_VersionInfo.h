#pragma once

namespace r2cm
{

	//
	// 2022.05.06 by R
	//
	// �������� �ʰ� ��̰� �۾��� �̾�� �� �ֵ��� ��� ����� ������ ��.
	//

	static struct
	{

		const char VersionNumber_1 = '1';	// ��Ģ : �Ʒ� ��õ� ��ǥ ����� ��� �ϼ��ϸ� 1 ����
		const char VersionNumber_2 = '0';	// ��Ģ : �Ʒ� ����� ��ǥ�� ���� �ܰ�� ������ �ִµ� �� ������ �ϼ��ϸ� 1 ����
		const char VersionNumber_3 = '2';	// ��Ģ : ������ �۾��� ���� �߰� �� ���� ������� �ڵ忡 � ��ȭ�� �����ϴ� �����̸� 1 ����

		const char String4Version[14] = { 'r', '2', 'c', 'm', ' ', ':', ' ', 'v', VersionNumber_1, '.', VersionNumber_2, '.', VersionNumber_3, '\0' };

		const char* const String4Road2Version_1_0_0 =
					"### Road 2 Version 1.0.0 ###"
			"\n"
			"\n"	"[o] " "Director, Menu, Item"
			"\n"	"[o] " "Inspector"
			"\n"	"[o] " "Window Utility"
			"\n"	"[o] " "Color Modifier"
		;

	} VersionInfo;
}