#include "addshapedialog.h"
#include <iostream>

AddShapeDialog::AddShapeDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::Dialog),
    color(QColor(255, 255, 255)){

    ui->setupUi(this);
    ui->addComboBox->addItem(tr("Pyramid"));
    ui->addComboBox->addItem(tr("Sphere"));

    colorDialog = new QColorDialog(this);
    colorDialog->setWindowFlags(Qt::Window);
    colorDialog->setModal(true);
    connect(ui->colorToolButton, SIGNAL(clicked(bool)), colorDialog, SLOT(exec()));
    connect(colorDialog, SIGNAL(colorSelected(QColor)), this, SLOT(setText(QColor)));

}

AddShapeDialog::~AddShapeDialog() {
    delete colorDialog;
    delete ui;
}

TYPE AddShapeDialog::getType() {
    bool typeChosen = (ui->addComboBox->currentText() == QString("Pyramid") ? false : true);
    return (typeChosen == false ? PYRAMID : SPHERE);
}

QVector3D *AddShapeDialog::getCords() {
    return new QVector3D(ui->dXSpinBox->value(), ui->dYSpinBox->value(),
                         ui->dZSpinBox->value());
}

QColor AddShapeDialog::getColor() {
    return color;
}

void AddShapeDialog::setText(QColor color) {
    this->color = color;
    ui->testLabel->setText(color.name());
}
