#include "formone.h"
#include "ui_formone.h"
#include <QPainter>

FormOne::FormOne(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormOne)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("绘制图形"));

    /**
     * 绘制简单的集合图形
     */
}

FormOne::~FormOne()
{
    delete ui;
}

void FormOne::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);
    painter.drawLine(QPoint(10,40),QPoint(40,40));  //画线

    QPen pen;   //画笔
    pen.setColor(Qt::red);
    painter.setPen(pen);
    QBrush brush(Qt::blue); //画刷
    brush.setStyle(Qt::SolidPattern);  //设置画刷样式
    painter.setBrush(brush);

    painter.drawRect(10,60,40,40);  //画矩形

    QRectF rect(10,120,40,40);
    painter.drawArc(rect,30*16,120*16); //画弧，因为角度被分为十六分之一，所以如果想设置为30度，就需要写为30*16

    /**
      * 三种渐变填充方式：
      * 1.线性渐变（linear gradient）在开始点和结束点之间插入颜色
      * 2.辐射渐变（radial gradient）在焦点和环绕它的圆环间插入颜色
      * 3.锥形渐变（conical gradient）在圆心周围插入颜色
      */

    /**
     * @brief linearGradient
     * 线性渐变
     */
    QLinearGradient linearGradient(QPoint(0,40),QPoint(0,60));
    linearGradient.setColorAt(0,Qt::red);
    linearGradient.setColorAt(0.5,QColor(112,125,30));
    linearGradient.setColorAt(1,QColor(QString::fromLocal8Bit("#000")));
    //渐变区域外的区域填充方式
    //QGradient::PadSpread 使用最接近的颜色进行填充(....y, y, r, g, g....)
    //QGradient::ReflectSpread 在渐变区域以外的区域反射渐变（y, r, g, g, r, y）
    //QGradient::RepeatSpread 在渐变区域以外的区域重复渐变(y, r, g, y, r, g)
    linearGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(linearGradient);
    painter.drawRect(100,40,40,60);

    /**
     * @brief radialGradient
     * 辐射渐变
     * arg1：圆心
     * arg2：半径。和圆心一起确定了一个圆
     * arg3：焦点
     */
    QRadialGradient radialGradient(QPoint(130,150),30,QPoint(130,150));
    radialGradient.setColorAt(0,Qt::yellow);
    radialGradient.setColorAt(1,Qt::gray);
    //radialGradient.setSpread(QGradient::RepeatSpread);
    painter.setBrush(radialGradient);
    painter.drawEllipse(QPoint(130,150),30,30);

    /**
     * @brief conicalGradient
     * 锥形渐变，指定中心点和一个角度，逆时针环绕中心插入颜色
     * arg1：圆心
     * arg2：角度（0～360）
     * setSpead对锥形渐变不生效
     */
    QConicalGradient conicalGradient(QPoint(130,230),60);
    conicalGradient.setColorAt(0,Qt::red);
    conicalGradient.setColorAt(1,Qt::yellow);
    painter.setBrush(conicalGradient);
    painter.drawEllipse(QPoint(130,230),30,30);

    /**
      * 绘制带箭头的直线，实现原理：
      * 绘制一条线段，在线段一端绘制一个多边形
      */
    painter.setRenderHint(QPainter::Antialiasing,true); // 去除反锯齿
    QPoint pointleft = QPoint(280,188);
    QPoint pointright = QPoint(470,188);
    QPointF pointTriangle1(pointleft.x(),pointright.y());
    QPointF pointTriangle2(pointleft.x() + 10,pointright.y() -3);
    QPointF pointTriangle3(pointleft.x() + 10,pointright.y() +3);

    QPolygonF polygonfTriangle;
    polygonfTriangle<<pointTriangle1<<pointTriangle2<<pointTriangle3;
    painter.setBrush(QBrush(QColor(0,150,250),Qt::SolidPattern));
    painter.setPen(QPen(QColor(0,150,250),1,Qt::SolidLine,Qt::RoundCap));
    painter.drawPolygon(polygonfTriangle,Qt::WindingFill);  //绘制多边形

    painter.setPen(QPen(QColor(0,150,250),1,Qt::SolidLine,Qt::RoundCap));
    painter.drawLine(pointleft,pointright);
}
