#ifndef ACCOUNTMANAGER_H
#define ACCOUNTMANAGER_H

#include "account.h"
#include <QList>
#include <QString>

class AccountManager
{
private:
    QList<Account> accounts;

public:
    AccountManager();

    void loadAccounts();
    Account* authenticate(int userId, int pin);
};

#endif // ACCOUNTMANAGER_H