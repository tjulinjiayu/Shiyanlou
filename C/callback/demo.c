#include <stdio.h>
#include <stdlib.h>
#include "callback.h"

int alarm1(int type){
   printf("Alarm1:%d\n", type);
   return 0;
}

int alarm2(int type){
   printf("Alarm2:%d\n", type);
   return 0;
}

int alarm3(int type){
   printf("Alarm3:%d\n", type);
   return 0;
}

int main() {
   register_alarm(alarm1);
   register_alarm(alarm2);
   register_alarm(alarm3);

   hit_alarm(0);
   hit_alarm(1);
   hit_alarm(2);
   return 0;
}
