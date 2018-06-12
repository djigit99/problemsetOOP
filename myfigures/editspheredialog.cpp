#include "editspheredialog.h"

EditSphereDialog::EditSphereDialog(QWidget* parent) :
    QDialog(parent), ui(new Ui::EditDialog),
    color( QColor(QColor::Invalid) ), radius(-1.0) {

    ui->setupUi(this);
    ui->changeCheckBox->setChecked(true);
    ui->radiusCheckBox->setChecked(true);

    colorDialog = new QColorDialog(this);
    connect(ui->changeCheckBox, SIGNAL(clicked(bool)), ui->colorToolButton, SLOT(setEnabled(bool)));
    connect(ui->radiusCheckBox, SIGNAL(clicked(bool)), ui->radiusSpinBox, SLOT(setEnabled(bool)));
    connect(ui->colorToolButton, SIGNAL(clicked(bool)), colorDialog, SLOT(exec()));
    connect(colorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(changeColor(QColor)));
}

EditSphereDialog::~EditSphereDialog() {
    delete colorDialog;
    delete ui;
}

QColor EditSphereDialog::getColor() {
    if (ui->changeCheckBox->isChecked()) {
        color = lastSelectedColor;
    }
    return color;
}

float EditSphereDialog::getRadius() {
    if (ui->radiusCheckBox->isChecked()) {
        radius = ui->radiusSpinBox->value();
    }
    return radius;
}

void EditSphereDialog::changeColor(QColor color) {
    this->lastSelectedColor = color;
}
