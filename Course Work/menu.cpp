#include <iostream>
#include <stdio.h>
#include <string>
#include <windows.h>
#include "Pharmacy.h"
#include "menu.h"
#include <regex>
#include <fstream>
#include <vector>
#include <sstream>

template <typename Type> string to_str(Type& t)
{
    ostringstream os;
    os << t;
    return os.str();
}

void Menu::add(vector<Pills>& Pill, vector<Devices>& Device)
{
    int number_in_menu, o_bool = 0;
    Pills temp_pill;
    Devices temp_device;
    cout << "�������� ����� ����:" << endl;
    do
    {
        cout << "1. ���������� ��������� � ���������\n2. �����\n> ";
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            int number_in_submenu;
            cout << "��� �� ������ ��������?\n1. ����������\n2. ����������\n> ";
            cin >> number_in_submenu;
            switch (number_in_submenu)
            {
            case 1:
            {
                int ooo_bool = 0;
                do
                {
                    string a;
                    float b;
                    int oo_bool = 0;
                    cout << "������� �������� ���������:\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    temp_pill.Set_Name(a);
                    cout << "������� ����� �������:\n> ";
                    getline(cin, a);
                    temp_pill.Set_Form(a);
                    cout << "������� ������ �������������:\n> ";
                    getline(cin, a);
                    temp_pill.Set_Distribution_method(a);
                    cout << "������� �������������:\n> ";
                    getline(cin, a);
                    temp_pill.Set_Manufacturer(a);
                    cout << "������� ���� ���������:\n";
                    do
                    {
                        regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)");
                        regex regex_minus("(-)");
                        string b_string;
                        try
                        {
                            cout << "> ";
                            cin >> b;
                            if (cin.fail())
                            {
                                throw - 1;
                            };
                            if (!cin.fail())
                            {
                                if (b < 0) cout << "������ (������� ������������� �����).\n";
                                b_string = to_str(b);
                                if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                if (b > 0) oo_bool++;
                            }
                        }
                        catch (int)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (������� �����).\n";
                        }
                        catch (exception const& an_error)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (" << an_error.what() << ").\n";
                        }
                    } while (oo_bool == 0);
                    oo_bool = 0;
                    temp_pill.Set_Price(b);
                    cout << "������� ������ (���� � ���, ����������� 0):\n";
                    do
                    {
                        regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)");
                        regex regex_minus("(-)");
                        string b_string;
                        try
                        {
                            cout << "> ";
                            cin >> b;
                            if (cin.fail())
                            {
                                throw - 1;
                            };
                            if (!cin.fail())
                            {
                                if (b < 0) cout << "������ (������� ������������� �����).\n";
                                if (b > 100) cout << "������ (������ �� ����� ���� ������ 100).\n";
                                b_string = to_str(b);
                                if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                if (b > 0 && b <= 100) oo_bool++;
                            }
                        }
                        catch (int)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (������� �����).\n";
                        }
                        catch (exception const& an_error)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (" << an_error.what() << ").\n";
                        }
                    } while (oo_bool == 0);
                    oo_bool = 0;
                    temp_pill.Set_Discount(b);
                    int number_in_subsubmenu;
                    cout << "���� �������� ������:\n��������: " << temp_pill.Get_Name() << "\n   ����� �������: " << temp_pill.Get_Form() << "\n   ������ �������������: " << temp_pill.Get_Distribution_method() << "\n   �������������: " << temp_pill.Get_Manufacturer() << "\n   ����: " << temp_pill.Get_Price() << " ���.\n   ������ (���� ���, ����������� 0): " << temp_pill.Get_Discount() << "%\n�� �����? (1. ��, ��������; 2. ���, ������)\n> ";
                    cin >> number_in_subsubmenu;
                    if (number_in_subsubmenu == 1)
                    {
                        Pill.push_back(temp_pill);
                        ooo_bool++;
                    }
                } while (ooo_bool == 0);
                cout << "���������� ������ �������." << endl;
            }
            break;
            case 2:
            {
                int ooo_bool = 0;
                do
                {
                    string a;
                    float b;
                    int oo_bool = 0, c;
                    cout << "������� �������� ����������:\n> ";
                    cin.ignore(255, '\n');
                    getline(cin, a);
                    temp_device.Set_Name(a);
                    cout << "������� ������� ������������:\n> ";
                    do
                    {
                        try
                        {
                            cin >> c;
                            if (cin.fail())
                            {
                                throw - 1;
                            };
                            if (!cin.fail())
                            {
                                if (c < 0) cout << "������ (������� ������������� �����).\n> ";
                                if (c > 0) oo_bool++;
                            }
                        }
                        catch (int)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (������� �����).\n> ";
                        }
                    } while (oo_bool == 0);
                    oo_bool = 0;
                    temp_device.Set_Level_of_security(c);
                    cout << "������� �������������:\n> ";
                    getline(cin, a);
                    temp_device.Set_Manufacturer(a);
                    cout << "������� ���� ������ (� ����� �����):\n> ";
                    do
                    {
                        try
                        {
                            cin >> c;
                            if (cin.fail())
                            {
                                throw - 1;
                            };
                            if (!cin.fail())
                            {
                                if (c < 0) cout << "������ (������� ������������� �����).\n> ";
                                if (c > 0) oo_bool++;
                            }
                        }
                        catch (int)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (������� �����).\n> ";
                        }
                    } while (oo_bool == 0);
                    oo_bool = 0;
                    temp_device.Set_Operation_period(c);
                    cout << "������� ���� ���������:\n";
                    do
                    {
                        regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)");
                        regex regex_minus("(-)");
                        string b_string;
                        try
                        {
                            cout << "> ";
                            cin >> b;
                            if (cin.fail())
                            {
                                throw - 1;
                            };
                            if (!cin.fail())
                            {
                                if (b < 0) cout << "������ (������� ������������� �����).\n";
                                b_string = to_str(b);
                                if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                if (b > 0) oo_bool++;
                            }
                        }
                        catch (int)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (������� �����).\n";
                        }
                        catch (exception const& an_error)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (" << an_error.what() << ").\n";
                        }
                    } while (oo_bool == 0);
                    oo_bool = 0;
                    temp_device.Set_Price(b);
                    cout << "������� ������ (���� � ���, ����������� 0):\n";
                    do
                    {
                        regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)");
                        regex regex_minus("(-)");
                        string b_string;
                        try
                        {
                            cout << "> ";
                            cin >> b;
                            if (cin.fail())
                            {
                                throw - 1;
                            };
                            if (!cin.fail())
                            {
                                if (b < 0) cout << "������ (������� ������������� �����).\n";
                                if (b > 100) cout << "������ (������ �� ����� ���� ������ 100).\n";
                                b_string = to_str(b);
                                if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                if (b > 0 && b <= 100) oo_bool++;
                            }
                        }
                        catch (int)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (������� �����).\n";
                        }
                        catch (exception const& an_error)
                        {
                            cin.clear();
                            cin.ignore(32767, '\n');
                            cout << "������ (" << an_error.what() << ").\n";
                        }
                    } while (oo_bool == 0);
                    oo_bool = 0;
                    temp_device.Set_Discount(b);
                    int number_in_subsubmenu;
                    cout << "���� �������� ������:\n��������: " << temp_pill.Get_Name() << "\n   ����� �������: " << temp_pill.Get_Form() << "\n   ������ �������������: " << temp_pill.Get_Distribution_method() << "\n   �������������: " << temp_pill.Get_Manufacturer() << "\n   ����: " << temp_pill.Get_Price() << " ���.\n   ������ (���� ���, ����������� 0): " << temp_pill.Get_Discount() << "%\n�� �����? (1. ��, ��������; 2. ���, ������)\n> ";
                    cin >> number_in_subsubmenu;
                    if (number_in_subsubmenu == 1)
                    {
                        Device.push_back(temp_device);
                        ooo_bool++;
                    }
                } while (ooo_bool == 0);
                cout << "���������� ������ �������." << endl;
            }
            }
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

