#ifndef EDITSPHEREDIALOG_H
#define EDITSPHEREDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "ui_editspheresdialog.h"

namespace Ui {
    class EditDialog;
}
class EditSphereDialog : public QDialog {
    Q_OBJECT

    Ui::EditDialog* ui;

    QColorDialog* colorDialog;

    QColor color;
    QColor lastSelectedColor;

    float radius;

public:
    EditSphereDialog(QWidget* parent = 0);
    ~EditSphereDialog();

    QColor getColor();
    float getRadius();

private slots:
    void changeColor(QColor);
};

#endif // EDITSPHEREDIALOG_H
