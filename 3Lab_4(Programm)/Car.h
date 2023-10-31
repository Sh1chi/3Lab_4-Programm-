#pragma once

#include <string>
#include <iostream>


// ����� ����������
class Car {
    string brand_model;  // ����� � ������ ����������
    string country;     // ������ ������������
    int year;            // ��� �������
    int price;           // ����
    string condition;    // ��������� (��������, "New" ��� "Used")
    int quantity;        // ���������� ��������� �����������

public:
    Car() : brand_model(""), country(""), year(0), price(0), condition(""), quantity(0) {}

    Car(string brand_model, string country, int year, int price, string condition, int quantity)
        : brand_model(brand_model), country(country), year(year), price(price), condition(condition), quantity(quantity) {}

    ~Car() {}

    // ������� ����� ��� ��������� ����� � ������ ����
    const string getBrand_model(); // ����� ��������� ����� � ������ ����
    const string getCountry();
    const int getYear();
    const int getPrice(); // ����� ��������� ���� ����
    const string getcondition();
    const int getquantity();

    void getBrand_model(); // ����� ��������� ����� � ������ ����
    void getCountry();
    void getYear();
    void getPrice(); // ����� ��������� ���� ����
    void condition();
    void quantity();

    void outputCar(); // ����� ������ ���������� �� ����������
};

