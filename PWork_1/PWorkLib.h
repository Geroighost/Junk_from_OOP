#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include "Calls.h"

using namespace std;

void menu(Calls*&, int&);
void add(Calls*&, int&);
void record_in_file(Calls*&, int);
void edit(Calls*&, int);
void sorting(Calls*, int);
void read_number_from_file(int&);
void read_elements_from_file(Calls*&, int);
void output_data_on_monitor(Calls*, int);
void for_sorting(Calls*, int, int, int&, int&, int&, int&, int&, int&, int&, int&, int&, int&, float&);


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

void menu(Calls*& My_Calls, int& number)
{
    int number_in_menu, o_bool = 0;
    do
    {
        cout << endl;
        printf_s("1. ������� ��� ������.\n2. �������� ������.\n3. ������ ���������.\n4. ������������ � ����.\n5. ���������� �������.\n6. ��������� ������.\n");
        cout << "> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            output_data_on_monitor(My_Calls, number);
        }
        break;
        case 2:
        {
            add(My_Calls, number);
        } break;
        case 3:
        {
            edit(My_Calls, number);
        } break;
        case 4:
        {
            record_in_file(My_Calls, number);
        } break;
        case 5:
        {
            sorting(My_Calls, number);
        } break;
        case 6:
        {
            o_bool++;
        } break;
        default: cout << "\n������� ���� ����� �� �� ����.";
        }
    } while (o_bool == 0);
}

