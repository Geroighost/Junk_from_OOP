#include "Pharmacy.h"
#include <string>
#include <sstream>
#include <iostream>
using namespace std;

template <typename Type> string to_str(Type& t)
{
	ostringstream os;
	os << t;
	return os.str();
}


Pharmacy::Pharmacy()
{
		name = " ";
		manufacturer = " ";
		price = 0.0;
		discount = 0.0;
}

void Pharmacy::Price_with_discount()
{
	float result;
	result = price - (price * (discount * 0.01));
	cout << "���� � ������ ������: " << result << " ���." << endl;
}

Pharmacy::~Pharmacy()
{
}

Pills::Pills()
{
	form = " ";
	distribution_method = " ";
}

Pills::~Pills()
{
}

string Pills::output_in_file()
{
	string b1, b2, b3, b4, b5, b6, b_result;
	b1 = name + " ";
	b2 = form + " ";
	b3 = distribution_method + " ";
	b4 = manufacturer + " ";
	b5 = to_str(price) + " ";
	b6 = to_str(discount) + " ";
	b_result = b1 + b2;
	b_result = b_result + b3;
	b_result = b_result + b4;
	b_result = b_result + b5;
	b_result = b_result + b6;
	return b_result;
}

Devices::Devices()
{
	level_of_security = 0;
	operation_period = 0;
}

Devices::~Devices()
{

}

string Devices::output_in_file()
{
	string b1, b2, b3, b4, b5, b6, b_result;
	b1 = name + " ";
	b2 = to_str(level_of_security) + " ";
	b3 = manufacturer + " ";
	b4 = to_str(operation_period) + " ";
	b5 = to_str(price) + " ";
	b6 = to_str(discount) + " ";
	b_result = b1 + b2;
	b_result = b_result + b3;
	b_result = b_result + b4;
	b_result = b_result + b5;
	b_result = b_result + b6;
	return b_result;
}

ostream& operator<<(ostream& out, const Pills& Pills)
{
	out << "��������: " << Pills.name << "\n   ����� �������: " << Pills.form << "\n   ������ �������������: " << Pills.distribution_method << "\n   �������������: " << Pills.manufacturer << "\n   ����: " << Pills.price << " ���.\n   ������ (���� ���, ����������� 0): " << Pills.discount << "%" << endl;
	return out;
}

ostream& operator<<(ostream& out, const Devices& Devices)
{
	out << "��������: " << Devices.name << "\n   ������� ������������: " << Devices.level_of_security << "\n   �������������: " << Devices.manufacturer << "\n   ���� ������: " << Devices.operation_period << " �.\n   ����: " << Devices.price << " ���.\n   ������ (���� ���, ����������� 0): " << Devices.discount << "%" << endl;
	return out;
}