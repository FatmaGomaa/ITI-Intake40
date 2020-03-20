#include<stdio.h>
#include<stdlib.h>
#include<conio.h>

void swap(int *num1, int *num2){
  int temp=0;
  temp= *num1;
  *num1=*num2;
  *num2=temp;
  printf("the numbers after swapping are %d  %d\n",*num1,*num2);
}

void main(void){
  int x=5,y=10;

  clrscr();
  printf("the numbers before swapping are %d  %d\n",x,y);
  swap(&x,&y);
  getch();

}
