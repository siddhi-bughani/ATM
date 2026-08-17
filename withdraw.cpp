#include "withdraw.h"
#include "ui_withdraw.h"

withdraw::withdraw(Account *account, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::withdraw)
    , currentAccount(account)
{
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}