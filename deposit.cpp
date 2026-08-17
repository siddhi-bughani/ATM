#include "deposit.h"
#include "ui_deposit.h"
#include <QMessageBox>

deposit::deposit(Account *account,
                 AccountManager *accountManager,
                 QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::deposit)
    , currentAccount(account)
    , accountManager(accountManager)
{
    ui->setupUi(this);
}

deposit::~deposit()
{
    delete ui;
}

void deposit::on_depositbutton_clicked()
{
    double amount = ui->depositmoney->text().toDouble();

    if (amount <= 0)
    {
        QMessageBox::warning(
            this,
            "Invalid Amount",
            "Please enter a valid amount."
            );
        return;
    }

    currentAccount->deposit(amount);

    accountManager->saveAccounts();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Deposit Successful");
    msgBox.setText(
        "₹" + QString::number(amount, 'f', 2) +
        " got deposited successfully."
        );

    msgBox.setStyleSheet(
        "QMessageBox { color: black; }"
        "QMessageBox QLabel { color: black; }"
        "QMessageBox QPushButton { color: black; }"
        );

    msgBox.exec();

    ui->depositmoney->clear();
}