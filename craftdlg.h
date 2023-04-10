#ifndef CRAFTDLG_H
#define CRAFTDLG_H

#include <QDialog>
#include "my_parameters.h"
#include <modbus/modbus.h>

namespace Ui {
class craftDlg;
}

class craftDlg : public QDialog
{
    Q_OBJECT

public:
    explicit craftDlg(my_parameters *mcs,QWidget *parent = nullptr);
    ~craftDlg();

    my_parameters *m_mcs;

    void init_dlg_show();
    void close_dlg_show();

    modbus_t *ctx_craft;

    bool link_craft_state;

private:
    Ui::craftDlg *ui;
};

#endif // CRAFTDLG_H
