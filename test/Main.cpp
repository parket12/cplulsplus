#include <iostream>
#include <string>
#include <windows.h>
#include "../StaticLib/Source.cpp"
#include "../DynamicLib/Header.h"

using namespace std;



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);


	HINSTANCE dynamicLib = LoadLibrary(L"DynamicLib.dll");
	if (!dynamicLib) {
		cerr << "�� ������� ��������� ���������� DynamicLib.dll" << endl;
		return 1;
	}


	typedef bool (*CharSearchFunc)(const char*, const char*);
	CharSearchFunc searchFunc = reinterpret_cast<CharSearchFunc>(GetProcAddress(dynamicLib, "SearchCharacters"));
	if (!searchFunc) {
		cerr << "�� ������� �������� ����� ������� SearchCharacters" << endl;
		FreeLibrary(dynamicLib);
		return 1;
	}

	cout << "������� ������: ";
	string input;
	getline(cin, input);

	cout << "�������, ��� � ��� ������: ";
	string characters;
	getline(cin, characters);

	cout << "�������� �� ������ \"" << input << "\" ������� \"" << characters << "\" ?" << endl;


	bool result = FindBukv(input.c_str(), characters.c_str());
	cout << (result ? "��" : "���") << endl;


	stfnlb(result);

	FreeLibrary(dynamicLib);

	return 0;
}
