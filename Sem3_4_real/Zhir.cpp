#include "Zhir.h"
#include <time.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void Zhir::Find_max_negative_element(int* numbers, int n)
{
	int result = 0;
	for (int i = 0; i < n; i++)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	cout << "��������� ������ �� int-���������: " << result << endl;
}

void Zhir::Find_max_negative_element(float* numbers, int n)
{
	float result = 0;
	for (int i = 0; i < n; i++)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	cout.precision(2);
	cout << "��������� ������ �� float-���������: " << result << endl;
}

void Zhir::Find_max_negative_element(double* numbers, int n)
{
	double result = 0;
	for (int i = 0; i < n; i++)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	cout.precision(3);
	cout << "��������� ������ �� double-���������: " << result << endl;
}
