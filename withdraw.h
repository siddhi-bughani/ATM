#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QMainWindow>
#include "account.h"

namespace Ui {
class withdraw;
}

class withdraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit withdraw(Account *account, QWidget *parent = nullptr);
    ~withdraw();

private:
    Ui::withdraw *ui;
    Account *currentAccount;
};

#endif // WITHDRAW_H