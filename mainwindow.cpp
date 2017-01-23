#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QAction>
#include <QDebug>
#include "formone.h"
#include "formtwo.h"
#include "formthree.h"
#include "formimage.h"
#include "formfive.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QAction *graph = new QAction(QString::fromLocal8Bit("绘制图形"),this);
    QAction *text = new QAction(QString::fromLocal8Bit("绘制文字"),this);
    QAction *path = new QAction(QString::fromLocal8Bit("绘制路径"),this);
    QAction *image = new QAction(QString::fromLocal8Bit("绘制图片"),this);
    QAction *test = new QAction(QString::fromLocal8Bit("涂鸦板"),this);
    QList<QAction *> list;
    list.append(graph);
    list.append(text);
    list.append(path);
    list.append(image);
    ui->mainToolBar->addActions(list);
    ui->mainToolBar->addAction(test);

    connect(graph,SIGNAL(triggered()),this,SLOT(on_graph_press()));
    connect(text,SIGNAL(triggered()),this,SLOT(on_text_press()));
    connect(path,SIGNAL(triggered()),this,SLOT(on_path_press()));
    connect(image,SIGNAL(triggered()),this,SLOT(on_image_press()));
    connect(test,SIGNAL(triggered()),this,SLOT(on_test_press()));

    _layout = new QStackedLayout(ui->centralWidget);
    FormOne *one = new FormOne(this);
    FormTwo *two = new FormTwo(this);
    FormThree *three = new FormThree(this);
    FormImage *imageWidget = new FormImage(this);
    FormFive *five = new FormFive(this);
    _layout->addWidget(one);
    _layout->addWidget(two);
    _layout->addWidget(three);
    _layout->addWidget(imageWidget);
    _layout->addWidget(five);

    setWindowTitle(QString::fromLocal8Bit("绘制图形"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_graph_press()
{
    _layout->setCurrentIndex(0);
    setWindowTitle(QString::fromLocal8Bit("绘制图形"));
}

void MainWindow::on_text_press()
{
    _layout->setCurrentIndex(1);
    setWindowTitle("绘制文字");
}

void MainWindow::on_path_press()
{
    _layout->setCurrentIndex(2);
    setWindowTitle("绘制路径");
}

void MainWindow::on_image_press()
{
    _layout->setCurrentIndex(3);
    setWindowTitle("绘制图片");
}

void MainWindow::on_test_press()
{
    _layout->setCurrentIndex(4);
    setWindowTitle("涂鸦板");
}
