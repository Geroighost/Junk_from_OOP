#include <iostream>
#include <clocale>

using namespace std;

int main()
{
	//����������� ����������.
	setlocale(LC_ALL, "Russian");
	FILE* myfile;
	int number, number_in_file = 1, o_bool = 0, o_bool1 = 0, n, * mass_number = 0;
	//�������� �����.
	fopen_s(&myfile, "log.dat", "wb+");
	//���� ����� � �� ������ � ����.
	cout << "������� ���������� ����� ��� ����� � ����:\n> ";
	cin >> number;
	for (int i = 0; i < number; i++)
	{
		number_in_file = number_in_file * 3;
		fwrite(&number_in_file, sizeof(int), 1, myfile); //������ � ����.
	}
	mass_number = new int[number];
	fseek(myfile, 0L, SEEK_SET); //����������� � ������ �����.
	fread(mass_number, sizeof(int), number, myfile); //������ number-��������� � ������ mass_number.
	fseek(myfile, 0L, SEEK_SET); //����������� � ������ �����. 
	//������������� ��������.
	for (int i = 0; i < number; i++)
	{
		fseek(myfile, 1L, SEEK_CUR); //����������� �� ���� ����.
		n = ftell(myfile); //��������� �������-����� � �������� �������� � n.
		//���� ���������.
		if (n % 2 == 0)
		{
			cout << mass_number[i] << " ";
		}
	}
	cout << endl;
	fclose(myfile); //�������� �����.
	system("pause");
	return 0;
}