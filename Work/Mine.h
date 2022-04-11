#pragma once
using namespace std;

struct lib_info
{
    string AUTHOR;
    string RELEASE_YEAR;
    int QUANTITY = 0;
    bool GIVEN;
    string STORED;
};

struct home_library
{
    string NAME;
    lib_info LIB_INFO;
};

void delete_underscores(string& str) //��������.
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

void add_underscores(string& str) //��������.
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

void number_of_structs(fstream& a, int& b, int& c) //��������.
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

void createstructs(fstream& a, int b, home_library*& c) //��������.
{
    char symbol;
    string my_string;
    fstream my_file;
    my_file.open("Log.txt");
    if (my_file.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_file >> my_string;
            delete_underscores(my_string);
            c[i].NAME = my_string;
            my_file >> my_string;
            delete_underscores(my_string);
            c[i].LIB_INFO.AUTHOR = my_string;
            my_file >> c[i].LIB_INFO.RELEASE_YEAR;
            my_file >> c[i].LIB_INFO.QUANTITY;
            my_file >> symbol;
            switch (symbol)
            {
            case '+':
            {
                c[i].LIB_INFO.GIVEN = true;
            }
            break;
            case '-':
            {
                c[i].LIB_INFO.GIVEN = false;
            } break;
            }
            my_file >> my_string;
            delete_underscores(my_string);
            c[i].LIB_INFO.STORED = my_string;
        }
    }
    my_file.close();
}

void create_new_struct(int b, home_library*& a) //��������.
{
    home_library* books = new home_library[b - 1];
    for (int i = 0; i < b - 1; i++)
    {
        books[i].NAME = a[i].NAME;
        books[i].LIB_INFO.AUTHOR = a[i].LIB_INFO.AUTHOR;
        books[i].LIB_INFO.RELEASE_YEAR = a[i].LIB_INFO.RELEASE_YEAR;
        books[i].LIB_INFO.QUANTITY = a[i].LIB_INFO.QUANTITY;
        books[i].LIB_INFO.GIVEN = a[i].LIB_INFO.GIVEN;
        books[i].LIB_INFO.STORED = a[i].LIB_INFO.STORED;
    }
    delete[] a;
    home_library* book_s = new home_library[b];
    for (int i = 0; i < b - 1; i++)
    {
        book_s[i].NAME = books[i].NAME;
        book_s[i].LIB_INFO.AUTHOR = books[i].LIB_INFO.AUTHOR;
        book_s[i].LIB_INFO.RELEASE_YEAR = books[i].LIB_INFO.RELEASE_YEAR;
        book_s[i].LIB_INFO.QUANTITY = books[i].LIB_INFO.QUANTITY;
        book_s[i].LIB_INFO.GIVEN = books[i].LIB_INFO.GIVEN;
        book_s[i].LIB_INFO.STORED = books[i].LIB_INFO.STORED;
    }
    a = book_s;
}

void display(home_library* a, int b) //��������.
{
    for (int i = 0; i < b; i++)
    {
        cout << "�������� �����: " << a[i].NAME << endl;
        cout << "�����: " << a[i].LIB_INFO.AUTHOR << endl;
        cout << "���� ����������: " << a[i].LIB_INFO.RELEASE_YEAR << " �." << endl;
        cout << "����������: " << a[i].LIB_INFO.QUANTITY << endl;
        if (a[i].LIB_INFO.GIVEN == true) cout << "������: ������" << endl;
        if (a[i].LIB_INFO.GIVEN == false) cout << "������: ���� � ����������" << endl;
        cout << "�������� �... : " << a[i].LIB_INFO.STORED << endl;
        cout << endl;
    }
    cout << "�������� ����� ����." << endl;
}