void add(Calls*& My_Calls, int& number)
{
    int number_in_menu, o_bool = 0;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ���������� ������ � ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            int a;
            string b;
            float c;
            if (number != 0)
            {
                Calls* New_Calls = new Calls[number + 1];
                for (int i = 0; i < number; i++)
                {
                    b = My_Calls[i].Get_Caller_Number();
                    New_Calls[i].Set_Caller_Number(b);
                    b = My_Calls[i].Get_Caller_Name();
                    New_Calls[i].Set_Caller_Name(b);
                    a = My_Calls[i].Get_Incoming_Or_Outgoing();
                    New_Calls[i].Set_Incoming_Or_Outgoing(a);
                    b = My_Calls[i].Get_Incoming_Or_Outgoing_Number();
                    New_Calls[i].Set_Incoming_Or_Outgoing_Number(b);
                    b = My_Calls[i].Get_Day_Of_Call();
                    New_Calls[i].Set_Day_Of_Call(b);
                    b = My_Calls[i].Get_Month_Of_Call();
                    New_Calls[i].Set_Month_Of_Call(b);
                    b = My_Calls[i].Get_Year_Of_Call();
                    New_Calls[i].Set_Year_Of_Call(b);
                    b = My_Calls[i].Get_Hour_Of_Call();
                    New_Calls[i].Set_Hour_Of_Call(b);
                    b = My_Calls[i].Get_Minutes_Of_Call();
                    New_Calls[i].Set_Minutes_Of_Call(b);
                    b = My_Calls[i].Get_Hours_Called();
                    New_Calls[i].Set_Hours_Called(b);
                    b = My_Calls[i].Get_Minutes_Called();
                    New_Calls[i].Set_Minutes_Called(b);
                    b = My_Calls[i].Get_Seconds_Called();
                    New_Calls[i].Set_Seconds_Called(b);
                    c = My_Calls[i].Get_Tariff_Of_One_Minute();
                    New_Calls[i].Set_Tariff_Of_One_Minute(c);
                }
                My_Calls = New_Calls;
            }
            number = number + 1;
            if (number == 1)
            {
                Calls* New_Calls = new Calls[number + 1];
                My_Calls = New_Calls;
            }
            cout << "������� ����� �������� (��� �����):\n> ";
            cin.ignore(255, '\n');
            getline(cin, b);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Caller_Number(b);
            cout << "������� ��� ��������:\n> ";
            getline(cin, b);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Caller_Name(b);
            cout << "������� 1, ���� ������ ��������, ��� 2, ���� ���������:\n";
            for (bool oo_bool = false; oo_bool == false; )
            {
                cout << "> ";
                cin >> a;
                switch (a)
                {
                case 1:
                {
                    oo_bool = true;
                } break;
                case 2:
                {
                    oo_bool = true;
                } break;
                default: cout << "����� ��������, ��������� ����." << endl;
                }
            }
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Incoming_Or_Outgoing(a);
            cout << "������� ����� ���������� ��� ��������� ��������:\n> ";
            cin.ignore(255, '\n');
            getline(cin, b);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Incoming_Or_Outgoing_Number(b);
            cout << "������� ���� ������ � ���� DD-MM-YYYY.\n> ";
            getline(cin, b);
            string str = b.substr(0, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Day_Of_Call(str);
            str = b.substr(3, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Month_Of_Call(str);
            str = b.substr(6, 4);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Year_Of_Call(str);
            cout << "������� ����� ������ � ���� HH:MM.\n> ";
            getline(cin, b);
            str = b.substr(0, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Hour_Of_Call(str);
            str = b.substr(3, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Minutes_Of_Call(str);
            cout << "������� ������� ������ ������ � ���� HH:MM:SS.\n> ";
            getline(cin, b);
            str = b.substr(0, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Hours_Called(str);
            str = b.substr(3, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Minutes_Called(str);
            str = b.substr(6, 2);
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Seconds_Called(str);
            cout << "������� ����� ����� ������ ��� ������� ��������:\n> ";
            cin >> c;
            for (int i = number - 1; i < number; i++)
                My_Calls[i].Set_Tariff_Of_One_Minute(c);
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

void record_in_file(Calls*& My_Calls, int number)
{
    ofstream file;
    file.open("log.txt");
    for (int i = 0; i < number; i++)
    {
        file << My_Calls[i].Get_Caller_Number() << " ";
        string a = My_Calls[i].Get_Caller_Name();
        add_underscores(a);
        file << a << " ";
        file << My_Calls[i].Get_Incoming_Or_Outgoing() << " ";
        file << My_Calls[i].Get_Incoming_Or_Outgoing_Number() << " ";
        file << My_Calls[i].Get_Day_Of_Call() << "-";
        file << My_Calls[i].Get_Month_Of_Call() << "-";
        file << My_Calls[i].Get_Year_Of_Call() << " ";
        file << My_Calls[i].Get_Hour_Of_Call() << ":";
        file << My_Calls[i].Get_Minutes_Of_Call() << " ";
        file << My_Calls[i].Get_Hours_Called() << ":";
        file << My_Calls[i].Get_Minutes_Called() << ":";
        file << My_Calls[i].Get_Seconds_Called() << " ";
        file << My_Calls[i].Get_Tariff_Of_One_Minute();
        if (i + 1 != number) file << "\n";
    }
    cout << "������������!" << endl;
}

void edit(Calls*& My_Calls, int number)
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
            float c;
            int memory = 0, number_in_menu2;
            cout << "�������� ����� ��������: " << endl;
            for (int i = 0; i < number; i++) cout << i + 1 << ". " << My_Calls[i].Get_Caller_Number() << endl;
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = 0; i < number; i++)
                if (a == My_Calls[i].Get_Caller_Number())
                {
                    int oo_bool = 0;
                    do
                    {
                        memory++;
                        cout << "��� �� ������ ��������?\n1. ����� ��������\n2. ��� ��������\n3. ��� ������.\n4. ����� ��������� ��� ���������� ��������.\n5. ���� ������\n6. ����� ������\n7. ����������������� ������\n8. ����� �� ���� ������\n9. ����� � ����\n> ";
                        cin >> number_in_menu2;
                        switch (number_in_menu2)
                        {
                        case 1:
                        {
                            cout << "������� ��������: " << My_Calls[i].Get_Caller_Number() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            My_Calls[i].Set_Caller_Number(a);
                            oo_bool++;
                        }
                        break;
                        case 2:
                        {
                            cout << "������� ��������: " << My_Calls[i].Get_Caller_Name() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            My_Calls[i].Set_Caller_Name(a);
                            oo_bool++;
                        }
                        break;
                        case 3:
                        {
                            cout << "������� ��������: " << My_Calls[i].Get_Day_Of_Call() << "." << My_Calls[i].Get_Month_Of_Call() << "." << My_Calls[i].Get_Year_Of_Call() << "\n��������, ��� �� ������ ��������: ���� (1), ����� (2), ��� (3).\n> " << endl;
                            int number;
                            cin >> number;
                            switch (number)
                            {
                            case 1:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Day_Of_Call(a);
                                oo_bool++;
                            } break;
                            case 2:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Month_Of_Call(a);
                                oo_bool++;
                            } break;
                            case 3:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Year_Of_Call(a);
                                oo_bool++;
                            } break;
                            }
                        }
                        break;
                        case 4:
                        {
                            cout << "������� ��������: ";
                            if (My_Calls[i].Get_Incoming_Or_Outgoing() == 1) cout << "�������� (1)" << endl;
                            if (My_Calls[i].Get_Incoming_Or_Outgoing() == 2) cout << "��������� (2)" << endl;
                            cout << "������� ���������:\n> ";
                            cin >> b;
                            My_Calls[i].Set_Incoming_Or_Outgoing(b);
                            oo_bool++;
                        } break;
                        case 5:
                        {

                        } break;
                        case 6:
                        {
                            cout << "������� ��������: " << My_Calls[i].Get_Hour_Of_Call() << ":" << My_Calls[i].Get_Minutes_Of_Call() << "\n��������, ��� �� ������ ��������: ���� (1), ������ (2).\n> " << endl;
                            int number;
                            cin >> number;
                            switch (number)
                            {
                            case 1:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Hour_Of_Call(a);
                                oo_bool++;
                            } break;
                            case 2:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Minutes_Of_Call(a);
                                oo_bool++;
                            } break;
                            }
                        }
                        break;
                        case 7:
                        {
                            cout << "������� ��������: " << My_Calls[i].Get_Hours_Called() << ":" << My_Calls[i].Get_Minutes_Called() << ":" << My_Calls[i].Get_Seconds_Called() << "\n��������, ��� �� ������ ��������: ���� (1), ������ (2), ������� (3).\n> " << endl;
                            int number;
                            cin >> number;
                            switch (number)
                            {
                            case 1:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Hours_Called(a);
                                oo_bool++;
                            } break;
                            case 2:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Minutes_Called(a);
                                oo_bool++;
                            } break;
                            case 3:
                            {
                                cout << "������� ���������:\n> ";
                                cin.ignore(255, '\n');
                                getline(cin, a);
                                My_Calls[i].Set_Seconds_Called(a);
                                oo_bool++;
                            } break;
                            }
                        }
                        break;
                        case 8:
                        {
                            cout << "������� ��������: " << My_Calls[i].Get_Tariff_Of_One_Minute() << endl;
                            cout << "������� ���������:\n> ";
                            cin >> c;
                            My_Calls[i].Set_Tariff_Of_One_Minute(c);
                            oo_bool++;
                        }
                        break;
                        case 9:
                        {
                            oo_bool++;
                        }
                        break;
                        default: cout << "����� �� �� ����.";
                        }
                    } while (oo_bool == 0);
                }
            if (memory == 0) cout << "����� ����� �� ������." << endl;
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

