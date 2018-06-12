#ifndef ADDSHAPE_H
#define ADDSHAPE_H

#include <QDialog>
#include <QColorDialog>
#include "ui_addshapedialog.h"
#include "sphere.h"
#include <QVector3D>

namespace Ui {
    class Dialog;
}

class AddShapeDialog : public QDialog {
    Q_OBJECT

    Ui::Dialog* ui;
    QColorDialog* colorDialog;

    QColor color;

public:
    explicit AddShapeDialog(QWidget* parent = 0);
    ~AddShapeDialog();

    TYPE getType();
    QVector3D *getCords();
    QColor getColor();

private slots:
    void setText(QColor);
};

#endif // ADDSHAPE_H