void Menu::record_in_file(vector<Pills> Pill, vector<Devices> Device)
{
    ofstream file, binary_file;
    int number_of_pills = Pill.size(), number_of_devices = Device.size();
    file.open("log.txt");
    binary_file.open("binary_log.txt", ios::binary);
    for (int i = 0; i < number_of_pills; i++)
    {
        file << "0 ";
        file << Pill[i].output_in_file();
        Pill[i].writeToBinStream(binary_file);
        if (i + 1 != number_of_pills) file << "\n";
        else if (i + 1 == number_of_pills && number_of_devices != 0) file << "\n";
    }
    for (int i = 0; i < number_of_devices; i++)
    {
        file << "1 ";
        file << Device[i].output_in_file();
        Device[i].writeToBinStream(binary_file);
        if (i + 1 != number_of_devices) file << "\n";
    }
    file.close();
    binary_file.close();
    cout << "������������!" << endl;
}

void Menu::edit(vector<Pills>& Pill, vector<Devices>& Device)
{
    int number_in_menu, o_bool = 0, number_pill = Pill.size(), number_device = Device.size();
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
            for (int i = 0; i < number_pill; i++) cout << Pill[i].Get_Name() << endl;
            for (int i = 0; i < number_device; i++) cout << Device[i].Get_Name() << endl;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, a);
            for (int i = 0; i < number_pill; i++)
                if (a == Pill[i].Get_Name())
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
                            cout << "������� ��������: " << Pill[i].Get_Name() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Pill[i].Set_Name(a);
                            oo_bool++;
                        }
                        break;
                        case 2:
                        {
                            cout << "������� ��������: " << Pill[i].Get_Manufacturer() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Pill[i].Set_Manufacturer(a);
                            oo_bool++;
                        }
                        break;
                        case 3:
                        {
                            cout << "������� ��������: " << Pill[i].Get_Price() << endl;
                            cout << "������� ���������:\n";
                            int ooo_bool = 0;
                            do
                            {
                                regex regular("([0-9+]+)(\.)([0-9]{1,2})|([0-9]+)");
                                regex regex_minus("(-)");
                                string b_string;
                                try
                                {
                                    cout << "> ";
                                    cin >> b;
                                    if (cin.fail())
                                    {
                                        throw - 1;
                                    };
                                    if (!cin.fail())
                                    {
                                        if (b < 0) cout << "������ (������� ������������� �����).\n";

                                        b_string = to_str(b);
                                        if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                        if (b > 0) ooo_bool++;
                                    }
                                }
                                catch (int)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (������� �����).\n";
                                }
                                catch (exception const& an_error)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (" << an_error.what() << ").\n";
                                }
                            } while (ooo_bool == 0);
                            Pill[i].Set_Price(b);
                            oo_bool++;
                        }
                        break;
                        case 4:
                        {
                            int ooo_bool = 0;
                            cout << "������� ��������: " << Pill[i].Get_Discount() << endl;
                            cout << "������� ���������:\n";
                            do
                            {
                                regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)");
                                regex regex_minus("(-)");
                                string b_string;
                                try
                                {
                                    cout << "> ";
                                    cin >> b;
                                    if (cin.fail())
                                    {
                                        throw - 1;
                                    };
                                    if (!cin.fail())
                                    {
                                        if (b < 0) cout << "������ (������� ������������� �����).\n";
                                        if (b > 100) cout << "������ (������ �� ����� ���� ������ 100).\n";
                                        b_string = to_str(b);
                                        if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                        if (b > 0 && b <= 100) ooo_bool++;
                                    }
                                }
                                catch (int)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (������� �����).\n";
                                }
                                catch (exception const& an_error)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (" << an_error.what() << ").\n";
                                }
                            } while (ooo_bool == 0);
                            Pill[i].Set_Discount(b);
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
            for (int i = 0; i < number_device; i++)
                if (a == Device[i].Get_Name())
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
                            cout << "������� ��������: " << Device[i].Get_Name() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Device[i].Set_Name(a);
                            oo_bool++;
                        }
                        break;
                        case 2:
                        {
                            cout << "������� ��������: " << Device[i].Get_Manufacturer() << endl;
                            cout << "������� ���������:\n> ";
                            cin.ignore(255, '\n');
                            getline(cin, a);
                            Device[i].Set_Manufacturer(a);
                            oo_bool++;
                        }
                        break;
                        case 3:
                        {
                            int ooo_bool = 0;
                            cout << "������� ��������: " << Device[i].Get_Price() << endl;
                            cout << "������� ���������:\n> ";
                            do
                            {
                                regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)");
                                regex regex_minus("(-)");
                                string b_string;
                                try
                                {
                                    cin >> b;
                                    if (cin.fail())
                                    {
                                        throw - 1;
                                    };
                                    if (!cin.fail())
                                    {
                                        if (b < 0) cout << "������ (������� ������������� �����).\n> ";
                                        b_string = to_str(b);
                                        if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                        if (b > 0) ooo_bool++;
                                    }
                                }
                                catch (int)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (������� �����).\n> ";
                                }
                                catch (exception const& an_error)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (" << an_error.what() << ")." << endl;
                                }
                            } while (ooo_bool == 0);
                            Device[i].Set_Price(b);
                            oo_bool++;
                        }
                        break;
                        case 4:
                        {
                            int ooo_bool = 0;
                            cout << "������� ��������: " << Device[i].Get_Discount() << endl;
                            cout << "������� ���������:\n> ";
                            do
                            {
                                regex regular("([0-9]+)(\.)([0-9]{1,2})|([0-9]+)|(-)([0-9])");
                                regex regex_minus("(-)");
                                string b_string;
                                try
                                {
                                    cin >> b;
                                    if (cin.fail())
                                    {
                                        throw - 1;
                                    };
                                    if (!cin.fail())
                                    {
                                        if (b < 0) cout << "������ (������� ������������� �����).\n> ";
                                        if (b > 100) cout << "������ (������ �� ����� ���� ������ 100).\n> ";
                                        b_string = to_str(b);
                                        if (!regex_match(b_string.c_str(), regular)) if (!regex_search(b_string.c_str(), regex_minus)) throw runtime_error("������� ������ ���� ����� ����� �������");
                                        if (b > 0 && b <= 100) ooo_bool++;
                                    }
                                }
                                catch (int)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (������� �����).\n> ";
                                }
                                catch (exception const& an_error)
                                {
                                    cin.clear();
                                    cin.ignore(32767, '\n');
                                    cout << "������ (" << an_error.what() << ")." << endl;
                                }
                            } while (ooo_bool == 0);
                            Device[i].Set_Discount(b);
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

