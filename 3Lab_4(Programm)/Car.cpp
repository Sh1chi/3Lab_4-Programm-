#include "Car.h"
#include <string>

using namespace std;

// ���������� ������� ������ Car

const string Car::getBrand_model(){
    return brand_model;
}

const string Car::getCountry(){
    return country;
}

const int Car::getYear(){
    return year;
}

const int Car::getPrice() {
    return price;
}

const string Car::getCondition(){
    return condition;
}

const int Car::getQuantity(){
    return quantity;
}



void Car::setBrand_model(string brand_model){
    this->brand_model = brand_model;
}

void Car::setCountry(string country){
    this->country = country;
}

void Car::setYear(int year){
    this->year = year;
}

void Car::setPrice(int price){
    this->price = price;
}

void Car::setCondition(string condition){
    this->condition = condition;
}

void Car::setQuantity(int quantity){
    this->quantity = quantity;
}

void Car::outputCar() {
    cout << "����� � ������ ����: " << brand_model << endl;
    cout << "������-�������������: " << country << endl;
    cout << "��� ������������: " << year << endl;
    cout << "����: " << price << endl;
    cout << "���������: " << condition << endl;
    cout << "����������: " << quantity << endl;
}
