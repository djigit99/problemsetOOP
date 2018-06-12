#ifndef CHOSESCENEDIALOG_H
#define CHOSESCENEDIALOG_H

#include <QDialog>
#include "ui_chosescenedialog.h"

namespace Ui {
    class ChoseDialog;
}

class ChoseSceneDialog : public QDialog {

public:
    explicit ChoseSceneDialog(QWidget* parent = 0);
    ~ChoseSceneDialog();
private:
    Ui::ChoseDialog* ui;
};

#endif // CHOSESCENEDIALOG_H