void sorting(Calls* My_Calls, int number)
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
                cout << "1. ��� ���������� �� ��������� ������ �������.\n2. ����� � ���������� ����" << endl;
                cout << "> ";
                cin >> number_in_menu;
                switch (number_in_menu)
                {
                case 1:
                {
                    string a, str;
                    string day1, month1, year1, hours1, minutes1, day2, month2, year2, hours2, minutes2;
                    cout << "������� ��������� ���� � ���� DD-MM-YYYY.\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    str = a.substr(0, 2);
                    day1 = str;
                    str = a.substr(3, 2);
                    month1 = str;
                    str = a.substr(6, 4);
                    year1 = str;
                    cout << "������� ��������� ����� � ���� HH:MM.\n> ";
                    getline(cin, a);
                    str = a.substr(0, 2);
                    hours1 = str;
                    str = a.substr(3, 2);
                    minutes1 = str;
                    cout << "������� �������� ���� � ���� DD-MM-YYYY.\n> ";
                    getline(cin, a);
                    str = a.substr(0, 2);
                    day2 = str;
                    str = a.substr(3, 2);
                    month2 = str;
                    str = a.substr(6, 4);
                    year2 = str;
                    cout << "������� �������� ����� � ���� HH:MM.\n> ";
                    getline(cin, a);
                    str = a.substr(0, 2);
                    hours2 = str;
                    str = a.substr(3, 2);
                    minutes2 = str;
                    int check = 0;
                    bool boool = false;
                    for (int i = 1; boool == false; i++)
                    {
                        if (i == 1)
                        {
                            if (year1 == year2) break;
                            else if (year1 < year2) boool = true;
                            else if (year1 > year2)
                            {
                                check = 1;
                                boool = true;
                            }
                        }
                        if (i == 2)
                        {
                            if (month1 == month2) break;
                            else if (month1 < month2) boool = true;
                            else if (month1 > month2)
                            {
                                check = 1;
                                boool = true;
                            }
                        }
                        if (i == 3)
                        {
                            if (day1 == day2) break;
                            else if (day1 < day2) boool = true;
                            else if (day1 > day2)
                            {
                                check = 1;
                                boool = true;
                            }
                        }
                        if (i == 4)
                        {
                            if (hours1 == hours2) break;
                            else if (hours1 < hours2) boool = true;
                            else if (hours1 > hours2)
                            {
                                check = 1;
                                boool = true;
                            }
                        }
                        if (i == 5)
                        {
                            if (minutes1 <= minutes1) boool = true;
                            else if (minutes1 > minutes1)
                            {
                                check = 1;
                                boool = true;
                            }
                        }
                    }
                    if (check == 1) cout << "�� ����� �������� ��������. ������������� �������� ������." << endl;
                    if (check == 0)
                    {
                        float sum_of_outgoing_calls = 0.0;
                        int seconds_of_outgoing_calls = 0, minutes_of_outgoing_calls = 0, hours_of_outgoing_calls = 0, minutes_of_outgoing_calls1 = 0, hours_of_outgoing_calls1 = 0;
                        int seconds_of_incoming_calls = 0, minutes_of_incoming_calls = 0, hours_of_incoming_calls = 0, minutes_of_incoming_calls1 = 0, hours_of_incoming_calls1 = 0;
                        for (int i = 0; i < number; i++)
                        {
                            if (My_Calls[i].Get_Year_Of_Call() >= year1 && My_Calls[i].Get_Year_Of_Call() < year2)
                            {
                                for_sorting(My_Calls, number, i, seconds_of_outgoing_calls, minutes_of_outgoing_calls, hours_of_outgoing_calls, minutes_of_outgoing_calls1, hours_of_outgoing_calls1, seconds_of_incoming_calls, minutes_of_incoming_calls, hours_of_incoming_calls, minutes_of_incoming_calls1, hours_of_incoming_calls1, sum_of_outgoing_calls);
                            }
                            else if (My_Calls[i].Get_Year_Of_Call() >= year1 && My_Calls[i].Get_Year_Of_Call() == year2)
                            {
                                if (My_Calls[i].Get_Month_Of_Call() >= month1 && My_Calls[i].Get_Month_Of_Call() < month2)
                                {
                                    for_sorting(My_Calls, number, i, seconds_of_outgoing_calls, minutes_of_outgoing_calls, hours_of_outgoing_calls, minutes_of_outgoing_calls1, hours_of_outgoing_calls1, seconds_of_incoming_calls, minutes_of_incoming_calls, hours_of_incoming_calls, minutes_of_incoming_calls1, hours_of_incoming_calls1, sum_of_outgoing_calls);
                                }
                                else if (My_Calls[i].Get_Month_Of_Call() >= month1 && My_Calls[i].Get_Month_Of_Call() == month2)
                                {
                                    if (My_Calls[i].Get_Day_Of_Call() >= day1 && My_Calls[i].Get_Day_Of_Call() < day2)
                                    {
                                        for_sorting(My_Calls, number, i, seconds_of_outgoing_calls, minutes_of_outgoing_calls, hours_of_outgoing_calls, minutes_of_outgoing_calls1, hours_of_outgoing_calls1, seconds_of_incoming_calls, minutes_of_incoming_calls, hours_of_incoming_calls, minutes_of_incoming_calls1, hours_of_incoming_calls1, sum_of_outgoing_calls);
                                    }
                                    else if (My_Calls[i].Get_Day_Of_Call() >= day1 && My_Calls[i].Get_Day_Of_Call() == day2)
                                    {
                                        if (My_Calls[i].Get_Hour_Of_Call() >= hours1 && My_Calls[i].Get_Hour_Of_Call() < hours2)
                                        {
                                            for_sorting(My_Calls, number, i, seconds_of_outgoing_calls, minutes_of_outgoing_calls, hours_of_outgoing_calls, minutes_of_outgoing_calls1, hours_of_outgoing_calls1, seconds_of_incoming_calls, minutes_of_incoming_calls, hours_of_incoming_calls, minutes_of_incoming_calls1, hours_of_incoming_calls1, sum_of_outgoing_calls);
                                        }
                                        else if (My_Calls[i].Get_Hour_Of_Call() >= hours1 && My_Calls[i].Get_Hour_Of_Call() == hours2)
                                        {
                                            if (My_Calls[i].Get_Minutes_Of_Call() >= minutes1 && My_Calls[i].Get_Minutes_Of_Call() <= minutes2)
                                            {
                                                for_sorting(My_Calls, number, i, seconds_of_outgoing_calls, minutes_of_outgoing_calls, hours_of_outgoing_calls, minutes_of_outgoing_calls1, hours_of_outgoing_calls1, seconds_of_incoming_calls, minutes_of_incoming_calls, hours_of_incoming_calls, minutes_of_incoming_calls1, hours_of_incoming_calls1, sum_of_outgoing_calls);
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        string string1, string2, string3;
                        int size;
                        string1 = to_string(hours_of_incoming_calls);
                        string2 = to_string(minutes_of_incoming_calls);
                        string3 = to_string(seconds_of_incoming_calls);
                        size = string1.length();
                        if (size == 1) string1.insert(0, "0");
                        size = string2.length();
                        if (size == 1) string2.insert(0, "0");
                        size = string3.length();
                        if (size == 1) string3.insert(0, "0");
                        cout << "����� ����� �������� ������� (��� ����): " << string1 << ":" << string2 << ":" << string3 << "." << endl;
                        string1 = to_string(hours_of_outgoing_calls);
                        string2 = to_string(minutes_of_outgoing_calls);
                        string3 = to_string(seconds_of_outgoing_calls);
                        size = string1.length();
                        if (size == 1) string1.insert(0, "0");
                        size = string2.length();
                        if (size == 1) string2.insert(0, "0");
                        size = string3.length();
                        if (size == 1) string3.insert(0, "0");
                        cout << "����� ����� ��������� ������� (��� ����): " << string1 << ":" << string2 << ":" << string3 << "." << endl;
                        cout << "����� (� ���.) �� ��������� ������ � ����������� �� ������ �� ������ (��� ����): " << sum_of_outgoing_calls << "." << endl;
                    }
                }
                break;
                case 2:
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
        } break;
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

void read_elements_from_file(Calls*& My_Calls, int number)
{
    fstream file;
    file.open("log.txt");
    if (file.is_open())
    {
        string a;
        int b;
        float c;
        for (int i = 0; i < number; i++)
        {
            file >> a;
            My_Calls[i].Set_Caller_Number(a);
            file >> a;
            delete_underscores(a);
            My_Calls[i].Set_Caller_Name(a);
            file >> b;
            My_Calls[i].Set_Incoming_Or_Outgoing(b);
            file >> a;
            My_Calls[i].Set_Incoming_Or_Outgoing_Number(a);
            file >> a;
            string str = a.substr(0, 2);
            My_Calls[i].Set_Day_Of_Call(str);
            str = a.substr(3, 2);
            My_Calls[i].Set_Month_Of_Call(str);
            str = a.substr(6, 4);
            My_Calls[i].Set_Year_Of_Call(str);
            file >> a;
            str = a.substr(0, 2);
            My_Calls[i].Set_Hour_Of_Call(str);
            str = a.substr(3, 2);
            My_Calls[i].Set_Minutes_Of_Call(str);
            file >> a;
            str = a.substr(0, 2);
            My_Calls[i].Set_Hours_Called(str);
            str = a.substr(3, 2);
            My_Calls[i].Set_Minutes_Called(str);
            str = a.substr(6, 2);
            My_Calls[i].Set_Seconds_Called(str);
            file >> c;
            My_Calls[i].Set_Tariff_Of_One_Minute(c);
        }
    }
}

void output_data_on_monitor(Calls* My_Calls, int number)
{
    cout << endl;
    for (int i = 0; i < number; i++)
    {
        cout.precision(3);
        cout << i + 1 << ". " << My_Calls[i];
    }
}

void for_sorting(Calls* My_Calls, int number, int i, int& seconds_of_outgoing_calls, int& minutes_of_outgoing_calls, int& hours_of_outgoing_calls, int& minutes_of_outgoing_calls1, int& hours_of_outgoing_calls1, int& seconds_of_incoming_calls, int& minutes_of_incoming_calls, int& hours_of_incoming_calls, int& minutes_of_incoming_calls1, int& hours_of_incoming_calls1, float& sum_of_outgoing_calls)
{
    int my_number_in_int;
    cout << i + 1 << ". " << My_Calls[i];
    if (i == number - 1) cout << endl;
    if (My_Calls[i].Get_Incoming_Or_Outgoing() == 1)
    {
        if (i == 0)
        {
            my_number_in_int = stoi(My_Calls[i].Get_Seconds_Called());
            seconds_of_incoming_calls = seconds_of_incoming_calls + my_number_in_int;
            my_number_in_int = stoi(My_Calls[i].Get_Minutes_Called());
            minutes_of_incoming_calls = minutes_of_incoming_calls + my_number_in_int;
            my_number_in_int = stoi(My_Calls[i].Get_Hours_Called());
            hours_of_incoming_calls = hours_of_incoming_calls + my_number_in_int;
        }
        if (i >= 1)
        {
            my_number_in_int = stoi(My_Calls[i].Get_Seconds_Called());
            seconds_of_incoming_calls = seconds_of_incoming_calls + my_number_in_int;
            if (seconds_of_incoming_calls > 60)
            {
                minutes_of_incoming_calls1 = seconds_of_incoming_calls / 60;
                seconds_of_incoming_calls = seconds_of_incoming_calls - (minutes_of_incoming_calls1 * seconds_of_incoming_calls);
                minutes_of_incoming_calls = minutes_of_incoming_calls + minutes_of_incoming_calls1;
            }
            my_number_in_int = stoi(My_Calls[i].Get_Minutes_Called());
            minutes_of_incoming_calls = minutes_of_incoming_calls + my_number_in_int;
            if (minutes_of_incoming_calls > 60)
            {
                hours_of_incoming_calls1 = minutes_of_incoming_calls / 60;
                minutes_of_incoming_calls = minutes_of_incoming_calls - (hours_of_incoming_calls1 * minutes_of_incoming_calls);
                hours_of_incoming_calls = hours_of_incoming_calls + hours_of_incoming_calls1;
            }
            my_number_in_int = stoi(My_Calls[i].Get_Hours_Called());
            hours_of_incoming_calls = hours_of_incoming_calls + my_number_in_int;
        }
    }
    if (My_Calls[i].Get_Incoming_Or_Outgoing() == 2)
    {
        if (i == 0)
        {
            my_number_in_int = stoi(My_Calls[i].Get_Seconds_Called());
            seconds_of_outgoing_calls = seconds_of_outgoing_calls + my_number_in_int;
            my_number_in_int = stoi(My_Calls[i].Get_Minutes_Called());
            minutes_of_outgoing_calls = minutes_of_outgoing_calls + my_number_in_int;
            my_number_in_int = stoi(My_Calls[i].Get_Hours_Called());
            hours_of_outgoing_calls = hours_of_outgoing_calls + my_number_in_int;
            sum_of_outgoing_calls = (((hours_of_outgoing_calls * 60) + minutes_of_outgoing_calls) * My_Calls[i].Get_Tariff_Of_One_Minute()) + ((seconds_of_outgoing_calls * My_Calls[i].Get_Tariff_Of_One_Minute()) / 60);
        }
        if (i >= 1)
        {
            my_number_in_int = stoi(My_Calls[i].Get_Seconds_Called());
            seconds_of_outgoing_calls = seconds_of_outgoing_calls + my_number_in_int;
            if (seconds_of_outgoing_calls > 60)
            {
                minutes_of_outgoing_calls1 = seconds_of_outgoing_calls / 60;
                seconds_of_outgoing_calls = seconds_of_outgoing_calls - (minutes_of_outgoing_calls1 * seconds_of_outgoing_calls);
                minutes_of_outgoing_calls = minutes_of_outgoing_calls + minutes_of_outgoing_calls1;
            }
            my_number_in_int = stoi(My_Calls[i].Get_Minutes_Called());
            minutes_of_outgoing_calls = minutes_of_outgoing_calls + my_number_in_int;
            if (minutes_of_outgoing_calls > 60)
            {
                hours_of_outgoing_calls1 = minutes_of_outgoing_calls / 60;
                minutes_of_outgoing_calls = minutes_of_outgoing_calls - (hours_of_outgoing_calls1 * minutes_of_outgoing_calls);
                hours_of_outgoing_calls = hours_of_outgoing_calls + hours_of_outgoing_calls1;
            }
            my_number_in_int = stoi(My_Calls[i].Get_Hours_Called());
            hours_of_outgoing_calls = hours_of_outgoing_calls + my_number_in_int;
            sum_of_outgoing_calls = (((hours_of_outgoing_calls * 60) + minutes_of_outgoing_calls) * My_Calls[i].Get_Tariff_Of_One_Minute()) + ((seconds_of_outgoing_calls * My_Calls[i].Get_Tariff_Of_One_Minute()) / 60);
        }
    }
}