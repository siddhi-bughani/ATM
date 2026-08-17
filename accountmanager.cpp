#include <QDir>
#include <QDebug>





#include "accountmanager.h"
#include <QFile>
#include <QTextStream>

AccountManager::AccountManager()
{
    loadAccounts();
}

void AccountManager::loadAccounts()
{
    QFile file("accounts.txt");

    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        qDebug() << "Could not open accounts.txt";
        qDebug() << "Looking in:" << QDir::currentPath();
        return;
    }

    QTextStream in(&file);

    while (!in.atEnd())
    {
        int id;
        QString name;
        int pin;
        double balance;

        in >> id >> name >> pin >> balance;

        Account account(id, name, pin, balance);
        accounts.append(account);
    }

    file.close();
}

Account* AccountManager::authenticate(int userId, int pin)
{
    for (Account &account : accounts)
    {
        if (account.getUserId() == userId &&
            account.checkPin(pin))
        {
            return &account;
        }
    }

    return nullptr;
}