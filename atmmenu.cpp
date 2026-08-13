#include "atmmenu.h"
#include "ui_atmmenu.h"

atmMenu::atmMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::atmMenu)
{
    ui->setupUi(this);
}

atmMenu::~atmMenu()
{
    delete ui;
}
