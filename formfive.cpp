#include "formfive.h"
#include "ui_formfive.h"
#include <QPainter>

FormFive::FormFive(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormFive)
{
    ui->setupUi(this);
}

FormFive::~FormFive()
{
    delete ui;
}

void FormFive::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.scale(2,2);     //放大

    QPixmap pix(200,200);
    pix.fill(Qt::red);      //设置背景色

    QPainter pp(&pix);  //设置画在QPixmap上
    pp.drawLine(0,0,50,50);
    painter.drawPixmap(100,20,pix);
}
