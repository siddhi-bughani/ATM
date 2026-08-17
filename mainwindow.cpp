#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "menu.h"
#include <QMessageBox>


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
    , currentAccount(nullptr)
{
    ui->setupUi(this);

    connect(ui->login, &QPushButton::clicked,
            this, &MainWindow::on_login_clicked);

    connect(ui->clear, &QPushButton::clicked,
            this, &MainWindow::on_clear_clicked);
}
MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_login_clicked()
{
    int userId = ui->id->text().toInt();
    int enteredPin = ui->pin->text().toInt();

    currentAccount = accountManager.authenticate(userId, enteredPin);

    if (currentAccount != nullptr)
    {
        menu *menuWindow = new menu(currentAccount, &accountManager, this);
        menuWindow->show();

        this->hide();
    }
    else
    {
        QMessageBox::warning(this, "Login Failed",
                             "Invalid User ID or PIN.");
    }
}



void MainWindow::on_clear_clicked()
{
    ui->id->clear();
    ui->pin->clear();
}

