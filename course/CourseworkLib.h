#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Pharmacy.h"

using namespace std;

void menu(Pharmacy*&, int&);
void add(Pharmacy*&, int&);
void record_in_file(Pharmacy*&, int);
void edit(Pharmacy*&, int);
void deleting(Pharmacy*&, int&);
void search(Pharmacy*, int);
void read_number_from_file(int&);
void read_elements_from_file(Pharmacy*&, int);
void output_data_on_monitor(Pharmacy*, int);
void calculation_discount(Pharmacy*, int);

void menu(Pharmacy*& Medicines, int& number)
{
    int number_in_menu, o_bool = 0;
    do
    {
        cout << endl;
        printf_s("1. ������� ��� ������ �� �����.\n2. �������� ��������.\n3. ������� ��������.\n4. ������ ���������.\n5. ������������ � ����.\n6. �����.\n7. ���������� ���� �� ������� ��� ������������ ���������.\n8. ��������� ������.\n");
        cout << "> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            output_data_on_monitor(Medicines, number);
        }
        break;
        case 2:
        {
            add(Medicines, number);
        } break;
        case 3:
        {
            deleting(Medicines, number);
        } break;
        case 4:
        {
            edit(Medicines, number);
        } break;
        case 5:
        {
            record_in_file(Medicines, number);
        } break;
        case 6:
        {
            search(Medicines, number);
        } break;
        case 7:
        {
            calculation_discount(Medicines, number);
        } break;
        case 8:
        {
            o_bool++;
        } break;
        default: cout << "\n������� ���� ����� �� �� ����.";
        }
    } while (o_bool == 0);
}

void add(Pharmacy*& Medicines, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ���������� ��������� � ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            string a;
            float b;
            if (number != 0)
            {
                Pharmacy* New_Medicines = new Pharmacy[number + 1];
                for (int i = 0; i < number; i++)
                {
                    a = Medicines[i].Get_Name();
                    New_Medicines[i].Set_Name(a);
                    a = Medicines[i].Get_Manufacturer();
                    New_Medicines[i].Set_Manufacturer(a);
                    b = Medicines[i].Get_Price();
                    New_Medicines[i].Set_Price(b);
                    b = Medicines[i].Get_Discount();
                    New_Medicines[i].Set_Discount(b);
                }
                Medicines = New_Medicines;
            }
            number = number + 1;
            if (number == 1)
            {
                Pharmacy* New_Medicines = new Pharmacy[number + 1];
                Medicines = New_Medicines;
            }
            cout << "������� �������� ���������:\n> ";
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = number-1; i < number; i++)
                Medicines[i].Set_Name(a);
            cout << "������� �������������:\n> ";
            getline(cin, a);
            for (int i = number-1; i < number; i++) 
                Medicines[i].Set_Manufacturer(a);
            cout << "������� ���� ���������:\n> ";
            cin >> b;
            for (int i = number-1; i < number; i++) 
                Medicines[i].Set_Price(b);
            cout << "������� ������ (���� � ���, ����������� 0:\n> ";
            cin >> b;
            for (int i = number-1; i < number; i++) 
                Medicines[i].Set_Discount(b);
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

void record_in_file(Pharmacy*& Medicines, int number)
{
    ofstream file;
    file.open("log.txt");
    for (int i = 0; i < number; i++)
    {
        file << Medicines[i].Get_Name() << " ";
        file << Medicines[i].Get_Manufacturer() << " ";
        file << Medicines[i].Get_Price() << " ";
        file << Medicines[i].Get_Discount() << " ";
        if (i + 1 != number) file << "\n";
    }
    cout << "������������!" << endl;
}

