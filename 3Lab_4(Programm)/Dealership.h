#pragma once

#include <string>
#include <iostream>
#include "Employee.h"
#include "Car.h"

#define MAX_EMPLOYEES 100
#define MAX_CARS 100

// ����� ����������
class Dealership {
    string dealership_name;                      // �������� ����������
    string address;                   // ����� ����������
    Employee employees[MAX_EMPLOYEES]; // ������ �����������
    Car cars[MAX_CARS];               // ������ ��������� �����������

public:
    Dealership() : dealership_name(""), address("") {}

    // ���������� � �����������
    Dealership(string name, string address, Car* carArray, int numCars, Employee* employeeArray, int numEmployees)
        : dealership_name(name), address(address) {
        // ������������� �������� � ������������
        for (int i = 0; i < numCars; ++i) {
            cars[i] = carArray[i];
        }

        for (int i = 0; i < numEmployees; ++i) {
            employees[i] = employeeArray[i];
        }
    }

    ~Dealership() {}

    const string getDealership_name(); // ����� ��������� �������� ����������
    const string getAddres();

    void setDealership_name(string dealership_name);
    void setAddres(string addres);

    void outputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars); // ������� ������ ���������� �� ����������
};

