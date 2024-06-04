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
		cerr << "Не удалось загрузить библиотеку DynamicLib.dll" << endl;
		return 1;
	}


	typedef bool (*CharSearchFunc)(const char*, const char*);
	CharSearchFunc searchFunc = reinterpret_cast<CharSearchFunc>(GetProcAddress(dynamicLib, "SearchCharacters"));
	if (!searchFunc) {
		cerr << "Не удалось получить адрес функции SearchCharacters" << endl;
		FreeLibrary(dynamicLib);
		return 1;
	}

	cout << "Введите строку: ";
	string input;
	getline(cin, input);

	cout << "Введите, что в ней искать: ";
	string characters;
	getline(cin, characters);

	cout << "Содержит ли строка \"" << input << "\" символы \"" << characters << "\" ?" << endl;


	bool result = FindBukv(input.c_str(), characters.c_str());
	cout << (result ? "Да" : "Нет") << endl;


	stfnlb(result);

	FreeLibrary(dynamicLib);

	return 0;
}
