#include "timemanager.h"

Time optimumTime(int64_t avaiableTime, int inc, int ply, int mtg)
{
    Time time;
    time.optimum = avaiableTime / 20;

    mtg = mtg == 0 ? 20 : mtg;
    int overhead = avaiableTime < 200 ? (avaiableTime < 100 ? 5 : 0) : 10;

    avaiableTime -= overhead;
    time.optimum = avaiableTime / mtg;

    time.optimum += inc / 2;
    if (time.optimum >= avaiableTime)
    {
        time.optimum = std::clamp(time.optimum, (int64_t)1, avaiableTime / 20);
    }

    time.maximum = time.optimum * 1.05f;
    if (time.maximum >= avaiableTime)
    {
        time.maximum = time.optimum;
    }
    if (time.maximum == 0 || time.optimum == 0)
    {
        time.maximum = time.optimum = 1;
    }
    return time;
}