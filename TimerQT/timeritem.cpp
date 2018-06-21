#include "timeritem.h"
#include <QMessageBox>
#include <QDebug>

TimerItem::TimerItem(QWidget *parent) : QWidget(parent) {

    timer = new Timer(0, 0 , 5);
    qtimer = new QTimer;

    itemNumberLabel = new QLabel(QString("1"),this);
    contextLineEdit = new QLineEdit(this);
    contextLineEdit->setPlaceholderText("Comment...");
    soundPushButton = new QPushButton(QIcon(":/alarm/alarm.png"), "", this);
    timeLineEdit = new QLineEdit(QString("00:00:05"),this);
    timeLineEdit->setFixedWidth(80);
    regExpValidator = new QRegExpValidator(
                QRegExp(QString("^([0-9]|0[0-9]|1[0-9]|2[0-3]):[0-5][0-9]:[0-5][0-9]$")));
    timeLineEdit->setValidator(regExpValidator);
    timeLineEdit->setPlaceholderText("HH:MM:SS");
    settingsButton = new QPushButton(QIcon(":/settings/settings.png"), "", this);
    playButton = new QPushButton(QIcon(":/playButton/play.png"), "", this);
    pauseButton = new QPushButton(QIcon(":/playButton/pause.png"), "", this);
    pauseButton->setEnabled(false);

    movie = new QMovie(":/alarm/giphy.gif");
    movie->setScaledSize(QSize(25, 25));
    movieLabel = new QLabel;
    movieLabel->setMovie(movie);

    layout = new QHBoxLayout(this);
    layout->addWidget(itemNumberLabel);
    layout->addWidget(contextLineEdit);
    layout->addWidget(soundPushButton);
    layout->addWidget(timeLineEdit);
    layout->addWidget(settingsButton);
    layout->addWidget(playButton);
    layout->addWidget(pauseButton);
    layout->addWidget(movieLabel);

    layout->setSizeConstraint(QLayout::SetFixedSize);
    setLayout(layout);

    sound = new QSound("");
    mediaPlayer = new QMediaPlayer();

    sDialog = new SettingsDialog(this);

    connect(soundPushButton, SIGNAL(clicked(bool)), this, SLOT(chooseFile()));
    connect(settingsButton, SIGNAL(clicked(bool)), sDialog, SLOT(exec()));
    connect(qtimer, SIGNAL(timeout()), this, SLOT(decTime()));
    connect(this, SIGNAL(timeOut()), this, SLOT(animationOn()));
    connect(playButton, SIGNAL(clicked(bool)), this, SLOT(timerStarted()));
    connect(pauseButton, SIGNAL(clicked(bool)), this, SLOT(timerPaused()));
    connect(timeLineEdit, SIGNAL(editingFinished()), this, SLOT(changeTimeData()));
}

TimerItem::~TimerItem() {
    delete timer;
    delete itemNumberLabel;
    delete contextLineEdit;
    delete soundPushButton;
    delete timeLineEdit;
    delete regExpValidator;
    delete settingsButton;
    delete sound;
    delete movie;
}

void TimerItem::animationOn() {
    mediaPlayer->play();
    movieLabel->show();
    movie->start();
}

void TimerItem::animationOff() {
    mediaPlayer->stop();
    movie->stop();
    movieLabel->hide();
}

void TimerItem::chooseFile() {
    soundPath = QFileDialog::getOpenFileName(this,
                                             "Open file",
                                             "/home",
                                             "Music file (*.mp3)");
    soundPath = "file://" + soundPath;
    mediaPlayer->setMedia(QUrl(soundPath));
    QMessageBox::information(this, tr("Open file"), soundPath);
}

void TimerItem::decTime() {
    timer->decTime();
    timeLineEdit->setText(QString::number(timer->getHours()).rightJustified(2, '0') + ":" +
                          QString::number(timer->getMinutes()).rightJustified(2, '0') + ":" +
                          QString::number(timer->getSeconds()).rightJustified(2, '0') );
    if (timer->timeIsOut()) {
        qtimer->stop();
        emit timeOut();
    }
}

void TimerItem::timerStarted() {
    itemNumberLabel->setEnabled(false);
    contextLineEdit->setEnabled(false);
    soundPushButton->setEnabled(false);
    timeLineEdit->setEnabled(false);
    settingsButton->setEnabled(false);
    playButton->setEnabled(false);
    pauseButton->setEnabled(true);
    qtimer->start(1000);
}

void TimerItem::timerPaused() {
    itemNumberLabel->setEnabled(true);
    contextLineEdit->setEnabled(true);
    soundPushButton->setEnabled(true);
    timeLineEdit->setEnabled(true);
    settingsButton->setEnabled(true);
    playButton->setEnabled(true);
    pauseButton->setEnabled(false);
    qtimer->stop();
    animationOff();

}

void TimerItem::changeTimeData() {
    timer->setHours(timeLineEdit->text().mid(0, 2).toInt());
    timer->setMinutes(timeLineEdit->text().mid(3, 2).toInt());
    timer->setSeconds(timeLineEdit->text().mid(6, 2).toInt());
}
