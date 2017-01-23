#ifndef FORMIMAGE_H
#define FORMIMAGE_H

#include <QWidget>

namespace Ui {
class FormImage;
}

class FormImage : public QWidget
{
    Q_OBJECT

public:
    explicit FormImage(QWidget *parent = 0);
    ~FormImage();

protected:
    void paintEvent(QPaintEvent *e);

private:
    Ui::FormImage *ui;
};

#endif // FORMIMAGE_H
