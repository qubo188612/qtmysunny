#ifndef CAMBUILDDLG_H
#define CAMBUILDDLG_H

#include <QDialog>
#include <my_parameters.h>

namespace Ui {
class cambuilddlg;
}

class cambuilddlg : public QDialog
{
    Q_OBJECT

public:
    explicit cambuilddlg(my_parameters *mcs,QWidget *parent = nullptr);
    ~cambuilddlg();

    void init_dlg_show();

private:
    Ui::cambuilddlg *ui;

    my_parameters *m_mcs;
};

#endif // CAMBUILDDLG_H
