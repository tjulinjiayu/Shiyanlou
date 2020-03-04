#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAX_ARGC_NUM 20
#define MAX_PARAM_LEN 20

int main(int argc, char * argv[])
{
    if (argc > 1){
        if (argc > MAX_ARGC_NUM){
            printf("argc number is out of range!\n");
            return 0;
        }

        char param[MAX_ARGC_NUM][MAX_PARAM_LEN];
        int j = 0;
        for(int i=1; i<argc; i++){
            if (strlen(argv[i]) > MAX_PARAM_LEN){
                printf("argument %d length is out of range!\n", i);
                return 0;
            }
            if (argv[i][0] == '-' && argv[i][1] == '-' && argv[i+1] != NULL){
                if (argv[i+1][0] == '-' && argv[i+1][1] == '-')
                    continue;
                strncpy(param[j], &argv[i][2], strlen(argv[i])-2);
                param[j][strlen(argv[i])-2] = '\0';
                printf("%s:%s\n", param[j], argv[i+1]);
                j++;
            }
        }
    }

    return 0;
}
