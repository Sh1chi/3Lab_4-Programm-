#include "Employee.h"
#include <string>

using namespace std;

const string Employee::getFirstName() {
    return person.getFirstName();
}
const string Employee::getLastName() {
    return person.getLastName();
}
void Employee::outputEmployee() {
    cout << "��� ����������: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "��������� ����������: " << position << endl;
    cout << "�������� ����������: " << salary << endl;
}

const int Employee::getSalary()
{
    return 0;
}

void Employee::setSalary()
{
}
