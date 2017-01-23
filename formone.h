#ifndef FORMONE_H
#define FORMONE_H

#include <QWidget>

namespace Ui {
class FormOne;
}

class FormOne : public QWidget
{
    Q_OBJECT

public:
    explicit FormOne(QWidget *parent = 0);
    ~FormOne();

protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::FormOne *ui;
};

#endif // FORMONE_H
