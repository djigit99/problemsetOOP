#include "settingsdialog.h"

SettingsDialog::SettingsDialog(QWidget* parent) : QDialog(parent) {
    chooseTimerCombo = new QComboBox(this);
    chooseTimerCombo->addItem("Item 1");
    chooseTimerCombo->addItem("Item 2");
    chooseTimerCombo->addItem("Item 3");
    saveButton = new QPushButton(tr("&Save"), this);
    saveButton->setDefault(true);
    cancelButton = new QPushButton(tr("&Cancel"), this);
    buttonBox = new QDialogButtonBox(Qt::Vertical, this);
    buttonBox->addButton(saveButton, QDialogButtonBox::ActionRole);
    buttonBox->addButton(cancelButton, QDialogButtonBox::ActionRole);

    optionWidget = new QWidget(this);
    optionWidget->hide();

    QGroupBox* gBox = new QGroupBox(tr("Choose a type"), this);
    QGridLayout* ctLayout = new QGridLayout(gBox);

    QVBoxLayout*  radioLayout = new QVBoxLayout(gBox);
    QRadioButton* timerRadioButton = new QRadioButton(tr("Timer"), gBox);
    QRadioButton* alarmRadioButton = new QRadioButton(tr("Alarm"), gBox);
    alarmRadioButton->setChecked(true);

    radioLayout->setSpacing(0);
    radioLayout->addWidget(alarmRadioButton);
    radioLayout->addWidget(timerRadioButton);
    radioLayout->setAlignment(alarmRadioButton, Qt::AlignTop);
    radioLayout->setAlignment(timerRadioButton, Qt::AlignTop);

    QGroupBox* timeGroupBox = new QGroupBox(gBox);
    QCheckBox* hoursCheckBox = new QCheckBox(tr("hours"), timeGroupBox);
    QCheckBox* minutesCheckBox = new QCheckBox(tr("minutes"), timeGroupBox);
    QCheckBox* secondsCheckBox = new QCheckBox(tr("seconds"), timeGroupBox);
    QVBoxLayout* timeVLayout = new QVBoxLayout(timeGroupBox);
    timeVLayout->addWidget(hoursCheckBox);
    timeVLayout->addWidget(minutesCheckBox);
    timeVLayout->addWidget(secondsCheckBox);
    timeGroupBox->setLayout(timeVLayout);
    timeGroupBox->hide();

    ctLayout->addLayout(radioLayout, 0, 0);
    ctLayout->addWidget(timeGroupBox, 0, 1);
    ctLayout->setAlignment(radioLayout, Qt::AlignTop);
    ctLayout->setAlignment(timeGroupBox, Qt::AlignTop);

    gBox->setLayout(ctLayout);

    gBox->hide();

    QGridLayout* gLayout = new QGridLayout(this);
    gLayout->addWidget(chooseTimerCombo, 0, 0);
    gLayout->addWidget(buttonBox, 0, 1);
    gLayout->setAlignment(chooseTimerCombo, Qt::AlignTop);
    gLayout->addWidget(gBox, 1, 0, 1, 2);
    gLayout->setSizeConstraint(QLayout::SetFixedSize);

    connect(this, SIGNAL(isNotNull(bool)), gBox, SLOT(setHidden(bool)));
    connect(chooseTimerCombo, SIGNAL(activated(int)), this, SLOT(itemChanged(int)));
    connect(alarmRadioButton, SIGNAL(toggled(bool)), timeGroupBox, SLOT(setHidden(bool)));

    setLayout(gLayout);
}

void SettingsDialog::itemChanged(int index) {
    if (index == 0) {
        emit isNotNull(true);
    } else {
        emit isNotNull(false);
    }
}
