#include <iostream>
#include <time.h>

using namespace std;

void setvalue(int*, int);
void setvalue(float*, int);
void print(int*, int);
void print(float*, int);
void printquestion(int*, float*, int, int);
void min_mod_choice(int*, float*, int, int);
void sum_of_elements_choice(int*, float*, int, int);
void min_mod(int*, int);
void min_mod(float*, int);
void sum_of_elements(int*, int);
void sum_of_elements(float*, int);

int main()
{
	setlocale(LC_ALL, "RUSSIAN");
	int celye, veshestv, answer, o3;
	o3 = 0;
	printf_s("������� ���������� ��������� ������� ����� �����: ");
	scanf_s("%i", &celye);
	int* p = new int[celye];
	printf_s("������� ���������� ��������� ������� �������. �����: ");
	scanf_s("%i", &veshestv);
	float* t = new float[veshestv];
	printf_s("������ �������...");
	setvalue(p, celye);
	setvalue(t, veshestv);
	printquestion(p, t, celye, veshestv);
	do
	{
		printf_s("\n�������� ����� �� ����:\n1. ����� ������������ �� ������ �������� �������.\n2. ����� ������� ��������� �������, ������������� ����� ������� �������������� ��������.\n3. �����");
		printf_s("\n�����: ");
		scanf_s("%i", &answer);
		switch (answer)
		{
		case 1:
		{
			min_mod_choice(p, t, celye, veshestv);
		}
		break;
		case 2:
		{
			sum_of_elements_choice(p, t, celye, veshestv);
		}
		break;
		case 3:
		{
			o3++;
		}
		break;
		default: printf_s("������� ���� ����� �� �� ����.");
		}
	} while (o3 == 0);
	printf_s("����� ���������.");
	return 0;
}

void setvalue(int* x, int m)
{
	srand(time(NULL));
	for (int j = 0; j < m; j++) x[j] = rand() % 101;
}

void setvalue(float* x, int m)
{
	srand(time(NULL));
	for (int j = 0; j < m; j++) x[j] = (float)(rand() % 20) * 0.001;
}

void print(int* x, int m)
{
	printf_s("\n");
	for (int j = 0; j < m; j++) printf_s("%i ", x[j]);
}

void print(float* x, int m)
{
	printf_s("\n");
	for (int j = 0; j < m; j++) printf_s("%0.3f ", x[j]);
}

void printquestion(int* p, float* t, int x, int y)
{
	int answer3, answer4, check;
	check = 0;
	printf_s("\n������� ������� ������� �� �����?\n1. ��\n2. ���");
	printf_s("\n�����: ");
	scanf_s("%i", &answer3);
	switch (answer3)
	{
	case 1:
	{
		printf_s("\n��� ������ �� ����� �����:");
		print(p, x);
		printf_s("\n��� ������ �� �������. �����:");
		print(t, y);
		do
		{
			printf_s("\n������� ���������?\n1. ��\n2. ���");
			printf_s("\n�����: ");
			scanf_s("%i", &answer4);
			switch (answer4)
			{
			case 1:
			{
				printf_s("\n��� ������ �� ����� �����:");
				print(p, x);
				printf_s("\n��� ������ �� �������. �����:");
				print(t, y);
			}
			break;
			case 2:
			{
				check++;
			}
			break;
			default: printf_s("���������� �����.");
			}
		} while (check == 0);
		check = 0;
	}
	break;
	case 2: break;
	}
}

void min_mod(int* x, int m)
{
	int min_mod, number = 0;
	min_mod = 100;
	for (int j = 0; j < m; j++) if (abs(x[j]) < min_mod) min_mod = x[j];
	for (int j = 0; j < m; j++) if (min_mod == abs(x[j])) number = j;
	printf_s("\n����� ������������ �� ������ �������� � ����� �����: %i", number+1);
}

void min_mod(float* x, int m)
{
	int number = 0;
	float min_mod = 100;
	for (int j = 0; j < m; j++) if (abs(x[j]) < min_mod) min_mod = x[j];
	for (int j = 0; j < m; j++) if (min_mod == abs(x[j])) number = j;
	printf_s("\n����� ������������ �� ������ �������� � �������. �����: %i", number+1);
}

void sum_of_elements(int* x, int m)
{
	int sum = 0, o_bool = 0;
	for (int j = 0; j < m; j++)
	{
		if (x[j] < 0 && o_bool == 0)
		{
			o_bool++;
		}
		if (o_bool == 1)
		{
			sum = sum + x[j];
		}
	}
	if (o_bool == 1) printf_s("\n����� �����: %i", sum);
	if (o_bool == 0) printf_s("\n����� ��������� ������� ��� ������������� �����.");
}

void sum_of_elements(float* x, int m)
{
	int o_bool = 0;
	float sum = 0;
	for (int j = 0; j < m; j++)
	{
		if (x[j] < 0 && o_bool == 0)
		{
			o_bool++;
		}
		if (o_bool == 1)
		{
			sum = sum + x[j];
		}
	}
	if (o_bool == 1) printf_s("\n����� ����� �� ������������ ��������: %0.3f", sum);
	if (o_bool == 0) printf_s("\n����� ��������� ������� ��� ������������� �����.");
}

void min_mod_choice(int* p, float* t, int x, int y)
{
	int answer5, answer6, check, justcheck;
	check = 0;
	justcheck = 0;
	do
	{
		printf_s("\n��� ������ ������� �� ������ ������� ������?\n1. �� �����\n2. �� ������������\n3. �����");
		printf_s("\n�����: ");
		scanf_s("%i", &answer5);
		switch (answer5)
		{
		case 1:
		{
			min_mod(p, x);

		}
		break;
		case 2:
		{
			min_mod(t, y);
		}
		break;
		case 3:
		{
			check++;
		}
		break;
		default: printf_s("���������� �����.");
		}
		if (answer5 != 3)
		{
			printf_s("\n������� ���������?\n1. ��\n2. ���");
			do
			{
				printf_s("\n�����: ");
				scanf_s("%i", &answer6);
				switch (answer6)
				{
				case 1:
				{
					justcheck++;
				}
				break;
				case 2:
				{
					check++;
					justcheck++;
				}
				break;
				default: printf_s("���������� �����.");
				}
			} while (justcheck == 0);
			justcheck = 0;
		}
	} while (check == 0);
}

void sum_of_elements_choice(int* p, float* t, int x, int y)
{
	int answer7, answer8, check, justcheck;
	check = 0;
	justcheck = 0;
	do
	{
		printf_s("\n��� ������ ������� �� ������ ������� �����?\n1. �� �����\n2. �� ������������\n3. �����");
		printf_s("\n�����: ");
		scanf_s("%i", &answer7);
		switch (answer7)
		{
		case 1:
		{
			sum_of_elements(p, x);

		}
		break;
		case 2:
		{
			sum_of_elements(t, y);
		}
		break;
		case 3:
		{
			check++;
		}
		break;
		default: printf_s("���������� �����.");
		}
		if (answer7 != 3)
		{
			printf_s("\n������� ���������?\n1. ��\n2. ���");
			do
			{
				printf_s("\n�����: ");
				scanf_s("%i", &answer8);
				switch (answer8)
				{
				case 1:
				{
					justcheck++;
				}
				break;
				case 2:
				{
					check++;
					justcheck++;
				}
				break;
				default: printf_s("���������� �����.");
				}
			} while (justcheck == 0);
			justcheck = 0;
		}
	} while (check == 0);
}