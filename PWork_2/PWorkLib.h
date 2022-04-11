#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Library.h"

using namespace std;

void menu(Library*&, int&);
void add(Library*&, int&);
void record_in_file(Library*&, int);
void edit(Library*&, int);
void deleting(Library*&, int&);
void search(Library*, int);
void read_number_from_file(int&);
void read_elements_from_file(Library*&, int);
void output_data_on_monitor(Library*, int);

void delete_underscores(string& str)
{
    int n = str.length(), i = 0;
    while (i < n)
    {
        if (str[i] == '_')
        {
            str.replace(i, 1, " ");
        }
        i++;
    }
}

void add_underscores(string& str)
{
    int n = str.length(), i = 0;
    while (i < n)
    {
        if (str[i] == ' ')
        {
            str.replace(i, 1, "_");
        }
        i++;
    }
}

void menu(Library*& My_Library, int& number)
{
    int number_in_menu, o_bool = 0;
    do
    {
        cout << endl;
        printf_s("1. ������� ��� �����.\n2. �������� �����.\n3. ������� �����.\n4. ������ ���������.\n5. ������������ � ����.\n6. ������ ��������.\n7. ��������� ������.\n");
        cout << "> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            output_data_on_monitor(My_Library, number);
        }
        break;
        case 2:
        {
            add(My_Library, number);
        } break;
        case 3:
        {
            deleting(My_Library, number);
        } break;
        case 4:
        {
            edit(My_Library, number);
        } break;
        case 5:
        {
            record_in_file(My_Library, number);
        } break;
        case 6:
        {
            search(My_Library, number);
        } break;
        case 7:
        {
            o_bool++;
        } break;
        default: cout << "\n������� ���� ����� �� �� ����.";
        }
    } while (o_bool == 0);
}

void add(Library*& My_Library, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ���������� ����� � ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            string a;
            int b;
            if (number != 0)
            {
                Library* New_Library = new Library[number + 1];
                for (int i = 0; i < number; i++)
                {
                    a = My_Library[i].Get_Name();
                    New_Library[i].Set_Name(a);
                    a = My_Library[i].Get_Author();
                    New_Library[i].Set_Author(a);
                    b = My_Library[i].Get_Year();
                    New_Library[i].Set_Year(b);
                    b = My_Library[i].Get_Quantity();
                    New_Library[i].Set_Quantity(b);
                }
                My_Library = New_Library;
            }
            number = number + 1;
            if (number == 1)
            {
                Library* New_Library = new Library[number + 1];
                My_Library = New_Library;
            }
            cout << "������� �������� �����:\n> ";
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = number - 1; i < number; i++)
                My_Library[i].Set_Name(a);
            cout << "������� ������:\n> ";
            getline(cin, a);
            for (int i = number - 1; i < number; i++)
                My_Library[i].Set_Author(a);
            cout << "������� ��� �������:\n> ";
            cin >> b;
            for (int i = number - 1; i < number; i++)
                My_Library[i].Set_Year(b);
            cout << "������� ���������� ���� � ����������:\n> ";
            cin >> b;
            for (int i = number - 1; i < number; i++)
                My_Library[i].Set_Quantity(b);
            cout << "���������� ������ �������." << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "����� �� �� ����." << endl;
        }
    } while (o_bool == 0);
}

void record_in_file(Library*& My_Library, int number)
{
    ofstream file;
    file.open("log.txt");
    for (int i = 0; i < number; i++)
    {
        string a = My_Library[i].Get_Name();
        add_underscores(a);
        file << a << " ";
        a = My_Library[i].Get_Author();
        add_underscores(a);
        file << a << " ";
        file << My_Library[i].Get_Year() << " ";
        file << My_Library[i].Get_Quantity() << " ";
        if (i + 1 != number) file << "\n";
    }
    cout << "������������!" << endl;
}

