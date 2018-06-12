#include "loadscenedialog.h"

LoadSceneDialog::LoadSceneDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::LoadDialog) {

    ui->setupUi(this);

}

LoadSceneDialog::~LoadSceneDialog() {
    delete ui;
}

uint LoadSceneDialog::getId(){
    return ui->lineEdit->text().toInt();
}
