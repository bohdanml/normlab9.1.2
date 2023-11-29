#include <iostream>
#include <Windows.h>
#include <string>
#include"Student.h"
using namespace std;


int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int N, K = 3, menuItem;
	cout << "¬вед≥ть к≥льк≥сть студент≥в N: "; cin >> N;

	Student* p = new Student[N];
	cout << endl << endl << endl;
	do
	{
		cout << "\n¬ибер≥ть д≥ю:" << endl << endl;
		cout << "(1) Ц —творити таблицю \n(2) Ц ¬ивести таблицю, \n(3) Ц ¬ивести к≥льк≥сть студент≥в, €к≥ мають оц≥нку б≥льшу 4,5, за вказаною к≥льк≥стю предмет≥в \n(4) - ¬ивести предмет з найб≥льшим середн≥м балом\n(0) - ¬их≥д\n¬вед≥ть номер опц≥њ: ";
		cin >> menuItem;
		switch (menuItem)
		{
		case 1: Create(p, N); break;
		case 2: PrintTable(p, N); break;
		case 3: Output3(QuantOfStudentsMarkThan45(p, N, K), " ≥льк≥сть студент≥в, €к≥ мають оц≥нку б≥льше 4,5: "); break;
		case 4: cout << SubjmaxAvgMark(p, N, K); break;
		case 0: break;
		}
	} while (menuItem != 0);

	cout << endl << endl << endl;

}