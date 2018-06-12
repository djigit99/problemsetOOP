#include "editpyramiddialog.h"

EditPyramidDialog::EditPyramidDialog( QWidget* parent) :
    QDialog(parent),
    ui(new Ui::MyDialog),
    color( QColor(QColor::Invalid) ),
    height(-1.0),
    width(-1.0) {

    ui->setupUi(this);
    ui->changeCheckBox->setChecked(true);
    ui->heightCheckBox->setChecked(true);
    ui->widthCheckBox->setChecked(true);

    colorDialog = new QColorDialog(this);
    connect(ui->changeCheckBox, SIGNAL(clicked(bool)), ui->colorToolButton, SLOT(setEnabled(bool)));
    connect(ui->heightCheckBox, SIGNAL(clicked(bool)), ui->heightSpinBox, SLOT(setEnabled(bool)));
    connect(ui->widthCheckBox, SIGNAL(clicked(bool)), ui->widthSpinBox, SLOT(setEnabled(bool)));

    connect(ui->colorToolButton, SIGNAL(clicked(bool)), colorDialog, SLOT(exec()));
    connect(colorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(changeColor(QColor)));

}

EditPyramidDialog::~EditPyramidDialog() {
    delete colorDialog;
    delete ui;
}

float EditPyramidDialog::getHeigh() {
    if (ui->heightCheckBox->isChecked()) {
        height = ui->heightSpinBox->value();
    }
    return height;
}

float EditPyramidDialog::getWidth() {
    if (ui->widthCheckBox->isChecked()) {
        width = ui->widthSpinBox->value();
    }
    return width;
}

QColor EditPyramidDialog::getColor() {
    if (ui->changeCheckBox->isChecked()) {
        color = lastSelectedColor;
    }
    return color;
}

void EditPyramidDialog::changeColor(QColor color) {
    this->lastSelectedColor = color;
}