void add(home_library*& a, int& b)
{
    char word;
    b++;
    create_new_struct(b, a);
    for (int i = 0; i < b; i++)
    {
        if (i == b - 1)
        {
            cin.ignore(255, '\n');
            cout << "������� �������� �����:\n> ";
            getline(cin, a[i].NAME);
            cout << "������� ������:\n> ";
            getline(cin, a[i].LIB_INFO.AUTHOR);
            cout << "������� ���� ����������:\n> ";
            getline(cin, a[i].LIB_INFO.RELEASE_YEAR);
            cout << "������� ���������� ����� ���� � ����������:\n> ";
            cin >> a[i].LIB_INFO.QUANTITY;
            cout << "������� [+], ���� ����� ������, [-], ���� ��� �������� � ����������:\n> ";
            cin >> word;
            if (word == '+') a[i].LIB_INFO.GIVEN = true;
            if (word == '-') a[i].LIB_INFO.GIVEN = false;
            cin.ignore(255, '\n');
            cout << "������� ��� ��������, � �������� �������� ��� ����� (���� ��� �������� � ���, ������� '�'):\n> ";
            getline(cin, a[i].LIB_INFO.STORED);
        }
    }
    cout << "���������� ������ �������.\n�������� ����� ����." << endl;
}

void del(home_library* a, int& b)
{
    string auth, name;
    int number = 0, number1 = 0, ooo_bool = 0, oooo_bool = 0;
    cout << "������� ������, ��� ����� �� ������ �������:\n";
    for (int i = 0; i < b; i++)
    {
        if (ooo_bool == 1)
            for (int n = 0; n < i; n++)
                if (a[i].LIB_INFO.AUTHOR == a[n].LIB_INFO.AUTHOR)
                {
                    oooo_bool++;
                }
        if (oooo_bool == 0) cout << a[i].LIB_INFO.AUTHOR << "\n";
        ooo_bool++;
        oooo_bool = 0;
    }
    cin.ignore(255, '\n');
    cout << "> ";
    getline(cin, auth);
    for (int i = 0; i < b; i++) if (auth == a[i].LIB_INFO.AUTHOR) number1++;
    if (number1 == 0) cout << "� ����� ������ ���� �� ����������." << endl;
    if (number1 == 1)
    {
        cout << "������� ���� ����� �� ������� ������. ������� �..." << endl;
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].NAME = a[i].NAME;
                a[i - 1].LIB_INFO.AUTHOR = a[i].LIB_INFO.AUTHOR;
                a[i - 1].LIB_INFO.RELEASE_YEAR = a[i].LIB_INFO.RELEASE_YEAR;
                a[i - 1].LIB_INFO.QUANTITY = a[i].LIB_INFO.QUANTITY;
                a[i - 1].LIB_INFO.GIVEN = a[i].LIB_INFO.GIVEN;
                a[i - 1].LIB_INFO.STORED = a[i].LIB_INFO.STORED;
            }
            if (auth == a[i].LIB_INFO.AUTHOR) number = 1;
        }
    }
    if (number1 > 1)
    {
        cout << "������� ��������� (" << number1 << ") ���� �� ������� ������. ��������, ����������, ������ �� ����������:\n";
        for (int i = 0; i < b; i++) if (auth == a[i].LIB_INFO.AUTHOR) cout << a[i].NAME << endl;
        cout << "> ";
        getline(cin, name);
        for (int i = 0; i < b; i++)
        {
            if (number == 1)
            {
                a[i - 1].NAME = a[i].NAME;
                a[i - 1].LIB_INFO.AUTHOR = a[i].LIB_INFO.AUTHOR;
                a[i - 1].LIB_INFO.RELEASE_YEAR = a[i].LIB_INFO.RELEASE_YEAR;
                a[i - 1].LIB_INFO.QUANTITY = a[i].LIB_INFO.QUANTITY;
                a[i - 1].LIB_INFO.GIVEN = a[i].LIB_INFO.GIVEN;
                a[i - 1].LIB_INFO.STORED = a[i].LIB_INFO.STORED;
            }
            if (name == a[i].NAME) number = 1;
        }
        if (number == 0) cout << "���� �� ������� ������ � ����� ��������� �� ����������." << endl;
    }
    if (number == 1) b--;
    cout << "�������� ����� ����." << endl;
}

