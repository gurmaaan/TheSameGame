#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWidgets();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_gen_btn_clicked()
{
    QList<int> mainList;
    int halfVal = MATRIX_H * MATRIX_W / 2;
    for (int i = 0; i < halfVal; i++)
    {
        mainList << i;
        mainList << i;
    }
    std::random_shuffle(mainList.begin(), mainList.end());

    for(int i = 0; i < MATRIX_W; i++)
    {
        for(int j = 0; j < MATRIX_H; j++)
        {
            QModelIndex index = _model->index(i,j);
            _model->setData(index, mainList.last(), Qt::DisplayRole);
            _model->setData(index, Qt::AlignCenter, Qt::TextAlignmentRole);
            mainList.removeLast();
        }
    }

}

void MainWindow::setWidgets()
{
    _model = new QStandardItemModel(MATRIX_W, MATRIX_H);
    ui->table_view->setModel(_model);
    ui->table_view->verticalHeader()->setSectionResizeMode(QHeaderView::Fixed);
    setCellSize();
}

void MainWindow::resizeEvent(QResizeEvent *event)
{
    Q_UNUSED(event);
    setCellSize();
}

void MainWindow::setCellSize()
{
    int rowH = ui->table_view->height() / MATRIX_H;
    int colW = ui->table_view->width() / MATRIX_W;
    ui->table_view->verticalHeader()->setDefaultSectionSize(rowH);
    for(int i = 0; i < ui->table_view->colorCount(); i++)
        ui->table_view->setColumnWidth(i, colW);
}
