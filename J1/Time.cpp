#include "Time.h"

using namespace std;
Time::Time()
{
    hour = 0;
    minute = 0;
    second = 0;
}

void Time::setTime(int h, int m, int s)
{
    hour = (h >= 0 && h < 24) ? h : 0;
    minute = (m >= 0 && m < 60) ? m : 0;
    second = (s >= 0 && s < 60) ? s : 0;
}

void Time::getMilTime()
{
    cout << (hour < 10 ? "0" : "") << hour << ":" << (minute < 10 ? "0" : "") << minute << endl;
}

int main(int argc, char *argv[])
{
    Time t;
    int h, m, s;
    if (argc != 4)
    {
        cout << "you should enter 3 argument!" << endl;
        return 0;
    }
    h = strtol(argv[1], nullptr, 0);
    m = strtol(argv[2], nullptr, 0);
    s = strtol(argv[3], nullptr, 0);
    t.setTime(h, m, s);
    t.getMilTime();
    return 0;
}