void edit(Library*& My_Library, int number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ������ ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            string a;
            int b;
            int memory = 0, number_in_menu2;
            cout << "�������� ����� ��� ��������������: " << endl;
            for (int i = 0; i < number; i++) cout << i + 1 << ". " << My_Library[i].Get_Name() << endl;
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = 0; i < number; i++)
                if (a == My_Library[i].Get_Name())
                {
                    int oo_bool = 0;
                    do
                    {
                        memory++;
                        cout << "��� �� ������ ��������?\n1. ��������\n2. ������\n3. ��� �������\n4. ����������\n5. ����� � ����\n> ";
                        cin >> number_in_menu2;
                        switch (number_in_menu2)
                        {
                        case 1:
                        {
                            cout << "������� ��������: " << My_Library[i].Get_Name() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            My_Library[i].Set_Name(a);
                            oo_bool++;
                        }
                        break;
                        case 2:
                        {
                            cout << "������� ��������: " << My_Library[i].Get_Author() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            My_Library[i].Set_Author(a);
                            oo_bool++;
                        }
                        break;
                        case 3:
                        {
                            cout << "������� ��������: " << My_Library[i].Get_Year() << endl;
                            cout << "������� ���������:\n> ";
                            cin >> b;
                            My_Library[i].Set_Year(b);
                            oo_bool++;
                        }
                        break;
                        case 4:
                        {
                            cout << "������� ��������: " << My_Library[i].Get_Quantity() << endl;
                            cout << "������� ���������:\n> ";
                            cin >> b;
                            My_Library[i].Set_Quantity(b);
                            oo_bool++;
                        }
                        break;
                        case 5:
                        {
                            oo_bool++;
                        }
                        break;
                        default: cout << "����� �� �� ����.";
                        }
                    } while (oo_bool == 0);
                }
            if (memory == 0) cout << "����� ����� �� �������." << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "����� �� �� ����." << endl;
        }
    } while (o_bool == 0);
}

void deleting(Library*& My_Library, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ������� ����� �� ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            cout << "��������, ����� ����� �� ������ ������ �� ������:" << endl;
            for (int i = 0; i < number; i++)
            {
                cout << i + 1 << ". " << My_Library[i].Get_Name() << endl;
            }
            string name, original_name;
            int i_memorized = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number; i++)
            {
                original_name = My_Library[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized = i;
                }
            }
            if (i_memorized != 0)
            {
                for (int i = i_memorized; i < number - 1; i++)
                {
                    string a;
                    int b;
                    a = My_Library[i + 1].Get_Name();
                    My_Library[i].Set_Name(a);
                    a = My_Library[i + 1].Get_Author();
                    My_Library[i].Set_Author(a);
                    b = My_Library[i + 1].Get_Year();
                    My_Library[i].Set_Year(b);
                    b = My_Library[i + 1].Get_Quantity();
                    My_Library[i].Set_Quantity(b);
                }
                number = number - 1;
                Library* New_Library = new Library[number];
                string a;
                int b;
                for (int i = 0; i < number; i++)
                {
                    a = My_Library[i].Get_Name();
                    New_Library[i].Set_Name(a);
                    a = My_Library[i].Get_Author();
                    New_Library[i].Set_Author(a);
                    b = My_Library[i].Get_Year();
                    New_Library[i].Set_Year(b);
                    b = My_Library[i].Get_Quantity();
                    New_Library[i].Set_Quantity(b);
                }
                My_Library = New_Library;
                cout << "������� �������." << endl;
            }
            else cout << "����� � ����� ��������� �� �������" << endl;
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "����� �� �� ����" << endl;
        }
    } while (o_bool == 0);
}

