#include "Employee.h"
#include <string>

using namespace std;

const string Employee::getFirstName() {
    return person.getFirstName();
}

const string Employee::getLastName() {
    return person.getLastName();
}

const int Employee::getSalary(){
    return salary;
}

void Employee::setFirstName(string first_name) {
    this->person.first_name = first_name;
}

void Employee::setLastName(string last_name) {
    this->person.last_name = last_name;
}

void Employee::setSalary(int salary){
    this->salary = salary;
}

void Employee::outputEmployee() {
    cout << "��� ����������: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "��������� ����������: " << position << endl;
    cout << "�������� ����������: " << salary << endl;
}
