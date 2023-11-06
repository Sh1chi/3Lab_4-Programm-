#include "Deal.h"

int Deal::ID = 0;

const int Deal::getDeal_number() {
    return deal_number;
}

const string Deal::getDate(){
    return date;
}

const int Deal::getTransaction_amount(){
    return transaction_amount;
}

int Deal::getID() {
    return ID;
}

void Deal::setDeal_number(int deal_number) {
    this->deal_number = deal_number;
}

void Deal::setDate(string date){
    this->date = date;
}

void Deal::setTransaction_amount(int transaction_amount){
    this->transaction_amount = transaction_amount;
}

void Deal::outputDeal() {
    for (int i = 0; i < numDeals; ++i) {
        cout << " -- ������ #" << deal_number << ":" << endl;
        cout << "���� ������: " << date << endl;
        cout << "��������: " << seller.getFirstName() << " " << seller.getLastName() << endl;
        cout << "����������: " << buyer.getFirstName() << " " << buyer.getLastName() << endl;
        cout << "����������: " << car_sold.getBrand_model() << endl;
        cout << "����� ������: " << transaction_amount << endl;
    }
}
