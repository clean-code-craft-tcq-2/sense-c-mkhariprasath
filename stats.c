#include "stats.h"
#include "math.h"

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
        
    //optimisation

    struct Stats ret;
    if (numberset == 0 || setlength == 0) //check for valid or non-empty array
    {
        ret.average = NAN;
        ret.min = NAN;
        ret.max = NAN;
        return ret;   
    }

    ret.max     = numberset[0];
    ret.min     = numberset[0];
    ret.average = numberset[0];
    
    for (int i = 1; i < setlength; i++)
    {
        if (numberset[i] < ret.min ) // check min than min
        {
            ret.min = numberset[i];
        }
        if (numberset[i] > ret.max ) // check max than max
        {
            ret.max = numberset[i];
        }
        ret.average = ret.average + numberset[i]; // accumulate
        if (i == (setlength-1))
            ret.average = ret.average/setlength; // calculate average

    }
    return ret;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
