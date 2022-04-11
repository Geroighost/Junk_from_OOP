﻿#include <iostream>
#include "Solution.h"
#include <fstream>

using namespace std;

void menu(int, Solution*);

int main()
{
    setlocale(LC_ALL, "Russian");
    int n = 0;
    float num1;
    double num2;
    long num3;
    cout << "Введите какое количество уравнений вы хотите ввести:\n> ";
    cin >> n;
    Solution* Equations = new Solution[n];
    for (int y = 0; y < n; y++)
    {
        cout << "Введите A, B и C в вашем " << y+1 << "-м уравнении (целое или вещественное):";
        for (int i = 3; i > 0; i--)
        {
            cout << "\n> ";
            if (i == 3) { cin >> num1; }
            else if (i == 2) { cin >> num2; }
            else if (i == 1) { cin >> num3; }
        }
        if (num1 != NULL)
        {
            Equations[y].set_A(num1);
        }
        if (num2 != NULL)
        {
            Equations[y].set_B(num2);
        }
        if (num3 != NULL)
        {
            Equations[y].set_C(num3);
        }
    }
    menu(n, Equations);
    return 0;
}

void menu(int n, Solution* Eq)
{
    int o = 0, number_in_menu;
    do
    {
        cout << "Какую операцию вы хотите провести?" << endl;
        if (n == 1)
        {
            cout << "1. Вывести условие.\n2. Вывести x1 и x2.\n3. Выход.\n> ";
            cin >> number_in_menu;
            switch (number_in_menu)
            {
            case 1:
            {
                for (int y = 0; y < n; y++) cout << "a = " << Eq[y].get_A() << ", b = " << Eq[y].get_B() << ", c = " << Eq[y].get_C() << endl;
            } break;
            case 2:
            {
                for (int y = 0; y < n; y++)
                {
                    float x1 = 0, x2 = 0;
                    Eq[y].method_coef_prop(x1, x2);
                    cout << "x1 = " << x1 << ", x2 = " << x2 << endl;
                }
            } break;
            case 3:
            {
                o = 1;
            } break;
            default: cout << "Не то число." << endl;
            };
        };
        if (n > 1)
        {
            cout << "1. Вывести все условия.\n2. Вывести x1 и x2 во всех уравнениях.\n3. Выход.\n> ";
            cin >> number_in_menu;
            switch (number_in_menu)
            {
            case 1:
            {
                for (int y = 0; y < n; y++) cout << y+1 << ") a = " << Eq[y].get_A() << ", b = " << Eq[y].get_B() << ", c = " << Eq[y].get_C() << endl;
            } break;
            case 2:
            {
                for (int y = 0; y < n; y++)
                {
                    float x1 = 0, x2 = 0;
                    Eq[y].method_coef_prop(x1, x2);
                    cout << y + 1 << ") x1 = " << x1 << ", x2 = " << x2 << endl;
                }
            } break;
            case 3:
            {
                o = 1;
            } break;
            default: cout << "Не то число." << endl;
            };
        };
    } while (o == 0);
    cout << "Сеанс завершен." << endl;
    Eq->~Solution;
}
