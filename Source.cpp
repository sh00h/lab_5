#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include<fstream>
#include<string>
#include"Header.h"
#include <ctime>
using namespace std;



int razmer = 10000; // ������ �������
int chislo = 1; // ����������, ������� �������� ��������� � �����
bool b1 = true, b2 = true, b3 = true; // ����������, ������� ������ ����������� ������������� ����� �� ������ �� ��� ������
int sravnenie(int n1, int n2, int n3) // ������� ���������, ����� �� ��� ����� �������, � ������ ����������� �� �������������
{
	if (!b1)
	{
		
		if (!b2) return 3;
		else if (!b3) return 2;
		else if (n2 <= n3) return 2;
		else return 3;
	}
	if (!b2)
	{
		
		if (!b1) return 3;
		else if (!b3) return 1;
		else if (n1 <= n3) return 1;
		else return 3;
	}
	if (!b3)
	{
		
		if (!b1) return 2;
		else if (!b2) return 1;
		else if (n1 <= n2) return 1;
		else return 2;
	}
	else {
		
		if (n1 <= n2 && n1 <= n3) return 1;
		else if (n2 <= n1 && n2 <= n3) return 2;
		else return 3;
	}
}
int main()
{
	setlocale(LC_ALL, "rus");
	// f - ���� � ����������� ��������
	file f("f.txt"), f1("f1.txt"), f2("f2.txt"), f3("f3.txt"), f4("f4.txt"), f5("f5.txt"), f6("f6.txt");
	if (!f.open_vvod(true))// ��������� ���� ��� ������
	{
		cout << "ERROR" << endl;
	}
	// ������� ������ � ����
	for (int i = 0; i <razmer; i++) {
		
		f.vvod(rand() % 1000); // ������ ��������� �����
		//f.vvod(i);
		if (i != razmer -1) f.vvod(" ");
	} 
	f.close_vvod(); // ��������� 
	
	// ��������� ��������� ����� �� 3 ����
	
	f.open_vivod(false); // ��������� ���� ��� ������, ��������� ��� ������
	f1.open_vvod(true);
	f2.open_vvod(true);
	f3.open_vvod(true);
	int popitka = 1; // ���������� �������� �� ��, � ����� ���� ������� �����
	
	int fl;


	while (!f.end()) { // ���� �� ����� �� ����� �����
		
			if (popitka == 1)
			{

				f1.vvod(f.vivod()); // ������ � ������ ���� ������ �����
				f1.vvod(" ");
				popitka++; // � ���������� �����
			}
			else if (popitka == 2)
			{
				
				f2.vvod(f.vivod()); // ������ ����� �� ������ ����
				f2.vvod(" ");
				popitka++;
			}
			else if (popitka == 3)
			{
			
				f3.vvod(f.vivod()); // ������ ����� � ������ ����, � ��� �����
				f3.vvod(" ");
				popitka = 1;
			
			}
	}
	f1.close_vvod(); // ��������� ��� ������
	f2.close_vvod();
	f3.close_vvod();
	f.close_vivod();


	f1.delete_last_symbol();// ������� ��������� ������� � ������
	f2.delete_last_symbol();
	f3.delete_last_symbol();
	int n1 = 0, n2 = 0, n3 = 0; // ���������� ��������� �� ����� �����
	int i1 = 0, i2 = 0, i3 = 0; // ���������� ������ ������� ��������� � �����

	int sr;
	while (true) {
		popitka = 1;
		// ��������� ������ ������
		f4.open_vvod(true);
		f5.open_vvod(true);
		f6.open_vvod(true);
		f1.open_vivod(false);
		f2.open_vivod(false);
		f3.open_vivod(false);


		while (!f1.end() || !f2.end() || !f3.end()) // ���� �� ����� �� ����� ��� ������
		{
			// ��������� ����������������� ������ ��� �����
			i1 = 0; i2 = 0; i3 = 0;
			b1 = true; b2 = true; b3 = true;
			if (f3.isEmpty()) { // ���� ���� ������, 
				b3 = false; // ���������� ���������� � ��� ������
				f3.propysk(); // ���������� ��������� ��������� �����k
			}
			if (f2.isEmpty()) // ���� ����� ��� � ����
			{
				b2 = false;
				f2.propysk();
			}
			if (!f1.end() && b1) // ��������� ������� : ���� �� ����� ����� � ���� ���� ����������� ����� �� ����� �����
			{
				n1 = f1.vivod(); // ����� �����
				i1++; // ����������� �������
			}
			else if (f1.end()) b1 = false; // ���� ����� �����, ������ ����������� � ���� ����������

			if (!f2.end() && b2) // ���� ����� ��� � ����
			{
				
				n2 = f2.vivod();
				i2++;
			}
			else if (f2.end()) b2 = false;

			if (!f3.end() && b3) // ���� ����� ��� � ����
			{
				
				n3 = f3.vivod();
				i3++;
			}
			else if (f3.end()) b3 = false;
			//--------------
			// ����������� �� ����� �� ������������� ������ �� ������
			if (popitka == 1) // � ������ ����(f4)
			{
				while (b1 || b2 || b3) { // ���� ���� ����������� ���������� ���� �� � ������ �����
					sr = sravnenie(n1, n2, n3);// ����� ����� ����������
					if (sr == 1)
					{
						
						f4.vvod(n1); // � ���� ������ ���������� �����
						if (i1 == chislo || f1.end()) b1 = false; // �� ���� ������� ���� �� ������ �����
						if (b1 && !f1.end()) // ���� ��������, �� � n1 ������� ��������� ������� �� �����
						{
							
							n1 = f1.vivod();
							i1++;
						}
						else if (f1.end()) b1 = false;
					}
					else if (sr == 2) // ���� �����, ������ � ������ �� ������� �����
					{
						
						f4.vvod(n2);
						if (i2 == chislo || f2.end()) b2 = false;
						if (b2 && !f2.end())
						{
							n2 = f2.vivod();
							i2++;
						}
					}
					else // ���� �����, ������ � ������ �� �������� �����
					{
						
						f4.vvod(n3);
						if (i3 == chislo || f3.end()) b3 = false;
						if (b3 && !f3.end())
						{
							n3 = f3.vivod();
							i3++;
						}
					}
					
					f4.vvod(" ");
				}
				popitka++; 
			}
			else if (popitka == 2) // ���� �����, ��� � ������ f4
			{
				while (b1 || b2 || b3) {
					sr = sravnenie(n1, n2, n3);
					if (sr == 1)
					{
					
						f5.vvod(n1);
						if (i1 == chislo || f1.end()) b1 = false;
						if (b1 && !f1.end())
						{
							
							n1 = f1.vivod();
							i1++;
						}
						else if (f1.end()) b1 = false;
					}
					else if (sr == 2)
					{
						f5.vvod(n2); 
						if (i2 == chislo || f2.end()) b2 = false;
						if (b2 && !f2.end())
						{
							
							n2 = f2.vivod();
							i2++;
						}
					}
					else
					{
						f5.vvod(n3); 
						if (i3 == chislo || f3.end()) b3 = false;
						if (b3 && !f3.end())
						{
							
							n3 = f3.vivod();
							i3++;
						}
					}
					f5.vvod(" "); 
				}
				popitka++;
			}
			else // � ������ f6
			{
				while (b1 || b2 || b3) {
					sr = sravnenie(n1, n2, n3);
					if (sr == 1)
					{
						f6.vvod(n1); 
						if (i1 == chislo || f1.end()) b1 = false;
						if (b1 && !f1.end())
						{
							n1 = f1.vivod(); 
							i1++;
						}
						else if (f1.end()) b1 = false;
					}
					else if (sr == 2)
					{
						f6.vvod(n2); 
						if (i2 == chislo || f2.end()) b2 = false;
						if (b2 && !f2.end())
						{
							n2 = f2.vivod(); 
							i2++;
						}
					}
					else
					{
						f6.vvod(n3); 
						if (i3 == chislo || f3.end()) b3 = false;
						if (b3 && !f3.end())
						{
							n3 = f3.vivod(); 
							i3++;
						}
					}
					f6.vvod(" "); 
				}
				popitka = 1;
			}

		}

		// ��������� ��� ������
		f4.close_vvod();
		f5.close_vvod();
		f6.close_vvod();
		f1.close_vivod();
		f2.close_vivod();
		f3.close_vivod();
		
		if (f5.isEmpty() && f6.isEmpty()) { // ���� � ����� f5 � f6 �� �������� ���������, �� � f4 ��������� ��������������� ������
			fl = 4;
			break;
		}

		f4.delete_last_symbol();
		f5.delete_last_symbol();
		f6.delete_last_symbol();
		// �������� ��� ���� �������� ��� � ������, ������ ��������: ������� ����� �� f4-f6 � �����, ������� � ��� ���� ������, � ����� f1-f3
		f1.open_vvod(true);
		f2.open_vvod(true); 
		f3.open_vvod(true);
		f4.open_vivod(false);
		f5.open_vivod(false);
		f6.open_vivod(false);
		chislo *= 3; // ����������� ��������� � ����� ����������� � ��� ����
		popitka = 1;
		while (!f4.end() || !f5.end() || !f6.end())  
		{
			// ��������� ����������������� ������ ��� �����
			i1 = 0; i2 = 0; i3 = 0;
			b1 = true; b2 = true; b3 = true;
			if (f5.isEmpty()) {
				b3 = false;
				f6.propysk();
			}
			if (f5.isEmpty())
			{
				b2 = false;
				f5.propysk();
			}
			if (!f4.end() && b1)
			{
				n1 = f4.vivod(); 
				i1++;
			}
			else if (f4.end()) b1 = false;

			if (!f5.end() && b2)
			{
				n2 = f5.vivod(); 
				i2++;
			}
			else if (f5.end()) b2 = false;

			if (!f6.end() && b3)
			{
				n3 = f6.vivod();
				i3++;
			}
			else if (f6.end()) b3 = false;
			//--------------
			if (popitka == 1) // � f1 
			{
				while (b1 || b2 || b3) {
					sr = sravnenie(n1, n2, n3);
					if (sr == 1)
					{
						f1.vvod(n1); 
						if (i1 == chislo || f4.end()) b1 = false;
						if (b1 && !f4.end())
						{
							n1 = f4.vivod(); 
							i1++;
						}
						else if (f4.end()) b1 = false;
					}
					else if (sr == 2)
					{
						f1.vvod(n2); 
						if (i2 == chislo || f5.end()) b2 = false;
						if (b2 && !f5.end())
						{
							n2 = f5.vivod(); 
							i2++;
						}
					}
					else
					{
						f1.vvod(n3);
						if (i3 == chislo || f6.end()) b3 = false;
						if (b3 && !f6.end())
						{
							n3 = f6.vivod(); 
							i3++;
						}
					}
					f1.vvod(" "); 
				}
				popitka++;
			}
			else if (popitka == 2) // � f2
			{
				while (b1 || b2 || b3) {
					sr = sravnenie(n1, n2, n3);
					if (sr == 1)
					{
						f2.vvod(n1); 
						if (i1 == chislo || f4.end()) b1 = false;
						if (b1 && !f4.end())
						{
							n1 = f4.vivod(); 
							i1++;
						}
						else if (f4.end()) b1 = false;
					}
					else if (sr == 2)
					{
						f2.vvod(n2);
						if (i2 == chislo || f5.end()) b2 = false;
						if (b2 && !f5.end())
						{
							n2 = f5.vivod();
							i2++; 
						}
					}
					else
					{
						f2.vvod(n3); 
						if (i3 == chislo || f6.end()) b3 = false;
						if (b3 && !f6.end())
						{
							n3 = f6.vivod();
							i3++; 
						}
					}
					f2.vvod(" "); 
					
				}
				popitka++;
			}
			else // � f3
			{
				while (b1 || b2 || b3) {
					sr = sravnenie(n1, n2, n3);
					if (sr == 1)
					{
						f3.vvod(n1); 
						if (i1 == chislo || f4.end()) b1 = false;
						if (b1 && !f4.end())
						{
							n1 = f4.vivod(); 
							i1++;
						}
						else if (f4.end()) b1 = false;
					}
					else if (sr == 2)
					{
						f3.vvod(n2); 
						if (i2 == chislo || f5.end()) b2 = false;
						if (b2 && !f5.end())
						{
							n2 = f5.vivod(); 
							i2++;
						}
					}
					else
					{
						f3.vvod(n3); 
						if (i3 == chislo || f6.end()) b3 = false;
						if (b3 && !f6.end())
						{
							n3 = f6.vivod(); 
							i3++;
						}
					}
					f3.vvod(" "); 

				}
				popitka = 1;
			}

		}

		chislo *= 3; // ����������� � ��� ���� ����������� ��������� � �����
		f1.close_vvod();
		f2.close_vvod();
		f3.close_vvod();
		f4.close_vivod();
		f5.close_vivod();
		f6.close_vivod();
		if (f3.isEmpty() && f2.isEmpty()) { // ���� f2 and f3 ������ �� � f1 ��������������� ������
			fl = 1;
			break;
		}
		f1.delete_last_symbol();
		f2.delete_last_symbol();
		f3.delete_last_symbol();

	}
	
	if (fl == 1)
	{
		cout << "������ ������������ � ����� f1.txt\n";
	}
	else cout << "������ ������������ � ����� f4.txt\n";
    system("pause");
	return 0;
}