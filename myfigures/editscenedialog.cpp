#include "editscenedialog.h"

EditSceneDialog::EditSceneDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::EditSceneUI) {

    ui->setupUi(this);

}

EditSceneDialog::~EditSceneDialog() {
    delete ui;
}

float EditSceneDialog::getAngleStep() {
    return ui->angleStepdSpinBox->value();
}

float EditSceneDialog::getMovingStep() {
    return ui->movingStepdSpinBox->value();
}
