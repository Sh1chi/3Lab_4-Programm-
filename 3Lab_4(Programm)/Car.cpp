#include "Car.h"

#include <string>

using namespace std;

// ���������� ������� ������ Car
const string Car::getBrandModel() {
    return brand_model;
}
const int Car::getPrice() {
    return price;
}
void Car::outputCar() {
    cout << "����� � ������ ����: " << brand_model << endl;
    cout << "������-�������������: " << country << endl;
    cout << "��� ������������: " << year << endl;
    cout << "����: " << price << endl;
    cout << "���������: " << condition << endl;
    cout << "����������: " << quantity << endl;
}
