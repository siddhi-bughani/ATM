#ifndef WITHDRAW_H
#define WITHDRAW_H

#include <QMainWindow>
#include "account.h"
#include "accountmanager.h"

namespace Ui {
class withdraw;
}

class withdraw : public QMainWindow
{
    Q_OBJECT

public:
    explicit withdraw(Account *account,
                      AccountManager *accountManager,
                      QWidget *parent = nullptr);
    ~withdraw();

private slots:
    void on_withdrawbutton_clicked();

private:
    Ui::withdraw *ui;
    Account *currentAccount;
    AccountManager *accountManager;
};

#endif // WITHDRAW_H