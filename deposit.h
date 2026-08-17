#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QMainWindow>
#include "account.h"

namespace Ui {
class deposit;
}

class deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit deposit(Account *account, QWidget *parent = nullptr);
    ~deposit();

private:
    Ui::deposit *ui;
    Account *currentAccount;
};

#endif // DEPOSIT_H
