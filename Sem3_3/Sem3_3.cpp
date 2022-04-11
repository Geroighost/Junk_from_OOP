﻿#include <iostream>

using namespace std;

class Vector2
{
private:
	int number1;
	int number2;
	int number3;
	int number4;
public:
	Vector2(int num1, int num2, int num3, int num4)
	{
		number1 = num1;
		number2 = num2;
		number3 = num3;
		number4 = num4;
	}
	Vector2()
	{
		number1 = 0;
		number2 = 0;
		number3 = 0;
		number4 = 0;
	}
	friend Vector2 operator+(const Vector2& N1, const Vector2& N2);
	friend Vector2 operator*(const Vector2&, int);
	int Get_num1() { return number1; }
	int Get_num2() { return number2; }
	int Get_num3() { return number3; }
	int Get_num4() { return number4; }
};

Vector2 operator+(const Vector2& N1, const Vector2& N2)
{
	Vector2 VectorSum;
	VectorSum.number1 = N1.number1 + N2.number1;
	VectorSum.number2 = N1.number2 + N2.number2;
	VectorSum.number3 = N1.number3 + N2.number3;
	VectorSum.number4 = N1.number4 + N2.number4;
	return VectorSum;
}

Vector2 operator*(const Vector2& N1, int num)
{
	Vector2 VectorTimes;
	VectorTimes.number1 = N1.number1 * num;
	VectorTimes.number2 = N1.number2 * num;
	VectorTimes.number3 = N1.number3 * num;
	VectorTimes.number4 = N1.number4 * num;
	return VectorTimes;
}

int main()
{
    Vector2 Vector_1(1, 3, 5, 7);
    Vector2 Vector_2(5, 8, 16, 56);
    Vector2 Vector_Sum = Vector_1 + Vector_2;
    cout << "Сумма векторов: (" << Vector_Sum.Get_num1() << ", " << Vector_Sum.Get_num2() << ", " << Vector_Sum.Get_num3() << ", " << Vector_Sum.Get_num4() << ")" << endl;
    int number, number1;
    cout << "Введите число, на которое нужно умножить вектор:\n>";
    cin >> number;
    cout << "Выберите какой вектор, 1 или 2?\n> ";
    cin >> number1;
    if (number1 == 1)
    {
       Vector2 Vector_Tim = Vector_1 * number;
    }
    if (number1 == 2)
    {
       Vector2 Vector_Tim = Vector_2 * number;
    }
	cout << "Произведение: (" << Vector_Sum.Get_num1() << ", " << Vector_Sum.Get_num2() << ", " << Vector_Sum.Get_num3() << ", " << Vector_Sum.Get_num4() << ")" << endl;
    system("pause");
    return 0;
}