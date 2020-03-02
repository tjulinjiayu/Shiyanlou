#include "callback.h"

void register_alarm(alarm a){
   static int index = 0;
   if(index < MAX_ALARMS-1)
       alarm_list[index++] = a;
}

int hit_alarm(int index){
   if ( index < 0 || index >= MAX_ALARMS)
      return 1;
   int reg_len = sizeof(alarm_list) / sizeof(alarm);
   if (index >= reg_len)
       return 1;
   (*alarm_list[index])(index);
   return 0;
}
