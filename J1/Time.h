#include <iostream>
#include <stdlib.h>

class Time
{
public:
    Time();
    void setTime(int, int, int);
    void getMilTime();
    void getStdTime();

private:
    int hour;
    int minute;
    int second;
};