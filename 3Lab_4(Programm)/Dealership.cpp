#include "Dealership.h"

#include <string>

using namespace std;

// ���������� ������� ������ Dealership

const string Dealership::getDealership_name() {
    return dealership_name;
}

const string Dealership::getAddres(){
    return address;
}

void Dealership::setDealership_name(string dealership_name){
    this->dealership_name = dealership_name;
}

void Dealership::setAddres(string addres){
    this->address = address;
}

void  Dealership::outputDealership(Employee* employeeArray, int num_employees, Car* carArray, int num_cars) {
    cout << "�������� ����������: " << name << endl;
    cout << "����� ����������: " << address << endl;
    cout << "-����������:" << endl;
    for (int j = 0; j < num_employees; ++j) {
        cout << j + 1 << ". " << employeeArray[j].getFirstName() << " " << employeeArray[j].getLastName() << endl;
    }

    // ����� ���������� � �����������
    cout << "-����������:" << endl;
    for (int j = 0; j < num_cars; ++j) {
        cout << j + 1 << ". " << carArray[j].getBrand_model() << endl;
    }
}