void search(Library* My_Library, int number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ������� ��������\n2. ����� � ������� ����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            int oo_bool = 0;
            cout << "��������, ��� �� ������ �������:" << endl;
            do
            {
                cout << "1. �����, ������������� �� ������� ������.\n2. �����, ������������� �� ����.\n3. ����� � ���������� ����" << endl;
                cout << "> ";
                cin >> number_in_menu;
                switch (number_in_menu)
                {
                case 1:
                {
                    string* mass = new string[number];
                    for (int i = 0; i < number; i++) mass[i] = My_Library[i].Get_Author();
                    for (int i = 0; i < number - 1; i++)
                    {
                        for (int j = 0; j < number - j; j++)
                        {
                            if (mass[j] > mass[j + 1])
                            {
                                string t = mass[j];
                                mass[j] = mass[j + 1];
                                mass[j + 1] = t;
                            }
                        }
                    }
                    for (int i = 0; i < number; i++)
                    {
                        int i_memorized = 0;
                        for (int j = 0; j < number; j++)
                        {
                            string a = My_Library[j].Get_Author();
                            if (mass[i] == a)
                                i_memorized = j;
                        }
                        cout << i + 1 << ". ��������: " << My_Library[i_memorized].Get_Name() << "\n   �����: " << My_Library[i_memorized].Get_Author() << "\n   ��� �������: " << My_Library[i_memorized].Get_Year() << "\n   ����������: " << My_Library[i_memorized].Get_Quantity() << endl;
                    }
                }
                break;
                case 2:
                {
                    int *mass = new int[number];
                    for (int i = 0; i < number; i++) mass[i] = My_Library[i].Get_Year();
                    for (int i = 0; i < number - 1; i++)
                    {
                        for (int j = 0; j < number - j; j++)
                        {
                            if (mass[j] > mass[j + 1])
                            {
                                int t = mass[j];
                                mass[j] = mass[j + 1];
                                mass[j + 1] = t;
                            }
                        }
                    }
                    for (int i = 0; i < number; i++)
                    {
                        int i_memorized = 0;
                        for (int j = 0; j < number; j++)
                        {
                            int a = My_Library[j].Get_Year();
                            if (mass[i] == a)
                                i_memorized = j;
                        }
                        cout << i + 1 << ". ��������: " << My_Library[i_memorized].Get_Name() << "\n   �����: " << My_Library[i_memorized].Get_Author() << "\n   ��� �������: " << My_Library[i_memorized].Get_Year() << "\n   ����������: " << My_Library[i_memorized].Get_Quantity() << endl;
                    }
                }
                break;
                case 3:
                {
                    oo_bool++;
                }
                break;
                default: cout << "��������� ����.";
                }
            } while (oo_bool == 0);
        }
        break;
        case 2:
        {
            o_bool++;
        }
        break;
        default: cout << "����� �� �� ����." << endl;
        }
    } while (o_bool == 0);
}

void read_number_from_file(int& number_of_elements)
{
    fstream file;
    char mainrow[200];
    file.open("log.txt");
    if (file.is_open())
    {
        while (!file.eof())
        {
            file.getline(mainrow, 200);
            number_of_elements++;
        }
        file.close();
    }
    else
    {
        cout << "Log-����� ������ ��������� �� ����������, ���� ��� ������ ������ ���������." << endl;
    }
}

void read_elements_from_file(Library*& My_Library, int number)
{
    fstream file;
    file.open("log.txt");
    if (file.is_open())
    {
        string a;
        int b;
        for (int i = 0; i < number; i++)
        {
            file >> a;
            delete_underscores(a);
            My_Library[i].Set_Name(a);
            file >> a;
            delete_underscores(a);
            My_Library[i].Set_Author(a);
            file >> b;
            My_Library[i].Set_Year(b);
            file >> b;
            My_Library[i].Set_Quantity(b);
        }
    }
}

void output_data_on_monitor(Library* My_Library, int number)
{
    cout << endl;
    for (int i = 0; i < number; i++)
    {
        string a1, a2;
        int b1, b2;
        a1 = My_Library[i].Get_Name();
        a2 = My_Library[i].Get_Author();
        b1 = My_Library[i].Get_Year();
        b2 = My_Library[i].Get_Quantity();
        cout.precision(2);
        cout << i + 1 << ". ��������: " << a1 << "\n   �����: " << a2 << "\n   ��� �������: " << b1 << "\n   ����������: " << b2 << endl;
    }
}