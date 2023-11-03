#include "Func.h"

// ������� ����� ���������� � ���������� � ������ ����������
void inputEmployee(string* first_name, string* last_name, string* position, int* salary) {
    cout << "������� ��� ����������: ";
    cin >> *first_name;
    cout << "������� ������� ����������: ";
    cin >> *last_name;
    cout << "������� ��������� ����������: ";
    cin.ignore(); // ������� ����� ����� ����� ����������� ������
    getline(cin, *position);
    cout << "������� �������� ����������: ";
    cin >> *salary;
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

// ������� ����� ���������� �� ����������� � ������ ����������
void inputCar(string* brand_model, string* country, int* year, int* price, string* condition, int* quantity) {
    cout << "������� ����� � ������ ����: ";
    cin.ignore(); // ������� ����� ����� ����� ����������� ������
    getline(cin, *brand_model);
    cout << "������� ������-�������������: ";
    getline(cin, *country);
    cout << "������� ��� ������������: ";
    cin >> *year;
    cout << "������� ����: ";
    cin >> *price;
    cout << "������� ���������: ";
    cin.ignore(); // ������� ����� ����� ����� ����������� ������
    getline(cin, *condition);
    cout << "������� ����������: ";
    cin >> *quantity;
}

// ������� ��� ��������� ��������� ��� ������� (��� ��������� ���������)
void SetConsoleEncoding() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}