#ifndef TIMER_H
#define TIMER_H

#include <QWidget>

typedef unsigned short _us;

class Timer {

public:
    Timer();
    Timer(_us hours, _us minutes, _us seconds);

    // setters
    void setHours(_us hours);
    void setMinutes(_us minutes);
    void setSeconds(_us seconds);

    // getters
    _us getHours();
    _us getMinutes();
    _us getSeconds();

    bool timeIsOut();
    void decTime();

private:
    _us hours;
    _us minutes;
    _us seconds;
};

#endif // TIMER_H
