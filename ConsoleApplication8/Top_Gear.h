#pragma once
using namespace std;

struct car_info
{
    int YEAR = 0;
    int MILEAGE = 0;
    int VOLUME = 0;
    int BODYWORK;
    int PRICE = 0;
};

struct car
{
    string MANUFACTURER;
    string CODE;
    car_info CAR_INFO;
};

void number_of_structs(fstream& a, int& b, int& c)
{
    char mainrow[200];
    a.open("Log.txt");
    if (a.is_open())
    {
        while (!a.eof())
        {
            a.getline(mainrow, 200);
            b++;
        }
        a.close();
    }
    else
    {
        cout << "Log-���� �� ������ � �������� �����. ������� ��� �������� ����.\n";
        c++;
    }
}

void createstructs(fstream& a, int b, car*& c)
{
    fstream my_file;
    my_file.open("Log.txt");
    if (my_file.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_file >> c[i].MANUFACTURER;
            my_file >> c[i].CODE;
            my_file >> c[i].CAR_INFO.YEAR;
            my_file >> c[i].CAR_INFO.MILEAGE;
            my_file >> c[i].CAR_INFO.VOLUME;
            my_file >> c[i].CAR_INFO.BODYWORK;
            my_file >> c[i].CAR_INFO.PRICE;
        }
    }
    my_file.close();
}

void create_new_struct(int b, car*& a)
{
    car* car_s = new car[b];
    for (int i = 0; i < b - 1; i++)
    {
        car_s[i].MANUFACTURER = a[i].MANUFACTURER;
        car_s[i].CODE = a[i].CODE;
        car_s[i].CAR_INFO.YEAR = a[i].CAR_INFO.YEAR;
        car_s[i].CAR_INFO.MILEAGE = a[i].CAR_INFO.MILEAGE;
        car_s[i].CAR_INFO.VOLUME = a[i].CAR_INFO.VOLUME;
        car_s[i].CAR_INFO.BODYWORK = a[i].CAR_INFO.BODYWORK;
        car_s[i].CAR_INFO.PRICE = a[i].CAR_INFO.PRICE;
    }
    delete[] a;
    a = car_s;
}

void display(car* a, int b)
{
    for (int i = 0; i < b; i++)
    {
        cout << "�����: " << a[i].MANUFACTURER << endl;
        cout << "���������������� ���: " << a[i].CODE << endl;
        cout << "��� �������: " << a[i].CAR_INFO.YEAR << " �." << endl;
        cout << "������: " << a[i].CAR_INFO.MILEAGE << " ��." << endl;
        cout << "����� ���������: " << a[i].CAR_INFO.VOLUME << " ��. ���." << endl;
        if (a[i].CAR_INFO.BODYWORK == 1) cout << "��� ������: �����������" << endl;
        else if (a[i].CAR_INFO.BODYWORK == 2) cout << "��� ������: �������" << endl;
        else if (a[i].CAR_INFO.BODYWORK == 3) cout << "��� ������: �����" << endl;
        else if (a[i].CAR_INFO.BODYWORK == 4) cout << "��� ������: �������" << endl;
        cout << "����: " << a[i].CAR_INFO.PRICE << " ���." << endl;
        cout << endl;
    }
}

void add(car*& a, int& b)
{
    int number;
    b++;
    create_new_struct(b, a);
    for (int i = 0; i < b; i++)
    {
        if (i == b - 1)
        {
            cout << "������� ����� ������:\n";
            cin >> a[i].MANUFACTURER;
            cout << "������� ��� ����� ������:\n";
            cin >> a[i].CODE;
            cout << "������� ��� ������������:\n";
            cin >> a[i].CAR_INFO.YEAR;
            cout << "������� ������ (� ��):\n";
            cin >> a[i].CAR_INFO.MILEAGE;
            cout << "������� ����� ��������� (� ��. ���):\n";
            cin >> a[i].CAR_INFO.VOLUME;
            cout << "������� ��� ������ (1 - �����������, 2 - �������, 3 - �����, 4 - �������):\n";
            cin >> number;
            a[i].CAR_INFO.BODYWORK = number;
            cout << "������� ���� (� ���):\n";
            cin >> a[i].CAR_INFO.PRICE;
        }
    }
}

