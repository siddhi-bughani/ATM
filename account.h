#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <QString>

class Account
{
private:
    int userId;
    QString username;
    int pin;
    double balance;

public:
    Account(int id, QString name, int pin, double balance);

    int getUserId();
    QString getUsername();
    int getPin();
    bool checkPin(int enteredPin);
    double getBalance();

    void deposit(double amount);
    bool withdraw(double amount);
};

#endif // ACCOUNT_H