void search(home_library* a, int b)
{
    int number, o_bool = 0;
    do
    {
        cout << "��� �� ������ �����?\n1. ��� ����� �� �.-�. ������.\n2. ��� ������� �� ��� ���� �����.\n3. �����.\n> ";
        cin >> number;
        switch (number)
        {
        case 1:
        {
            string author;
            int o = 0, oo_bool = 0;
            cout << "������� �������� ������, ���������� � ���������:\n> ";
            cin.ignore(255, '\n');
            getline(cin, author);
            cout << "��� ����� ������� ������:";
            for (int i = 0; i < b; i++)
            {
                if (author == a[i].LIB_INFO.AUTHOR)
                {
                    if (oo_bool == 0)
                    {
                        cout << " ";
                        oo_bool++;
                    }
                    else cout << ", ";
                    cout << a[i].NAME;
                    o++;
                }
            }
            if (o == 0) cout << " ���/�� �������.";
            if(o >= 1) cout << ".";
            cout << endl;
        }
        break;
        case 2:
        {
            string name;
            int oo_bool = 0;
            cout << "������� �������� �����:\n> ";
            cin.ignore(255, '\n');
            getline(cin, name);
            for (int i = 0; i < b; i++)
            {
                if (name == a[i].NAME)
                {
                    cout << "����� ���� �������� ������� " << a[i].LIB_INFO.AUTHOR;
                    oo_bool++;
                }
            }
            if (oo_bool == 0) cout << "����� � ����� ��������� �� �������.";
            cout << endl;
        } break;
        case 3:
        {
            o_bool = 1;
        } break;
        default: cout << "������� ���� ����� �� �� ������� ����.\n";
        }
    } while (o_bool == 0);
    cout << "����������� � ����." << endl;
}

void calculation(home_library* a, int b)
{
    int number, o_bool = 0;
    cout << "";
    do
    {
        cout << "��� �� ������ ���������?\n1. ����� ������� ���������� ���������� ����.\n2. ���������� �������� ����.\n3. �����.\n> ";
        cin >> number;
        switch (number)
        {
        case 1:
        {
            int max = 0, o = 0;
            for (int i = 0; i < b; i++) if (a[i].LIB_INFO.QUANTITY > max) max = a[i].LIB_INFO.QUANTITY;
            for (int i = 0; i < b; i++)
                if (max == a[i].LIB_INFO.QUANTITY) cout << a[i].LIB_INFO.QUANTITY << " -- " << a[i].NAME << endl;
        }
        break;
        case 2:
        {
            int number = 0;
            cout << "���������� ��������: ";
            for (int i = 0; i < b; i++) if (a[i].LIB_INFO.GIVEN == true) number++;
            cout << number << "\n�������� �����:";
            for (int i = 0; i < b; i++) if (a[i].LIB_INFO.GIVEN == true)
            {
                cout << " ";
                cout << a[i].NAME;
            }
            cout << endl;
        }
        break;
        case 3:
        {
            o_bool = 1;
        } break;
        default: cout << "������� ���� ����� �� �� ������� ����.\n";
        }
    } while (o_bool == 0);
    cout << "����������� � ����." << endl;
}

