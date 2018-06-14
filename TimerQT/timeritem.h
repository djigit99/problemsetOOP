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

class TimerItem : public QWidget
{
    Q_OBJECT
public:
    explicit TimerItem(QWidget *parent = nullptr);
    ~TimerItem();

private:
    Timer* timer;
    QString soundPath;
    QSound* sound;
    QMediaPlayer* mediaPlayer;
    QMovie* movie;

    QHBoxLayout* layout;
    QLabel* itemNumberLabel;
    QLineEdit* contextLineEdit;
    QPushButton* soundPushButton;
    QLineEdit* timeLineEdit;
    QRegExpValidator* regExpValidator;
    QPushButton* playButton;

signals:

public slots:
    void soundOn();
    void soundOff();
    void chooseFile();
};

#endif // TIMERITEM_H
