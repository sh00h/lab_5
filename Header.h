#pragma once
#include <string>
#include <fstream>
using namespace std;

class file // класс для удобной работы с записью и чтением файлов
{
private:
	string name;
	ofstream out;
	ifstream in;
public:
	file(string s) // коструктор с путём
	{
		name = s;
	}
	bool open_vvod(bool trunc) // открытие ofstream, если true то с флагом trunc (trunc - очищает данные в файле)
	{
		if (trunc)
		{
			out.open(name, ios::trunc);
		}
		else {
			out.open(name);
		}
		if (out.is_open())
			return true;
		else return false;
	}
	void close_vvod() // закрытие ввода
	{
		out.close();
	}
	void vvod(int n) // ввод числа
	{
		out << n;
	}
	void vvod(string n) // ввод строки
	{
		out << n;
	}
	// vivod
	bool open_vivod(bool trunc) // таким же образом открываем чтение
	{
		if (trunc)
		{
			in.open(name, ios::trunc);
		}
		else {
			in.open(name);
		}
		if (in.is_open())
			return true;
		else return false;
	}
	void close_vivod() // закрытие чтения
	{
		in.close();
	}

	int vivod() // счтитываем число
	{
		string s;
		in >> s;
		
		return stoi(s);
	}
	void propysk() // функцию, которая вызывается для пропуска последнего символа
	{
		string s;
		in >> s;
	}
	bool end()// проверить конец файла
	{
		return in.eof();
	}
	void delete_last_symbol() // удаляем последний пробел в файле
	{
		in.open(name);
		
		string s;
		getline(in, s);
		in.close();
		if (s.length() != 0) {
			s.erase(s.end() - 1);

			out.open(name, ios::trunc);
			out << s;

			out.close();
		}
	}
	bool isEmpty()// проверка на пустоту
	{
		ifstream i;
		i.open(name, std::ios::binary | std::ios::ate);
		int n = i.tellg();
		i.close();
		if (n == 0) return true;
		else return false;
	}
};