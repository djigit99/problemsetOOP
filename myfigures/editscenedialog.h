#ifndef EDITSCENEDIALOG_H
#define EDITSCENEDIALOG_H

#include <QDialog>
#include "ui_editscenedialog.h"

namespace Ui {
    class EditSceneUI;
}

class EditSceneDialog : public QDialog {

    Q_OBJECT

public:
    explicit EditSceneDialog(QWidget* parent = 0);
    ~EditSceneDialog();

    float getAngleStep();
    float getMovingStep();

private:
    Ui::EditSceneUI* ui;
};

#endif // EDITSCENEDIALOG_H
