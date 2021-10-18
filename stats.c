#include "stats.h"

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    if(computedStats.max > maxThreshold)
    {
        (*alerters[0])();
        (*alerters[1])();
    }
}

float min(const float* numberset, int setlength)
{
    float ret = numberset[0];
    for (int i = 1; i < setlength; i++)
    {
        if (numberset[i] < ret )
        {
            ret = numberset[i];
        }
    }
    return (float)ret;
}

float max(const float* numberset, int setlength)
{
    float ret = numberset[0];
    for (int i = 1; i < setlength; i++)
    {
        if (numberset[i] > ret)
        {
            ret = numberset[i];
        }
    }
    return (float)ret;
}
float avg(const float* numberset, int setlength)
{
    float ret = 0;
    for (int i = 0; i < setlength; i++)
    {
        ret = ret + numberset[i];
    }
    return (float)(ret/setlength);
}

struct Stats compute_statistics(const float* numberset, int setlength) {
        
    struct Stats s;
    s.average = avg(numberset, setlength);
    s.min = min(numberset, setlength);
    s.max = max(numberset, setlength);
    return s;
}

void emailAlerter()
{}
void ledAlerter()
{}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
