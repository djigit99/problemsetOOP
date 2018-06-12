#ifndef EDITPYRAMIDDIALOG_H
#define EDITPYRAMIDDIALOG_H

#include <QDialog>
#include <QColorDialog>
#include "ui_editpyramiddialog.h"

namespace Ui{
    class MyDialog;
}
class EditPyramidDialog : public QDialog {
    Q_OBJECT

    Ui::MyDialog* ui;

    QColorDialog* colorDialog;

    QColor color;
    QColor lastSelectedColor;
    float height;
    float width;

public:
    explicit EditPyramidDialog(QWidget* parent = 0);
    ~EditPyramidDialog();

    float getHeigh();
    float getWidth();
    QColor getColor();

private slots:
    void changeColor(QColor);
};

#endif // EDITPYRAMIDDIALOG_H
