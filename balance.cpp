#include "balance.h"
#include "ui_balance.h"


balance::balance(Account *account, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::balance)
    , currentAccount(account)
{
    ui->setupUi(this);

    ui->label->setText(
        "Balance: ₹" + QString::number(currentAccount->getBalance())
        );
}

balance::~balance()
{
    delete ui;
}
