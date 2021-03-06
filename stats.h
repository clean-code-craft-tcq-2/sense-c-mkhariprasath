#include "alerter.h"
typedef struct Stats 
{
  float max;
  float min;
  float average;
}stats;

struct Stats compute_statistics(const float* numberset, int setlength);

float min(const float* numberset, int setlength);
float max(const float* numberset, int setlength);
float avg(const float* numberset, int setlength);
void check_and_alert(float maxThreshold, alerter_funcptr alerters[], struct Stats computedStats);
