#include "deposit.h"
#include "ui_deposit.h"

deposit::deposit(Account *account, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deposit)
    , currentAccount(account)
{
    ui->setupUi(this);
}

deposit::~deposit()
{
    delete ui;
}