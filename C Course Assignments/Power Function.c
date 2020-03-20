#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

int Power(int num,int pow){
  if (pow ==1)  {
  return num;
  }else{
  return (num * Power(num,pow -1))  ;
 }
}

void main(void){

	char number=1;
	int power=1;
	int result=0;
	clrscr();
	flushall();

	printf("please enter valid number\n");
	scanf("%d",&number);
	flushall();
   //	scanf("%d",&result);

	printf("please enter valid power\n");
	scanf("%d",&power);
	flushall();

	result = Power(number,power);
	printf("%d ^  %d is %d",number,power,result);
  //	result=0;
	getch();

}