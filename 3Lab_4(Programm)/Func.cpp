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


Dealership inputDealership() {
    cout << "    __-- �������� ���������� --__" << endl;

    cin.ignore();
    // ���� ������ � ����������
    string dealership_name, dealership_address;
    cout << "������� �������� ����������: ";
    getline(cin, dealership_name);
    cout << "������� ����� ����������: ";
    getline(cin, dealership_address);

    // ���� ���������� ����������� � �������� ������� �����������
    cout << "������� ���������� �����������: ";
    cin >> numEmployees;

    Employee* employeeArray = new Employee[numEmployees]; // ��������� ������ ��� ������� �����������

    cout << endl;
    cout << "  -- ���� ������ � ����������� --" << endl;
    for (int i = 0; i < numEmployees; ++i) {
        string first_name, last_name, position;
        int salary;
        cout << "��������� #" << i + 1 << ":" << endl;
        inputEmployee(&first_name, &last_name, &position, &salary);
        employeeArray[i] = Employee(first_name, last_name, position, salary);
        cout << endl;
    }

    // ���� ���������� ����������� � �������� ������� �����������
    cout << "������� ���������� �����������: ";
    cin >> numCars;

    Car* carArray = new Car[numCars]; // ��������� ������ ��� ������� �����������

    cout << endl;
    cout << "  -- ���� ������ �� ����������� --" << endl;
    for (int i = 0; i < numCars; ++i) {
        string brand_model, country, condition;
        int year, price, quantity;
        cout << "���������� #" << i + 1 << ":" << endl;
        inputCar(&brand_model, &country, &year, &price, &condition, &quantity);
        carArray[i] = Car(brand_model, country, year, price, condition, quantity);
        cout << endl;
    }

    Dealership dealership(dealership_name, dealership_address, carArray, numCars, employeeArray, numEmployees);

    // ������������ ���������� ������
    delete[] employeeArray;
    delete[] carArray;

    return dealership;
}

Deal* inputDeal(Dealership dealership){
    // ���� ���������� ������ � �������� ������� ������
    cout << endl;
    cout << "������� ���������� ������: ";
    cin >> numDeals;
    Deal* dealArray = new Deal[numDeals];

    int deal_number;
    cout << endl;
    cout << "  -- ���� ������ � ������� --" << endl;
    // ���� ������ � ������ ������ � �� ���������� � �������
    for (int i = 0; i < numDeals; ++i) {
        //���� ������ ������
        cout << "������ #";
        cin >> deal_number;

        //���� ���� ������
        string deal_date;
        cout << "������� ���� ������: ";
        cin >> deal_date;

        // ���� ������ � ����������
        string buyer_first_name, buyer_last_name, buyer_phone_number;
        inputCustomer(&buyer_first_name, &buyer_last_name, &buyer_phone_number);
        Customer buyer(buyer_first_name, buyer_last_name, buyer_phone_number);

        Employee* seller = dealership.getEmployees();
        // ����� ������ ��������� ����������� � �������� �������
        cout << "�������� �������� (������� ����� ����������):" << endl;
        dealership.outEmployeesChoice();
        int seller_choice;
        cin >> seller_choice;


        Car* car_sold = dealership.getCars();
        // ������� ������ ��������� ����������� � �������� �������
        cout << "�������� ���������� (������� ����� ����������):" << endl;
        dealership.outCarsChoice();
        int car_choice;
        cin >> car_choice;

        cout << "����� ������:" << endl;
        int transaction_amount;
        cin >> transaction_amount;

        // �������� ������� ������ � ���������� ��� � �������
        dealArray[i] = Deal(deal_number, deal_date, seller[seller_choice], buyer, car_sold[car_choice], transaction_amount);
        cout << endl;
    }

    return dealArray;
}

void outputDeals(Deal* deals) {
    for (int i = 0; i < numDeals; ++i) {
        deals[i].outputDeal();
        cout << endl;
    }
}


