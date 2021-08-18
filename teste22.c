#include <stdio.h>
int main(void){
int num, q=1;
int *p;
num=100;
p = &num;
q = *p;
printf("%d",q);
}