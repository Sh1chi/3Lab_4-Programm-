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

const string Customer::getPerson()
{
    return string();
}

void Customer::setPerson()
{
}

void Customer::outputCustomer() {
    cout << "��� ����������: " << person.getFirstName() << " " << person.getLastName() << endl;
    cout << "����� ��������: " << phone_number << endl;
}

// ������� ����� ���������� � ���������� � ������ ����������
void inputCustomer(string* first_name, string* last_name, string* phone_number) {
    cout << "������� ��� ����������: ";
    cin >> *first_name;
    cout << "������� ������� ����������: ";
    cin >> *last_name;
    cout << "������� ����� ��������: ";
    cin >> *phone_number;
}