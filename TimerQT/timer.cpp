#include "timer.h"

Timer::Timer(QWidget* parent) : QWidget(parent) {
    hours = minutes = seconds = 0u;
}

Timer::Timer(_us hours, _us minutes, _us seconds,
             QWidget* parent)
        : QWidget(parent) {

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

