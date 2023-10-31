#pragma once
#include <string>

using namespace std;

// ����� ��������
struct Person {
    string first_name;  // ��� ��������
    string last_name;   // ������� ��������

public:
    Person() : first_name(""), last_name("") {}

    Person(string first_name, string last_name) : first_name(first_name), last_name(last_name) {}

    ~Person() {}

    const string getFirstName(); // ����� ��������� ����� ��������
    const string getLastName();// ����� ��������� ������� ��������
};


