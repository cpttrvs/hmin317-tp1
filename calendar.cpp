#include "calendar.h"

Calendar::Calendar(int t)
{
    tick = t;
}

Calendar::~Calendar() {

}

void Calendar::season(int value) {
    std::string s;
    switch(value)
    {
    case 0: s = "summer";
        break;
    case 1: s = "fall";
        break;
    case 2: s = "winter";
        break;
    case 3: s = "spring";
        break;
    default: s = "error";
        break;
    }
    std::cout << "Season received :" << s << std::endl;
}

void Calendar::startCalendar() {
    std::cout << "Calendar started (day:" << days << ")" << std::endl;
    timer.start(tick, this);
}

void Calendar::timerEvent(QTimerEvent *e) {
    days++;
    if(days%91==0) {
        std::cout << "Days " << days << std::endl;
        emit seasonChanged();
    }
}

