#include "chosescenedialog.h"

ChoseSceneDialog::ChoseSceneDialog(QWidget* parent) :
    QDialog(parent),
    ui(new Ui::ChoseDialog) {

    ui->setupUi(this);

}

ChoseSceneDialog::~ChoseSceneDialog() {
    delete ui;
}
