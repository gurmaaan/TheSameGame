#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStandardItemModel>
#include <randommatrix.h>
#include <QDebug>
//
#include "static.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_gen_btn_clicked();

private:
    Ui::MainWindow *ui;
    QStandardItemModel *_model;
    //
    void setWidgets();
    void resizeEvent(QResizeEvent* event);
    void setCellSize();
};

#endif // MAINWINDOW_H
