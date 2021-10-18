
float min(const float* numberset, int setlength);
float max(const float* numberset, int setlength);
float avg(const float* numberset, int setlength);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
void emailAlerter();
void ledAlerter();

void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats)
{
    localMax = computedStats.max;
    if(localMax > maxThreshold)
    {
        alerters[0]();
        alerters[1]();
    }
}

float min(const float* numberset, int setlength)
{
    float ret = numberset[0];
    for (int i = 1; i < setlength; i++)
    {
        if (ret < numberset[i])
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
        if (ret > numberset[i])
        {
            ret = numberset[i];
        }
    }
    return (float)ret;
}
float avg(const float* numberset, int setlength)
{
    float ret = numberset[0];
    for (int i = 0; i < setlength; i++)
    {
        ret = ret + numberset[i];
    }
    return (float)(ret/setlength);
}

struct Stats compute_statistics(const float* numberset, int setlength) {
        
    struct Stats s;
    s.average = avg(const float* numberset, int setlength);
    s.min = min(const float* numberset, int setlength);
    s.max = max(const float* numberset, int setlength);
    return s;
}

int emailAlertCallCount = 0;
int ledAlertCallCount = 0;
