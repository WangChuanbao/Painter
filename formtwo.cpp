#include "formtwo.h"
#include "ui_formtwo.h"
#include <QPainter>
#include <QFont>
#include <QFontDatabase>
#include <QDebug>

FormTwo::FormTwo(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormTwo)
{
    ui->setupUi(this);
    setWindowTitle(QString::fromLocal8Bit("绘制文字"));

    /**
     * 绘制文字
     */

    //获取支持的字体
    QFontDatabase fontDatabase;
    qDebug() << fontDatabase.families() << endl;
}

FormTwo::~FormTwo()
{
    delete ui;
}

void FormTwo::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    QPainter painter(this);

    //设置字体颜色为红色
    //QPen pen(Qt::red);
    QPen pen;
    //设置字体颜色渐变
    QLinearGradient linearGradient(QPoint(0,120),QPoint(120,200));
    linearGradient.setColorAt(0,Qt::red);
    linearGradient.setColorAt(0.5,Qt::yellow);
    linearGradient.setColorAt(1,Qt::blue);
    pen.setBrush(linearGradient);

    painter.setPen(pen);

    //设置字体为宋体，15号，加粗，斜体。也可以创建一个font然后设置属性
    //QFont font("宋体",15,QFont::Bold,true);

    QFont font;

    font.setFamily("宋体");   //字体
    font.setPointSize(15);  //字号
    font.setBold(true);     //加粗
    font.setItalic(true);   //斜体
    font.setUnderline(true);    //下划线

    /*
        MixedCase,      大小写混合，文本大小写
        AllUppercase,   全部大写
        AllLowercase,   全部小写
        SmallCaps,      全部大写,字体大小保持原来字体大小。
        Capitalize      首字母大写
     */
    font.setCapitalization(QFont::AllLowercase);   //字母大小写
    //PercentageSpacing 比例间距
    //AbsoluteSpacing 绝对间距
    font.setLetterSpacing(QFont::AbsoluteSpacing,10);   //字符间距

    painter.setFont(font);

    painter.drawText(120,80,QString::fromLocal8Bit("drawText"));

    painter.save(); //保存坐标系状态

    painter.translate(50,50);   //将点（50，50）设为原点
    painter.rotate(90);     //坐标以原点顺时针旋转90度
    painter.drawText(0,0,QString::fromLocal8Bit("helloq"));

    painter.restore();  //恢复以前的坐标系状态

    painter.drawText(QRectF(20,20,300,200),Qt::AlignHCenter,QString::fromLocal8Bit("drawText"));    //指定文字位置，并居中显示
}
