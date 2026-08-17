#include "withdraw.h"
#include "ui_withdraw.h"
#include <QMessageBox>

withdraw::withdraw(Account *account,
                   AccountManager *accountManager,
                   QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::withdraw)
    , currentAccount(account)
    , accountManager(accountManager)
{
    ui->setupUi(this);
}

withdraw::~withdraw()
{
    delete ui;
}

void withdraw::on_withdrawbutton_clicked()
{
    double amount = ui->withdrawmoney->text().toDouble();

    if (amount <= 0)
    {
        QMessageBox::warning(
            this,
            "Invalid Amount",
            "Please enter a valid amount."
            );
        return;
    }

    if (amount > currentAccount->getBalance())
    {
        QMessageBox msgBox(this);
        msgBox.setWindowTitle("Insufficient Balance");
        msgBox.setText("You do not have enough balance.");

        msgBox.setStyleSheet(
            "QMessageBox { color: black; }"
            "QMessageBox QLabel { color: black; }"
            "QMessageBox QPushButton { color: black; }"
            );

        msgBox.exec();
        return;
    }

    currentAccount->withdraw(amount);

    accountManager->saveAccounts();

    QMessageBox msgBox(this);
    msgBox.setWindowTitle("Withdrawal Successful");
    msgBox.setText(
        "₹" + QString::number(amount, 'f', 2) +
        " withdrawn successfully."
        );

    msgBox.setStyleSheet(
        "QMessageBox { color: black; }"
        "QMessageBox QLabel { color: black; }"
        "QMessageBox QPushButton { color: black; }"
        );

    msgBox.exec();

    ui->withdrawmoney->clear();
}