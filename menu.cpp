#include "menu.h"
#include "ui_menu.h"

menu::menu(Account *account, QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::menu)
    , currentAccount(account)
{
    ui->setupUi(this);

    ui->label->setText("Welcome, " + currentAccount->getUsername());
}

menu::~menu()
{
    delete ui;
}