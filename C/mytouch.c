#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<time.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdbool.h>
#include<sys/time.h>
#include<sys/stat.h>

#define CH_ATIME 1
#define CH_MTIME 2
//定义创建文件时的模式，此处对用户，组，其他设置的权限都是可读可写。
#define MODE_RW_UGO (S_IRUSR | S_IWUSR | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH)
//标志文件access time 和 modify time的改变情况
static int change_times;
// 如果有(-c)选项，并且不存在命令行中输入的文件名，则不创建
static bool no_create;
//当设置新的access time 和 modify time的时候使用
static struct timespec newtime[2];
//mytouch命令核心的核心模块，用于创建或者更新文件的时间戳。
static bool mytouch(const char *file);

int main(int argc, char **argv)
{
    int c;
    bool ok = true;
    change_times = 0;
    no_create = false;
    //从命令行中得到命令的选项，即以'-'开头的参数。目前只支持三种选型-a, -c, -m。
    while((c = getopt(argc, argv, "acm")) != -1)
    {
        switch (c)
        {
            case 'a':
                change_times |= CH_ATIME;
                break;
            case 'c':
                no_create = true;
                break;
            case 'm':
                change_times |= CH_MTIME;
                break;
            default:
                printf("fault option!");
        }
    }

    if(change_times == 0)
        change_times = CH_ATIME | CH_MTIME;

    newtime[0].tv_nsec = UTIME_NOW;
    newtime[1].tv_nsec = UTIME_NOW;
    //如果optind == argc，代表少输入文件名字。
    if(optind == argc)
        printf("missing file operand\n");

    for(; optind < argc; ++optind)
        ok &= mytouch(argv[optind]);

    exit(ok ? EXIT_SUCCESS : EXIT_FAILURE);
}

static bool mytouch(const char *file)
{
    bool ok;
    int fd = -1;
    if (!no_create)
    {
        fd = open(file, O_CREAT | O_WRONLY, MODE_RW_UGO);
    }
    //在主函数中，如果没有检测到（-a）（-m），则change_times == (CH_ATIME | CH_MTIME)，\
    //否则按照选项只用改变其中一个时间戳。
    if (change_times != (CH_ATIME | CH_MTIME))
    {
        //只设定其中一个时间值。
        if(change_times == CH_MTIME)
            newtime[0].tv_nsec = UTIME_OMIT;
        else
            newtime[1].tv_nsec = UTIME_OMIT;
    }

    ok = (utimensat(AT_FDCWD, file, newtime, 0) == 0);
    return true;
}


