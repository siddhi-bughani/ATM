#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "account.h"
#include "accountmanager.h"

class MainWindow;

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(Account *account,
                  AccountManager *accountManager,
                  MainWindow *loginWindow,
                  QWidget *parent = nullptr);

    ~menu();

private slots:
    void on_view_clicked();
    void on_deposit_clicked();
    void on_withdraw_clicked();
    void on_exit_clicked();

private:
    Ui::menu *ui;

    Account *currentAccount;
    AccountManager *accountManager;
    MainWindow *loginWindow;
};

#endif // MENU_H