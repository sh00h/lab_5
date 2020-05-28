#define _CRT_SECURE_NO_WARNINGS
#include <Windows.h>
#include <iostream>
#include<fstream>
#include<string>
#include"Header.h"
#include <ctime>
using namespace std;



int razmer = 10000; // размер массива
int chislo = 1; // переменная, которая содержит элементов в серии
bool b1 = true, b2 = true, b3 = true; // переменная, которая хранит возможность использования числа из одного из трёх файлов
int sravnenie(int n1, int n2, int n3) // функция возращает, какое из трёх чисел мменьше, с учётом возможности их использования
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
	// f - файл с изначальным массивом
	file f("f.txt"), f1("f1.txt"), f2("f2.txt"), f3("f3.txt"), f4("f4.txt"), f5("f5.txt"), f6("f6.txt");
	if (!f.open_vvod(true))// открываем файл для записи
	{
		cout << "ERROR" << endl;
	}
	// заносим данные в файл
	for (int i = 0; i <razmer; i++) {
		
		f.vvod(rand() % 1000); // вводим случайные числа
		//f.vvod(i);
		if (i != razmer -1) f.vvod(" ");
	} 
	f.close_vvod(); // закрываем 
	
	// начальное разбиение чисел на 3 файл
	
	f.open_vivod(false); // открываем файл для чтения, остальные для записи
	f1.open_vvod(true);
	f2.open_vvod(true);
	f3.open_vvod(true);
	int popitka = 1; // переменная отвечает за то, в какой файл заносим числа
	
	int fl;


	while (!f.end()) { // пока не дошли до конца файла
		
			if (popitka == 1)
			{

				f1.vvod(f.vivod()); // вводим в первый файл первое число
				f1.vvod(" ");
				popitka++; // к следующему файлу
			}
			else if (popitka == 2)
			{
				
				f2.vvod(f.vivod()); // второе число во второй файл
				f2.vvod(" ");
				popitka++;
			}
			else if (popitka == 3)
			{
			
				f3.vvod(f.vivod()); // третье число в третий файл, и так далее
				f3.vvod(" ");
				popitka = 1;
			
			}
	}
	f1.close_vvod(); // закрываем все потоки
	f2.close_vvod();
	f3.close_vvod();
	f.close_vivod();


	f1.delete_last_symbol();// удаляем последние пробелы в файлах
	f2.delete_last_symbol();
	f3.delete_last_symbol();
	int n1 = 0, n2 = 0, n3 = 0; // переменные считанные из файла числа
	int i1 = 0, i2 = 0, i3 = 0; // переменные хранят порядок ээлемента в файла

	int sr;
	while (true) {
		popitka = 1;
		// открываем нужные потоки
		f4.open_vvod(true);
		f5.open_vvod(true);
		f6.open_vvod(true);
		f1.open_vivod(false);
		f2.open_vivod(false);
		f3.open_vivod(false);


		while (!f1.end() || !f2.end() || !f3.end()) // пока не дошли до конца трёх файлов
		{
			// начальное инициализирование первых трёх чисел
			i1 = 0; i2 = 0; i3 = 0;
			b1 = true; b2 = true; b3 = true;
			if (f3.isEmpty()) { // если файл пустой, 
				b3 = false; // невозможно обратиться к его числам
				f3.propysk(); // пропускаем последний невидимый симвоk
			}
			if (f2.isEmpty()) // тоже самое что и выше
			{
				b2 = false;
				f2.propysk();
			}
			if (!f1.end() && b1) // проверяем условие : если не конец файла и если есть возможность взять из файла число
			{
				n1 = f1.vivod(); // берем число
				i1++; // увеличиваем позицию
			}
			else if (f1.end()) b1 = false; // если конец файла, делаем невозможным к нему обратиться

			if (!f2.end() && b2) // тоже самое что и выше
			{
				
				n2 = f2.vivod();
				i2++;
			}
			else if (f2.end()) b2 = false;

			if (!f3.end() && b3) // тоже самое что и выше
			{
				
				n3 = f3.vivod();
				i3++;
			}
			else if (f3.end()) b3 = false;
			//--------------
			// раскидываем на число по упорядоченным сериям по файлам
			if (popitka == 1) // в первый файл(f4)
			{
				while (b1 || b2 || b3) { // пока есть возможность обратиться хотя бы к одному файлу
					sr = sravnenie(n1, n2, n3);// какое число наименьшее
					if (sr == 1)
					{
						
						f4.vvod(n1); // в файл вводим наименьшее число
						if (i1 == chislo || f1.end()) b1 = false; // не даем забрать файл из другой серии
						if (b1 && !f1.end()) // если возможно, то в n1 заносим следующий элемент из файла
						{
							
							n1 = f1.vivod();
							i1++;
						}
						else if (f1.end()) b1 = false;
					}
					else if (sr == 2) // тоже самое, только с числом из второго файла
					{
						
						f4.vvod(n2);
						if (i2 == chislo || f2.end()) b2 = false;
						if (b2 && !f2.end())
						{
							n2 = f2.vivod();
							i2++;
						}
					}
					else // тоже самое, только с числом из третьего файла
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
			else if (popitka == 2) // тоже самое, что с файлом f4
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
			else // с файлом f6
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

		// закрываем все потоки
		f4.close_vvod();
		f5.close_vvod();
		f6.close_vvod();
		f1.close_vivod();
		f2.close_vivod();
		f3.close_vivod();
		
		if (f5.isEmpty() && f6.isEmpty()) { // если в файле f5 и f6 не осталось элементов, то в f4 находится отсортированный массив
			fl = 4;
			break;
		}

		f4.delete_last_symbol();
		f5.delete_last_symbol();
		f6.delete_last_symbol();
		// проводим все теже операции что и раньше, только наоборот: сливаем серии из f4-f6 в серии, которые в три раза больше, в файлы f1-f3
		f1.open_vvod(true);
		f2.open_vvod(true); 
		f3.open_vvod(true);
		f4.open_vivod(false);
		f5.open_vivod(false);
		f6.open_vivod(false);
		chislo *= 3; // количевство элементов в серии увеличиваем в три раза
		popitka = 1;
		while (!f4.end() || !f5.end() || !f6.end())  
		{
			// начальное инициализирование первых трёх чисел
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
			if (popitka == 1) // в f1 
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
			else if (popitka == 2) // в f2
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
			else // в f3
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

		chislo *= 3; // увеличиваем в три раза количевство элементов в серии
		f1.close_vvod();
		f2.close_vvod();
		f3.close_vvod();
		f4.close_vivod();
		f5.close_vivod();
		f6.close_vivod();
		if (f3.isEmpty() && f2.isEmpty()) { // если f2 and f3 пустые то в f1 отсортированный массив
			fl = 1;
			break;
		}
		f1.delete_last_symbol();
		f2.delete_last_symbol();
		f3.delete_last_symbol();

	}
	
	if (fl == 1)
	{
		cout << "Массив отсортирован в файле f1.txt\n";
	}
	else cout << "Массив отсортирован в файле f4.txt\n";
    system("pause");
	return 0;
}