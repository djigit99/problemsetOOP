#ifndef SETTINGSDIALOG_H
#define SETTINGSDIALOG_H

#include "timer.h"

#include <QDialog>
#include <QComboBox>
#include <QDialogButtonBox>
#include <QGridLayout>
#include <QPushButton>
#include <QGroupBox>
#include <QRadioButton>
#include <QCheckBox>
#include <QVBoxLayout>
#include <QSpacerItem>


class SettingsDialog : public QDialog {

    Q_OBJECT
public:
    SettingsDialog(QWidget* parent = nullptr);
private:
    QComboBox* chooseTimerCombo;
    QPushButton* saveButton;
    QPushButton* cancelButton;
    QDialogButtonBox* buttonBox;
    QWidget* optionWidget;

signals:
    void isNotNull(bool);

public slots:
    void itemChanged(int);
};

#endif // SETTINGSDIALOG_H
