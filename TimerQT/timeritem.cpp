#include "timeritem.h"
#include <QMessageBox>
#include <QDebug>

TimerItem::TimerItem(QWidget *parent) : QWidget(parent) {

    timer = new Timer;

    itemNumberLabel = new QLabel(QString("1"),this);
    contextLineEdit = new QLineEdit(this);
    contextLineEdit->setPlaceholderText("Comment...");
    soundPushButton = new QPushButton(QIcon(":/alarm/alarm.png"), "", this);
    timeLineEdit = new QLineEdit(this);
    timeLineEdit->setFixedWidth(80);
    regExpValidator = new QRegExpValidator(
                QRegExp(QString("^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$")));
    timeLineEdit->setValidator(regExpValidator);
    timeLineEdit->setPlaceholderText("HH:MM:SS");
    playButton = new QPushButton(QIcon(":/playButton/play.png"), "", this);
    movie = new QMovie(":/alarm/giphy.gif");
    movie->setScaledSize(QSize(25, 25));
    QLabel* label = new QLabel;
    label->setMovie(movie);
    layout = new QHBoxLayout(this);
    layout->addWidget(itemNumberLabel);
    layout->addWidget(contextLineEdit);
    layout->addWidget(soundPushButton);
    layout->addWidget(timeLineEdit);
    layout->addWidget(playButton);
    layout->addWidget(label);
    layout->addStretch();

    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    sound = new QSound("");
    mediaPlayer = new QMediaPlayer();

    connect(soundPushButton, SIGNAL(clicked(bool)), this, SLOT(chooseFile()));
    connect(playButton, SIGNAL(clicked(bool)), this, SLOT(soundOn()));
}

TimerItem::~TimerItem() {
    delete timer;
    delete itemNumberLabel;
    delete contextLineEdit;
    delete soundPushButton;
    delete timeLineEdit;
    delete regExpValidator;
    delete sound;
    delete movie;
}

void TimerItem::soundOn() {
    soundPath = "file://" + soundPath;
    mediaPlayer->setMedia(QUrl(soundPath));
    mediaPlayer->play();
    movie->start();
}

void TimerItem::soundOff() {

}

void TimerItem::chooseFile() {
    soundPath = QFileDialog::getOpenFileName(this,
                                             "Open file",
                                             "/home",
                                             "Music file (*.mp3)");

    QMessageBox::information(this, tr("Open file"), soundPath);
}
