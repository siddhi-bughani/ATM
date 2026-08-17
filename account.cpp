#include "account.h"

Account::Account(int id, QString name, int pin, double balance) {
    this->userId = id;
    this->username = name;
    this->pin = pin;
    this->balance = balance;

}

int Account::getUserId()
{
    return userId;
}

QString Account::getUsername()
{
    return username;
}

bool Account::checkPin(int enteredPin)
{
    return enteredPin == pin;
}

double Account::getBalance()
{
    return balance;
}

void Account::deposit(double amount)
{
    if (amount > 0)
    {
        balance += amount;
    }
}
bool Account::withdraw(double amount)
{
    if (amount > 0 && amount <= balance)
    {
        balance -= amount;
        return true;
    }

    return false;
}