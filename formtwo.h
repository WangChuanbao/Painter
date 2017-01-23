#ifndef FORMTWO_H
#define FORMTWO_H

#include <QWidget>

namespace Ui {
class FormTwo;
}

class FormTwo : public QWidget
{
    Q_OBJECT

public:
    explicit FormTwo(QWidget *parent = 0);
    ~FormTwo();

protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::FormTwo *ui;
};

#endif // FORMTWO_H