void Menu::deleting(vector<Pills>& Pill, vector<Devices>& Device)
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
            int numb = 0;
            cout << "��������, ����� �������� �� ������ ������ �� ������:" << endl;
            int number_pill = Pill.size(), number_device = Device.size();
            for (int i = 0; i < number_pill; i++)
            {
                cout << numb + 1 << ". " << Pill[i].Get_Name() << " (���������)" << endl;
                numb++;
            }
            for (int i = 0; i < number_device; i++)
            {
                cout << numb + 1 << ". " << Device[i].Get_Name() << " (����������)" << endl;
                numb++;
            }
            string name, original_name;
            int i_memorized_pill = 0, i_memorized_device = 0, oo_bool_pill = 0, oo_bool_device = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number_pill; i++)
            {
                original_name = Pill[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized_pill = i;
                    oo_bool_pill++;
                }
            }
            for (int i = 0; i < number_device; i++)
            {
                original_name = Device[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized_device = i;
                    oo_bool_device++;
                }
            }
            if ((i_memorized_pill == 0 && oo_bool_pill != 0) || (i_memorized_pill != 0 && oo_bool_pill != 0))
            {
                
                Pill.erase(Pill.begin() + (i_memorized_pill - 1));
                cout << "������� �������." << endl;
            }
            if ((i_memorized_device == 0 && oo_bool_device != 0) || (i_memorized_device != 0 && oo_bool_device != 0))
            {
                Device.erase(Device.begin() + (i_memorized_device - 1));
                cout << "������� �������." << endl;
            }
            else if ((i_memorized_pill == 0 && oo_bool_pill == 0) && (i_memorized_device == 0 && oo_bool_device == 0)) cout << "�������� ������� �������." << endl;
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

