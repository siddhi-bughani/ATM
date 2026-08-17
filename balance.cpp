#include "balance.h"
#include "ui_balance.h"

balance::balance(Account *account, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::balance)
    , currentAccount(account)
{
    ui->setupUi(this);
}

balance::~balance()
{
    delete ui;
}
