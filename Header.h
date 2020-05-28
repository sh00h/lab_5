#pragma once
#include <string>
#include <fstream>
using namespace std;

class file // ����� ��� ������� ������ � ������� � ������� ������
{
private:
	string name;
	ofstream out;
	ifstream in;
public:
	file(string s) // ���������� � ����
	{
		name = s;
	}
	bool open_vvod(bool trunc) // �������� ofstream, ���� true �� � ������ trunc (trunc - ������� ������ � �����)
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
	void close_vvod() // �������� �����
	{
		out.close();
	}
	void vvod(int n) // ���� �����
	{
		out << n;
	}
	void vvod(string n) // ���� ������
	{
		out << n;
	}
	// vivod
	bool open_vivod(bool trunc) // ����� �� ������� ��������� ������
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
	void close_vivod() // �������� ������
	{
		in.close();
	}

	int vivod() // ���������� �����
	{
		string s;
		in >> s;
		
		return stoi(s);
	}
	void propysk() // �������, ������� ���������� ��� �������� ���������� �������
	{
		string s;
		in >> s;
	}
	bool end()// ��������� ����� �����
	{
		return in.eof();
	}
	void delete_last_symbol() // ������� ��������� ������ � �����
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
	bool isEmpty()// �������� �� �������
	{
		ifstream i;
		i.open(name, std::ios::binary | std::ios::ate);
		int n = i.tellg();
		i.close();
		if (n == 0) return true;
		else return false;
	}
};