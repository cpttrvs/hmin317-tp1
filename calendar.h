#ifndef CALENDAR_H
#define CALENDAR_H

#include <QBasicTimer>
#include <QObject>
#include <iostream>
#include <string>

class Calendar : public QObject
{
    Q_OBJECT
public:
    explicit Calendar(int t);
    ~Calendar();

    void startCalendar();

    int getCurrentDay() const { return days; }

public slots:
    void season(int value);

signals:
    void seasonChanged();

protected:
    void timerEvent(QTimerEvent *e);

private:
    QBasicTimer timer;
    int days;
    int tick;

};

#endif // CALENDAR_H
