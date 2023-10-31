#pragma once
#include "Person.h"
#include <string>
#include <iostream>

// ����� ����������
class Employee {
    Person person;      // ���������� � ����������
    string position;   // ��������� ����������
    int salary;        // �������� ����������

public:
    Employee() : position(""), salary(0) {}

    Employee(string first_name, string last_name, string position, int salary)
        : person(first_name, last_name), position(position), salary(salary) {}

    ~Employee() {}

    const string getFirstName(); // ����� ��������� ����� ����������
    const string getLastName(); // ����� ��������� ����� ����������
    const int getSalary();
    void setSalary();
    void outputEmployee(); // ����� ������ ���������� � ����������
};

