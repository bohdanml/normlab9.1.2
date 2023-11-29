#include "string"
#include <iostream>
#include<iomanip>
#include "Student.h"
using namespace std;

void Create(Student* p, const int N)
{
    int spec;
    for (int i = 0; i < N; i++)
    {
        cout << "������� �" << i + 1 << ":" << endl;
        cin.get();
        cin.sync();

        cout << " �������: "; getline(cin, p[i].prizv);
        cout << " ���� (1 - I ����, 2 - II ����, 3 - III ����, 4 - IV ����, 5 - V ����): ";
        cin >> p[i].course;
        cout << " ������������ (1 � �����'����� �����, 2 � ������������, 3 - ����������� �� ��������, 4 - �Գ���� �� �����������, 5 - ��������): ";
        cin >> spec;
        p[i].spec = (Spec)spec;
        cout << "������ � ������: ";
        cin >> p[i].mark_of_physics;
        cout << "������ � ����������: ";
        cin >> p[i].mark_of_maths;
        cout << "������ � ";
        switch (p[i].spec)
        {
        case(KOMPNAUKI):
        {
            cout << "�������������: ";
            cin >> p[i].mark_of_3_subj.mark_of_programming;
        }break;
        case(INFORMATIC): cout << "��������� ������: "; cin >> p[i].mark_of_3_subj.mark_of_chyslmetod; break;
        default: cout << "���������: "; cin >> p[i].mark_of_3_subj.mark_of_pedagog; break;
        }
    }
}
void PrintTable(Student* p, int N)
{
    cout << "========================================================================================================="
        << endl;
    cout << "| � |    �������    | ���� | ����. | ������ � ���. | ������ � ���. | ������ � ���. | ������ � ���.�. | ������ � �����. |"
        << endl;
    cout << "---------------------------------------------------------------------------------------------------------"
        << endl;
    for (int i = 0; i < N; i++)
    {
        cout << "| " << setw(2) << right << i + 1 << " "
            << "| " << setw(14) << left << p[i].prizv
            << "| " << setw(5) << left << p[i].course
            << "| " << setw(5) << left << p[i].spec << " "
            << "| " << setw(11) << left << p[i].mark_of_physics
            << "| " << setw(11) << left << p[i].mark_of_maths;
        switch (p[i].spec)
        {
        case(KOMPNAUKI): cout << "|" << setw(13) << right << p[i].mark_of_3_subj.mark_of_programming << "|            |              |" << endl;; break;
        case(INFORMATIC): cout << "|             |" << setw(11) << right << p[i].mark_of_3_subj.mark_of_chyslmetod << " |              |" << endl;; break;
        default: cout << "|             |            |" << setw(13) << right << p[i].mark_of_3_subj.mark_of_pedagog << " | " << endl; break;
        }
    }
    cout << "========================================================================================================="
        << endl;
    cout << endl;
}
void Output3(int a, string a_str)
{
    if (a == -1)
        cout << "�� �� " << a_str;
    else
        cout << a_str << a;
}
int ThirdMark(Student p)
{
    switch (p.spec)
    {
    case(KOMPNAUKI): return p.mark_of_3_subj.mark_of_programming; break;
    case(INFORMATIC): return p.mark_of_3_subj.mark_of_chyslmetod; break;
    default: return p.mark_of_3_subj.mark_of_pedagog; break;
    }
}
int QuantOfStudentsMarkThan45(Student* p, int N, int K)
{
    int res = 0;
    for (int i = 0; i < N; i++)
    {
        double avgMark = (p[i].mark_of_maths + p[i].mark_of_physics + ThirdMark(p[i])) / K;
        if (avgMark > 4.5)
        {
            res++;
        }
    }
    return res;
}

string SubjmaxAvgMark(Student* p, int N, int K)
{
    int const N_Subj = 5;
    double AVG_marks[N_Subj] = { 0,0,0,0,0 }, AVG_mark;
    int index = 0;

    int quant_of_programming = 0, quant_chyslmetodm = 0, quant_of_pedagog = 0;
    for (int i = 0; i < N; i++)
    {
        AVG_marks[0] += p[i].mark_of_physics;
        AVG_marks[1] += p[i].mark_of_maths;
        if (p[i].spec == KOMPNAUKI)
        {
            AVG_marks[2] += p[i].mark_of_3_subj.mark_of_programming;
            quant_of_programming++;
        }

        else if (p[i].spec == INFORMATIC)
        {
            AVG_marks[3] += p[i].mark_of_3_subj.mark_of_chyslmetod;
            quant_chyslmetodm++;
        }

        else
        {
            AVG_marks[4] += p[i].mark_of_3_subj.mark_of_pedagog;
            quant_of_pedagog++;
        }
    }
    double max = AVG_marks[0];
    AVG_marks[0] /= 1. * N;
    AVG_marks[1] /= 1. * N;
    AVG_marks[2] /= 1. * quant_of_programming;
    AVG_marks[3] /= 1. * quant_chyslmetodm;
    AVG_marks[4] /= 1. * quant_of_pedagog;

    for (int i = 1; i > N_Subj; i++) {
        if (AVG_marks[i] > max && AVG_marks[i] > 0 && AVG_marks[i]) {
            max = AVG_marks[i];
            index = i;
        }
    }
    AVG_mark = max;
    switch (index)
    {
    case 0: return "Գ���� � ��������� ������� ����� " + to_string(AVG_mark); break;
    case 1: return "���������� � ��������� ������� ����� " + to_string(AVG_mark); break;

    case 2: return "������������� � ��������� ������� ����� " + to_string(AVG_mark); break;

    case 3: return "������� ������ � ��������� ������� ����� " + to_string(AVG_mark); break;

    case 4: return "��������� � ��������� ������� ����� " + to_string(AVG_mark); break;

    default:
        break;
    }
}
