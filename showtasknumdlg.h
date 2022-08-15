#ifndef SHOWTASKNUMDLG_H
#define SHOWTASKNUMDLG_H

#include <QDialog>

namespace Ui {
class showtasknumdlg;
}

class showtasknumdlg : public QDialog
{
    Q_OBJECT

public:
    explicit showtasknumdlg(QWidget *parent = nullptr);
    ~showtasknumdlg();

private slots:
    void on_tableWidget_cellClicked(int row, int column);

private:
    Ui::showtasknumdlg *ui;
};

#endif // SHOWTASKNUMDLG_H
