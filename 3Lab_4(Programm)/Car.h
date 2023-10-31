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
    const string getCondition();
    const int getQuantity();

    void setBrand_model(string brand_model);
    void setCountry(string country);
    void setYear(int year);
    void setPrice(int price); // ����� ��������� ���� ����
    void setCondition(string condition);
    void setQuantity(int quantity);

    void outputCar(); // ����� ������ ���������� �� ����������
};

