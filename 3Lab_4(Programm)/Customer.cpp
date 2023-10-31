#include "Customer.h"
#include <string>

using namespace std;

// ���������� ������� ������ Customer
const string Customer::getFirstName() {
    return person.getFirstName();
}

const string Customer::getLastName() {
    return person.getLastName();
}

const string Customer::getPhone_number(){
    return phone_number;
}

void Customer::setFirstName(string first_name){
    this->person.first_name = first_name;
}

void Customer::setLastName(string last_name){
    this->person.last_name = last_name;
}

void Customer::setPhone_number(string phone_number){
    this->phone_number = phone_number;
}

void Customer::outputCustomer() {
    cout << "��� ����������: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "����� ��������: " << phone_number << endl;
}