void del(car* a, int& b)
{
    string mark, code;
    int number = 0, number1 = 0;
    cout << "������� ����� ������, ������� ����� �������:\n";
    cin >> mark;
    for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) number1++;
    if (number1 == 0) cout << "����� � ����� ������ �� ����������." << endl;
    if (number1 == 1)
    {
        cout << "������� 1 ������ � ����� ������. �������..." << endl;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].MANUFACTURER = a[i].MANUFACTURER;
                a[i - 1].CODE = a[i].CODE;
                a[i - 1].CAR_INFO.YEAR = a[i].CAR_INFO.YEAR;
                a[i - 1].CAR_INFO.MILEAGE = a[i].CAR_INFO.MILEAGE;
                a[i - 1].CAR_INFO.VOLUME = a[i].CAR_INFO.VOLUME;
                a[i - 1].CAR_INFO.BODYWORK = a[i].CAR_INFO.BODYWORK;
                a[i - 1].CAR_INFO.PRICE = a[i].CAR_INFO.PRICE;
            }
            if (mark == a[i].MANUFACTURER) number = 1;
        }
    }
    if (number1 > 1)
    {
        cout << "������� ��������� (" << number1 << ") ����� � ����� ������. ��������, ����������, ����� ������ �� ����������:\n";
        for (int i = 0; i < b; i++) if (a[i].MANUFACTURER == mark) cout << a[i].CODE << endl;
        cin >> code;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].MANUFACTURER = a[i].MANUFACTURER;
                a[i - 1].CODE = a[i].CODE;
                a[i - 1].CAR_INFO.YEAR = a[i].CAR_INFO.YEAR;
                a[i - 1].CAR_INFO.MILEAGE = a[i].CAR_INFO.MILEAGE;
                a[i - 1].CAR_INFO.VOLUME = a[i].CAR_INFO.VOLUME;
                a[i - 1].CAR_INFO.BODYWORK = a[i].CAR_INFO.BODYWORK;
                a[i - 1].CAR_INFO.PRICE = a[i].CAR_INFO.PRICE;
            }
            if (code == a[i].CODE) number = 1;
        }
        if (number == 0) cout << "����� � ����� ������ � ����� �� ����������." << endl;
    }
    if (number == 1) b--;
}

void search(car* a, int b)
{
    int number, o_bool = 0;
    cout << "��� �� ������ �����?\n1. ����� ����� ������.\n2. ����� ������ ������.\n3. �����.\n";
    do
    {
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int year = 0, year_max = 0;
            for (int i = 0; i < b; i++)
            {
                year = a[i].CAR_INFO.YEAR;
                if (year > year_max) year_max = year;
            }
            cout << "�����(-��) �����(-��) ������(-�):" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.YEAR == year_max) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        }
        break;
        case 2:
        {
            int year = 0, year_min = 3000;
            for (int i = 0; i < b; i++)
            {
                year = a[i].CAR_INFO.YEAR;
                if (year < year_min) year_min = year;
            }
            cout << "�����(-��) ������(-��) ������(-�):" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.YEAR == year_min) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        } break;
        case 3:
        {
            o_bool = 1;
        } break;
        default: cout << "������� ���� ����� �� �� ������� ����.\n";
        }
    } while (o_bool == 0);
}

void calculation(car* a, int b)
{
    int number, o_bool = 0;
    cout << "��� �� ������ ���������?\n1. ����� ������� ������.\n2. ������ � ����� ������� ��������.\n3. ���������� ����� ������������ ����.\n4. �����.\n";
    do
    {
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int price_max = 0, price = 0;
            for (int i = 0; i < b; i++)
            {
                price = a[i].CAR_INFO.PRICE;
                if (price > price_max) price_max = price;
            }
            cout << "�����(-��) �������(-��) ������(-�):" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.PRICE == price_max) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        }
        break;
        case 2:
        {
            int mileage_max = 0, mileage = 0;
            for (int i = 0; i < b; i++)
            {
                mileage = a[i].CAR_INFO.MILEAGE;
                if (mileage > mileage_max) mileage_max = mileage;
            }
            cout << "������(-�) � ����� ������� ��������:" << endl;
            for (int i = 0; i < b; i++)
            {
                if (a[i].CAR_INFO.MILEAGE == mileage_max) cout << "- " << a[i].MANUFACTURER << " " << a[i].CODE << endl;
            }
        }
        break;
        case 3:
        {
            int one = 0, two = 0, three = 0, four = 0, number = 0;
            for (int i = 0; i < b; i++)
            {
                number = a[i].CAR_INFO.BODYWORK;
                if (number == 1) one++;
                else if (number == 2) two++;
                else if (number == 3) three++;
                else if (number == 4) four++;
            }
            cout << "���������� ����� �� �����:\n�������������: " << one << "\n���������: " << two << "\n�������: " << three << "\n���������: " << four << endl;
        } break;
        case 4:
        {
            o_bool = 1;
        } break;
        default: cout << "������� ���� ����� �� �� ������� ����.\n";
        }
    } while (o_bool == 0);
    cout << "����������� � ����." << endl;
}

