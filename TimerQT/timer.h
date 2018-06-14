#ifndef TIMER_H
#define TIMER_H

#include <QSound>
#include <QTimer>
#include <QWidget>

typedef unsigned short _us;

class Timer : public QWidget {

public:
    Timer(QWidget *parent = nullptr);
    Timer(_us hours, _us minutes, _us seconds, QWidget *parent = nullptr);

    // setters
    void setHours(_us hours);
    void setMinutes(_us minutes);
    void setSeconds(_us seconds);

    // getters
    _us getHours();
    _us getMinutes();
    _us getSeconds();

private:
    _us hours;
    _us minutes;
    _us seconds;

    QTimer* timer;

};

#endif // TIMER_H
