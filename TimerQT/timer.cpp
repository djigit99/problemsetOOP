#include "timer.h"

Timer::Timer(){
    hours = minutes = seconds = 0u;
}

Timer::Timer(_us hours, _us minutes, _us seconds) {

    this->hours = hours;
    this->minutes = minutes;
    this->seconds = seconds;
}

void Timer::setHours(_us hours) {
    this->hours = hours;
}

void Timer::setMinutes(_us minutes) {
    this->minutes = minutes;
}

void Timer::setSeconds(_us seconds) {
    this->seconds = seconds;
}

_us Timer::getHours(){
    return hours;
}

_us Timer::getMinutes() {
    return minutes;
}

_us Timer::getSeconds() {
    return seconds;
}

bool Timer::timeIsOut() {
    return hours == 0 && minutes == 0 &&
            seconds == 0;
}

void Timer::decTime() {
    if (timeIsOut()) {
        return ;
    }
    if (seconds > 0) {
        seconds--;
    } else if (minutes > 0) {
        seconds = 59;
        minutes--;
    } else {
        hours--;
        seconds = minutes = 59;
    }
}

