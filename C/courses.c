#include <stdio.h>
#include <string.h>

// 此处 courses 数据不要做任何改动
// courses 变量名不许修改
char *courses[] = {"C","C++","PHP","ASP","ASP.NET","C#","JAVA","BASIC","PASCAL","COBOL"};

void sort(char *p[], int n) {   //实参是指针数组，形参也得为指针数组
    char *tmp;
    int i, j, k;
    for (i = 0; i < n; ++ i) {
        k = i;
        for (j = i; j < n; ++ j) {
            if (strcmp(p[j],p[k]) < 0) {    //p[j] - p[k]   (字典序相减)
                k = j;
            }
        }
        if (k != j) {
            tmp = p[k];
            p[k] = p[i];
            p[i] = tmp;
        }
    }
}

int main() {
    int n = sizeof(courses) / sizeof(char *);   //计算指针数组长度，sizeof(数组名) / sizeof(数组元素类型)
    sort(courses, n);
    int i;
    for (i = 0; i < n; ++ i) {
        printf("%s\n", courses[i]);
    }
    return 0;
}
