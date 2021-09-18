/*
 * main.cc
 *
 *  Created on: 18 сент. 2021 г.
 *      Author: unyuu
 */

#include <iostream>
#include <sstream>
#include <cstring>

/*
 * C-строка
 * 		массив символов типа char, заканчивающийся символом
 * 		с кодом 0
 * 		char *			<-- можно изменять
 * 		const char *	<-- нельзя изменять
 *
 * C++-строка
 * 		экземпляры класса std::string.
 *
 * "Строковый литерал"
 * 		имеет тип const char *
 *
 */

/*
 * 1. Вывод строки на консоль
 * 2. Определение длины строки
 * 3. Работа с отдельными символами
 * 4. Создание копии строки
 * 5. Извлечение подстроки
 * 6. Замена подстроки
 * 7. Разбиение на части по разделителю
 * 8. Конкатенация строк
 * 9. Ввод строки с консоли
 */

void c_strings_test()
{
	auto s1 = "Hello, world!";
	auto s2 = "Мама мыла пилораму";
	auto s3 = "All your base are belong to us.";

	std::cout << "Строка 1: " << s1 << std::endl;
	std::cout << "Строка 2: " << s2 << std::endl;
	std::cout << "Строка 3: " << s3 << std::endl;

	std::cout << "Длина строки 1 = " << strlen(s1) << std::endl;
	std::cout << "Длина строки 2 = " << strlen(s2) << std::endl;
	std::cout << "Длина строки 3 = " << strlen(s3) << std::endl;

	std::cout << "Символ 5 в строке 1 = " << s1[5] << std::endl;

	char * s1_copy = new char[strlen(s1) + 1];
	strcpy(s1_copy, s1);
	s1_copy[5] = '!';
	std::cout << "Изменённая копия строки 1: " << s1_copy << std::endl;
	s1_copy[12] = '?';
	std::cout << "Изменённая копия строки 1: " << s1_copy << std::endl;

	auto fragment = "people";
	strncpy(s1_copy + 7, fragment, strlen(fragment));
	std::cout << "Ещё раз: " << s1_copy << std::endl;
	delete s1_copy;

	char * s1_substr = new char[6];
	strncpy(s1_substr, s1 + 7, 5);
	std::cout << "Фрагмент строки s1: " << s1_substr << std::endl;
	delete s1_substr;

	auto s3_copy = strdup(s3);
	char * substr = strtok(s3_copy, " ");
	while (substr != nullptr) {
		std::cout << "Кусок: " << substr << std::endl;
		substr = strtok(nullptr, " ");
	}
	free(s3_copy);

	char * newstr = new char[strlen(s1) +
							 strlen(s2) +
							 strlen(s3) + 1];
	newstr[0] = 0;

	strcat(newstr, s1);
	strcat(newstr, s2);
	strcat(newstr, s3);

	std::cout << "Результат конкатенации: " << newstr << std::endl;

	delete newstr;

	char input_buffer[20];
	std::cout << "Введите строку: ";
	std::cin.getline(input_buffer, 20);
	std::cout <<
			"Введена строка - \"" <<
			input_buffer <<
			"\"" <<
			std::endl;
}

int main()
{
	using namespace std::literals;

	std::string s1 = "Hello, world!";
	std::string s2 = "Мама мыла пилораму";
	auto s3 = "All your base are belong to us."s;

//	 * 1. Вывод строки на консоль
	std::cout << "Строка 1: " << s1 << std::endl;
	std::cout << "Строка 2: " << s2 << std::endl;
	std::cout << "Строка 3: " << s3 << std::endl;

//	 * 2. Определение длины строки
	std::cout << "Длина строки 1 = " << s1.length() << std::endl;
	std::cout << "Длина строки 2 = " << s2.length() << std::endl;
	std::cout << "Длина строки 3 = " << s3.length() << std::endl;

//	 * 3. Работа с отдельными символами
//	 * 4. Создание копии строки
	std::cout << "Символ 5 в строке 1 = " << s1[5] << std::endl;
	auto s1_copy = s1; // Копирование строки - просто присваивание
	s1_copy[5] = '!';
	std::cout << "Изменённая копия строки 1: " << s1_copy << std::endl;
	s1_copy[12] = '?';
	std::cout << "Изменённая копия строки 1: " << s1_copy << std::endl;
	std::cout << "Оригинал: " << s1 << std::endl;

//	 * 5. Извлечение подстроки
	auto s1_substr = s1.substr(7, 5);
	std::cout << "Фрагмент строки s1: " << s1_substr << std::endl;

//	 * 6. Замена подстроки
	std::string fragment = "people";
	s1_copy.replace(7, fragment.length(), fragment);
	std::cout << "Ещё раз: " << s1_copy << std::endl;

//	 * 7. Разбиение на части по разделителю
	std::stringstream s3_copy(s3);
	std::string substr;
	while (std::getline(s3_copy, substr, ' '))
		std::cout << "Кусок: " << substr << std::endl;

//	 * 8. Конкатенация строк
	auto newstr = s1 + s2 + s3;
	std::cout << "Результат конкатенации: " << newstr << std::endl;

//	 * 9. Ввод строки с консоли
	std::string line;
	std::cout << "Введите строку: ";
	std::getline(std::cin, line);
	std::cout <<
			"Введена строка - \"" <<
			line <<
			"\"" <<
			std::endl;

	auto c_string = "This is a C string";
	std::string cpp_string = c_string;

	std::string cpp_string_1 = "This is a C++ string";
	auto c_string_1 = cpp_string_1.c_str();

	return 0;
}


