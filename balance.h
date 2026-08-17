#ifndef BALANCE_H
#define BALANCE_H

#include <QMainWindow>
#include "account.h"

namespace Ui {
class balance;
}

class balance : public QMainWindow
{
    Q_OBJECT

public:
    explicit balance(Account *account, QWidget *parent = nullptr);
    ~balance();

private:
    Ui::balance *ui;
    Account *currentAccount;
};

#endif // BALANCE_H