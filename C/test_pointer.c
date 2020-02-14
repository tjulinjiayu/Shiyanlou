#include<stdio.h>
#include<stdlib.h>

void exchange(int * q1,int * q2,int * q3);

int main(int argc,char * argv[])//tips: main����Ҫ��������������ղ���
{
    int a, b, c;
	int *p1, *p2, *p3;

	if(argc == 1)
	{
  		printf("please enter 3 integer number:");
   		scanf("%d%d%d", &a, &b, &c);
    }
	else if(argc == 4)//tips: ����Ҫʵ�ִ������ж������ݣ���scanf ֻ�ܴӼ�������
	{
  		a = atoi(argv[1]);
        b = atoi(argv[2]);
        c = atoi(argv[3]);
	}
	else
		return -1;

    p1 = &a;
    p2 = &b;
    p3 = &c;
    exchange(p1, p2, p3);
    printf("the order is :%d,%d,%d\n",a,b,c);

	return 0;
}

void exchange(int *q1,int *q2,int *q3)
{
   void swap(int *p1,int *p2);

   if(*q1 < *q2) swap(q1,q2);
   if(*q1 < *q3) swap(q1,q3);
   if(*q2 < *q3) swap(q2,q3);
}

void swap(int *p1,int *p2)
{
  int temp;

  temp = *p1;
  *p1 = *p2;
  *p2 = temp;
}