void Menu::search(vector<Pills>& Pill, vector<Devices>& Device)
{
    int number_in_menu, o_bool = 0, number_pill = Pill.size(), number_device = Device.size();
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
                    for (int i = 0; i < number_pill; i++)
                    {
                        if (a == Pill[i].Get_Name())
                        {
                            cout << "��������: " << Pill[i].Get_Name() << "\n�������������: " << Pill[i].Get_Manufacturer() << "\n����: " << Pill[i].Get_Price() << " ���.\n������ (���� �������): " << Pill[i].Get_Discount() << "%" << endl;
                            Pill[i].Price_with_discount();
                            memory++;
                        }
                    }
                    for (int i = 0; i < number_device; i++)
                    {
                        if (a == Device[i].Get_Name())
                        {
                            cout << "����������: " << Device[i].Get_Name() << "\n�������������: " << Device[i].Get_Manufacturer() << "\n����: " << Device[i].Get_Price() << " ���.\n������ (���� �������): " << Device[i].Get_Discount() << "%" << endl;
                            Pill[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "��������(-�) ��� ����������(-�) � ����� ��������� �� ������(-�)." << endl;
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
                    for (int i = 0; i < number_pill; i++)
                    {
                        if (a == Pill[i].Get_Manufacturer())
                        {
                            if (memory == 0) cout << "��������� �� ������� �������������: " << endl;
                            cout << "��������: " << Pill[i].Get_Name() << "\n����: " << Pill[i].Get_Price() << " ���.\n������ (���� �������): " << Pill[i].Get_Discount() << "%" << endl;
                            Pill[i].Price_with_discount();
                            memory++;
                        }
                    }
                    for (int i = 0; i < number_device; i++)
                    {
                        if (a == Device[i].Get_Manufacturer())
                        {
                            cout << "����������: " << Device[i].Get_Name() << "\n����: " << Device[i].Get_Price() << " ���.\n������ (���� �������): " << Device[i].Get_Discount() << "%" << endl;
                            Device[i].Price_with_discount();
                            memory++;
                        }
                    }
                    if (memory == 0)
                    {
                        cout << "��������(-�) ��� ����������(-�) �� ������� ������������� �� ������(-�).";
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
                    for (int i = 0; i < number_pill; i++)
                    {
                        if (a == Pill[i].Get_Price())
                        {
                            if (memory == 0) cout << "��������� � ����� �����: " << endl;
                            cout << "��������: " << Pill[i].Get_Name() << "\n�������������: " << Pill[i].Get_Manufacturer() << "������ (���� �������): " << Pill[i].Get_Discount() << "%" << endl;
                            Pill[i].Price_with_discount();
                            memory++;
                        }
                    }
                    for (int i = 0; i < number_device; i++)
                    {
                        if (a == Device[i].Get_Price())
                        {
                            cout << "����������: " << Device[i].Get_Name() << "\n�������������: " << Device[i].Get_Manufacturer() << "������ (���� �������): " << Device[i].Get_Discount() << "%" << endl;
                            Device[i].Price_with_discount();
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
                    for (int i = 0; i < number_pill; i++)
                    {
                        if (a == Pill[i].Get_Discount())
                        {
                            if (memory == 0) cout << "��������� � ����� �������: " << endl;
                            cout << "��������: " << Pill[i].Get_Name() << "\n�������������: " << Pill[i].Get_Manufacturer() << "\n����: " << Pill[i].Get_Price() << " ���." << endl;
                            Pill[i].Price_with_discount();
                            memory++;
                        }
                    }
                    for (int i = 0; i < number_device; i++)
                    {
                        if (a == Device[i].Get_Discount())
                        {
                            if (memory == 0) cout << "��������� � ����� �������: " << endl;
                            cout << "��������: " << Device[i].Get_Name() << "\n�������������: " << Device[i].Get_Manufacturer() << "\n����: " << Device[i].Get_Price() << " ���." << endl;
                            Device[i].Price_with_discount();
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

void Menu::read_elements_from_file(vector<Pills>& Pill, vector<Devices>& Device)
{
    fstream file;
    int number = 0;
    file.open("log.txt");
    if (file.is_open())
    {
        char mainrow[100];
        while (!file.eof())
        {
            number++;
            file.getline(mainrow, 100);
        }
        file.close();
        file.open("log.txt");
        if (file.is_open())
        {
            int divider, number_for_int;
            Pills Remembered_pill;
            Devices Remembered_device;
            string str;
            float float_number_for_if;
            for (int i = 0; i < number; i++)
            {
                file >> divider;
                if (divider == 0)
                {
                    file >> str;
                    Remembered_pill.Set_Name(str);
                    file >> str;
                    Remembered_pill.Set_Form(str);
                    file >> str;
                    Remembered_pill.Set_Distribution_method(str);
                    file >> str;
                    Remembered_pill.Set_Manufacturer(str);
                    file >> float_number_for_if;
                    Remembered_pill.Set_Price(float_number_for_if);
                    file >> float_number_for_if;
                    Remembered_pill.Set_Discount(float_number_for_if);
                    Pill.push_back(Remembered_pill);
                }
                if (divider == 1)
                {
                    file >> str;
                    Remembered_device.Set_Name(str);
                    file >> number_for_int;
                    Remembered_device.Set_Level_of_security(number_for_int);
                    file >> str;
                    Remembered_device.Set_Manufacturer(str);
                    file >> number_for_int;
                    Remembered_device.Set_Operation_period(number_for_int);
                    file >> float_number_for_if;
                    Remembered_device.Set_Price(float_number_for_if);
                    file >> float_number_for_if;
                    Remembered_device.Set_Discount(float_number_for_if);
                    Device.push_back(Remembered_device);
                }
            }
            file.close();
        }
    }
    else
    {
        cout << "Log-����� ������ ��������� �� ����������, ���� ��� ������ ������ ���������." << endl;
    }
}

void Menu::big_menu(vector<Pills> Pill, vector<Devices> Device)
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
            system("cls");
            output_data_on_monitor(Pill, Device);
            system("pause");
            system("cls");
        }
        break;
        case 2:
        {
            system("cls");
            add(Pill, Device);
            system("cls");
        } break;
        case 3:
        {
            system("cls");
            deleting(Pill, Device);
            system("cls");
        } break;
        case 4:
        {
            system("cls");
            edit(Pill, Device);
            system("cls");
        } break;
        case 5:
        {
            record_in_file(Pill, Device);
        } break;
        case 6:
        {
            system("cls");
            search(Pill, Device);
            system("cls");
        } break;
        case 7:
        {
            system("cls");
            calculation_discount(Pill, Device);
            system("cls");
        } break;
        case 8:
        {
            o_bool++;
        } break;
        default: cout << "\n������� ���� ����� �� �� ����.";
        }
    } while (o_bool == 0);
}

Menu::Menu()
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    setlocale(LC_ALL, "RUSSIAN");
    cout << "Please, change font of the console to Consolas or Lucida!" << endl;
    vector<Pills> Pill;
    vector<Devices> Device;
    read_elements_from_file(Pill, Device);
    big_menu(Pill, Device);
    cout << "End of the program.\n";
}

void Menu::output_data_on_monitor(vector<Pills> Pill, vector<Devices> Device)
{
    int number_of_pills = Pill.size(), number_of_devices = Device.size();
    cout << "���������:\n" << endl;
    for (int i = 0; i < number_of_pills; i++)
    {
        cout << Pill[i] << endl;
    }
    cout << "����������:\n" << endl;
    for (int i = 0; i < number_of_devices; i++)
    {
        cout << Device[i] << endl;
    }
}

void Menu::calculation_discount(vector<Pills> Pill, vector<Devices> Device)
{
    int o_bool = 0;
    int number_of_pills = Pill.size(), number_of_devices = Device.size();
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
            cout << "������� �������� ������, ��� �������� ����� ��������� ��������� ����: " << endl;
            for (int i = 0; i < number_of_pills; i++)
            {
                cout << Pill[i].Get_Name() << endl;
            }
            for (int i = 0; i < number_of_devices; i++)
            {
                cout << Device[i].Get_Name() << endl;
            }
            string name, original_name;
            int i_memorized, memory = 0, memory_if = 0;
            cout << "> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < number_of_pills; i++)
            {
                original_name = Pill[i].Get_Name();
                if (name == original_name)
                {
                    i_memorized = i;
                    memory++;
                }
                if (memory != 0)
                {
                    cout << "��������: " << Pill[i_memorized].Get_Name() << "\n����: " << Pill[i_memorized].Get_Price() << " ���.\n������: " << Pill[i_memorized].Get_Discount() << " %" << endl;
                    Pill[i_memorized].Price_with_discount();
                    memory_if++;
                }
                memory = 0;
            }
            if (memory_if == 0)
            {
                for (int i = 0; i < number_of_devices; i++)
                {
                    original_name = Device[i].Get_Name();
                    if (name == original_name)
                    {
                        i_memorized = i;
                        memory++;
                    }
                    if (memory != 0)
                    {
                        cout << "��������: " << Device[i_memorized].Get_Name() << "\n����: " << Device[i_memorized].Get_Price() << " ���.\n������: " << Device[i_memorized].Get_Discount() << " %" << endl;
                        Device[i_memorized].Price_with_discount();
                        memory_if++;
                    }
                    memory = 0;
                }
            }
            if (memory_if == 0) cout << "����� �������� �� ������." << endl;
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
