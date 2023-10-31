#pragma once
#include "Person.h"
#include <string>
#include <iostream>


// ����� ����������
class Customer {
    Person person;         // ���������� � ����������
    string phone_number;  // ����� �������� ����������

public:
    Customer() : phone_number("") {}

    Customer(string first_name, string last_name, string phone_number)
        : person(first_name, last_name), phone_number(phone_number) {}

    ~Customer() {}

    const string getFirstName(); // ����� ��������� ����� ����������
    const string getLastName(); // ����� ��������� ����� ����������
    const string getPhone_number();

    void setFirstName(string first_name);
    void setLastName(string last_name);
    void setPhone_number(string phone_number);

    void outputCustomer(); // ����� ������ ���������� � ����������
};

