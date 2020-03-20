#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void main(void){
   int sum=0,current=0;
   clrscr();
   printf("pleaser enter numbers \n");
   while(sum<100){
	 scanf("%d",&current);
	 sum += current;
   }
   printf("the sum of numbers you entered is %d",sum);
   getch();

}