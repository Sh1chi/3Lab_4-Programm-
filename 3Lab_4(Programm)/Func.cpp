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

    string dealership_name, dealership_address;
    while (true) {
        // ���� ������ � ����������
        cout << "������� �������� ����������: ";
        getline(cin, dealership_name);
        cout << "������� ����� ����������: ";
        getline(cin, dealership_address);
        if (dealership_name.empty() || dealership_address.empty()) {
            cout << "������: '������������ ����' !\n\n";
        }
        else
            break;
    }

    // ���� ���������� ����������� � �������� ������� �����������
    cout << "������� ���������� �����������: ";
    cin >> numEmployees;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }

    if (numEmployees <= 0) {
        throw exception("������: '������������ ����������' !");
    }

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

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }

    if (numCars <= 0) {
        throw exception("������: '������������ ����������' !");
    }

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

Deal* inputDeal(Dealership dealership, string carData[][3]){
    if (dealership.getDealership_name().empty() || dealership.getAddres().empty()) {
        throw exception("����������� ���������");
    }
    // ���� ���������� ������ � �������� ������� ������
    cout << endl;
    cout << "������� ���������� ������: ";
    cin >> numDeals;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }
    if (numDeals <= 0){
        throw exception("������: '������������ ����������' !");
    }
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
        seller_choice -= 1;

        Car* car_sold = dealership.getCars();
        // ������� ������ ��������� ����������� � �������� �������
        cout << "�������� ���������� (������� ����� ����������):" << endl;
        dealership.outCarsChoice();
        int car_choice;
        cin >> car_choice;
        car_choice -= 1;

        cout << "����� ������: ";
        int transaction_amount;
        cin >> transaction_amount;


        // ���������� ����� ���� � ��� ���� � ������ carData
        carData[i][0] = to_string(deal_number);
        carData[i][1] = car_sold[car_choice].getBrand_model();
        carData[i][2] = to_string(transaction_amount * 0.05);

        // �������� ������� ������ � ���������� ��� � �������
        dealArray[i] = Deal(deal_number, deal_date, seller[seller_choice], buyer, car_sold[car_choice], transaction_amount);
        cout << endl;
    }

    return dealArray;
}

void outputProfitDealership(string carData[][3]) {
    system("cls");
    cout << "   __--������� ����������--__\n\n";
    int total_profit = 0;
    for (int i = 0; i < numDeals; ++i) {
        cout << "������ #" << carData[i][0] << endl;
        cout << "�����: " << carData[i][1] << endl;
        cout << "�������: " << carData[i][2] << endl;
        total_profit += stoi(carData[i][2]);
        cout << endl;
    }
    cout << "����� ������� ����������: " << total_profit;
    cout << endl;
}

void outputDeals(Deal* deals) {
    if (numDeals < 1) {
        throw exception("������� ������ �����...");
    }
    for (int i = 0; i < numDeals; ++i) {
        deals[i].outputDeal();
        cout << endl;
    }
}


void addCarsToDealership(Dealership& dealership)
{
    cout << "   __--���������� ����� ����������� � ���������--__" << endl;

    int numNewCars;
    cout << "������� ���������� ����� �����������: ";
    cin >> numNewCars;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }
    if (numNewCars <= 0) {
        throw exception("������: '������������ ����������' !");
    }

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
    cout << "   __--���������� ����� ����������� � ���������--__" << endl;

    int numNewEmployees;
    cout << "������� ���������� ����� �����������: ";
    cin >> numNewEmployees;
    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }
    if (numNewEmployees <= 0) {
        throw exception("������: '������������ ����������' !");
    }

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

    cout << "   __--�������� �����������--__" << endl;

    dealership.outCarsChoice();

    int car_choice;
    cout << "������� ����� ����������, ������� �� ������ �������: ";
    cin >> car_choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }

    if (car_choice < 0 || car_choice >= numCars) {
        throw exception("������: '������������ ����� ����������' ! �������� �� ���������");
    }

    // �������� ��������� �� ������ ����������� � ����������
    Car* cars = dealership.getCars();

    // ������� ��������� ���������� ����� ������ ���������� ���������
    for (int i = car_choice - 1; i < numCars; ++i) {
        cars[i] = cars[i + 1];
    }

    // ��������� ����� ���������� ����������� � ����������
    numCars--;

    cout << "���������� ������ �� ����������." << endl;
}

// ������� �������� ���������� �� ����������
void removeEmployeeFromDealership(Dealership& dealership){

    cout << "   __--�������� �����������--__" << endl;

    dealership.outEmployeesChoice();

    int employee_choice;
    cout << "������� ����� ����������, �������� �� ������ �������: ";
    cin >> employee_choice;

    if (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        throw invalid_argument("������: '������������ ����' !");
    }

    if (employee_choice < 0 || employee_choice >= numEmployees) {
        throw exception("������: '������������ ����� ����������' ! �������� �� ���������");
    }

    // �������� ��������� �� ������ ����������� � ����������
    Employee* employees = dealership.getEmployees();

    // ������� ���������� ���������� ����� ������ ���������� ���������
    for (int i = employee_choice - 1; i < numEmployees; ++i) {
        employees[i] = employees[i + 1];
    }

    // ��������� ����� ���������� ����������� � ����������
    numEmployees--;

    cout << "��������� ������ �� ����������." << endl;
}

