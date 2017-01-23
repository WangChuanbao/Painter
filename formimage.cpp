#include "formimage.h"
#include "ui_formimage.h"
#include <QPainter>

FormImage::FormImage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormImage)
{
    ui->setupUi(this);

    /**
      * 绘制图片
      * Qt提供四个类来处理图像数据：
      * QImage：主要进行I/O处理，也可以直接访问和操作像素
      * QPixmap：主要用在屏幕上显示图片
      * QBitmap：QPixmap的子类，用来处理颜色深度为1的图像，即只能显示黑白两种颜色
      * QPicture：用来记录并重演QPainter命令
      */
}

FormImage::~FormImage()
{
    delete ui;
}

void FormImage::paintEvent(QPaintEvent *e)
{
    Q_UNUSED(e);

    /** －－－－－简单绘制图片－－－－－ */

    QPainter painter(this);

    //1.使用drawImage简单绘图
    QImage ima(":/images/1.jpg");
    //painter.drawImage(QRect(0,0,400,300),ima);    //方式一、将图片绘制在指定区域

    QRect target(0,0,400,300);  //窗口上显示图片的区域
    QRect source(400,0,1000,1000);  //划定源图像中需要显示的区域
    //painter.drawImage(target,ima,source);

    //2.使用QPixmap简单绘图
    QPixmap pix;
    pix.load(":/images/1.jpg");
    //painter.drawPixmap(0,0,200,150,pix);

    /** －－－－－缩放图片－－－－－ */
    int width = pix.width();
    int height = pix.height();
    /**
     * arg3：图片缩放方式
     * KeepAspectRatio：在给定的区域内保持宽高比
     * KeepAspectRatioByExpanding：保持宽高比，有可能超出给定区域
     * IgnoreAspectRatio：不保持宽高比
     */
    pix = pix.scaled(width/6,height/6,Qt::KeepAspectRatio);
    //painter.drawPixmap(0,0,pix);

    /** －－－－－旋转图片－－－－－ */
    //使图片以图片中心进行旋转90度
    QPixmap pix2;
    pix2.load(":/images/1.jpg");
    painter.drawPixmap(100,50,200,200,pix2);

    painter.save();     //保存坐标系
    painter.translate(200.0,150.0);     //1.将图片中心设置为原点
    painter.rotate(90);     //2.顺时针旋转90度
    painter.drawPixmap(-100,0,200,200,pix2);
    painter.restore();  //还原坐标系

    //图片扭曲
    painter.shear(0.5,0);   //横向扭曲
    painter.drawPixmap(300,0,100,100,pix);
}
