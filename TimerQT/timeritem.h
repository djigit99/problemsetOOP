#ifndef TIMERITEM_H
#define TIMERITEM_H

#include "timer.h"
#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <QHBoxLayout>
#include <QRegExp>
#include <QRegExpValidator>
#include <QFileDialog>
#include <QSound>
#include <QMediaPlayer>
#include <QMovie>
#include <QTimer>

#include "settingsdialog.h"

class TimerItem : public QWidget {
    Q_OBJECT
public:
    explicit TimerItem(QWidget *parent = nullptr);
    ~TimerItem();

private:
    Timer* timer;
    QTimer* qtimer;
    QString soundPath;
    QSound* sound;
    QMediaPlayer* mediaPlayer;
    QMovie* movie;
    QLabel* movieLabel;

    QHBoxLayout* layout;
    QLabel* itemNumberLabel;
    QLineEdit* contextLineEdit;
    QPushButton* soundPushButton;
    QLineEdit* timeLineEdit;
    QRegExpValidator* regExpValidator;
    QPushButton* settingsButton;
    QPushButton* playButton;
    QPushButton* pauseButton;

    SettingsDialog* sDialog;

signals:
    void timeOut();

public slots:
    void animationOn();
    void animationOff();
    void chooseFile();
    void decTime();
    void timerStarted();
    void timerPaused();
    void changeTimeData();
};

#endif // TIMERITEM_H
