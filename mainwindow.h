#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedLayout>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_graph_press();
    void on_text_press();
    void on_path_press();
    void on_image_press();
    void on_test_press();

private:
    Ui::MainWindow *ui;
    QStackedLayout *_layout;
};

#endif // MAINWINDOW_H
