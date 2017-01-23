#include "formthree.h"
#include "ui_formthree.h"
#include <QPainter>

FormThree::FormThree(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormThree)
{
    ui->setupUi(this);

    /**
     * 使用路径
     */
}

FormThree::~FormThree()
{
    delete ui;
}

void FormThree::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    //简单绘图
    //创建QPainterPath对象后，可以使用lineTo()、arcTo()、cubicTo()、quadTo()等函数将直线或曲线添加到路径中
    QPainterPath path;
    path.addEllipse(0,100,50,50);
    path.lineTo(100,200);

    QPainter painter(this);
    painter.setPen(Qt::red);
    painter.setBrush(Qt::yellow);
    painter.drawPath(path);

    //复制图形
    QPainterPath path2;
    path2.addPath(path);
    path2.translate(100,0);
    painter.drawPath(path2);

    QPainterPath path3;
    path3.addRect(200,50,40,40);
    //改变当前点的位置，移动到（100，100）点
    path3.moveTo(200,100);
    path3.lineTo(300,200);
    painter.drawPath(path3);
}
