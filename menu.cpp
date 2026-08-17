#include "menu.h"
#include "ui_menu.h"
#include "mainwindow.h"
#include "balance.h"
#include "deposit.h"
#include "withdraw.h"

menu::menu(Account *account,
           AccountManager *accountManager,
           MainWindow *loginWindow,
           QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
    , currentAccount(account)
    , accountManager(accountManager)
    , loginWindow(loginWindow)
{
    ui->setupUi(this);

    ui->label->setText(
        "Welcome " + currentAccount->getUsername()
        );
}

menu::~menu()
{
    delete ui;
}

void menu::on_view_clicked()
{
    balance *balanceWindow = new balance(currentAccount);
    balanceWindow->show();
}

void menu::on_deposit_clicked()
{
    deposit *depositWindow =
        new deposit(currentAccount, accountManager);

    depositWindow->show();
}

void menu::on_withdraw_clicked()
{
    withdraw *withdrawWindow =
        new withdraw(currentAccount);

    withdrawWindow->show();
}

void menu::on_exit_clicked()
{
    loginWindow->show();
    this->close();
}