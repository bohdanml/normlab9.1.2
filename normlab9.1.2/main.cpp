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
	cout << "������ ������� �������� N: "; cin >> N;

	Student* p = new Student[N];
	cout << endl << endl << endl;
	do
	{
		cout << "\n������� ��:" << endl << endl;
		cout << "(1) � �������� ������� \n(2) � ������� �������, \n(3) � ������� ������� ��������, �� ����� ������ ����� 4,5, �� �������� ������� �������� \n(4) - ������� ������� � ��������� ������� �����\n(0) - �����\n������ ����� �����: ";
		cin >> menuItem;
		switch (menuItem)
		{
		case 1: Create(p, N); break;
		case 2: PrintTable(p, N); break;
		case 3: Output3(QuantOfStudentsMarkThan45(p, N, K), "ʳ������ ��������, �� ����� ������ ����� 4,5: "); break;
		case 4: cout << SubjmaxAvgMark(p, N, K); break;
		case 0: break;
		}
	} while (menuItem != 0);

	cout << endl << endl << endl;

}