void edit(home_library*& a, int b)
{
    int o_bool = 0, number_menu, edit_int, bool_number = 0, bool_number_2 = 0, oo_bool = 0, ooo_bool = 0, oooo_bool = 0;
    char edit_char;
    string edit_string, author, name;
    cout << "�������� ������:\n";
    for (int i = 0; i < b; i++)
    {
        if (ooo_bool == 1)
            for (int n = 0; n < i; n++)
                if (a[i].LIB_INFO.AUTHOR == a[n].LIB_INFO.AUTHOR)
                {
                    oooo_bool++;
                }
        if (oooo_bool == 0) cout << a[i].LIB_INFO.AUTHOR << "\n";
        ooo_bool++;
        oooo_bool = 0;
    }
    do
    {
        cin.ignore(255, '\n');
        cout << "> ";
        getline(cin, author);
        if (bool_number < 2)
        {
            for (int i = 0; i < b; i++) if (author == a[i].LIB_INFO.AUTHOR) o_bool++;
            if (o_bool == 0)
            {
                cout << "��������� ����.\n";
                bool_number++;
            }
        }
        else
        {
            cout << "�� ����� ������ ����������� 3 ���� ������. ������� ����� � ���� ��� ������ ������ ��������?\n1. ��, ����� � ����.\n2. ���, ����������� ���.\n> ";
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
        cout << "�������� �������� �����:\n";
        for (int i = 0; i < b; i++) if (author == a[i].LIB_INFO.AUTHOR) cout << a[i].NAME << "\n";
        do
        {
            cout << "> ";
            getline(cin, name);
            if (bool_number < 2)
            {
                for (int i = 0; i < b; i++) if (name == a[i].NAME) o_bool++;
                if (o_bool == 0)
                {
                    cout << "��������� ����.\n";
                    bool_number++;
                }
            }
            else
            {
                cout << "�� ����� �������� ����������� 3 ���� ������. ������� ����� � ���� ��� ������ ������ ��������?\n1. ��, ����� � ����.\n2. ���, ����������� ���.\n> ";
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
                cout << "��������, ��� �� ������ ��������:\n1. ��������\n2. ������\n3. ���� ����������\n4. ����������\n5. ������/�� ������\n6. �������� �...\n7. ����� � ������� ����\n> ";
                cin >> number_menu;
                switch (number_menu)
                {
                case 1:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "������� ���������:\n> ";
                                getline(cin, a[i].NAME);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 2:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "������� ���������:\n> ";
                                getline(cin, a[i].LIB_INFO.AUTHOR);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 3:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "������� ���������:\n> ";
                                getline(cin, a[i].LIB_INFO.RELEASE_YEAR);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 4:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cout << "������� ���������:\n> ";
                                cin >> edit_int;
                                a[i].LIB_INFO.QUANTITY = edit_int;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 5:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cout << "������� ��������� (������ [+] ��� �������� � ���������� [-]):\n> ";
                                cin >> edit_char;
                                if (edit_char == '+') a[i].LIB_INFO.GIVEN = true;
                                if (edit_char == '-') a[i].LIB_INFO.GIVEN = false;
                                break;
                            }
                    o_bool++;
                }
                break;
                case 6:
                {
                    for (int i = 0; i < b; i++)
                        if (author == a[i].LIB_INFO.AUTHOR)
                            if (name == a[i].NAME)
                            {
                                cin.ignore(255, '\n');
                                cout << "������� ���������:\n> ";
                                getline(cin, a[i].LIB_INFO.STORED);
                                break;
                            }
                    o_bool++;
                }
                break;
                case 7:
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

void rewrite(home_library* a, int b)
{
    string my_string;
    ofstream my_outfile;
    my_outfile.open("Log.txt");
    if (my_outfile.is_open())
    {
        for (int i = 0; i < b; i++)
        {
            my_string = a[i].NAME;
            add_underscores(my_string);
            my_outfile << my_string << " ";
            my_string = a[i].LIB_INFO.AUTHOR;
            add_underscores(my_string);
            my_outfile << my_string << " ";
            my_outfile << a[i].LIB_INFO.RELEASE_YEAR << " ";
            my_outfile << a[i].LIB_INFO.QUANTITY << " ";
            if (a[i].LIB_INFO.GIVEN == true) my_outfile << "+ ";
            if (a[i].LIB_INFO.GIVEN == false) my_outfile << "- ";
            my_string = a[i].LIB_INFO.STORED;
            add_underscores(my_string);
            my_outfile << my_string << " ";
            if (i + 1 != b) my_outfile << "\n";
        }
    }
    cout << "���������� ������ �������.\n�������� ����� ����." << endl;
}

void menu(home_library*& a, int& b)
{
    int number_in_menu, o_bool = 0;
    do
    {
        printf_s("1. ������� ��� ����� �� �����.\n2. �������� �����.\n3. ������� �����.\n4. ������ ���������.\n5. ������������ � ����.\n6. �����.\n7. ����������.\n8. ��������� ������.\n");
        cout << "> ";
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