#ifndef __CALLBACK_H__
#define __CALLBACK_H__

#define MAX_ALARMS 10

typedef int (*alarm)(int type);

alarm alarm_list[MAX_ALARMS];

void register_alarm(alarm a);

int hit_alarm(int index);

#endif // __CALLBACK_H__