void edit(car*& a, int b)
{
    int o_bool = 0, number_menu, edit_int, bool_number = 0, bool_number_2 = 0, oo_bool = 0, ooo_bool = 0, oooo_bool = 0;
    string mark, code, edit_string;
    do
    {
        cout << "�������� ����� ������:\n";
        for (int i = 0; i < b; i++)
        {
            if (ooo_bool >= 1)
                for (int n = 0; n < i; n++)
                    if (a[i].MANUFACTURER == a[n].MANUFACTURER)
                    {
                        oooo_bool++;
                    }
            if (oooo_bool == 0) cout << a[i].MANUFACTURER << "\n";
            ooo_bool++;
            oooo_bool = 0;
        }
        cout << endl;
        cin >> mark;
        if (bool_number < 2)
        {
            for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) o_bool++;
            if (o_bool == 0)
            {
                cout << "��������� ����.\n";
                bool_number++;
            }
        }
        else
        {
            cout << "�� ����� ����� ����������� 3 ���� ������. ������� ����� � ���� ��� ������ ������ ��������?\n1. ��, ����� � ����.\n2. ���, ����������� ���.\n> ";
            cin >> bool_number_2;
            switch (bool_number_2)
            {
            case 1:
            {
                o_bool++;
                oo_bool++;
            } break;
            case 2:
            {
                bool_number = 0;
            } break;
            default: cout << "\n������� ���� ����� �� �� ����.";
            }
        }
    } while (o_bool == 0);
    o_bool = 0;
    bool_number = 0;
    bool_number_2 = 0;
    if (oo_bool == 0)
    {
        do
        {
            cout << "�������� ��� ������:\n";
            for (int i = 0; i < b; i++) if (mark == a[i].MANUFACTURER) cout << a[i].CODE << "\n";
            cout << endl;
            cin >> code;
            if (bool_number < 2)
            {
                for (int i = 0; i < b; i++) if (code == a[i].CODE) o_bool++;
                if (o_bool == 0)
                {
                    cout << "��������� ����.\n";
                    bool_number++;
                }
            }
            else
            {
                cout << "�� ����� ��� ����������� 3 ���� ������. ������� ����� � ���� ��� ������ ������ ��������?\n1. ��, ����� � ����.\n2. ���, ����������� ���.\n> ";
                cin >> bool_number_2;
                switch (bool_number_2)
                {
                case 1:
                {
                    o_bool++;
                    oo_bool++;
                }
                case 2:
                {
                    bool_number = 0;
                }
                default: cout << "\n������� ���� ����� �� �� ����.";
                }
            }
        } while (o_bool == 0);
        if (oo_bool == 0)
            do
            {
                cout << "��������, ��� �� ������ ��������:\n1. �����\n2. ���\n3. ��� ������������\n4. ������\n5. ����� ���������\n6. ��� ������\n7. ����\n8. ����� � ����\n";
                cin >> number_menu;
                switch (number_menu)
                {
                case 1:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (������� �������� - " << a[i].MANUFACTURER << "):\n";
                                cin >> edit_string;
                                a[i].MANUFACTURER = edit_string;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 2:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (������� �������� - " << a[i].CODE << "):\n";
                                cin >> edit_string;
                                a[i].CODE = edit_string;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 3:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (������� �������� - " << a[i].CAR_INFO.YEAR << " �.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.YEAR = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 4:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (������� �������� - " << a[i].CAR_INFO.MILEAGE << " ��.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.MILEAGE = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 5:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (������� �������� - " << a[i].CAR_INFO.VOLUME << " ��. ���.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.VOLUME = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 6:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (1 - �����������, 2 - �������, 3 - �����, 4 - �������) (������� �������� - " << a[i].CAR_INFO.BODYWORK << "):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.BODYWORK = edit_int;
                                break;
                            }
                    o_bool++;
                }
                case 7:
                {
                    for (int i = 0; i < b; i++)
                        if (mark == a[i].MANUFACTURER)
                            if (code == a[i].CODE)
                            {
                                cout << "������� ��������� (������� �������� - " << a[i].CAR_INFO.PRICE << " ���.):\n";
                                cin >> edit_int;
                                a[i].CAR_INFO.PRICE = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 8:
                {
                    o_bool++;
                }
                break;
                default: cout << "\n������� ���� ����� �� �� ����.";
                }
            } while (o_bool == 0);
    }
    cout << "����������� � ����.\n" << endl;
}

void rewrite(car* a, int b)
{
    ofstream my_outfile;
    my_outfile.open("Log.txt");
    if (my_outfile.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_outfile << a[i].MANUFACTURER << " ";
            my_outfile << a[i].CODE << " ";
            my_outfile << a[i].CAR_INFO.YEAR << " ";
            my_outfile << a[i].CAR_INFO.MILEAGE << " ";
            my_outfile << a[i].CAR_INFO.VOLUME << " ";
            my_outfile << a[i].CAR_INFO.BODYWORK << " ";
            my_outfile << a[i].CAR_INFO.PRICE << " ";
            if (i + 1 != b) my_outfile << "\n";
        }
    }
}

void menu(car*& a, int& b)
{
    int number_in_menu, o_bool = 0;
    do
    {
        printf_s("1. ������� ��� ������ �� �����.\n2. �������� ������.\n3. ������� ������.\n4. ������ ���������.\n5. ������������ � ����.\n6. �����.\n7. ����������.\n8. ��������� ������.\n");
        cin >> number_in_menu;
        switch (number_in_menu)
        {
        case 1:
        {
            display(a, b);
        }
        break;
        case 2:
        {
            add(a, b);
        } break;
        case 3:
        {
            del(a, b);
        } break;
        case 4:
        {
            edit(a, b);
        } break;
        case 5:
        {
            rewrite(a, b);
        } break;
        case 6:
        {
            search(a, b);
        } break;
        case 7:
        {
            calculation(a, b);
        } break;
        case 8:
        {
            o_bool = 1;
        } break;
        default: cout << "\n������� ���� ����� �� �� ����.";
        }
    } while (o_bool == 0);
}