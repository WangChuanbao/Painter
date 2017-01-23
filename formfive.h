#ifndef FORMFIVE_H
#define FORMFIVE_H

#include <QWidget>

namespace Ui {
class FormFive;
}

class FormFive : public QWidget
{
    Q_OBJECT

public:
    explicit FormFive(QWidget *parent = 0);
    ~FormFive();

protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::FormFive *ui;
};

#endif // FORMFIVE_H