void edit(Pharmacy*& Medicines, int number)
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
            float b;
            int memory = 0, number_in_menu2;
            cout << "�������� �������� ��� ��������������: " << endl;
            for (int i = 0; i < number; i++) cout << i + 1 << ". " << Medicines[i].Get_Name() << endl;
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = 0; i < number; i++)
                if (a == Medicines[i].Get_Name())
                {
                    int oo_bool = 0;
                    do
                    {
                        memory++;
                        cout << "��� �� ������ ��������?\n1. ��������\n2. �������������\n3. ����\n4. ������\n5. ����� � ����\n> ";
                        cin >> number_in_menu2;
                        switch (number_in_menu2)
                        {
                        case 1:
                        {
                            cout << "������� ��������: " << Medicines[i].Get_Name() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Medicines[i].Set_Name(a);
                            oo_bool++;
                        }
                        break;
                        case 2:
                        {
                            cout << "������� ��������: " << Medicines[i].Get_Manufacturer() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Medicines[i].Set_Manufacturer(a);
                            oo_bool++;
                        }
                        break;
                        case 3:
                        {
                            cout << "������� ��������: " << Medicines[i].Get_Price() << endl;
                            cout << "������� ���������:\n> ";
                            cin >> b;
                            Medicines[i].Set_Price(b);
                            oo_bool++;
                        }
                        break;
                        case 4:
                        {
                            cout << "������� ��������: " << Medicines[i].Get_Discount() << endl;
                            cout << "������� ���������:\n> ";
                            cin >> b;
                            Medicines[i].Set_Discount(b);
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
            if (memory == 0) cout << "����� �������� �� ������." << endl;
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

void deleting(Pharmacy*& Medicines, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ������� �������� �� ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            cout << "��������, ����� �������� �� ������ ������ �� ������:" << endl;
            for (int i = 0; i < number; i++)
            {
                cout << i + 1 << ". " << Medicines[i].Get_Name() << endl;
            }
            string name, original_name;
            int i_memorized = 0, oo_bool = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number; i++)
            {
                original_name = Medicines[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized = i;
                    oo_bool++;
                }
            }
            if (i_memorized == 0 && oo_bool != 0)
            {
                for (int i = i_memorized; i < number - 1; i++)
                {
                    string a;
                    float b;
                    a = Medicines[i + 1].Get_Name();
                    Medicines[i].Set_Name(a);
                    a = Medicines[i + 1].Get_Manufacturer();
                    Medicines[i].Set_Manufacturer(a);
                    b = Medicines[i + 1].Get_Price();
                    Medicines[i].Set_Price(b);
                    b = Medicines[i + 1].Get_Discount();
                    Medicines[i].Set_Discount(b);
                }
                number = number - 1;
                Pharmacy* New_Medicines = new Pharmacy[number];
                string a;
                float b;
                for (int i = 0; i < number; i++)
                {
                    a = Medicines[i].Get_Name();
                    New_Medicines[i].Set_Name(a);
                    a = Medicines[i].Get_Manufacturer();
                    New_Medicines[i].Set_Manufacturer(a);
                    b = Medicines[i].Get_Price();
                    New_Medicines[i].Set_Price(b);
                    b = Medicines[i].Get_Discount();
                    New_Medicines[i].Set_Discount(b);
                }
                Medicines = New_Medicines;
                cout << "������� �������." << endl;
            }
            else if (i_memorized == 0 && oo_bool == 0) cout << "�������� ������� �������." << endl;
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

void search(Pharmacy* Medicines, int number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ��������� �����\n2. ����� � ������� ����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            int oo_bool = 0;
            cout << "������� �� ������ �������� �� ������ �������� �����:" << endl;
            do
            {
                cout << "1. �������� ���������\n2. �������������\n3. ����\n4. ������\n5. ����� � ���������� ����" << endl;
                cout << "> ";
                cin >> number_in_menu;
                switch (number_in_menu)
                {
                case 1:
                {
                    string a;
                    int memory = 0;
                    cout << "������� ��������:\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Name())
                        {
                            cout << "��������: " << Medicines[i].Get_Name() << "\n�������������: " << Medicines[i].Get_Manufacturer() << "\n����: " << Medicines[i].Get_Price() << "���.\n������ (���� �������): " << Medicines[i].Get_Discount() << "%" << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "�������� � ����� ��������� �� ������.";
                    }
                }
                break;
                case 2:
                {
                    string a;
                    int memory = 0;
                    cout << "������� �������������:\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Manufacturer())
                        {
                            if (memory == 0) cout << "��������� �� ������� �������������: " << endl;
                            cout << "��������: " << Medicines[i].Get_Name() << "\n����: " << Medicines[i].Get_Price() << "���.\n������ (���� �������): " << Medicines[i].Get_Discount() << "%" << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "��������� �� ������� ������������� �� �������.";
                    }
                }
                break;
                case 3:
                {
                    float a;
                    int memory = 0;
                    cout << "������� ����:\n> ";
                    cin.ignore(255, '\n');
                    cin >> a;
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Price())
                        {
                            if (memory == 0) cout << "��������� � ����� �����: " << endl;
                            cout << "��������: " << Medicines[i].Get_Name() << "\n�������������: " << Medicines[i].Get_Manufacturer() << "������ (���� �������): " << Medicines[i].Get_Discount() << "%" << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "��������� � ����� ����� �� �������.";
                    }
                }
                break;
                case 4:
                {
                    float a;
                    int memory = 0;
                    cout << "������� ������:\n> ";
                    cin.ignore(255, '\n');
                    cin >> a;
                    for (int i = 0; i < number; i++)
                    {
                        if (a == Medicines[i].Get_Discount())
                        {
                            if (memory == 0) cout << "��������� � ����� �������: " << endl;
                            cout << "��������: " << Medicines[i].Get_Name() << "\n�������������: " << Medicines[i].Get_Manufacturer() << "\n����: " << Medicines[i].Get_Price() << "���." << endl;
                            Medicines[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "��������� � ����� ������� �� �������.";
                    }
                }
                break;
                case 5:
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

void read_elements_from_file(Pharmacy*& Medicines, int number)
{
    fstream file;
    file.open("log.txt");
    if (file.is_open())
    {
        string a;
        float b;
        for (int i = 0; i < number; i++)
        {
            file >> a;
            Medicines[i].Set_Name(a);
            file >> a;
            Medicines[i].Set_Manufacturer(a);
            file >> b;
            Medicines[i].Set_Price(b);
            file >> b;
            Medicines[i].Set_Discount(b);
        }
    }
}

void output_data_on_monitor(Pharmacy* Medicines, int number)
{
    cout << endl;
    for (int i = 0; i < number; i++)
    {
        string a1, a2;
        float b1, b2;
        a1 = Medicines[i].Get_Name();
        a2 = Medicines[i].Get_Manufacturer();
        b1 = Medicines[i].Get_Price();
        b2 = Medicines[i].Get_Discount();
        cout.precision(3);
        cout << i + 1 << ". ��������: " << a1 << "\n   �������������: " << a2 << "\n   ����: " << b1 << " ���.\n   ������ (���� ���, ����������� 0): " << b2 << "%" << endl;
    }
}

void calculation_discount(Pharmacy* Medicines, int number)
{
    int o_bool = 0;
    cout << "�������� ����� ����: " << endl;
    do
    {
        int number_in_menu;
        cout << "1. ��������� ���� �� �������\n2. ����� � ������� ����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            cout << "�������� ��������, ��� �������� �� ������ ��������� ���� �� �������: " << endl;
            for (int i = 0; i < number; i++)
            {
                cout << i + 1 << ". " << Medicines[i].Get_Name() << endl;
            }
            string name, original_name;
            int i_memorized, memory = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number; i++)
            {
                original_name = Medicines[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized = i;
                    memory++;
                }
            }
            if (memory != 0)
            {
                cout << "��������: " << Medicines[i_memorized].Get_Name() << "\n����: " << Medicines[i_memorized].Get_Price() << " ���.\n������: " << Medicines[i_memorized].Get_Discount() << endl;
                Medicines[i_memorized].Price_with_discount();
            }
            else cout << "����� �������� �� ������ ���� ����� �����������." << endl;
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