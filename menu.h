
#ifndef MENU_H
#define MENU_H

#include <QMainWindow>
#include "account.h"

namespace Ui {
class menu;
}

class menu : public QMainWindow
{
    Q_OBJECT

public:
    explicit menu(Account *account, QWidget *parent = nullptr);
    ~menu();

private:
    Ui::menu *ui;
    Account *currentAccount;
};

#endif // MENU_H