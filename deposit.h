#ifndef DEPOSIT_H
#define DEPOSIT_H

#include <QMainWindow>
#include "account.h"
#include "accountmanager.h"

namespace Ui {
class deposit;
}

class deposit : public QMainWindow
{
    Q_OBJECT

public:
    explicit deposit(Account *account,
                     AccountManager *accountManager,
                     QWidget *parent = nullptr);
    ~deposit();

private slots:
    void on_depositbutton_clicked();

private:
    Ui::deposit *ui;
    Account *currentAccount;
    AccountManager *accountManager;
};

#endif // DEPOSIT_H