void addCarsToDealership(Dealership& dealership)
{
    cout << "\n\t~~���������� ����� ����������� � ���������~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewCars;
    cout << "������� ���������� ����� �����������: ";
    cin >> numNewCars;

    int newTotalCars = numCars + numNewCars;

    // �������� ��������� �� ������ ����������� � ����������
    Car* oldCars = dealership.getCars();

    // ������� ��������� ������, ���� ��������� ������������ ����������
    Car* tempCars = new Car[newTotalCars];

    // �������� ������������ ���������� �� ��������� ������
    for (int i = 0; i < numCars; ++i) {
        tempCars[i] = oldCars[i];
    }

    cout << "-------------------------------------------" << endl;
    // ������ � ��������� ����� ���������� �� ��������� ������
    for (int i = numCars; i < newTotalCars; ++i) {
        // ���� ������ �� ����������
        string brand_model, country, condition;
        int year, price, quantity;

        cout << "���������� #" << i + 1 << endl;
        inputCar(&brand_model, &country, &year, &price, &condition, &quantity);
        cout << "-------------------------------------------" << endl;

        // ������� ����� ���������� � ��������� �� ��������� ������
        tempCars[i] = Car(brand_model, country, year, price, condition, quantity);
    }

    // ��������� ���������� ����������� � ����������
    numCars = newTotalCars;

    // ��������� ������ ����������� ���������� �� ����� ��������� ������
    dealership.setCars(tempCars);

    delete[] tempCars;
}

void addEmployeesToDealership(Dealership& dealership)
{
    cout << "\n\t~~���������� ����� ����������� � ���������~~" << endl;

    cout << "-------------------------------------------" << endl;
    int numNewEmployees;
    cout << "������� ���������� ����� �����������: ";
    cin >> numNewEmployees;

    int newTotalEmployees = numEmployees + numNewEmployees;

    // �������� ��������� �� ������ ����������� � ����������
    Employee* oldEmployees = dealership.getEmployees();

    // ������� ��������� ������, ���� ��������� ������������ �����������
    Employee* tempEmployees = new Employee[newTotalEmployees];

    // �������� ������������ ����������� �� ��������� ������
    for (int i = 0; i < numEmployees; ++i) {
        tempEmployees[i] = oldEmployees[i];
    }

    cout << "-------------------------------------------" << endl;
    // ������ � ��������� ����� ����������� �� ��������� ������
    for (int i = numEmployees; i < newTotalEmployees; ++i) {
        // ���� ������ � ����������
        string first_name, last_name, position;
        int salary;

        cout << "��������� #" << i + 1 << endl;
        inputEmployee(&first_name, &last_name, &position, &salary);
        cout << "-------------------------------------------" << endl;

        // ������� ������ ���������� � ��������� �� ��������� ������
        tempEmployees[i] = Employee(first_name, last_name, position, salary);
    }

    // ��������� ���������� ����������� � ����������
    numEmployees = newTotalEmployees;

    // ��������� ������ ����������� ���������� �� ����� ��������� ������
    dealership.setEmployees(tempEmployees);

    delete[] tempEmployees;
}

// ������� �������� ���������� �� ����������
void removeCarFromDealership(Dealership& dealership){

    dealership.outCarsChoice();

    int carIndex;
    cout << "������� ����� ����������, ������� �� ������ �������: ";
    cin >> carIndex;

    if (carIndex < 0 || carIndex >= numCars) {
        cout << "������������ ����� ����������. �������� �� ���������." << endl;
        return;
    }

    // �������� ��������� �� ������ ����������� � ����������
    Car* cars = dealership.getCars();

    // ������� ��������� ���������� ����� ������ ���������� ���������
    for (int i = carIndex - 1; i < numCars; ++i) {
        cars[i] = cars[i + 1];
    }

    // ��������� ����� ���������� ����������� � ����������
    numCars--;

    cout << "���������� ������ �� ����������." << endl;
}

// ������� �������� ���������� �� ����������
void removeEmployeeFromDealership(Dealership& dealership){

    dealership.outEmployeesChoice();

    int employeeIndex;
    cout << "������� ����� ����������, �������� �� ������ �������: ";
    cin >> employeeIndex;

    if (employeeIndex < 0 || employeeIndex >= numEmployees) {
        cout << "������������ ����� ����������. �������� �� ���������." << endl;
        return;
    }

    // �������� ��������� �� ������ ����������� � ����������
    Employee* employees = dealership.getEmployees();

    // ������� ���������� ���������� ����� ������ ���������� ���������
    for (int i = employeeIndex - 1; i < numEmployees; ++i) {
        employees[i] = employees[i + 1];
    }

    // ��������� ����� ���������� ����������� � ����������
    numEmployees--;

    cout << "��������� ������ �� ����������." << endl;
}

// ������� ��� ��������� ��������� ��� ������� (��� ��������� ���������)
void SetConsoleEncoding() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
}