#ifndef LOADSCENEDIALOG_H
#define LOADSCENEDIALOG_H

#include <QDialog>
#include "ui_loadscenedialog.h"

namespace Ui {
    class LoadDialog;
}

class LoadSceneDialog : public QDialog {

    Q_OBJECT

public:
    explicit LoadSceneDialog(QWidget* parent = 0);
    ~LoadSceneDialog();

    uint getId();

private:
    Ui::LoadDialog* ui;
};


#endif // LOADSCENEDIALOG_H
