#include "showtasknumdlg.h"
#include "ui_showtasknumdlg.h"

showtasknumdlg::showtasknumdlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::showtasknumdlg)
{
    ui->setupUi(this);
    ui->tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);//禁止用户修改
    ui->tableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);//设为整行选中
}

showtasknumdlg::~showtasknumdlg()
{
    delete ui;
}

void showtasknumdlg::on_tableWidget_cellClicked(int row, int column)
{
    QString str = ui->tableWidget->item(row,0)->text();
    int tasknum = str.toInt();
    switch(tasknum)
    {
    case 0:
        //内角缝
    break;
    case 1 ... 99:

    break;
    case 100:

    break;
    default:
    break;
    }
}

