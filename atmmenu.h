#ifndef ATMMENU_H
#define ATMMENU_H

#include <QWidget>

namespace Ui {
class atmMenu;
}

class atmMenu : public QWidget
{
    Q_OBJECT

public:
    explicit atmMenu(QWidget *parent = nullptr);
    ~atmMenu();

private:
    Ui::atmMenu *ui;
};

#endif // ATMMENU_H
